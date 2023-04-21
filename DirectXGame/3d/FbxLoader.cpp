#include "FbxLoader.h"
#include<cassert>


/// <summary>
/// 静的メンバ変数の実体
/// </summary>
const std::string FbxLoader::baseDirectory = "Resources/";


void FbxLoader::Initialize(ID3D12Device* device)
{
    // 最初期化チェック
    assert(fbxManager == nullptr);

    // 引数からメンバ変数を代入
    this->device = device;

    // FBXマネージャの生成
    fbxManager = FbxManager::Create();

    //FBXマネージャの入出力設定
    FbxIOSettings* ios = FbxIOSettings::Create(fbxManager, IOSROOT);
    fbxManager->SetIOSettings(ios);

    //FBXインポータの生成
    fbxImporter = FbxImporter::Create(fbxManager, "");

}

FbxLoader* FbxLoader::GetInstance()
{
    static FbxLoader instance;
    return &instance;
}

void FbxLoader::LoadModelFromFile(const string& modelName)
{

    const string directoryPath = baseDirectory + modelName + "/";

    const string fileName = modelName + ".fbx";

    const string fullpath = directoryPath + fileName;

    if (!fbxImporter->Initialize(fullpath.c_str(), -1, fbxManager->GetIOSettings()))
    {
        assert(0);
    }

    // シーン生成
    FbxScene* fbxScene =
        FbxScene::Create(fbxManager, "fbxScene");

    // ファイルからロードしたFBXの情報をしーんにインポート
    fbxImporter->Import(fbxScene);
}

void FbxLoader::Finalize()
{
    // 各種FBXインスタンスの破棄
    fbxImporter->Destroy();
    fbxManager->Destroy();
}
