﻿#include "BlockController.h"
#include "../Framework/GameObject.h"
#include "../Framework/Input.h"
#include "../Framework/Rigidbody.h"
#include <string>

BlockController::BlockController(CGameObject* game_object) : CMonoBehavior(game_object)
{
	m_isGoDown = true; 
	m_isRight = false;
	m_pos = _gameObject->GetComponent<CTransform>()->Get_Position();
	m_size = _gameObject->GetComponent<CRenderer>()->GetSize();
}

void BlockController::Update(DWORD dt)
{
	m_pos = _gameObject->GetComponent<CTransform>()->Get_Position();
	auto transform = _gameObject->GetComponent<CTransform>();
	if (m_pos.y + m_size.y >= SCREEN_HEIGHT) {
		transform->Set_Position(Vector2(transform->Get_Position().x, SCREEN_HEIGHT - m_size.y));
		SetIsGoDown(false);
	}
	else if (m_pos.y <= 0)
	{
		transform->Set_Position(Vector2(transform->Get_Position().x, 0));
		SetIsGoDown(true);
	}

	Move();
}

void BlockController::Render()
{
}

void BlockController::Move()
{
	auto rigidbody = _gameObject->GetComponent<CRigidbody>();
	auto input = CInput::GetInstance();

	for (short key = 0; key < 256; key++)
		if (input->KeyDown(key))
			;// MessageBoxW(nullptr, std::to_wstring(key).c_str(), L"", MB_OK);

	if (input->KeyDown(31) && !m_isRight)
		rigidbody->SetVelocity(Vector2(0, 1));

	if (input->KeyUp(31) && !m_isRight)
		rigidbody->SetVelocity(Vector2(0, 0));

	if (input->KeyDown(17) && !m_isRight)
		rigidbody->SetVelocity(Vector2(0, -1));
	
	if (input->KeyUp(17) && !m_isRight)
		rigidbody->SetVelocity(Vector2(0, 0));


	if (input->ButtonDown(0) && m_isRight)
		rigidbody->SetVelocity(Vector2(0, 1));
	
	if (input->ButtonUp(0) && m_isRight)
		rigidbody->SetVelocity(Vector2(0, 0));

	if (input->ButtonDown(1) && m_isRight)
		rigidbody->SetVelocity(Vector2(0, -1));
	
	if (input->ButtonUp(1) && m_isRight)
		rigidbody->SetVelocity(Vector2(0, 0));

}