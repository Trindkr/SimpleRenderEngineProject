#pragma once

#include <stack>
#include "Engine/Component.h"

namespace ExampleGame {
	class PlayerController : public MyEngine::Component {
		const float RotSpeed = 5;
		const float MovSpeed = 5;
		const float MovAmount = 20;
		glm::vec2 MovDirection = glm::vec2(0, 1);

		bool forward
			, rotateLeft
			, rotateRight
			, shoot;


	public:
		glm::vec2 position;
		float rotaiton;

		void Init() override;
		void KeyEvent(SDL_Event&) override;
		void Update(float) override;
	};
}