#include "scop.hpp"

GLuint vbo, vao, ProgramID, width = 800, height = 600;
GLFWwindow* window;

// Initial position : on +Z
glm::vec3 position = glm::vec3( 0, 0, 20 ); 
// Initial horizontal angle : toward -Z
float horizontalAngle = 3.14f;
// Initial vertical angle : none
float verticalAngle = 0.0f;
// Initial Field of View
float initialFoV = 45.0f;
float Zoom = 1.0f;

float speed = 3.0f; // 3 units / second
float mouseSpeed = 0.005f;


static const GLfloat test_triangle[] = {
-1.0f, -1.0f, 0.0f,
1.0f, -1.0f, 0.0f,
0.0f,  1.0f, 0.0f,
};

void setUpOpenGl(std::vector < glm::vec3 > &vertices)
{
	(void) vertices;
	// Set up OpenGL context and shaders
	glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D rendering
	glEnable(GL_CULL_FACE); // Enable backface culling
	// // Set up VAO
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Set up VBO
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	// glBufferData(GL_ARRAY_BUFFER, sizeof(test_triangle), test_triangle, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

void display(std::vector < glm::vec3 > & vertices) {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Bind VAO and enable shader program
    glBindVertexArray(vao);
    glUseProgram(ProgramID);

	// Projection matrix: 45° Field of View, 4:3 ratio, display range: 0.1 unit <-> 100 units
	// glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float) width / (float)height, 0.1f, 100.0f);

	// Or, for an ortho camera:
	//glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates


	// Compute the MVP matrix from keyboard and mouse input
	computeMatricesFromInputs();
	glm::mat4 ProjectionMatrix = getProjectionMatrix();
	glm::mat4 ViewMatrix = getViewMatrix();
	glm::mat4 ModelMatrix = glm::mat4(1.0);
	glm::mat4 mvp = ProjectionMatrix * ViewMatrix * ModelMatrix;


	// Get a handle for our "MVP" uniform
	// Only during the initialisation
	GLuint MatrixID = glGetUniformLocation(ProgramID, "MVP");

	// Send our transformation to the currently bound shader, in the "MVP" uniform
	// This is done in the main loop since each model will have a different MVP matrix (At least for the M part)
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);

    // glm::vec4 color1 = glm::vec4(0.843f, 0.918f, 0.953f, 1);
	glm::vec4 color1 = glm::vec4(1.0f, 1.0f, 1.0f, 1);
	glm::vec4 color2 = glm::vec4(0.467f, 0.71f, 0.851f, 1);
	// glm::vec4 color2 = glm::vec4(1.0f, 1.0f, 1.0f, 1);
	GLuint evenClr = glGetUniformLocation(ProgramID, "_EvenColor");
	GLuint oddClr = glGetUniformLocation(ProgramID, "_OddColor");
	glUniform4fv(evenClr, 1, &color1[0]);
	glUniform4fv(oddClr, 1, &color2[0]);

    // Draw the object
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());

    // Unbind VAO and shader program
    glBindVertexArray(0);
    glUseProgram(0);
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }
    std::vector<glm::vec3> vertices;
    loadObj("./resources/42.obj", vertices);
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
		Zoom += yoffset;
	});


	setUpOpenGl(vertices);

	ProgramID = LoadShaders( "./vertexShader.dsl", "./fragmentShader.dsl" );

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Call the display function
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
