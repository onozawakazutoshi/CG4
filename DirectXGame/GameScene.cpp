#include "GameScene.h"
#include <random>



std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

using namespace KamataEngine;
using namespace MathUtility;

void GameScene::Initialize() {
	model_->StaticInitialize();
	model_ = Model2::Create(); 
	
	camera_ = new Camera;
	camera_->Initialize();
	
	srand((unsigned)time(NULL));
	position = {100.0f,0.0f, 0};
	tex = TextureManager::Load("uvChecker.png");
	color_.Initialize();
	color_.SetColor(Vector4{1, 1, 1, 1});
	worldtransform_.Initialize();
	worldtransform_.translation_ = position;
	worldtransform_.scale_ = {10.0f, 10.0f, 1.0f};
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void GameScene::Update() { 
	worldtransform_.translation_ = position;
	worldtransform_.scale_ = {10.0f, 10.0f, 1.0f};


}

void GameScene::Draw() { 
	DirectXCommon* dxcommon = DirectXCommon::GetInstance();
	Model2::PreDraw(dxcommon->GetCommandList());

	model_->Draw(worldtransform_, *camera_,tex,&color_);
	
	Model2::PostDraw();
	
	

}

//void GameScene::ParticleBorn() {
//	for (int i = 0; i < 1; i++) {
//		Parrticle* particle_ = new Parrticle();
//		Vector3 position_ = position;
//
//		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};
//
//		Normalize(velocity);
//		velocity *= distribution(randomEngine);
//		velocity *= 0.1f;
//	}
//}
