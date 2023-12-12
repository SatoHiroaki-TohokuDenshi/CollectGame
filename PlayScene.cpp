#include "PlayScene.h"
#include "Stage.h"
#include "Button.h"

// �R���X�g���N�^
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

// ������
void PlayScene::Initialize() {
	Instantiate<Stage>(this);
	Button* b = (Button*)Instantiate<Button>(this);
	b->LoadFile("Image\\TestButton");
	b->SetButtonPosition(50, 20);
}

// �X�V
void PlayScene::Update() {

}

// �`��
void PlayScene::Draw() {

}

// �J��
void PlayScene::Release() {

}
