#include "app.h"


int App::init(int width, int height, const char* title) {
   
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Couldn't init sdl");
        return 1;                
    }

    this->window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );
            

    if (this->window == NULL) {
        printf("Couldn't create a window. Error: %s",SDL_GetError());
        return 1;
    }


    // Initialise renderer
    if (this->renderer.init(this->window,this->entityManager.getRegistry()) > 0) {
        return 1;
    }

    // SDL_image and asset initiatialisation
    int imgFlag = IMG_INIT_JPG | IMG_INIT_PNG;

    if (IMG_Init(imgFlag) == 0) {
        printf("Couldn't initialise SDL_Image");
        return 1;
    }


    return 0;
}

App::~App() {

    SDL_DestroyWindow( this->window );
    this->window = NULL;
    SDL_Quit();

    printf("You close the app\n");
}



void App::run() {
    
    SDL_Event event;
    this->running = true;

    entt::entity player = this->entityManager.createEntity();
    this->entityManager.addRectComponent(player,100,100,128,128);
    this->entityManager.addTextureComponent(player,"player",0,0,128,128);
    this->entityManager.addMoveSpeedComponent(player,3.0);
    this->entityManager.addInputComponent(player);

    // for limiting frame rate to 60fps
    const int fps = 60;
    const int frameDelay = 1000 / fps;
    Uint32 frameStart;
    int frameTime;


    while (this->running) {

        frameStart = SDL_GetTicks();

        this->handleEvent(&event);
        this->update(player);
        this->render();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay-frameTime);
        }

    }

}

void App::update(entt::entity player)
{
    this->inputSys.clear();
}


void App::render()
{

    this->renderer.clear();
    // render stuff;
    this->renderer.renderAll();
    
    this->renderer.present();
}


void App::handleEvent(SDL_Event* event) 
{

    while( SDL_PollEvent( event ) ) { 
        switch (event->type) {
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                this->inputSys.handleKeyInput(event->key);
                break; 
            case SDL_QUIT:
                this->running = false;
                break;
            default:
                break;
        }
    } 

}
