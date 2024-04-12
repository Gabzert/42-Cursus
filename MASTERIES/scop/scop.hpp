#pragma once

#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <GLES3/gl3.h>
#include <GL/glcorearb.h>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>


#include "Vertex.hpp"
#include "Matrix.hpp"

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
extern Vec3 position;
extern float Zoom;


struct Material {
    std::string name;
    Vec3 ambientColor;
    Vec3 diffuseColor;
    Vec3 specularColor;
    float shininess;
    // You can add more properties such as texture paths if needed
};

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
bool loadObj(const char * path, std::vector < Vec3 > & out_vertices, std::vector < Vec3 > &out_normals, std::vector < Material > & out_materials, std::vector < Vec3> & out_colors);
Matrix getViewMatrix();
Matrix getProjectionMatrix();
void computeMatricesFromInputs();
void putInOrigin(std::vector < Vec3 > &vertices);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
GLuint loadBMP(const char * imagepath);
void calculateUV(std::vector < Vec3 > &vertices, std::vector < Vec2 > &uvs);
void controls_setup(GLFWwindow* window);
Matrix rotationMatrix(float angle, Vec3 axis);
