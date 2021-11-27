// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Content/Blueprints/WeaponTypes.h"
#include "MyDataAsset.generated.h"
/**
 * 
 */
UCLASS(BlueprintType)
class FIRSTPERSONPROJECT_API UMyDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UStaticMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Strength = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWeaponTypes weaponType;
};
