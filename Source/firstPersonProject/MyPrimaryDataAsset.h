// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MyPrimaryDataAsset.generated.h"

/**
 * 
 */



UCLASS(BlueprintType)
class FIRSTPERSONPROJECT_API UMyPrimaryDataAsset : public UPrimaryDataAsset
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
};
