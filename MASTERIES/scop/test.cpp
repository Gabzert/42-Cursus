#include <GL/glut.h>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>

bool loadObj(    const char * path,
    std::vector < glm::vec3 > & out_vertices,
    std::vector < glm::vec2 > & out_uvs,
    std::vector < glm::vec3 > & out_normals
){
	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	std::vector< glm::vec3 > temp_vertices;
	std::vector< glm::vec2 > temp_uvs;
	std::vector< glm::vec3 > temp_normals;
	FILE * file = fopen(path, "r");
	if( file == NULL ){
		printf("Impossible to open the file !\n");
		return false;
	}
	while(1){
		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.
		else{
			//If the first word of the line is “v”, then the rest has to be 3 floats, so create a glm::vec3 out of them, and add it to the vector.
			if ( strcmp( lineHeader, "v" ) == 0 ){
				glm::vec3 vertex;
				fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
				temp_vertices.push_back(vertex);
			}
			//if it’s not a “v” but a “vt”, then the rest has to be 2 floats, so create a glm::vec2 and add it to the vector.
			else if ( strcmp( lineHeader, "vt" ) == 0 ){
				glm::vec2 uv;
				fscanf(file, "%f %f\n", &uv.x, &uv.y );
				temp_uvs.push_back(uv);
			}
			//same thing for the normals :
			else if ( strcmp( lineHeader, "vn" ) == 0 ){
				glm::vec3 normal;
				fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
				temp_normals.push_back(normal);
			}
			//And now the “f”, which is more difficult :
			else if ( strcmp( lineHeader, "f" ) == 0 ){
				std::string vertex1, vertex2, vertex3;
				unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
				int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
				if (matches != 9){
					printf("File can't be read by our simple parser : ( Try exporting with other options\n");
					return false;
				}
				vertexIndices.push_back(vertexIndex[0]);
				vertexIndices.push_back(vertexIndex[1]);
				vertexIndices.push_back(vertexIndex[2]);
				uvIndices.push_back(uvIndex[0]);
				uvIndices.push_back(uvIndex[1]);
				uvIndices.push_back(uvIndex[2]);
				normalIndices.push_back(normalIndex[0]);
				normalIndices.push_back(normalIndex[1]);
				normalIndices.push_back(normalIndex[2]);
			}
		}
		//We go through each vertex ( each v/vt/vn ) of each triangle ( each line with a “f” ) :
		// For each vertex of each triangle
		//the index to the vertex position is vertexIndices[i] :
		for( unsigned int i=0; i<vertexIndices.size(); i++ ){

			//so the position is temp_vertices[ vertexIndex-1 ] (there is a -1 because C++ indexing starts at 0 and OBJ indexing starts at 1, remember ?) :
			unsigned int vertexIndex = vertexIndices[i];

			//And this makes the position of our new vertex
			glm::vec3 vertex = temp_vertices[ vertexIndex-1 ];

			//The same is applied for UVs and normals, and we’re done !
			out_vertices.push_back(vertex);
		}
		return true;
	}
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.5, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.5, -0.5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.0, 0.5);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Example");

    // glutDisplayFunc(display);
	// Read our .obj file
	std::vector< glm::vec3 > vertices;
	std::vector< glm::vec2 > uvs;
	std::vector< glm::vec3 > normals; // Won't be used at the moment.
	bool res = loadOBJ("cube.obj", vertices, uvs, normals);
	//and give your vectors to OpenGL instead of your arrays :

	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
    glutMainLoop();
    return 0;
}
