#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"

// �R���X�g���N�^
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1)
{
}

// �f�X�g���N�^
Player::~Player()
{
}

// ������
void Player::Initialize() {
	// ���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Model\\TestPlayer.fbx");
	assert(hModel_ >= 0);

	// �����ɋɏ��̓����蔻���ݒ�
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.5f, 0.5f, 0.5f), 0.2f);
	AddCollider(collision);
}

// �X�V
void Player::Update() {
	Camera::SetTarget(transform_.position_);
}

// �`��
void Player::Draw() {
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

// �J��
void Player::Release() {

}

// �����ɓ�������
void Player::OnCollision(GameObject* pTarget) {

}

