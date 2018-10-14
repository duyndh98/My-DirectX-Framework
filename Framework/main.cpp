#include "stdafx.h"
#include "Macros.h"
#include "GameManager.h"
#include <iostream>
#include "Scene.h"

using namespace Framework;

LRESULT WINAPI WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		result = DefWindowProc(hWnd, message, wParam, lParam);
	}

	return result;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	CGameManager::Instantiate(hInstance, nShowCmd, SCREEN_WIDTH, SCREEN_HEIGHT, FULL_SCREEN);
	CGameManager* pGameManager = CGameManager::GetInstance();
	
	auto scene = Framework::CScene::Instantiate();
	//pGameManager->SetCurrentScene(scene);

	do
	{
		/*
		Framework::Object::UObjectData data = { {} };
		Framework::Object::CGameObject* mario = Framework::Object::CGameObject::Instantiate(Vector2(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));

		data.renderData = { "mario.png" };
		mario->AddComponent({ Framework::Object::EObjectType::RENDERER, data });

		mario->AddRigidbody(new CRigidbody(mario));
		mario->GetRigidbody()->SetVelocity(Vector2(1, 1));

		Framework::Object::UObjectData data2 = { {} };
		data2.renderData = { "Block.png" };
		Framework::Object::CGameObject* leftblock = Framework::Object::CGameObject::Instantiate(Vector2(0, 0));
		leftblock->AddComponent({ Framework::Object::EObjectType::RENDERER, data2 });

		leftblock->AddRigidbody(new CRigidbody(leftblock));
		leftblock->GetRigidbody()->SetVelocity(Vector2(0, 0));

		Framework::Object::CGameObject* rightblock = Framework::Object::CGameObject::Instantiate(Vector2(SCREEN_WIDTH - 10, 0));
		rightblock->AddComponent({ Framework::Object::EObjectType::RENDERER, data2 });

		rightblock->AddRigidbody(new CRigidbody(rightblock));
		rightblock->GetRigidbody()->SetVelocity(Vector2(0, 0));
		*/

		/*builderData.transformBuilder = { VECTOR3_ZERO, VECTOR3_ZERO, VECTOR3_ZERO };
		mario->AddComponent(Framework::Object::EBuilderType::TRANSFORM, builderData);*/

		pGameManager->Run();
		
	} while (false);
	
	CGameManager::Destroy();
	CGraphic::Destroy();

	return 0;
}
