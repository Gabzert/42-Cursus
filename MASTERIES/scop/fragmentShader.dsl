#version 300 es
precision mediump float;

uniform vec4 _EvenColor;
uniform vec4 _OddColor;

in vec3 worldPos;

out vec4 fragColor;

void main() {

    // Scale the position to adjust for shader input and floor the values so we have whole numbers
	vec3 adjustedWorldPos = floor(worldPos / 0.25);
    
    // Add different dimensions
   	float chessboard = adjustedWorldPos.x + adjustedWorldPos.y + adjustedWorldPos.z;

    //float chessboard = worldPos.x + worldPos.y + worldPos.z;

    // Divide it by 2 and get the fractional part, resulting in a value of 0 for even and 0.5 for odd numbers
    chessboard = fract(chessboard * 0.5);
    
    // Multiply it by 2 to make odd values white instead of grey
    chessboard *= 2.0;
    
    // Interpolate between color for even fields (0) and color for odd fields (1)
    vec4 color = mix(_EvenColor, _OddColor, chessboard);
    
    fragColor = color;
}




//out vec3 color;
//uniform vec3 colors[3];

//void main(){
//	int group = int(gl_FragCoord.x + gl_FragCoord.y) % 10000;
//	int face = group % 3;
//	color = colors[face];