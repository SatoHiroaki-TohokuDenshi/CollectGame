#pragma once
#include "Engine/GameObject.h"

// Player���Ǘ�����N���X
class Player : public GameObject {
private:
	XMFLOAT3 velocity_;		// �ړ���
	bool isJumped_;			// �W�����v������

	// �ړ�����
	void Move();

	// �d�͉����x
	float gravity_;
	// �d�͂��v�Z
	void CalcGravity();

public:
	// �R���X�g���N�^
	Player(GameObject* parent);

	// �f�X�g���N�^
	~Player();

	// ������
	void Initialize() override;

	// �X�V
	void Update() override;

	// �`��
	void Draw() override;

	// �J��
	void Release() override;

	//�����ɓ�������
	//�����FpTarget ������������
	void OnCollision(GameObject* pTarget) override;
};