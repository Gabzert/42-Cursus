#pragma once

#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <GLES3/gl3.h>
#include <GL/glcorearb.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <fstream>
#include <sstream>


extern GLuint vbo;
extern GLuint vao;
extern GLuint ProgramID;
extern GLuint width;
extern GLuint height;
extern GLFWwindow* window;
extern float horizontalAngle;
extern float verticalAngle;
extern float initialFoV;
extern float speed;
extern float mouseSpeed;
extern glm::vec3 position;
extern float Zoom;


GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
bool loadObj(const char * path, std::vector < glm::vec3 > & out_vertices);
glm::mat4 getViewMatrix();
glm::mat4 getProjectionMatrix();
void computeMatricesFromInputs();

