// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include <UMG/Public/Components/Widget.h>
#include "LatentActions.h"
#include "MoveWidgetTransitionAction.h"
#include "BlueprintUtils.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPERSONPROJECT_API UBlueprintUtils : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
public:	
	UFUNCTION(BlueprintCallable, Category = "Widget Transitions", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo"))
		static void MoveWidgetTo(UWidget* Widget, const FVector2D TargetPosition, float TransitionTime, const EEasingFunc::Type XEasing, const EEasingFunc::Type YEasing, UObject* WorldContextObject, struct FLatentActionInfo LatentInfo);
};
