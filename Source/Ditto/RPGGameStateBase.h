// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Ditto.h"
#include "GameFramework/GameStateBase.h"
#include "RPGGameStateBase.generated.h"

/** Base class for GameMode, should be blueprinted */
UCLASS()
class DITTO_API ARPGGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	/** Constructor */
	ARPGGameStateBase() {}
};

