// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintUtils.h"

UBlueprintUtils::UBlueprintUtils(class FObjectInitializer const&) {

}

void UBlueprintUtils::MoveWidgetTo(UWidget* Widget, const FVector2D TargetPosition, float TransitionTime, const EEasingFunc::Type XEasing, const EEasingFunc::Type YEasing, UObject* WorldContextObject, struct FLatentActionInfo LatentInfo)
{
	if (Widget == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("MoveWidgetTo was called with a null Widget"));
	}

	if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();

		FMoveWidgetTransitionAction* NewAction = new FMoveWidgetTransitionAction(
			Widget,
			TargetPosition,
			TransitionTime,
			XEasing,
			YEasing,
			LatentInfo
		);

		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, NewAction);
	}
}