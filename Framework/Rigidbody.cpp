﻿#include "stdafx.h"
#include "Rigidbody.h"

#include "GameObject.h"

using namespace Framework;

CRigidbody::CRigidbody(CGameObject * gameObject)
{
	this->m_pGameObject = gameObject;
	this->_velocity = Vector2(0, 0);
	this->_mass = 0;
	this->_gravityScale = 1;
	this->_isKinematic = false;
}

void CRigidbody::Update(DWORD dt)
{
	if (_isKinematic) return;

	auto pTransform = m_pGameObject->GetComponent<CTransform>();
	if (pTransform)
		pTransform->PlusPosition(_velocity * dt);
}

void CRigidbody::Render()
{
}
