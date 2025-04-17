#pragma once
#include <KamataEngine.h>
#include "Parrticle.h"

using namespace KamataEngine;

class GameScene {

public:
	GameScene() {}
	~GameScene() { 
		delete modelParticle_;
		for (Parrticle* particle : particles_) {
			delete particle;
		}
		particles_.clear();
	}

	void Initialize();

	void Update();

	void Draw();

private:
	Model* modelParticle_ = nullptr;
	Camera* camera_;
	std::list<Parrticle*> particles_;
};
