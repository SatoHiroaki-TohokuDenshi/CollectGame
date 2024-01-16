#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/SphereCollider.h"

namespace {
	const float GRAVITY = 0.01f;
}

// �R���X�g���N�^
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), velocity_{},
	isOnFloor_(true)
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
	SphereCollider* collision = new SphereCollider(XMFLOAT3(1.0f, 0.5f, 0.5f), 0.1f);
	AddCollider(collision);
}

// �X�V
void Player::Update() {
	if (Input::IsKeyDown(DIK_R) || transform_.position_.y <= -100.0f) {
		transform_.position_ = { 0.0f, 0.0f, 0.0f };
		velocity_ = { 0.0f, 0.0f, 0.0f };
		isOnFloor_ = true;
		return;
	}

	isOnFloor_ = false;
	Collision(FindObject("Stage"));

	Move();
	transform_.position_ = transform_.position_ + velocity_;

	//Camera::SetPosition({ transform_.position_.x, transform_.position_.y, transform_.position_.z - 5.0f });
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
	if (pTarget->GetObjectName() == "Stage") {
		if (velocity_.y <= 0.0f) {
			velocity_.y = 0.0f;
			isOnFloor_ = true;
		}
	}
}

void Player::Move() {
	// ���Z�b�g
	velocity_.x = 0.0f;
	velocity_.z = 0.0f;

	// ���E�ړ�
	if (Input::IsKey(DIK_D)) {
		velocity_.x += 0.1f;
	}
	if (Input::IsKey(DIK_A)) {
		velocity_.x -= 0.1f;
	}

	// �O��ړ�
	if (Input::IsKey(DIK_W)) {
		velocity_.z += 0.1f;
	}
	if (Input::IsKey(DIK_S)) {
		velocity_.z -= 0.1f;
	}

	if (!isOnFloor_) {
		velocity_.y -= GRAVITY;
		return;
	}

	// �W�����v
	if (Input::IsKeyDown(DIK_SPACE)) {
		velocity_.y += 0.2f;
	}
}
