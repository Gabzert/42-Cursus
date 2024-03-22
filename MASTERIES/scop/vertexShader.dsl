#version 300 es

layout(location = 0) in vec3 vertexPosition_modelspace;

uniform mat4 MVP;

out vec3 worldPos;

void main(){
	gl_Position =  MVP * vec4(vertexPosition_modelspace,1);

	// Calculate the position of the vertex in the world
	worldPos = (mat4(1.0f) * vec4(vertexPosition_modelspace, 1)).xyz;
}