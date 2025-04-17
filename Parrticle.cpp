#include "Parrticle.h"

void Parrticle::Initialize(Model* model) { 
	assert(model);
	model_ = model;
	worldtransform_.Initialize();
}

void Parrticle::Update() { 
	worldtransform_.TransferMatrix();

}

void Parrticle::Draw(Camera& camera) { 
	model_->Draw(worldtransform_, camera);

}
