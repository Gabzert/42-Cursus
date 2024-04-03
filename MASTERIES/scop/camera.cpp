#include "scop.hpp"

Matrix ViewMatrix;
Matrix ProjectionMatrix;
// Define variables to store initial mouse position when dragging starts
double dragStartX, dragStartY = 0;
bool isDragging = false;

Matrix getViewMatrix(){
	return ViewMatrix;
}
Matrix getProjectionMatrix(){
	return ProjectionMatrix;
}

// Mouse button callback function
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	(void) mods;
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        if (action == GLFW_PRESS) {
            // Start dragging
            isDragging = true;
            glfwGetCursorPos(window, &dragStartX, &dragStartY);
        }
        else if (action == GLFW_RELEASE) {
            // Stop dragging
            isDragging = false;
        }
    }
}

// Mouse movement callback function
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
	(void) window;
    if (isDragging) {
        // Calculate offset from drag start position
        double deltaX = dragStartX - xpos;
        double deltaY = ypos - dragStartY;

        // Update orientation based on mouse movement
        horizontalAngle += mouseSpeed * deltaX;
        verticalAngle += mouseSpeed * deltaY;

        // Clamp vertical angle to avoid flipping
        verticalAngle = std::max(-89.0f, std::min(89.0f, verticalAngle));

        // Update drag start position for next frame
        dragStartX = xpos;
        dragStartY = ypos;
    }
}

// MATRICE OK
Matrix perspective(float fov, float aspectRatio, float nearClip, float farClip) {
    Matrix projectionMatrix;
    
    // Convert field of view from degrees to radians
    float fovRadians = fov * (M_PI / 180.0f);
    
    // Calculate the distance to the view plane
    float d = 1.0f / tan(fovRadians / 2.0f);
    
    // Calculate the matrix elements
    projectionMatrix[0][0] = d / aspectRatio;
    projectionMatrix[1][1] = d;
    projectionMatrix[2][2] = (nearClip + farClip) / (nearClip - farClip);
    projectionMatrix[2][3] = -1.0f;
    projectionMatrix[3][2] = (2.0f * nearClip * farClip) / (nearClip - farClip);
    
	// std::cout << "----- Projection matrix: ---------" << std::endl;
	// for (int i = 0; i < 4; i++) {
	// 	for (int j = 0; j < 4; j++) {
	// 		std::cout << projectionMatrix[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }

    return projectionMatrix;
}

// MATRICE OK
Matrix lookAt(Vec3& position, Vec3& target, Vec3& up) {
    // Calculate the forward vector (direction from position to target)
    Vec3 forward = (target - position).normalize();
    
    // Calculate the right vector
    Vec3 right = forward.cross(up).normalize();
    
    // Calculate the actual up vector
    Vec3 actualUp = right.cross(forward);
    
    Matrix matrix;

    // set rotation part, inverse rotation matrix: M^-1 = M^T for Euclidean transform
    matrix[0][0] = right.x;
    matrix[1][0] = right.y;
    matrix[2][0] = right.z;
    matrix[0][1] = actualUp.x;
    matrix[1][1] = actualUp.y;
    matrix[2][1] = actualUp.z;
    matrix[0][2] = -forward.x;
    matrix[1][2] = -forward.y;
    matrix[2][2]= -forward.z;
    // set translation part
    matrix[3][0]= -(right.x * position.x + right.y * position.y + right.z * position.z);
    matrix[3][1]= -(actualUp.x * position.x + actualUp.y * position.y + actualUp.z * position.z);
    matrix[3][2]= (forward.x * position.x + forward.y * position.y + forward.z * position.z);

    // set the last element to 1
    matrix[3][3] = 1.0f;

	// std::cout << "----- View matrix: ---------" << std::endl;
	// for (int i = 0; i < 4; i++) {
	// 	for (int j = 0; j < 4; j++) {
	// 		std::cout << matrix[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }

    return matrix;
}

void computeMatricesFromInputs() {

    position.x = cos(verticalAngle) * sin(horizontalAngle) * Zoom;
    position.y = sin(verticalAngle) * Zoom;
    position.z = cos(verticalAngle) * cos(horizontalAngle) * Zoom;

	Vec3 direction(0.0f, 0.0f, 0.0f);

    // Define up vector
	Vec3 up(0.0f, 1.0f, 0.0f);
    
    float FoV = initialFoV;

	ProjectionMatrix = perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);
	ViewMatrix = lookAt(position, direction, up);
}

// MATRICE OK
void putInOrigin(std::vector < Vec3 > &vertices){
    GLfloat minX = vertices[0].x, maxX = vertices[0].x;
    GLfloat minY = vertices[0].y, maxY = vertices[0].y;
    GLfloat minZ = vertices[0].z, maxZ = vertices[0].z;

    for (const auto& Vec3 : vertices) {
        minX = std::min(minX, Vec3.x);
        maxX = std::max(maxX, Vec3.x);
        minY = std::min(minY, Vec3.y);
        maxY = std::max(maxY, Vec3.y);
        minZ = std::min(minZ, Vec3.z);
        maxZ = std::max(maxZ, Vec3.z);
    }

	GLfloat centerX = (minX + maxX) / 2.0f;
	GLfloat centerY = (minY + maxY) / 2.0f;
	GLfloat centerZ = (minZ + maxZ) / 2.0f;

	GLfloat translateX = -centerX;
	GLfloat translateY = -centerY;
	GLfloat translateZ = -centerZ;

    Matrix translationMatrix(1.0f); // Identity matrix
    translationMatrix[3][0] = translateX;
    translationMatrix[3][1] = translateY;
    translationMatrix[3][2] = translateZ;

	for (auto& Vec3 : vertices) {
		Vec3.x += translateX;
		Vec3.y += translateY;
		Vec3.z += translateZ;
	}
}

void calculateUV(std::vector<Vec3>& vertices, std::vector<Vec2>& uvs) {
	// Find bounding box of the mesh
	Vec3 minVertex, maxVertex = vertices[0];
	for (const auto& vertex : vertices) {
		minVertex.x = std::min(minVertex.x, vertex.x);
		minVertex.y = std::min(minVertex.y, vertex.y);
		minVertex.z = std::min(minVertex.z, vertex.z);
		maxVertex.x = std::max(maxVertex.x, vertex.x);
		maxVertex.y = std::max(maxVertex.y, vertex.y);
		maxVertex.z = std::max(maxVertex.z, vertex.z);
	}

	// Calculate center and radius of the bounding cylinder
	Vec3 center = (minVertex + maxVertex);
	center.x *= 0.5f;
	center.y *= 0.5f;
	center.z *= 0.5f;

	// Project vertices onto the cylinder and calculate UV coordinates
	for (Vec3 vertex : vertices) {
		// Calculate cylindrical coordinates
		Vec3 direction = vertex - center;
		float angle = std::atan2(direction.z, direction.x);
		float height = vertex.y - minVertex.y; // Assume cylinder is aligned with Y-axis

		// Map cylindrical coordinates to UV space
		Vec2 uv;
		uv.x = (angle + M_PI) / (2.0f * M_PI); // Normalize angle to [0, 1]
		uv.y = height / (maxVertex.y - minVertex.y); // Normalize height to [0, 1]

		uvs.push_back(uv);
	}
}

