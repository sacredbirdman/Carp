#version 140
#extension GL_ARB_explicit_uniform_location : enable
#extension GL_ARB_explicit_attrib_location : enable

layout(location = 0)in vec2 vert;
layout(location = 1)uniform mat4 proj;
layout(location = 2)uniform mat4 rot;

void main()
{
  vec4 pos = vec4(vert, 0.9, 1.0);
  gl_Position = proj*rot*pos;
}
