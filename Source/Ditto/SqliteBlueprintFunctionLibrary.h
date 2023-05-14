// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SqliteBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class DITTO_API USqliteBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static int OpenDataBase(FString DataPath);
	
};
