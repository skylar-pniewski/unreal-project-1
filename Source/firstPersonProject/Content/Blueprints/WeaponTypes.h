// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponTypes.generated.h"
/**
 * 
 */
UENUM(BlueprintType)
enum class EWeaponTypes : uint8 {
	WEAP_Single		UMETA(DisplayName = "Single"),
	WEAP_Burst		UMETA(DisplayName = "Burst"),
	WEAP_Auto		UMETA(DisplayName = "Automatic"),
};