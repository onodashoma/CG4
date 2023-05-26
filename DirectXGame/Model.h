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
	//フレンドクラス
	friend class FbxLoader;
	
public: //サブクラス
	//頂点データ構造体
	struct VertexPosNormalUv
	{
		DirectX::XMFLOAT3 pos; // xyz座標
		DirectX::XMFLOAT3 normal; // 法線ベクトル
		DirectX::XMFLOAT2 uv; // uv座標
	};
private:
	//モデル名
	std::string name;
	//ノード配列
	std::vector<Node>nodes;
	// メッシュを持つノード
	Node* meshNode = nullptr;
	// 頂点データ配列
	std::vector<VertexPosNormalUv>vertices;
	// 頂点インデックス配列
	std::vector<unsigned short>indices;

	// アンビエント係数
	DirectX::XMFLOAT3 ambient = { 1,1,1 };
	// ディフューズ係数
	DirectX::XMFLOAT3 diffese = { 1,1,1 };
	// テクスチャメタデータ
	DirectX::TexMetadata metadata = {};
	// スクラッチイメージ
	DirectX::ScratchImage scratchImg = {};
};

