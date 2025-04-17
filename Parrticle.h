#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;

class Parrticle {
public:
	void Initialize(Model*model,Vector3 position);

	void Update();

	void Draw(Camera& camera);

private:
	WorldTransform worldtransform_;
	Model* model_ = nullptr;
	ObjectColor objectColor_;
	Vector4 color_;

};
