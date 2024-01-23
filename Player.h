#pragma once
#include "Engine/GameObject.h"

// Player���Ǘ�����N���X
class Player : public GameObject {
private:
	enum class ACTION_STATE {
		IDLE,		// 0:���얳���A�ҋ@
		WALK,		// 1:����
		DASH,		// 2:����
		AIR,		// 3:�󒆁i�W�����v�A�������j
		LANDING,	// 4:���n
		MAX			// 5:�ԕ�
	} state_;

	int hModel_;		//���f���ԍ�

	void Move();			// �ړ�����
	XMFLOAT3 velocity_;		// �ړ���
	bool isOnFloor_;		// ���̏�ɂ��邩

	//State�F��Ԃɂ�鏈��
	void UpdateIdle();
	void UpdateWalk();
	void UpdateDash();
	void UpdateAir();
	void UpdateLanding();

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