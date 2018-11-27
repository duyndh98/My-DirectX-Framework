﻿#pragma once
#include "MonoBehavier.h"
#include "GameObject.h"

using namespace Framework;

class PlayerController : public CMonoBehavior
{
public:
	enum State
	{
		JUMP = 1,
		MOVE_RIGHT = 2,
		MOVE_LEFT = 4,
		IDLE = 0
	};

private:
	int m_state;

	//Cons / Des
private:
	PlayerController() = default;
public:
	PlayerController(CGameObject *gameObject);
	~PlayerController() = default;

	int GetState() const { return m_state; }
	void SetState(int state);

	//Override
private:
	void OnCollisionEnter(CCollision* collision) override;
	void Update(DWORD dt) override;
	void Render() override;
};