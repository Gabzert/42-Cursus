#version 300 es
precision mediump float;

in vec3 vertexColor;

out vec4 fragColor;

void main() {
    fragColor = vec4(vertexColor, 1.0); // Set fragment color to vertex color
}




// // Material properties
// struct Material {
//     vec3 ambientColor;
//     vec3 diffuseColor;
//     vec3 specularColor;
//     float shininess;
// };

// // Uniforms
// uniform Material material;
// uniform vec3 cameraPos;

// // Input from vertex shader
// in vec3 worldPos;
// in vec3 Normal_cameraspace;
// in vec3 EyeDirection_cameraspace;
// in vec3 LightDirection_cameraspace;

// // Output color
// out vec3 finalColor;

// void main() {

// 	vec3 LightColor = vec3(1,1,1);
// 	float LightPower = 50.0f;
// 	vec3 lightPos = vec3(4.0,4.0,4.0);


// 	// Distance to the light
// 	float distance = length( lightPos - worldPos );

// 	// Normal of the computed fragment, in camera space
// 	vec3 n = normalize( Normal_cameraspace );
// 	// Direction of the light (from the fragment to the light)
// 	vec3 l = normalize( LightDirection_cameraspace );
// 	// Cosine of the angle between the normal and the light direction, 
// 	// clamped above 0
// 	//  - light is at the vertical of the triangle -> 1
// 	//  - light is perpendicular to the triangle -> 0
// 	//  - light is behind the triangle -> 0
// 	float cosTheta = clamp( dot( n,l ), 0.0, 1.0 );
	
// 	// Eye vector (towards the camera)
// 	vec3 E = normalize(EyeDirection_cameraspace);
// 	// Direction in which the triangle reflects the light
// 	vec3 R = reflect(-l,n);
// 	// Cosine of the angle between the Eye vector and the Reflect vector,
// 	// clamped to 0
// 	//  - Looking into the reflection -> 1
// 	//  - Looking elsewhere -> < 1
// 	float cosAlpha = clamp( dot( E,R ), 0.0, 1.0 );
	
// 	finalColor = material.ambientColor +
// 		material.diffuseColor * LightColor * LightPower * cosTheta / (distance*distance) +
// 		material.specularColor * LightColor * LightPower * pow(cosAlpha,5.0) / (distance*distance);

//     // // Calculate ambient lighting
//     // vec3 ambient = material.ambientColor;

//     // // Calculate diffuse lighting (Lambertian reflection)
//     // vec3 lightDir = normalize(vec3(4.0, 4.0, 4.0)); // Example light direction
//     // float diffuseIntensity = max(dot(normalize(Normal), lightDir), 0.0);
//     // vec3 diffuse = material.diffuseColor * diffuseIntensity;

//     // // Calculate specular lighting (Phong reflection)
//     // vec3 viewDir = normalize(cameraPos - worldPos);
//     // vec3 reflectDir = reflect(-lightDir, Normal);
//     // float specIntensity = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
//     // vec3 specular = material.specularColor * specIntensity;

//     // // Final color calculation
//     // // finalColor = ambient + (diffuse * LightColor * LightPower) + (specular * LightColor * LightPower);


// }


// uniform vec4 _EvenColor;
// uniform vec4 _OddColor;

// in vec3 worldPos;

// out vec4 fragColor;

// void main() {

//     // Scale the position to adjust for shader input and floor the values so we have whole numbers
// 	vec3 adjustedWorldPos = floor(worldPos / 0.25);
    
//     // Add different dimensions
//    	float chessboard = adjustedWorldPos.x + adjustedWorldPos.y + adjustedWorldPos.z;

//     //float chessboard = worldPos.x + worldPos.y + worldPos.z;

//     // Divide it by 2 and get the fractional part, resulting in a value of 0 for even and 0.5 for odd numbers
//     chessboard = fract(chessboard * 0.5);
    
//     // Multiply it by 2 to make odd values white instead of grey
//     chessboard *= 2.0;
    
//     // Interpolate between color for even fields (0) and color for odd fields (1)
//     vec4 color = mix(_EvenColor, _OddColor, chessboard);
    
//     fragColor = color;
// }
