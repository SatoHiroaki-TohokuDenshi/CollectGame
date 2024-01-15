#pragma once
#include "Engine/GameObject.h"

// Player���Ǘ�����N���X
class Player : public GameObject {
private:
	int hModel_;		//���f���ԍ�

	// �ړ��Ɋ֌W������
	XMFLOAT3 velocity_;	// �ړ���
	float gravity_;		// �d�͉����x
	bool isJumped_;		// �W�����v������

	void MoveInput();	// �ړ�����

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

	// �����ɓ�������
	// �����FpTarget ������������
	void OnCollision(GameObject* pTarget) override;
};