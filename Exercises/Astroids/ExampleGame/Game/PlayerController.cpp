#include "PlayerController.h"
#include "Engine/MyEngine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace ExampleGame {

	void PlayerController::Init() {
		MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
		MyEngine::GameObject* parent = GetGameObject();
		parent->position = engine->GetScreenSize() / 2.f;
	}

    void PlayerController::Update(float deltaTime)
    {
        MyEngine::Engine* engine = MyEngine::Engine::GetInstance();
        MyEngine::GameObject* parent = GetGameObject();

        if (forward)
        {
            parent->position += MovDirection * MovAmount * deltaTime;
        }
        if (rotateLeft)
        {
            parent->rotation += RotSpeed;

			float x = glm::cos(glm::radians(parent->rotation));
			float y = glm::sin(glm::radians(parent->rotation));
			MovDirection = glm::vec2(x, y);
            
        }
        if (rotateRight)
        {
            parent->rotation -= RotSpeed;

			float x = glm::cos(glm::radians(parent->rotation));
			float y = glm::sin(glm::radians(parent->rotation));
			MovDirection = glm::vec2(x, y);
        }
        if (shoot)
        {
            // Shoot
        }
    }

	void PlayerController::KeyEvent(SDL_Event& event) {

		switch (event.key.keysym.sym) {
		case SDLK_w:
			std::cout << " -> x: " << MovDirection.x << " -> y: " << MovDirection.y << std::endl;
			forward = event.type == SDL_KEYDOWN;
			break;
		case SDLK_a:

			std::cout << " -> x: " << MovDirection.x << " -> y: " << MovDirection.y << std::endl;

			rotateLeft = event.type == SDL_KEYDOWN;
			break;
		case SDLK_d:
			std::cout << " -> x: " << MovDirection.x << " -> y: " << MovDirection.y << std::endl;
			rotateRight = event.type == SDL_KEYDOWN;
			break;
		case SDLK_SPACE:
			shoot = event.type == SDL_KEYDOWN;
			break;
		}
	}

}