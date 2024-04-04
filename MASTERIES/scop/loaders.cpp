#include "scop.hpp"

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

Vec3 crossProduct(const Vec3& a, const Vec3& b) {
    Vec3 result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}


GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path){

	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vec3 Shader code from the file
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

	// Compile Vec3 Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
	glCompileShader(VertexShaderID);

	// Check Vec3 Shader
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

GLuint loadBMP(const char * imagepath) {
	std::cout << "Reading image " << imagepath << std::endl;

	// Open the file
	std::ifstream file(imagepath, std::ios::binary);
	if (!file) {
		std::cout << imagepath << " could not be opened. Are you in the right directory? Don't forget to read the FAQ!" << std::endl;
		return 0;
	}

	// Read the header, i.e. the 54 first bytes
	unsigned char header[54];
	if (!file.read(reinterpret_cast<char*>(header), 54)) {
		std::cout << "Not a correct BMP file" << std::endl;
		return 0;
	}

	// A BMP files always begins with "BM"
	if (header[0] != 'B' || header[1] != 'M') {
		std::cout << "Not a correct BMP file" << std::endl;
		return 0;
	}

	// Make sure this is a 24bpp file
	if (*reinterpret_cast<int*>(&header[0x1E]) != 0 || *reinterpret_cast<int*>(&header[0x1C]) != 24) {
		std::cout << "Not a correct BMP file" << std::endl;
		return 0;
	}

	// Read the information about the image
	unsigned int dataPos = *reinterpret_cast<int*>(&header[0x0A]);
	unsigned int imageSize = *reinterpret_cast<int*>(&header[0x22]);
	unsigned int width = *reinterpret_cast<int*>(&header[0x12]);
	unsigned int height = *reinterpret_cast<int*>(&header[0x16]);
	

	// Some BMP files are misformatted, guess missing information
	if (imageSize == 0) {
		imageSize = width * height * 3; // 3 : one byte for each Red, Green and Blue component
	}
	if (dataPos == 0) {
		dataPos = 54; // The BMP header is done that way
	}

	// Create a buffer
	std::vector<unsigned char> data(imageSize);

	// Read the actual data from the file into the buffer
	if (!file.read(reinterpret_cast<char*>(data.data()), imageSize)) {
		std::cout << "Failed to read image data" << std::endl;
		return 0;
	}

	// Everything is in memory now, the file can be closed.
	file.close();

	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);
	glActiveTexture(GL_TEXTURE0);
	// "Bind" the newly created texture: all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);
	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data.data());
	// Poor filtering, or ...
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 

	// ... nice trilinear filtering ...
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	// ... which requires mipmaps. Generate them automatically.
	glGenerateMipmap(GL_TEXTURE_2D);
	// std::cout << glGetError() << std::endl;
	// Return the ID of the texture we just created
	return textureID;
}

bool loadObj(const char * path, std::vector < Vec3 > & out_vertices, std::vector < Vec3 > &out_normals, std::vector <Material>& out_materials, std::vector < Vec3 > &out_colors){
	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	std::vector< Vec3 > temp_vertices;
	std::ifstream file;
	file.open(path);

	Vec3 color3 = Vec3(0.634f, 0.457f, 0.789f);
	Vec3 color2 = Vec3(0.467f, 0.71f, 0.851f);
	Vec3 color1 = Vec3(0.843f, 0.918f, 0.953f);
	std::vector<Vec3> colors = {color1, color2, color3};
	if(!file.is_open()){
		printf("Impossible to open the file !\n");
		return false;
	}
	while(file){
		std::string line;
		std::getline(file, line);
		std::vector<std::string> tokens = split(line, ' ');
		if ( tokens[0] == "v"){
			Vec3 vertex;
			vertex.x = std::stof(tokens[1]);
			vertex.y = std::stof(tokens[2]);
			vertex.z = std::stof(tokens[3]);			
			temp_vertices.push_back(vertex);
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
			Vec3 v0 = temp_vertices[vertexIndices[i] - 1];
			Vec3 v1 = temp_vertices[vertexIndices[i + 1] - 1];
			Vec3 v2 = temp_vertices[vertexIndices[i + 2] - 1];
			Vec3 faceNormal = crossProduct(v1 - v0, v2 - v0);
			for (int j = 0; j < 3; j++) {
				out_normals.push_back(faceNormal);
			}
		}
		//We go through each Vec3 ( each v/vt/vn ) of each triangle ( each line with a “f” ) :
		// For each Vec3 of each triangle the index to the Vec3 position is vertexIndices[i] :
		for( unsigned int i=0; i<vertexIndices.size(); i++ ){
			unsigned int vertexIndex = vertexIndices[i];
			Vec3 vertex = temp_vertices[ vertexIndex-1 ];
			Vec3 color = colors[i % 3];
			out_vertices.push_back(vertex);
			out_colors.push_back(color);
		}
	}
	return false;
}
