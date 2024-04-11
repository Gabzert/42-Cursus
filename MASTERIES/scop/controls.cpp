#include "scop.hpp"
extern double dragStartX, dragStartY;
extern bool isDragging;
extern bool toggle;

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

void change_texture_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	(void) window;
	(void) scancode;
	(void) mods;
	if (key == GLFW_KEY_T && action == GLFW_PRESS) {
		toggle = !toggle;
	}
}

void controls_setup(GLFWwindow* window) {
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
	// Set mouse button callback
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	// Set cursor position callback
	glfwSetCursorPosCallback(window, cursor_position_callback);

	glfwSetKeyCallback(window, change_texture_callback);

}
