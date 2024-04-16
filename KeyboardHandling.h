#ifndef KeyboardHandling_h
#define KeyboardHandling_h

#include "Game.h"
#include "ECS.h"
#include "Components.h"


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

		}
		if (keystates[SDL_SCANCODE_LEFT]) {
			trans->velocity.x = -1;
			sprite->Play("Walk");
			sprite->spriteflip = SDL_FLIP_HORIZONTAL;
		}
		if (keystates[SDL_SCANCODE_DOWN]) {
			trans->velocity.y = 1;
			sprite->Play("Walk");
		}
		if (keystates[SDL_SCANCODE_RIGHT]) {
			trans->velocity.x = 1;
			sprite->Play("Walk");
			sprite->spriteflip = SDL_FLIP_NONE;
		}

		if(Game::event.type == SDL_KEYUP) sprite ->Play("Idle");
	}
};

#endif // Keyboardhandling_h
