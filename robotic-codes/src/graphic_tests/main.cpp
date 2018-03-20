#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

using namespace glm;
using namespace std;

bool running = 1;
void firstTriangle(GLFWwindow* w);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
  printf("Found: %d\n", key);
  if (action == GLFW_PRESS){
    if (key == GLFW_KEY_ESCAPE ){
      glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
  }
}

static void err_callback(int errnum, const char* desc){
  fprintf(stderr, "OOPS: %s\n", desc);
}

int main(int argc, char* argv[]){
  if (!glfwInit()){
    fprintf(stderr, "Failed to start GLFW");
    return -1;
  }
  glfwWindowHint(GLFW_SAMPLES, 16);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwSetErrorCallback(err_callback);
  GLFWwindow* win;
  win = glfwCreateWindow( 1500, 1000, "W I N D O W", NULL, NULL);
  if (win == NULL){
    fprintf(stderr, "Failed top open GLFW window");
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(win);
  glfwSetKeyCallback(win, key_callback);
  //glfwSetInputMode(win, GLFW_STICKY_KEYS, GL_TRUE);
  while (!glfwWindowShouldClose(win)){
    // `draw` equivelent in processing
    printf("LOOP\n");
    glfwWaitEvents();
  }
  return 0;
}
