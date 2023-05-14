// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "RPGItem.h"
#include "RPGEquipItem.generated.h"

/** Native base class for weapons, should be blueprinted */
UCLASS()
class DITTO_API URPGEquipItem : public URPGItem
{
	GENERATED_BODY()

public:
	/** Constructor */
	URPGEquipItem()
	{
		ItemType = URPGAssetManager::WeaponItemType;
	}

	/** Weapon actor to spawn */
	// UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon)
	// TSubclassOf<AActor> WeaponActor;
};