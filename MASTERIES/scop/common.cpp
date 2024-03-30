#include "scop.hpp"

Matrix ViewMatrix;
Matrix ProjectionMatrix;

std::vector<std::string> split(std::string s, char delimiter) {
	std::vector<std::string> tokens;
	size_t pos = 0;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		std::string token = s.substr(0, pos);
		tokens.push_back(token);
		s.erase(0, pos + 1);
	}
	tokens.push_back(s);  // Add the last token
	return tokens;
}

Vertex3 crossProduct(const Vertex3& a, const Vertex3& b) {
    Vertex3 result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}

// MATRICE OK
Matrix putInOrigin(std::vector < Vertex3 > &vertices){
    GLfloat minX = vertices[0].x, maxX = vertices[0].x;
    GLfloat minY = vertices[0].y, maxY = vertices[0].y;
    GLfloat minZ = vertices[0].z, maxZ = vertices[0].z;

    for (const auto& Vertex3 : vertices) {
        minX = std::min(minX, Vertex3.x);
        maxX = std::max(maxX, Vertex3.x);
        minY = std::min(minY, Vertex3.y);
        maxY = std::max(maxY, Vertex3.y);
        minZ = std::min(minZ, Vertex3.z);
        maxZ = std::max(maxZ, Vertex3.z);
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

	std::cout << "----- Translation matrix: ---------" << std::endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << translationMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return translationMatrix;
}

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path){

	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex3 Shader code from the file
	std::string VertexShaderCode;
	std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
	if(VertexShaderStream.is_open()){
		std::stringstream sstr;
		sstr << VertexShaderStream.rdbuf();
		VertexShaderCode = sstr.str();
		VertexShaderStream.close();
	}else{
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertex_file_path);
		getchar();
		return 0;
	}

	// Read the Fragment Shader code from the file
	std::string FragmentShaderCode;
	std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
	if(FragmentShaderStream.is_open()){
		std::stringstream sstr;
		sstr << FragmentShaderStream.rdbuf();
		FragmentShaderCode = sstr.str();
		FragmentShaderStream.close();
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;

	// Compile Vertex3 Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
	glCompileShader(VertexShaderID);

	// Check Vertex3 Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}

	// Compile Fragment Shader
	printf("Compiling shader : %s\n", fragment_file_path);
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
	glCompileShader(FragmentShaderID);

	// Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}

	// Link the program
	printf("Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> ProgramErrorMessage(InfoLogLength+1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}

	// glDetachShader(ProgramID, VertexShaderID);
	// glDetachShader(ProgramID, FragmentShaderID);
	
	// glDeleteShader(VertexShaderID);
	// glDeleteShader(FragmentShaderID);

	return ProgramID;
}

void loadMaterials(const char* path, std::vector<Material>& out_materials) {
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("Impossible to open the file: %s\n", path);
        return;
    }

    Material currentMaterial;
    char lineHeader[128];
    while (fscanf(file, "%s", lineHeader) != EOF) {
        if (strcmp(lineHeader, "newmtl") == 0) {
            if (currentMaterial.name != "") {
                out_materials.push_back(currentMaterial);
            }
            fscanf(file, "%s\n", lineHeader);
            currentMaterial.name = lineHeader;
        } else if (strcmp(lineHeader, "Ka") == 0) {
            fscanf(file, "%f %f %f\n", &currentMaterial.ambientColor.x, &currentMaterial.ambientColor.y, &currentMaterial.ambientColor.z);
        } else if (strcmp(lineHeader, "Kd") == 0) {
            fscanf(file, "%f %f %f\n", &currentMaterial.diffuseColor.x, &currentMaterial.diffuseColor.y, &currentMaterial.diffuseColor.z);
        } else if (strcmp(lineHeader, "Ks") == 0) {
            fscanf(file, "%f %f %f\n", &currentMaterial.specularColor.x, &currentMaterial.specularColor.y, &currentMaterial.specularColor.z);
        } else if (strcmp(lineHeader, "Ns") == 0) {
            fscanf(file, "%f\n", &currentMaterial.shininess);
        }
        // You can add more material properties parsing here if needed
    }

    if (currentMaterial.name != "") {
        out_materials.push_back(currentMaterial);
    }

    fclose(file);
}

