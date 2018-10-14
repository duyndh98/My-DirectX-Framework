﻿#pragma once
#include "Macros.h"

namespace Framework
{
	// Enum for builder
	enum EObjectType
	{
		UNKNOWN = 0,
		GAME_OBJECT = 1,
		TRANSFORM = 2,
		RENDERER = 3,
		RIGIDBODY = 4
	};

	// Initialize parameters for Game Object
	struct SGameObjectBuilder
	{
	};

	// Initialize parameters for Render Component
	struct SRendererBuilder
	{
		WString texturePath = nullptr;
	};

	// Initialize parameters for Transform Component
	struct STransformBuilder
	{
		Vector2 position = VECTOR2_ZERO;
		Vector2 rotation = VECTOR2_ZERO;
		Vector2 scale = VECTOR2_ONE;
	};

	// Builder
	union UObjectData
	{
		SGameObjectBuilder gameObjectData;
		SRendererBuilder renderData;
		STransformBuilder transformData;
	};

	// Builder Struct
	struct SBuilder
	{
		EObjectType builderType = EObjectType::UNKNOWN;
		UObjectData builderData = { {} };
	};

	// Object class
	class CObject 
	{
		// Properties
	protected:
		EObjectType m_type = EObjectType::UNKNOWN;
		CObject* m_parentObject = nullptr;

		// Cons / Des
	public:
		CObject() = default;
		virtual ~CObject() = default;
		
		// Getters / Setters
	public:
		void SetParentObject(CObject* pParent);

		// Abstract methods
	public:
		virtual void Update(DWORD dt) = 0;

		// Static methods
	public:                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
		static CObject* Instantiate(SBuilder builder);
		static void Destroy(CObject* &instance);
	};
}