#version 300 es

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexColors; 

uniform mat4 MVP;

// out vec3 worldPos;
out vec3  vertexColor;

void main(){
	gl_Position =  MVP * vec4(vertexPosition_modelspace,1);

	vertexColor = vertexColors;
	// Calculate the position of the vertex in the world
	// worldPos = (mat4(1.0f) * vec4(vertexPosition_modelspace, 1)).xyz;
}



/*
uniform mat4 MVP;
uniform mat4 M;
uniform mat4 V;

out vec3 worldPos;
out vec3 Normal_cameraspace;
out vec3 EyeDirection_cameraspace;
out vec3 LightDirection_cameraspace;

void main(){
	gl_Position =  MVP * vec4(vertexPosition_modelspace,1);

	// Calculate the position of the vertex in the world
	worldPos = (M * vec4(vertexPosition_modelspace, 1)).xyz;
	vec3 lightPos = vec3(4.0,4.0,4.0);

	// Vector that goes from the vertex to the camera, in camera space.
	// In camera space, the camera is at the origin (0,0,0).
	vec3 vertexPosition_cameraspace = ( V * M * vec4(vertexPosition_modelspace,1)).xyz;
	EyeDirection_cameraspace = vec3(0,0,0) - vertexPosition_cameraspace;

	// Vector that goes from the vertex to the light, in camera space. M is ommited because it's identity.
	vec3 LightPosition_cameraspace = ( V * vec4(lightPos,1)).xyz;
	LightDirection_cameraspace = LightPosition_cameraspace + EyeDirection_cameraspace;
	
	// Normal of the the vertex, in camera space
	Normal_cameraspace = ( V * M * vec4(vertexNormal,0)).xyz;
}
*/