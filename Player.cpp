#include "Player.h"
#include "Engine/Input.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"

// コンストラクタ
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hModel_(-1), velocity_(0.0f, 0.0f, 0.0f),
	isJumped_(false), gravity_(0.01f)
{
}

// デストラクタ
Player::~Player()
{
}

// 初期化
void Player::Initialize() {
	//モデルデータのロード
	hModel_ = Model::Load("Model\\TestPlayer.fbx");
	assert(hModel_ >= 0);

	// 足元に極小の当たり判定を設定
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.2f);
	AddCollider(collision);
}

// 更新
void Player::Update() {
	MoveInput();
	transform_.position_ = transform_.position_ + velocity_;
}

// 描画
void Player::Draw() {
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

// 開放
void Player::Release() {

}

//何かに当たった
void Player::OnCollision(GameObject* pTarget) {
	//当たったときの処理

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
