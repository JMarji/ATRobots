#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>

#define SC_WIDTH 1280
#define SC_HEIGHT 720
#define WINDOW_NAME "Robotic Codes"

int initialize();
void drawMenu();
bool quit_status = false;
SDL_Window* win = NULL;
SDL_Renderer* ren = NULL;
TTF_Font *font = NULL;
void dGrayRect(int x1, int y1, int x2, int y2);
void dButton(int x1, int y1, int x2, int y2, char *label);

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
  dGrayRect(0, 0, (SC_WIDTH*0.00806451613), SC_HEIGHT);                 // Left Border
  dGrayRect(0, 0, SC_WIDTH, (SC_HEIGHT*0.009765625));                   // Top Border
  dGrayRect(SC_WIDTH-(SC_WIDTH*0.00806451613), 0, SC_WIDTH, SC_HEIGHT); // Right Border
  dGrayRect(0, SC_HEIGHT-(SC_HEIGHT*0.009765625), SC_WIDTH, SC_HEIGHT); // Bottom Border
  dGrayRect((SC_WIDTH*0.00806451613),
      (SC_HEIGHT*0.009765625)*9,
      SC_WIDTH-(SC_WIDTH*0.00806451613),
      SC_HEIGHT/2); // file selection background
  char *labels[] = {"R1", "R2", "R3"};
  for (int i=0; i<3; i++){
    dButton((SC_WIDTH*0.0161290323), (SC_HEIGHT*0.09765625)*(i+1), 50, 50, labels[i]);
  }

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

void dButton(int x1, int y1, int x2, int y2, char *label){  // can only take in a single line of text
  x2 += x1; //convert offsets to absolute positions
  y2 += y1;
  if (font == NULL){
    font = TTF_OpenFont("Computerfont.ttf", (y2-y1-6));
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
