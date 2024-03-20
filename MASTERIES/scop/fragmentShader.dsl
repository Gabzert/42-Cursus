#version 300 es
precision mediump float;

out vec3 color;
uniform vec3 colors[3];

void main(){
	int group = int(gl_FragCoord.x + gl_FragCoord.y) % 10000;
	int face = group % 3;
	color = colors[face];
}