#include "Parrticle.h"

using namespace MathUtility;

void Parrticle::Initialize(Model* model) { 
	assert(model);
	model_ = model;
	worldtransform_.Initialize();

	objectColor_.Initialize();
	color_ = {1, 1, 0, 1};

}

void Parrticle::Update() { 
	worldtransform_.translation_ += {0.0f, 0.1f, 0.0f};
	//worldtransform_.TransferMatrix();

	worldtransform_.UpdateMatrix();

	objectColor_.SetColor(color_);
}

void Parrticle::Draw(Camera& camera) { 
	model_->Draw(worldtransform_, camera,&objectColor_);

}
