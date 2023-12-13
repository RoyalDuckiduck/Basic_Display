#version 120

attribute vec3 position;

varying vec3 pos;

void main(){
  gl_Position = vec4(position, 1);

  pos = position;
}
