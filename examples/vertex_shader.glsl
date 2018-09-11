#version 120

attribute vec2 vert;
uniform mat4 proj;
uniform mat4 rot;

void main()
{
  vec4 pos = vec4(vert, 0.9, 1.0);
  gl_Position = proj*rot*pos;
}
