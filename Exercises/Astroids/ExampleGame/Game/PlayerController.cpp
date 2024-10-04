#include "PlayerController.h"
#include "Engine/MyEngine.h"

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
			parent->position += MovDirection * MovAmount * glm::sin(MovSpeed * engine->GetTime());
		}
		if (rotateLeft)
		{
			parent->rotation -= RotSpeed;
		}
		if (rotateRight)
		{
			parent->rotation += RotSpeed;
		}
		if (shoot)
		{
			// Shoot
		}

	}

	void PlayerController::KeyEvent(SDL_Event& event) {

		switch (event.key.keysym.sym) {
		case SDLK_w:
			//parent->position += MovDirection * MovAmount * glm::sin(MovSpeed * engine->GetTime());
			std::cout << "Forward pressed" << std::endl;
			forward = event.type == SDL_KEYDOWN;
			break;
		case SDLK_a:
			//parent->rotation -= RotSpeed;
			rotateLeft = event.type == SDL_KEYDOWN;
			break;
		case SDLK_d:
			//parent->rotation += RotSpeed;
			rotateRight = event.type == SDL_KEYDOWN;
			break;
		case SDLK_SPACE:
			shoot = event.type == SDL_KEYDOWN;
			break;
		}
	}

}