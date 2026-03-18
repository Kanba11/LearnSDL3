#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int argc, char* argv[]) {

    SDL_Window *window;       
    SDL_Renderer *renderer;
    bool done = false;
    SDL_Init(SDL_INIT_VIDEO);              
    
    if (!SDL_CreateWindowAndRenderer("Window", 640, 480, 0, &window, &renderer)) {
        SDL_Log("Error", SDL_GetError());
    return 1;
    }

    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}
