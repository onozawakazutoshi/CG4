#pragma once

#include <KamataEngine.h>

using namespace KamataEngine;

class BackScreen {
public:
	void Initialize();

	void Update();
	void Draw(ID3D12GraphicsCommandList* commandList);

private:
	Sprite* sprite = nullptr;
	Vector2 pos;
};
