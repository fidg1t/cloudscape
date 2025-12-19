#version 460 core

in vec4 worldPosition;
in vec4 worldNormal;

uniform vec3 lightPos;
uniform vec3 eyePos;

out vec4 fragColor;

void main()
{
  vec3 diffuse_coefficient = vec3(0.0, 0.8, 0.4);
  vec3 ambient_color = vec3(0.3, 0.3, 0.3);
  vec3 light_color = vec3(1.0, 1.0, 1.0);

    // Declarations
  vec3 L = normalize(lightPos - vec3(worldPosition));
  vec3 m = normalize(vec3(worldNormal));
  float ML = max(0, dot(m, L));
  vec3 V = normalize(eyePos - vec3(worldPosition));
  vec3 RL = normalize(2 * ML * m - L);

  // Ambient Calculation
  vec3 color_ambient = diffuse_coefficient * ambient_color;

  // Diffuse Calculation
  vec3 color_diffuse = diffuse_coefficient * ML * light_color;

  // Specular Calculation
  //vec3 color_specular = specular_coefficient * pow(max(0, dot(vec3(RL), vec3(V))), specular_exponent) * light_color * ML;
  
  fragColor = vec4(color_ambient + color_diffuse, 1);
}