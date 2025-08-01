#include "Title.h"


void Title::Initialize() {
	uint32_t tex = TextureManager::Load("uvChecker.png");

	sprite = Sprite::Create(tex, /*Vector2(worldtransform_.translation_.x*10+640, worldtransform_.translation_.y*10+360)*/ {640, 360}, {1,1,1,1}, {0.5, 0.5});
	sprite->SetSize({1280, 720});
}

void Title::Draw(ID3D12GraphicsCommandList* commandList) { 
	
	Sprite::PreDraw(commandList);
		
	sprite->Draw();

	Sprite::PostDraw();
}

void Title::Update() {

}
