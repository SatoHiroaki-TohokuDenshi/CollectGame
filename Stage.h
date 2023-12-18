#pragma once
#include "Engine/GameObject.h"
#include <vector>

// �}�b�v�̃^�C�v
enum MAP_TYPE {
	T_PLAYER = -1,      // �v���C���[�̏����ʒu
	T_AIR = 0,          // �����Ȃ����
	T_GROUND = 1,       // ���ʂ̏� : 1
	T_LUPHILL,          // ���t������ : 2
	T_UUPHILL,          // ��t������ : 3
	T_UDOWNHILL,		// ��t������� : 4
	T_LDOWNHILL,		// ���t������� : 5
	T_MAX,				// �Ǘ��p�ԕ�
};

// Stage���Ǘ�����N���X
class Stage : public GameObject {
private:
	std::vector<std::vector<int>> stage_;
	std::vector<int> hModel_;        // ���f���Ǘ��ԍ�

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