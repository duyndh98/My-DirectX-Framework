#include "ChargedShootController.h"
#include "Animation.h"
#include "GameObject.h"
#include "Animator.h"

void ChargedShootController::OnCollisionEnter(CCollision * collision)
{
	CDebug::Log(collision->GetColliderName());
	CDebug::Log(collision->GetOtherColliderName());
	CDebug::Log(m_pGameObject->GetName());
	CDebug::Log("\n");
	if (collision->CheckNameInCollision(m_pGameObject->GetName()))
		m_pGameObject->GetComponent<CAnimator>()->SetBool("isCollision", true);
}

void ChargedShootController::Update(DWORD dt)
{
	CAnimator *anim = m_pGameObject->GetComponent<CAnimator>();
	if (anim->GetBool("isCollision") && anim->GetCurrentAnimation()->IsLastFrame())
	{
	}
}

void ChargedShootController::Render()
{
}