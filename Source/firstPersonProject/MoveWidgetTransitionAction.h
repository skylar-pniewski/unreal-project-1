// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/WeakObjectPtr.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
#include <UMG/Public/Components/Widget.h>
#include <Math/Vector2D.h>
#include "Kismet/KismetMathLibrary.h"
#include <Kismet/GameplayStatics.h>

/**
 * 
 */
class FMoveWidgetTransitionAction : public FPendingLatentAction {
public:
	UWidget* Widget;
	const FVector2D TargetPosition;
	float Duration;

	const EEasingFunc::Type XEasing;
	const EEasingFunc::Type YEasing;

	const FVector2D InitialPosition;
	float ElapsedTime = 0;

	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;

	FMoveWidgetTransitionAction(UWidget* Widget, const FVector2D TargetPosition, float TransitionTime, EEasingFunc::Type XEasing, EEasingFunc::Type YEasing, const FLatentActionInfo& LatentInfo)
		: Widget(Widget)
		, InitialPosition(Widget->RenderTransform.Translation)
		, TargetPosition(TargetPosition)
		, XEasing(XEasing)
		, YEasing(YEasing)
		, Duration(TransitionTime)
		, ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
	{

	}

	virtual void UpdateOperation(FLatentResponse& Response) override {
		ElapsedTime += Response.ElapsedTime();

		float alpha = FMath::Clamp(ElapsedTime / Duration, 0.f, 1.f);

		float x = UKismetMathLibrary::Ease(InitialPosition.X, TargetPosition.X, alpha, XEasing);
		float y = UKismetMathLibrary::Ease(InitialPosition.Y, TargetPosition.Y, alpha, YEasing);

		Widget->SetRenderTranslation(FVector2D(x, y));

		Response.FinishAndTriggerIf(alpha >= 1.0f, ExecutionFunction, OutputLink, CallbackTarget);
	}

#if WITH_EDITOR

	virtual FString GetDescription() const override
	{
		static const FNumberFormattingOptions TransitionTimeFormatOptions = FNumberFormattingOptions()
			.SetMinimumFractionalDigits(3)
			.SetMaximumFractionalDigits(3);

		return FText::Format(NSLOCTEXT("FMoveWidgetTransitionAction", "MoveWidgetTransitionActionTimeFmt", "Move Widget Transition ({0} seconds left)"), FText::AsNumber(Duration - ElapsedTime, &TransitionTimeFormatOptions)).ToString();
	}

#endif
};
