#pragma once
#include <KamataEngine.h>
#include <algorithm>

using namespace KamataEngine;

class Parrticle {
public:
	void Initialize(Model* model, Vector3 position, Vector3 velocity);

	void Update();

	void Draw(Camera& camera);

	bool IsFinished() { 
		return isFinished_;
	}

private:
	WorldTransform worldtransform_;
	Model* model_ = nullptr;
	ObjectColor objectColor_;
	Vector4 color_;
	Vector3 velocity_;
	bool isFinished_ = false;
	float counter_ = 0.0f;
	const float kDuration = 1.0f;

};
