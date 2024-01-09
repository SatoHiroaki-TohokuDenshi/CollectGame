#include "Player.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"

// コンストラクタ
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), isJumped_(false),
	velocity_(0.0f, 0.0f, 0.0f), gravity_(0.1f)
{
}

// デストラクタ
Player::~Player()
{
}

// 初期化
void Player::Initialize() {
	// 足元に極小の当たり判定を設定
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 0.2f);
	AddCollider(collision);
}

// 更新
void Player::Update() {
	Move();
}

// 描画
void Player::Draw() {

}

// 開放
void Player::Release() {

}

//何かに当たった
void Player::OnCollision(GameObject* pTarget) {
	//当たったときの処理

}

void Player::CalcGravity() {
	velocity_.y -= gravity_;
}

void Player::Move() {
	// 左
	if (Input::IsKey(DIK_A)) {
		velocity_.x -= 0.1f;
	}
	// 右
	if (Input::IsKey(DIK_D)) {
		velocity_.x += 0.1f;
	}

	// ジャンプしているなら、入力を受け付けない
	if (isJumped_)	return;
	// ジャンプ
	if (Input::IsKeyDown(DIK_SPACE)) {
		velocity_.y = 5.0f;
		isJumped_ = true;
	}
}