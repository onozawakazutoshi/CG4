#include "Hp.h"

void Hp::Initialize(Vector2 pos) {
	uint32_t tex = TextureManager::Load("white1x1.png");

	sprite = Sprite::Create(tex, /*Vector2(worldtransform_.translation_.x*10+640, worldtransform_.translation_.y*10+360)*/ pos, {1, 0, 0, 0.5f}, {0.5, 0.5});
	sprite2 = Sprite::Create(tex, /*Vector2(worldtransform_.translation_.x*10+640, worldtransform_.translation_.y*10+360)*/ pos, {0, 1, 0, 1}, {0.5, 0.5});
	
	size_ = {80, 20};
	pos_ = pos;

	sprite->SetSize(size_);
	sprite2->SetSize(size_);

}

void Hp::Draw(ID3D12GraphicsCommandList* commandList) {

	Sprite::PreDraw(commandList);

	sprite->Draw();
	sprite2->Draw();

	Sprite::PostDraw();
}

void Hp::Update() {

	if (size_.x >= 0) {
		size_.x--;
		pos_.x -= 0.5;
	} else {
		size_.x = 80;
		pos_.x += 40; 
	}

	sprite2->SetSize(size_);
	sprite2->SetPosition(pos_);

}