#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize() {
	modelParticle_ = Model::CreateSphere(4, 4); 
	camera_ = new Camera;
	camera_->Initialize();
	particle_ = new Parrticle();
	particle_->Initialize(modelParticle_);
}

void GameScene::Update() { 
	particle_->Update();

}

void GameScene::Draw() { 
	DirectXCommon* dxcommon = DirectXCommon::GetInstance();
	Model::PreDraw(dxcommon->GetCommandList());


	particle_->Draw(*camera_);


	Model::PostDraw();
	

}
