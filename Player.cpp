#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

// �R���X�g���N�^
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), velocity_(0.0f, 0.0f, 0.0f),
	isJumped_(false), gravity_(0.01f)
{
}

// �f�X�g���N�^
Player::~Player()
{
}

// ������
void Player::Initialize() {
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Model\\TestPlayer.fbx");
	assert(hModel_ >= 0);

	// �����ɋɏ��̓����蔻���ݒ�
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.2f);
	AddCollider(collision);
}

// �X�V
void Player::Update() {
	MoveInput();
	transform_.position_ = transform_.position_ + velocity_;
}

// �`��
void Player::Draw() {
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

// �J��
void Player::Release() {

}

//�����ɓ�������
void Player::OnCollision(GameObject* pTarget) {
	//���������Ƃ��̏���

}

void Player::MoveInput() {
	if (Input::IsKey(DIK_A)) {
		velocity_.x = -0.1f;
	}
	else if (Input::IsKey(DIK_D)) {
		velocity_.x = 0.1f;
	}
	else {
		velocity_.x = 0.0f;
	}

	if (isJumped_) {
		velocity_.y -= gravity_;
		return;
	}
	if (Input::IsKey(DIK_SPACE)) {
		velocity_.y = 0.3f;
		isJumped_ = true;
	}
}
