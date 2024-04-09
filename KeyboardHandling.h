#ifndef KeyboardHandling_h
#define KeyboardHandling_h

#include "Game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardHandling : public Component
{
public:
    TransformComponent *trans;

    void init() override
    {
        trans = &entity -> getComponent<TransformComponent>();
    }
    const Uint8* keystates = SDL_GetKeyboardState(NULL);

    void update() override {
		trans->velocity.x = 0;
		trans->velocity.y = 0;

		if (keystates[SDL_SCANCODE_UP]) {
			trans->velocity.y = -1;
		}
		if (keystates[SDL_SCANCODE_LEFT]) {
			trans->velocity.x = -1;
		}
		if (keystates[SDL_SCANCODE_DOWN]) {
			trans->velocity.y = 1;
		}
		if (keystates[SDL_SCANCODE_RIGHT]) {
			trans->velocity.x = 1;
		}
	}
};

#endif // Keyboardhandling_h
