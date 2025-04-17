#include "Parrticle.h"

using namespace MathUtility;

void Parrticle::Initialize(Model* model, Vector3 position, Vector3 velocity) { 
	assert(model);
	model_ = model;
	worldtransform_.Initialize();
	worldtransform_.translation_ = position;
	worldtransform_.scale_ = {0.2f, 0.2f, 0.2f};

	velocity_ = velocity;
	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

}

void Parrticle::Update() { 
	worldtransform_.translation_ += velocity_;
	//worldtransform_.TransferMatrix();

	worldtransform_.UpdateMatrix();

	objectColor_.SetColor(color_);
}

void Parrticle::Draw(Camera& camera) { 
	model_->Draw(worldtransform_, camera,&objectColor_);

}
