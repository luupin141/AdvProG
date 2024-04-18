#ifndef KeyboardHandling_h
#define KeyboardHandling_h

#include "Game.h"
#include "ECS.h"
#include "Components.h"

int direction = 0;
int dashCD  = 100;
int sprintCD = 100;

class KeyboardHandling : public Component
{
public:
    TransformComponent *trans;
    SpriteComponent *sprite;


    void init() override
    {
        trans = &entity -> getComponent<TransformComponent>();
        sprite = &entity -> getComponent<SpriteComponent>();
    }
    const Uint8* keystates = SDL_GetKeyboardState(NULL);

    void update() override {
		trans->velocity.x = 0;
		trans->velocity.y = 0;


		if (keystates[SDL_SCANCODE_UP]) {
			trans->velocity.y = -1;
			sprite->Play("Walk");
            direction = 1;
		}
		if (keystates[SDL_SCANCODE_LEFT]) {
			trans->velocity.x = -1;
			sprite->Play("Walk");
			sprite->spriteflip = SDL_FLIP_NONE;
			direction = 2;
		}
		if (keystates[SDL_SCANCODE_DOWN]) {
			trans->velocity.y = 1;
			sprite->Play("Walk");
			direction = 3;
		}
		if (keystates[SDL_SCANCODE_RIGHT]) {
			trans->velocity.x = 1;
			sprite->Play("Walk");
			sprite->spriteflip = SDL_FLIP_HORIZONTAL;
			direction = 4;
		}
		if (keystates[SDL_SCANCODE_D]&&dashCD!=0)
        {

            switch(direction)
            {
            case 1:
                trans->velocity.y=-64;
                sprite->Play("Dash");
                break;
            case 2:
                trans->velocity.x=-64;
                sprite->Play("Dash");
                break;
            case 3:
                trans->velocity.y=64;
                sprite->Play("Dash");
                break;
            case 4:
                trans->velocity.x=64;
                sprite->Play("Dash");
                break;
            }
            dashCD -=20;

        }
        if (Game::event.type==SDL_KEYDOWN&&keystates[SDL_SCANCODE_S]&&sprintCD!=0)
        {
            trans->pace=3;
            sprintCD --;
        }
		if(Game::event.type == SDL_KEYUP){
                sprite ->Play("Idle");
                trans->pace=2;
		}
	}
};

#endif // Keyboardhandling_h
