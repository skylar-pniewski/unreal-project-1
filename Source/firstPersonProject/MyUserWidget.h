// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InputCoreTypes.h"

#include "MyUserWidget.generated.h"
/**
 * 
 */
UCLASS()
class FIRSTPERSONPROJECT_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	void GenerateRandom();
	
	UFUNCTION(BlueprintCallable)
		void OnGenerateButtonClicked();


	float growth;

public:
	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UPROPERTY(EditAnywhere, meta=( BindWidget ))
	class UTextBlock* RandomNumberLabel;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* GenerateButton;

	UPROPERTY(EditAnywhere)
	class UTextBlock* TestLabel;

	UFUNCTION()
		void UpdateFill();

	UFUNCTION(BlueprintCallable)
	void ChangeColor(FColor color);

	UFUNCTION()
		virtual void Show();

	UFUNCTION()
		virtual void Hide();

	UFUNCTION()
		virtual void OnKeyClicked();
};
