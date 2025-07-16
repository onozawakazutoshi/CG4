#include "GameScene.h"
#include <random>



std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

using namespace KamataEngine;
using namespace MathUtility;

void GameScene::Initialize() {
	Model2::StaticInitialize();
	model_ = Model2::CreateSphere(4, 4); 
	camera_ = new Camera;
	camera_->Initialize();
	
	srand((unsigned)time(NULL));
	position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};
	tex = TextureManager::Load("Line.png");
	color_->SetColor(Vector4{0, 0, 0, 1});
}

void GameScene::Update() { 
	

}

void GameScene::Draw() { 
	DirectXCommon* dxcommon = DirectXCommon::GetInstance();
	Sprite::PreDraw(dxcommon->GetCommandList());

	model_->Draw(position, camera_,color_);
	
	Sprite::PostDraw();
	

}

void GameScene::ParticleBorn() {
	for (int i = 0; i < 1; i++) {
		Parrticle* particle_ = new Parrticle();
		Vector3 position_ = position;

		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};

		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.1f;
	}
}
