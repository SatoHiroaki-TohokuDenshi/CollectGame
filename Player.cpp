#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
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
	// ���f���f�[�^�̃��[�h
	hModel_ = Model::Load("Model\\TestPlayer.fbx");
	assert(hModel_ >= 0);

	// �����ɋɏ��̓����蔻���ݒ�
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0.5f, 0.5f, 0.5f), 0.2f);
	AddCollider(collision);
}

// �X�V
void Player::Update() {
	// �f�o�b�O�p���Z�b�g�R�[�h
	if (Input::IsKeyDown(DIK_R)) {
		transform_.position_ = { 0.0f, 0.0f, 0.0f };
		velocity_ = { 0.0f, 0.0f, 0.0f };
		isJumped_ = false;
		return;
	}


	MoveInput();
	transform_.position_ = transform_.position_ + velocity_;

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
	//�X�e�[�W
	if (pTarget->GetObjectName() == "Stage") {
		isJumped_ = false;
		velocity_.y = 0.0f;
	}
}

void Player::MoveInput() {
	velocity_.x = 0.0f;
	velocity_.z = 0.0f;

	// �O��ړ�
	if (Input::IsKey(DIK_S)) {	// ��
		velocity_.z += -0.1f;
	}
	if (Input::IsKey(DIK_W)) {	// �E
		velocity_.z += 0.1f;
	}

	// ���E�ړ�
	if (Input::IsKey(DIK_A)) {	// ��
		velocity_.x += -0.1f;
	}
	if (Input::IsKey(DIK_D)) {	// �E
		velocity_.x += 0.1f;
	}

	// �W�����v���Ă��痎���������ďI���
	if (isJumped_) {
		velocity_.y -= gravity_;
		return;
	}
	if (Input::IsKey(DIK_SPACE)) {
		velocity_.y = 0.25f;
		isJumped_ = true;
	}
}