bool loadObj(const char * path, std::vector < Vertex3 > & out_vertices, std::vector < Vertex3 > &out_normals, std::vector <Material>& out_materials, std::vector < Vertex3 > &out_colors){
	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	std::vector< Vertex3 > temp_vertices;
	std::ifstream file;
	file.open(path);

	Vertex3 color3 = Vertex3(0.634f, 0.457f, 0.789f);
	Vertex3 color2 = Vertex3(0.467f, 0.71f, 0.851f);
	Vertex3 color1 = Vertex3(0.843f, 0.918f, 0.953f);
	std::vector<Vertex3> colors = {color1, color2, color3};
	if(!file.is_open()){
		printf("Impossible to open the file !\n");
		return false;
	}
	while(file){
		std::string line;
		std::getline(file, line);
		std::vector<std::string> tokens = split(line, ' ');
		if ( tokens[0] == "v"){
			Vertex3 Vertex3;
			Vertex3.x = std::stof(tokens[1]);
			Vertex3.y = std::stof(tokens[2]);
			Vertex3.z = std::stof(tokens[3]);			
			temp_vertices.push_back(Vertex3);
		} else if (tokens[0] == "f"){
			unsigned int vertexIndex[4];
			if (tokens.size() == 4) {
				vertexIndex[0] = std::stoi(tokens[1]);
				vertexIndex[1] = std::stoi(tokens[2]);
				vertexIndex[2] = std::stoi(tokens[3]);
				vertexIndices.push_back(vertexIndex[0]);
				vertexIndices.push_back(vertexIndex[1]);
				vertexIndices.push_back(vertexIndex[2]);
			} else if (tokens.size() == 5){
				vertexIndex[0] = std::stoi(tokens[1]);
				vertexIndex[1] = std::stoi(tokens[2]);
				vertexIndex[2] = std::stoi(tokens[3]);
				vertexIndex[3] = std::stoi(tokens[4]);
				// First triangle
				vertexIndices.push_back(vertexIndex[0]);
				vertexIndices.push_back(vertexIndex[1]);
				vertexIndices.push_back(vertexIndex[2]);
				// Second triangle
				vertexIndices.push_back(vertexIndex[0]);
				vertexIndices.push_back(vertexIndex[2]);
				vertexIndices.push_back(vertexIndex[3]);
			}
		} else if (tokens[0] == "mtllib") {
			std::string materialFilePath = "./resources/" + tokens[1];
			loadMaterials(materialFilePath.c_str(), out_materials);
		}
		for (unsigned int i = 0; i < vertexIndices.size(); i += 3) {
			Vertex3 v0 = temp_vertices[vertexIndices[i] - 1];
			Vertex3 v1 = temp_vertices[vertexIndices[i + 1] - 1];
			Vertex3 v2 = temp_vertices[vertexIndices[i + 2] - 1];
			Vertex3 faceNormal = crossProduct(v1 - v0, v2 - v0);
			for (int j = 0; j < 3; j++) {
				out_normals.push_back(faceNormal);
			}
		}
		//We go through each Vertex3 ( each v/vt/vn ) of each triangle ( each line with a “f” ) :
		// For each Vertex3 of each triangle the index to the Vertex3 position is vertexIndices[i] :
		for( unsigned int i=0; i<vertexIndices.size(); i++ ){
			unsigned int vertexIndex = vertexIndices[i];
			Vertex3 vertex = temp_vertices[ vertexIndex-1 ];
			Vertex3 color = colors[i % 3];
			out_vertices.push_back(vertex);
			out_colors.push_back(color);
		}
	}
	return false;
}

Matrix getViewMatrix(){
	return ViewMatrix;
}
Matrix getProjectionMatrix(){
	return ProjectionMatrix;
}

// void computeMatricesFromInputs(){

// 	// Get mouse position
// 	double xpos, ypos;
// 	glfwGetCursorPos(window, &xpos, &ypos);

// 	// Reset mouse position for next frame
// 	glfwSetCursorPos(window, width/2, height/2);

// 	// Compute new orientation
// 	horizontalAngle += mouseSpeed * float(width/2 - xpos );
// 	verticalAngle   += mouseSpeed * float( height/2 - ypos );

// 	position = Vertex3(
// 		cos(verticalAngle) * sin(horizontalAngle) * Zoom, 
// 		sin(verticalAngle) * Zoom,
// 		cos(verticalAngle) * cos(horizontalAngle) * Zoom
// 	);
	
// 	Vertex3 direction = Vertex3(0.0, 0.0, 0.0);

// 	Vertex3 up = Vertex3(0.0, 1.0, 0.0);
// 	float FoV = initialFoV; // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.

// 	// Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
// 	ProjectionMatrix = glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);
// 	// Camera matrix
// 	ViewMatrix = glm::lookAt(
// 			position,           // Camera is here
// 			direction, // and looks here : at the same position, plus "direction"
// 			up                  // Head is up (set to 0,-1,0 to look upside-down)
// 			);
// }

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
    
	std::cout << "----- Projection matrix: ---------" << std::endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << projectionMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

    return projectionMatrix;
}

// MATRICE OK
Matrix lookAt(Vertex3& position, Vertex3& target, Vertex3& up) {
    // Calculate the forward vector (direction from position to target)
    Vertex3 forward = (target - position).normalize();
    
    // Calculate the right vector
    Vertex3 right = forward.cross(up).normalize();
    
    // Calculate the actual up vector
    Vertex3 actualUp = right.cross(forward);
    
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

	std::cout << "----- View matrix: ---------" << std::endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

    return matrix;
}

void computeMatricesFromInputs() {
    // Get mouse position
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    // Reset mouse position for next frame
    glfwSetCursorPos(window, width / 2, height / 2);

    // Compute new orientation
    horizontalAngle += mouseSpeed * float(width / 2 - xpos);
    verticalAngle += mouseSpeed * float(height / 2 - ypos);

    position.x = cos(verticalAngle) * sin(horizontalAngle) * Zoom;
    position.y = sin(verticalAngle) * Zoom;
    position.z = cos(verticalAngle) * cos(horizontalAngle) * Zoom;

	Vertex3 direction(0.0f, 0.0f, 0.0f);

    // Define up vector
	Vertex3 up(0.0f, 1.0f, 0.0f);
    
    float FoV = initialFoV;

	ProjectionMatrix = perspective(FoV, 4.0f / 3.0f, 0.1f, 100.0f);
	ViewMatrix = lookAt(position, direction, up);
}



