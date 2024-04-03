#include "scop.hpp"

GLuint vbo, vao, ProgramID, width = 800, height = 600;
GLFWwindow* window;

// Initial position : on +Z
Vec3 position = Vec3( 10, 0, 0 ); 
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
	-1.0f,-1.0f,-1.0f,
	-1.0f,-1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f, 1.0f,-1.0f,
	-1.0f,-1.0f,-1.0f,
	-1.0f, 1.0f,-1.0f,
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

static const GLfloat test_cube_uv[] = { 
	0.000059f, 1.0f-0.000004f, 
	0.000103f, 1.0f-0.336048f, 
	0.335973f, 1.0f-0.335903f, 
	1.000023f, 1.0f-0.000013f, 
	0.667979f, 1.0f-0.335851f, 
	0.999958f, 1.0f-0.336064f, 
	0.667979f, 1.0f-0.335851f, 
	0.336024f, 1.0f-0.671877f, 
	0.667969f, 1.0f-0.671889f, 
	1.000023f, 1.0f-0.000013f, 
	0.668104f, 1.0f-0.000013f, 
	0.667979f, 1.0f-0.335851f, 
	0.000059f, 1.0f-0.000004f, 
	0.335973f, 1.0f-0.335903f, 
	0.336098f, 1.0f-0.000071f, 
	0.667979f, 1.0f-0.335851f, 
	0.335973f, 1.0f-0.335903f, 
	0.336024f, 1.0f-0.671877f, 
	1.000004f, 1.0f-0.671847f, 
	0.999958f, 1.0f-0.336064f, 
	0.667979f, 1.0f-0.335851f, 
	0.668104f, 1.0f-0.000013f, 
	0.335973f, 1.0f-0.335903f, 
	0.667979f, 1.0f-0.335851f, 
	0.335973f, 1.0f-0.335903f, 
	0.668104f, 1.0f-0.000013f, 
	0.336098f, 1.0f-0.000071f, 
	0.000103f, 1.0f-0.336048f, 
	0.000004f, 1.0f-0.671870f, 
	0.336024f, 1.0f-0.671877f, 
	0.000103f, 1.0f-0.336048f, 
	0.336024f, 1.0f-0.671877f, 
	0.335973f, 1.0f-0.335903f, 
	0.667969f, 1.0f-0.671889f, 
	1.000004f, 1.0f-0.671847f, 
	0.667979f, 1.0f-0.335851f
};

void setUpOpenGl(std::vector < Vec3 > &vertices, std::vector < Vec2 > &uvs, std::vector < Vec3 > &colors){

	(void) vertices;
	(void) uvs;
	putInOrigin(vertices);
	// Register callback functions
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	// Set up OpenGL context and shaders
	glEnable(GL_DEPTH_TEST); // Enable depth testing for 3D rendering
	glEnable(GL_CULL_FACE); // Enable backface culling
	glEnable(GL_TEXTURE_2D);
	// // Set up VAO
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//------------- VERTICES VBO-------------------
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	// glBufferData(GL_ARRAY_BUFFER, sizeof(Vec3) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(test_cube), test_cube, GL_STATIC_DRAW);
	
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	//---------------------------------------------

	//------------- COLOR VBO ---------------------
	GLuint colorVBO;
	glGenBuffers(1, &colorVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorVBO);
	glBufferData(GL_ARRAY_BUFFER, colors.size() * sizeof(Vec3), &colors[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	//---------------------------------------------


	// ------------- UVS VBO -----------------------
	GLuint vboUvs;
	glGenBuffers(1, &vboUvs);
	glBindBuffer(GL_ARRAY_BUFFER, vboUvs);
	// glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(Vec2), &uvs[0], GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(test_cube_uv), test_cube_uv, GL_STATIC_DRAW);

	// Specify Vec3 attribute pointers for uvs
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	//---------------------------------------------



	// Clean up
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glDeleteBuffers(1, &colorVBO);
}

void display(std::vector < Vec3 > & vertices, std::vector < Vec2 > & uvs, GLuint Texture) {
	(void) uvs;

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Bind VAO and enable shader program
    glBindVertexArray(vao);
    glUseProgram(ProgramID);

	// Compute the MVP matrix from keyboard and mouse input
	computeMatricesFromInputs();
	Matrix ProjectionMatrix = getProjectionMatrix();
	Matrix ViewMatrix = getViewMatrix();
	Matrix ModelMatrix(1.0f);
	Matrix mvp = ModelMatrix * ViewMatrix * ProjectionMatrix ;
	// std::cout << "----- MVP Matrix: ---------" << std::endl;
	// for (int i = 0; i < 4; i++) {
	// 	for (int j = 0; j < 4; j++) {
	// 		std::cout << mvp[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
	GLuint MatrixID = glGetUniformLocation(ProgramID, "MVP");
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);

	GLuint useTexture = glGetUniformLocation(ProgramID, "useTexture");
	glUniform1i(useTexture, 1);

	// Bind our texture in Texture Unit 0
	GLuint TextureID  = glGetUniformLocation(ProgramID, "textureSampler");
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, Texture);
	glUniform1i(TextureID, 0);



    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	// printf("Done Drawing\n");
    glBindVertexArray(0);
    glUseProgram(0);
	glBindTexture(GL_TEXTURE_2D, 0);
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
    std::vector<Vec3> vertices;
	std::vector<Vec3> normals;
	std::vector<Material> materials;
	std::vector<Vec3> colors;
	std::vector<Vec2> uvs;
    loadObj(argv[1], vertices, normals, materials, colors);
	GLuint Texture = loadBMP("./resources/amogus.bmp");
	calculateUV(vertices, uvs);
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


	setUpOpenGl(vertices, uvs, colors);

	ProgramID = LoadShaders( "./vertexShader.glsl", "./fragmentShader.glsl" );
	printf("Program Loaded \n");

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Call the display function
		// system("clear");
        display(vertices, uvs, Texture);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up GLFW
    glfwTerminate();
    return 0;
}
