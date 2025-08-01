#pragma once
#include <KamataEngine.h>
#include "Parrticle.h"
#include "Model2.h"
#include "BackScreen.h"

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
	KamataEngine::Vector3 position;
	uint32_t tex;
	KamataEngine::ObjectColor color_;
	KamataEngine::WorldTransform worldtransform_;
	BackScreen* backScreen = new BackScreen;

};
