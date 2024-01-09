#include "Player.h"
#include "Engine/SphereCollider.h"

// �R���X�g���N�^
Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), velocity_(0.0f, 0.0f, 0.0f), gravity_(0.1f)
{
}

// �f�X�g���N�^
Player::~Player()
{
}

// ������
void Player::Initialize() {
	// �����ɋɏ��̓����蔻���ݒ�
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.2f);
	AddCollider(collision);
}

// �X�V
void Player::Update() {

}

// �`��
void Player::Draw() {

}

// �J��
void Player::Release() {

}

//�����ɓ�������
void Player::OnCollision(GameObject* pTarget) {
	//���������Ƃ��̏���

}

void Player::CalcGravity() {
	velocity_.y -= gravity_;
}