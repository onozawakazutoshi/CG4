#pragma once

#include <KamataEngine.h>

using namespace KamataEngine;

class Score {
public:
	void Initialize();

	void Update();
	void Draw(ID3D12GraphicsCommandList* commandList);

private:
	Sprite* sprite_[5] = {};

	Vector2 size_;

	int score = 0;
};
