#pragma once
#include <KamataEngine.h>
#include "Parrticle.h"

using namespace KamataEngine;

class GameScene {

public:
	GameScene() {}
	~GameScene() { 
		delete modelParticle_;
		delete particle_;
	}

	void Initialize();

	void Update();

	void Draw();

private:
	Model* modelParticle_ = nullptr;
	Camera* camera_;
	Parrticle* particle_ = nullptr;
};
