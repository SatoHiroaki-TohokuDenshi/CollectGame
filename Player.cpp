#include "Player.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"

// �R���X�g���N�^
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), isJumped_(false),
	velocity_(0.0f, 0.0f, 0.0f), gravity_(0.1f)
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
	Move();
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

void Player::Move() {
	// ��
	if (Input::IsKey(DIK_A)) {
		velocity_.x -= 0.1f;
	}
	// �E
	if (Input::IsKey(DIK_D)) {
		velocity_.x += 0.1f;
	}

	// �W�����v���Ă���Ȃ�A���͂��󂯕t���Ȃ�
	if (isJumped_)	return;
	// �W�����v
	if (Input::IsKeyDown(DIK_SPACE)) {
		velocity_.y = 5.0f;
		isJumped_ = true;
	}
}