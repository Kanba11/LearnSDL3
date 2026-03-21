#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

int main(int argc, char* argv[]) {

    // Pointer to manage the SDL
    SDL_Window *window;       
    SDL_Renderer *renderer;
    // Loop control flag (ends when true)
    bool done = false;
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);              
    
    // Create window and renderer
    if (!SDL_CreateWindowAndRenderer("Window", 640, 480, 0, &window, &renderer)) {
        SDL_Log("Error", SDL_GetError());
    return 1;
    }
    
    // Main loop - keeps running while done is false
    while (!done) {
        // Variable to store incoming events
        SDL_Event event;
        // Poll and process each event in the queue
        while (SDL_PollEvent(&event)) {
            // Detect window close
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }

            // Detect key press event
            if (event.type == SDL_EVENT_KEY_DOWN) {
                if (event.key.scancode == SDL_SCANCODE_ESCAPE) {
                    done = true;
                }
            }
        }
        
        // Set draw color
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        // Fill the screen with the current draw color
        SDL_RenderClear(renderer);
        // Swap back buffer to screen
        SDL_RenderPresent(renderer);
    }

    // Destroy SDL to free its memory   
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return 0;
}
