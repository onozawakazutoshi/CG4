#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;

class Hp {
public:
	void Initialize(Vector2 pos);

	void Update();
	void Draw(ID3D12GraphicsCommandList* commandList);

private:
	Sprite* sprite = nullptr;
	Sprite* sprite2 = nullptr;

	Vector2 size_;
	Vector2 pos_;

};
