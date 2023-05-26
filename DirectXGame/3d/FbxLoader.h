#pragma once

#include "fbxsdk.h"
#include"Model.h"

#include <d3d12.h>
#include <d3dx12.h>
#include <string>

class FbxLoader
{

private: //エイリアス
	// std::を省略
	using string = std::string;


public: //定数
	// モデル格納ルートパス
	static const string baseDirectory;


public:

	/// <summary>
	/// シングルトンインスタンスの取得
	/// </summary>
	
	void Initialize(ID3D12Device* device);

	/// <returns>インスタンス</returns>
	static FbxLoader* GetInstance();
	
	// テクスチャがない場合の標準テクスチャファイル名
	static const string defaultTextureFileName;

	void ParseNodeRecursive(Model* model, FbxNode* fbxNode, Node* parent = nullptr);

	void LoadModelFromFile(const string& modelName);

	void ParseMesh(Model* model, FbxNode* fbxNode);
	
	//頂点座標読み取り
	void ParseMeshVertices(Model* model, FbxMesh* fbxMesh);

	// 面情報読み取り
	void ParseMeshFaces(Model* model, FbxMesh* fbxMesh);

	// マテリアル読み取り
	void ParseMaterial(Model* model, FbxNode* fbxNode);

	// テクスチャ読み込み
	void LoadTexture(Model* model, const std::string& fullpath);

	// ディレクトリを含んだファイルパスからファイル名を抽出する
	std::string ExtractFileName(const std::string& path);

	void Finalize();

	



private:
	
	// privateなコンストラクタ（シングルトンパターン）
	FbxLoader() = default;
	// privateなデストラクタ（シングルトンパターン）
	~FbxLoader() = default;

	// D3D12デバイス
	ID3D12Device* device = nullptr;

	// FBXマネージャ
	FbxManager* fbxManager = nullptr;

	// FBXインポータ
	FbxImporter* fbxImporter = nullptr;


	// コピーコンストラクタを禁止（シングルトンパターン）
	FbxLoader(const FbxLoader& obj) = delete;
	// コピー代入演算子を禁止（シングルトンパターン）
	void operator=(const FbxLoader& obj) = delete;





};