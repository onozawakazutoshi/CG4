#include "Parrticle.h"

using namespace KamataEngine;
using namespace MathUtility;


void Parrticle::Initialize(Model* model, Vector3 position, Vector3 velocity,int r) { 
	assert(model);
	model_ = model;
	worldtransform_.Initialize();
	worldtransform_.translation_ = position;
	worldtransform_.scale_ = {2.0f, 2.0f, 2.0f};

	velocity_ = velocity;
	objectColor_.Initialize();
	color_ = {1, 1, 1, 1};
	r;
	uint32_t tex = TextureManager::Load("Line.png");

	sprite_ = Sprite::Create(tex, /*Vector2(worldtransform_.translation_.x*10+640, worldtransform_.translation_.y*10+360)*/ {640,360}, color_, {0.5, 0.5});
	sprite_->SetRotation(worldtransform_.translation_.x);
	sprite_->SetSize(Vector2(100, 100));
}

void Parrticle::Update() {
	
	if (isFinished_) {
		return;
	}

	counter_ += 1.0f / 60.0f;

	if (counter_ >= kDuration) {
		counter_ = kDuration;
		isFinished_ = true;
	} 
	worldtransform_.translation_ += velocity_;
	worldtransform_.TransferMatrix();

	worldtransform_.UpdateMatrix();

	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);

	sprite_->SetColor(color_);

	

}

void Parrticle::Draw(Camera& camera) { 
	camera;
	//model_->Draw(worldtransform_, camera,&objectColor_);
	sprite_->Draw();
}
