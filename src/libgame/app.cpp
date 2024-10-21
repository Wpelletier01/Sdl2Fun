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
    this->entityManager.addMoveSpeedComponent(player,10.0);

    // for limiting frame rate to 60fps
    const int fps = 60;
    const int frameDelay = 1000 / fps;
    Uint32 frameStart;
    int frameTime;

    World wrld("../assets/world/testing/test.json",this->renderer.getSDLRenderer());


    while (this->running) {

        frameStart = SDL_GetTicks();

        this->handleEvent(&event);
        this->update(player);
        this->render(&wrld);

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay-frameTime);
        }

    }

}

void App::update(entt::entity player)
{   
    entt::registry* pregistry = this->entityManager.getRegistry();
    this->inputSys.update(pregistry);
    this->moveSys.update(pregistry);

    this->movePlayer(player,pregistry);

    this->inputSys.clear();
}


void App::render(World* world)
{

    this->renderer.clear();
    // render stuff;
    this->renderer.renderAll(world);
    
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

void App::movePlayer(entt::entity player, entt::registry* registry)
{

    auto& rect = registry->get<Rect>(player);
    auto& speed = registry->get<MoveSpeed>(player);
    

    const Uint8* keyboardState = SDL_GetKeyboardState(NULL);

    if (keyboardState[SDL_SCANCODE_A]) {
        rect.val.x -= speed.s;
        SDL_Log("move left");
    } 
    
    
    if (keyboardState[SDL_SCANCODE_W]) {
        rect.val.y -= speed.s;
        SDL_Log("move up");
    }
    
    if (keyboardState[SDL_SCANCODE_D]) {
        rect.val.x += speed.s;
        SDL_Log("move right");
    }
    
    if (keyboardState[SDL_SCANCODE_S]) {
        rect.val.y += speed.s;
        SDL_Log("move down");
    }

}