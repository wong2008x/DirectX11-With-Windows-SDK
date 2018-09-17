#ifndef GAMEAPP_H
#define GAMEAPP_H

#include <DirectXColors.h>
#include <DDSTextureLoader.h>
#include <WICTextureLoader.h>
#include "d3dApp.h"
#include "Camera.h"
#include "GameObject.h"
class GameApp : public D3DApp
{
public:
	// �����ģʽ
	enum class CameraMode { FirstPerson, ThirdPerson, Free };
	
public:
	GameApp(HINSTANCE hInstance);
	~GameApp();

	bool Init();
	void OnResize();
	void UpdateScene(float dt);
	void DrawScene();

private:
	bool InitResource();

private:
	
	ComPtr<ID2D1SolidColorBrush> mColorBrush;				// ��ɫ��ˢ
	ComPtr<IDWriteFont> mFont;								// ����
	ComPtr<IDWriteTextFormat> mTextFormat;					// �ı���ʽ

	GameObject mBoltAnim;									// ���綯��
	GameObject mWoodCrate;									// ľ��
	GameObject mFloor;										// �ذ�
	std::vector<GameObject> mWalls;							// ǽ��
	GameObject mMirror;										// ����

	std::vector<ComPtr<ID3D11ShaderResourceView>> mBoltSRVs;// ���綯������

	Material mShadowMat;									// ��Ӱ����
	Material mWoodCrateMat;									// ľ�в���

	BasicFX mBasicFX;										// Basic��Ч������

	CBChangesEveryFrame mCBFrame;							// �û�������Ž���ÿһ֡���и��µı���
	CBDrawingStates mDrawingState;							// �û�������Ż���״̬
	CBChangesOnResize mCBChangesOnReSize;							// �û�������Ž��ڴ��ڴ�С�仯ʱ���µı���
	CBChangesRarely mCBRarely;							// �û�������Ų����ٽ����޸ĵı���

	std::shared_ptr<Camera> mCamera;						// �����
	CameraMode mCameraMode;									// �����ģʽ

};


#endif