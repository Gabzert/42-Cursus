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
extern Vertex3 position;
extern float Zoom;


struct Material {
    std::string name;
    Vertex3 ambientColor;
    Vertex3 diffuseColor;
    Vertex3 specularColor;
    float shininess;
    // You can add more properties such as texture paths if needed
};

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
bool loadObj(const char * path, std::vector < Vertex3 > & out_vertices, std::vector < Vertex3 > &out_normals, std::vector < Material > & out_materials, std::vector < Vertex3> & out_colors);
Matrix getViewMatrix();
Matrix getProjectionMatrix();
void computeMatricesFromInputs();
Matrix putInOrigin(std::vector < Vertex3 > &vertices);

