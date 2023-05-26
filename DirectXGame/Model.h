#pragma once
#include <string>
#include<DirectXMath.h>
#include<DirectXTex.h>
#include<vector>


struct Node
{

	std::string name;

	DirectX::XMVECTOR scaling = { 1,1,1,0 };

	DirectX::XMVECTOR rotation = { 0,0,0,0 };

	DirectX::XMVECTOR translation = { 0,0,0,1 };

	DirectX::XMMATRIX transform;

	DirectX::XMMATRIX globalTransform;

	Node* parent = nullptr;

};

class Model
{
public:
	//�t�����h�N���X
	friend class FbxLoader;
	
public: //�T�u�N���X
	//���_�f�[�^�\����
	struct VertexPosNormalUv
	{
		DirectX::XMFLOAT3 pos; // xyz���W
		DirectX::XMFLOAT3 normal; // �@���x�N�g��
		DirectX::XMFLOAT2 uv; // uv���W
	};
private:
	//���f����
	std::string name;
	//�m�[�h�z��
	std::vector<Node>nodes;
	// ���b�V�������m�[�h
	Node* meshNode = nullptr;
	// ���_�f�[�^�z��
	std::vector<VertexPosNormalUv>vertices;
	// ���_�C���f�b�N�X�z��
	std::vector<unsigned short>indices;

	// �A���r�G���g�W��
	DirectX::XMFLOAT3 ambient = { 1,1,1 };
	// �f�B�t���[�Y�W��
	DirectX::XMFLOAT3 diffese = { 1,1,1 };
	// �e�N�X�`�����^�f�[�^
	DirectX::TexMetadata metadata = {};
	// �X�N���b�`�C���[�W
	DirectX::ScratchImage scratchImg = {};
};

