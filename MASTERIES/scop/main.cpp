#include "scop.hpp"

GLuint vbo, vao, ProgramID, width = 800, height = 600;
GLFWwindow* window;

// Initial position : on +Z
Vertex3 position = Vertex3( 10, 0, 0 ); 
// Initial horizontal angle : toward -Z
float horizontalAngle = 3.14f;
// Initial vertical angle : none
float verticalAngle = 0.0f;
// Initial Field of View
float initialFoV = 45.0f;
float Zoom = 10.0f;

float speed = 3.0f; // 3 units / second
float mouseSpeed = 0.005f;


static const GLfloat test_cube[] = {
    -1.0f,-1.0f,-1.0f, // triangle 1 : begin
	-1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f, // triangle 1 : end
    1.0f, 1.0f,-1.0f, // triangle 2 : begin
	-1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f, // triangle 2 : end
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f
};

void setUpOpenGl(std::vector < Vertex3 > &vertices, std::vector < Vertex3 > &normals, std::vector < Vertex3 > &colors)
{
	(void) vertices;
	(void) normals;
	// Set up OpenGL context and shaders
	glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D rendering
	glEnable(GL_CULL_FACE); // Enable backface culling
	// // Set up VAO
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Set up VBO
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex3) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	// glBufferData(GL_ARRAY_BUFFER, sizeof(test_cube), test_cube, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	// // Generate and bind VBO for normals
	// GLuint vboNormals;
	// glGenBuffers(1, &vboNormals);
	// glBindBuffer(GL_ARRAY_BUFFER, vboNormals);
	// glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(Vertex3), &normals[0], GL_STATIC_DRAW);

	// // Specify Vertex3 attribute pointers for normals
	// glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, nullptr); // Assuming normals are at location 1
	// glEnableVertexAttribArray(2); // Enable Vertex3 attribute array for normals

	// GLint cameraPos = glGetUniformLocation(ProgramID, "cameraPos");
	// glUniform3fv(cameraPos, 1, &position[0]);


	GLuint colorVBO;
	glGenBuffers(1, &colorVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
	glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(Vertex3), &colors[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Clean up
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glDeleteBuffers(1, &colorVBO);
}

void display(std::vector < Vertex3 > & vertices) {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Bind VAO and enable shader program
    glBindVertexArray(vao);
    glUseProgram(ProgramID);

	// Compute the MVP matrix from keyboard and mouse input
	computeMatricesFromInputs();
	Matrix ProjectionMatrix = getProjectionMatrix();
	Matrix ViewMatrix = getViewMatrix();
	Matrix ModelMatrix = putInOrigin(vertices);
	// Matrix ModelMatrix(1.0f);
	Matrix mvp = ModelMatrix * ViewMatrix * ProjectionMatrix ;
	std::cout << "----- MVP Matrix: ---------" << std::endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << mvp[i][j] << " ";
		}
		std::cout << std::endl;
	}
	GLuint MatrixID = glGetUniformLocation(ProgramID, "MVP");
	// Send our transformation to the currently bound shader, in the "MVP" uniform
	// This is done in the main loop since each model will have a different MVP matrix (At least for the M part)
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);
	// GLuint ModelMatrixID = glGetUniformLocation(ProgramID, "M");
	// glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMatrix[0][0]);
	// GLuint ViewMatrixID = glGetUniformLocation(ProgramID, "V");
	// glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &ViewMatrix[0][0]);

	// glm::vec4 color2 = glm::vec4(0.467f, 0.71f, 0.851f, 1);
	// glm::vec4 color1 = glm::vec4(0.843f, 0.918f, 0.953f, 1);
	// GLuint evenClr = glGetUniformLocation(ProgramID, "_EvenColor");
	// GLuint oddClr = glGetUniformLocation(ProgramID, "_OddColor");
	// glUniform4fv(evenClr, 1, &color1[0]);
	// glUniform4fv(oddClr, 1, &color2[0]);
	// printf("Drawing\n");
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	// printf("Done Drawing\n");
    glBindVertexArray(0);
    glUseProgram(0);
}

int main(int argc, char** argv) {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }
	if (argc != 2) {
		std::cerr << "Usage: ./scop <obj file>\n";
		return -1;
	}
    std::vector<Vertex3> vertices;
	std::vector<Vertex3> normals;
	std::vector<Material> materials;
	std::vector<Vertex3> colors;
    loadObj(argv[1], vertices, normals, materials, colors);
    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(width, height, "OpenGL Example", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Set the display function
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow*, int width, int height) { glViewport(0, 0, width, height); });
    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		(void) mods;
		(void) scancode;
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);
    });
	glfwSetScrollCallback(window, [](GLFWwindow* window, double xoffset, double yoffset) {
		// Zoom in or out based on the yoffset value
		(void) window;
		(void) xoffset;
		Zoom -= yoffset;
	});


	setUpOpenGl(vertices, normals, colors);

	ProgramID = LoadShaders( "./vertexShader.glsl", "./fragmentShader.glsl" );
	printf("Program Loaded \n");
	// GLint materialAmbientLoc = glGetUniformLocation(ProgramID, "material.ambientColor");
	// GLint materialDiffuseLoc = glGetUniformLocation(ProgramID, "material.diffuseColor");
	// GLint materialSpecularLoc = glGetUniformLocation(ProgramID, "material.specularColor");
	// GLint materialShininessLoc = glGetUniformLocation(ProgramID, "material.shininess");

	// // Set material uniforms
	// glUniform3fv(materialAmbientLoc, 1, &materials[0].ambientColor[0]);
	// glUniform3fv(materialDiffuseLoc, 1, &materials[0].diffuseColor[0]);
	// glUniform3fv(materialSpecularLoc, 1, &materials[0].specularColor[0]);
	// glUniform1f(materialShininessLoc, materials[0].shininess);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Call the display function
		system("clear");
        display(vertices);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up GLFW
    glfwTerminate();
    return 0;
}
