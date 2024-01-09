#pragma once
#include "Engine/GameObject.h"

// Player���Ǘ�����N���X
class Player : public GameObject {
private:
	float gravity_;			// �d�͉����x
	XMFLOAT3 velocity_;		// �ړ���
	void CalcGravity();		// �d�͂��v�Z

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