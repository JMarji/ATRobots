#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>

#define SC_WIDTH 1240
#define SC_HEIGHT 1024
#define WINDOW_NAME "Robotic Codes"

int initialize();
void drawMenu();
bool quit_status = false;
SDL_Window* win = NULL;
SDL_Renderer* ren = NULL;
TTF_Font *font = NULL;
void dGrayRect(int x1, int y1, int x2, int y2);
void dButton(int x1, int y1, int x2, int y2, char *label);
void title();
void dBRect(int x1, int y1, int x2, int y2);

int main(int argc, char* argv[]){
  if (!initialize())
    fprintf(stderr, "Couldn't initialize SDL2\n");
  SDL_Event event;
  while (!quit_status){ // While loop for running
    while (SDL_PollEvent(&event) != 0){ // handle input
      if (event.type == SDL_QUIT)
        quit_status = true;
    }
    // Prepare things
    SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(ren);
    drawMenu();
    // Show things
    SDL_RenderPresent(ren);
  }
  //Time to quit
  TTF_CloseFont(font);
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  ren = NULL;
  win = NULL;
  SDL_Quit();
  return 0;
}

int initialize(){
  int result = 0;
  if (TTF_Init() == -1){
    fprintf(stderr, "%s\n", "Couldn't initialize TTF font system.");
    exit(-1);
  }
  result += SDL_Init(SDL_INIT_VIDEO);
  result += SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
  win = SDL_CreateWindow(WINDOW_NAME,
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      SC_WIDTH,
      SC_HEIGHT,
      SDL_WINDOW_SHOWN);
  ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  if (win == NULL || ren == NULL){
    fprintf(stderr, "%s\n", "Couldn't make windows with renderer");
    exit(-1);
  }
  SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0x00);
  return result;
}

void drawMenu(){
  char* labels[] = {(char*)"X", (char*)"R1", (char*)"R2", (char*)"R3", (char*)"R4", (char*)"R5", (char*)"R6"};
  dGrayRect(0, 0, 10, 1024);                // Left Border
  dGrayRect(0, 0, 1240, 10);                // Top Border
  dGrayRect(1230, 0, 1240, 1024);           // Right Border
  dGrayRect(0, 1014, 1240, 1024);           // Bottom Border
  title();
  dGrayRect(10, 90, 1230, 512);             // file selection background
  dButton(10, 158, 50, 50, labels[0]);      // R1 Close
  dButton(10, 276, 50, 50, labels[0]);      // R2 Close
  dButton(10, 394, 50, 50, labels[0]);      // R3 Close
  dButton(70, 158, 50, 50, labels[1]);      // R1 Open
  dButton(70, 276, 50, 50, labels[2]);      // R2 Open
  dButton(70, 394, 50, 50, labels[3]);      // R3 Open
  dBRect(123, 158, 407, 50);                // File Box R1
  dBRect(123, 276, 407, 50);                // File Box R2
  dBRect(123, 394, 407, 50);                // File Box R3
  dButton(630, 158, 50, 50, labels[0]);      // R4 Close
  dButton(630, 276, 50, 50, labels[0]);      // R5 Close
  dButton(630, 394, 50, 50, labels[0]);      // R6 Close
  dButton(690, 158, 50, 50, labels[4]);      // R4 Open
  dButton(690, 276, 50, 50, labels[5]);      // R5 Open
  dButton(690, 394, 50, 50, labels[6]);      // R6 Open
  dBRect(743, 158, 407, 50);                // File Box R4
  dBRect(743, 276, 407, 50);                // File Box R5
  dBRect(743, 394, 407, 50);                // File Box R6
}

void dGrayRect(int x1, int y1, int x2, int y2){
  /* OLD: used native SDL rectangle
  SDL_Rect bar = { x1, y1, x2, y2};
  SDL_SetRenderDrawColor(ren, 0xAA, 0xAA, 0xAA, 0xFF);
  SDL_RenderFillRect(ren, &bar);
  */
  // Now uses SDL2_gfx
  boxRGBA(ren, x1, y1, x2, y2, 0x96, 0x96, 0x96, 0xFF);
}

void dBRect(int x1, int y1, int x2, int y2){
  x2 += x1;
  y2 += y1;
  boxRGBA(ren, x1, y1, x2, y2, 0x00, 0x00, 0x00, 0xFF);
}

void title(){
  if (font == NULL){
    font = TTF_OpenFont("DS-DIGI.TTF", 60);
  }
  SDL_Color color={255,255,255};
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "Robotic Codes", color);
  SDL_Texture* Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
  SDL_Rect Message_rect; //create a rect
  Message_rect.x = 10;  //controls the rect's x coordinate
  Message_rect.y = 10; // controls the rect's y coordinte
  Message_rect.w = 780; // controls the width of the rect
  Message_rect.h = 60; // controls the height of the rect
  SDL_RenderCopy(ren, Message, NULL, &Message_rect);
  SDL_FreeSurface(surfaceMessage);
  font=NULL;
}

void dButton(int x1, int y1, int x2, int y2, char *label){  // can only take in a single line of text
  x2 += x1; //convert offsets to absolute positions
  y2 += y1;
  if (font == NULL){
    font = TTF_OpenFont("DS-DIGI.TTF", (y2-y1-6));
  }
  boxRGBA(ren, x1+1, y1+1, x2-1, y2-1, 0xFF, 0xFF, 0xFF, 0xFF); // draw button
  boxRGBA(ren, x1+3, y1+3, x2-3, y2-3, 0xAA, 0xAA, 0xAA, 0xFF);
  SDL_Color color={0,0,0};
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, label, color);
  SDL_Texture* Message = SDL_CreateTextureFromSurface(ren, surfaceMessage);
  SDL_Rect Message_rect; //create a rect
  Message_rect.x = x1+5;  //controls the rect's x coordinate
  Message_rect.y = y1+3; // controls the rect's y coordinte
  Message_rect.w = (y2-y1-6); // controls the width of the rect
  Message_rect.h = (y2-y1-6); // controls the height of the rect
  SDL_RenderCopy(ren, Message, NULL, &Message_rect);
  SDL_FreeSurface(surfaceMessage);
}
