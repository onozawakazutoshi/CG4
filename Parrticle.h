#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;

class Parrticle {
public:
	void Initialize(Model* model, Vector3 position, Vector3 velocity);

	void Update();

	void Draw(Camera& camera);

private:
	WorldTransform worldtransform_;
	Model* model_ = nullptr;
	ObjectColor objectColor_;
	Vector4 color_;
	Vector3 velocity_;
};
