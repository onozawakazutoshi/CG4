#include "Score.h"
void Score::Initialize() {
	uint32_t tex = TextureManager::Load("number.png");
	size_ = {40,80};
	for (int i = 0; i < 5; i++) {
		sprite_[i] = Sprite::Create(tex, {100 + size_.x * i, 5});
		sprite_[i]->SetSize(size_);
		sprite_[i]->SetTextureRect({0, 0}, {32,64});
	}
	
}

void Score::Draw(ID3D12GraphicsCommandList* commandList) {

	Sprite::PreDraw(commandList);

	for (int i = 0; i < 5; i++) {
		sprite_[i]->Draw();
	}

	Sprite::PostDraw();
}

void Score::Update() {
	score++;
	int nuber = score;
	
	for (int i = 0; i < 5; i++) {
		int n = 1;
		for (int j = 0; j < 5 - i; j++) {
			n *= 10;
		}
		nuber = int(nuber/n);
		sprite_[i]->SetTextureRect({32.0f*nuber, 0}, {32, 64});
		nuber = score % n;
	}
}
