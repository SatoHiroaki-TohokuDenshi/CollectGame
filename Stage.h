#pragma once
#include "Engine/GameObject.h"
#include <vector>

// �}�b�v�̃^�C�v
enum MAP_TYPE {
	T_PLAYER = -1,	// �v���C���[�����ʒu
	T_NONE = 0,		// �����Ȃ����
	T_FLOOR,		// ���ʂ̏�
	T_MAX,			// �Ǘ��p�ԕ�
};

// Stage���Ǘ�����N���X
class Stage : public GameObject {
private:
	std::vector<std::vector<int>> stage_;
	int hModel_;    //���f���ԍ�

public:
	// �R���X�g���N�^
	Stage(GameObject* parent);

	// �f�X�g���N�^
	~Stage();

	// ������
	void Initialize() override;

	// �X�V
	void Update() override;

	// �`��
	void Draw() override;

	// �J��
	void Release() override;
};