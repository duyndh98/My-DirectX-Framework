#include "BulletController.h"
#include "Input.h"
#include "GameObject.h"


BulletController::BulletController(CGameObject * gameObject) : CMonoBehavior(gameObject)
{
}

void BulletController::Update(DWORD dt)
{
	CInput *input = CInput::GetInstance();
	if (input->KeyDown(DIK_E))
	{		
		Vector2 pos = m_pGameObject->GetComponent<CTransform>()->Get_Position();
		pos.x += 50;
		auto pBullet = CGameObject::Instantiate("BusterShot", nullptr, pos);
		pBullet->GetComponent<CRigidbody>()->SetVelocity({ .3,0 });
	}
}

void BulletController::Render()
{
}

