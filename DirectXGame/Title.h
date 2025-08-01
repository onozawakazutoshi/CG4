#pragma once
#include <KamataEngine.h>

using namespace KamataEngine;


class Title {

public:
	void Initialize();

	void Update();
	void Draw(ID3D12GraphicsCommandList* commandList);

private:
	Sprite* sprite = nullptr;

};
