﻿#pragma once
#include "Collision.h"
#include "Collider.h"

namespace Framework {
	class CPhysicObserver
	{
		// Cons / Des
	public:
		CPhysicObserver() = default;
		virtual ~CPhysicObserver() = default;

		// Observer Method, do not virtual because any child inherited can override or not 
	public:
		virtual void OnCollisionEnter(CCollision *collision) {}
		virtual void OnCollisionExit(CCollision *collision) {}
		virtual void OnCollisionStay(CCollision *collision) {}

		virtual void OnTriggerEnter(CCollider *other) {}
		virtual void OnTriggerExit(CCollider *other) {}
		virtual void OnTriggerStay(CCollider *other) {}
	};
}