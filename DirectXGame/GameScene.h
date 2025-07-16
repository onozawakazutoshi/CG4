#pragma once
#include <KamataEngine.h>
#include "Parrticle.h"
#include "Model2.h"

class GameScene {

public:
	GameScene() {}
	~GameScene() { 
		delete model_;
		
		model_->StaticFinalize();
		
		
	}

	void Initialize();

	void Update();

	void Draw();

	void ParticleBorn();

private:
	KamataEngine::Model2* model_ = nullptr;
	KamataEngine::Camera* camera_;
	KamataEngine::Vector3 position = {0, 0, 0};
	uint32_t tex;
	KamataEngine::ObjectColor color_;
	KamataEngine::WorldTransform worldtransform_;
};
