// Fill out your copyright notice in the Description page of Project Settings.

#include "MyUserWidget.h"

#include <Components/Button.h>
#include <Components/TextBlock.h>
#include <Components/InputComponent.h>
#include <Styling/SlateColor.h>
#include <Blueprint/WidgetTree.h>
#include <Components/CanvasPanelSlot.h>
#include "InputCoreTypes.h"
#include "GameFramework/PlayerInput.h"
#include "GameFramework/PlayerController.h"
//#include "Engine/EngineBaseTypes.h"
#include "Framework/Commands/InputChord.h"
#include "Kismet/GameplayStatics.h"

void UMyUserWidget::NativeConstruct() {
	Super::NativeConstruct();
	growth = 0;
	GenerateRandom();
	//GetWorld()->
	GenerateButton->OnClicked.AddUniqueDynamic(this, &UMyUserWidget::OnGenerateButtonClicked);
	//if(InputComponent)
		//InputComponent->BindKey("G", IE_Pressed, this, &UMyUserWidget::OnKeyClicked);
	if (InputComponent) {
		
		FInputActionBinding& NewBinding = InputComponent->BindAction("Jump", IE_Pressed, this, &UMyUserWidget::OnKeyClicked);
		NewBinding.bConsumeInput = false;
	}
	APlayerController* player = UGameplayStatics::GetPlayerController(this, 0);
	
}



void UMyUserWidget::GenerateRandom() {
	int32 RandomNumber = FMath::RandRange(0, 100);

	//UTextBlock* testText = Co/*nstructObject<UTextBlock>(UTextBlock::StaticClass(), this);
	//CreateWidget<UTextBlock>(GetWorld(), ButtonTemplateWidget);
	//GenerateButton->AddChild(*/
	if (WidgetTree) {
		UTextBlock* text = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		TestLabel = text;
		text->SetText(FText::FromString(FString("TEST")));
		UPanelWidget* root = Cast<UPanelWidget>(GetRootWidget());
		UPanelSlot* slot = root->AddChild(text);
		//UCanvasPanelSlot* canvasSlot = Cast<UCanvasPanelSlot>(slot);

		//canvasSlot->SetAnchors(FAnchors(0.5f, 0.5f));
		//canvasSlot->SetAlignment(FVector2D(0.5f, 0.5f));
		//canvasSlot->SetOffsets(FMargin(0, 0, 0, 0));
	}
	RandomNumberLabel->SetText(FText::AsNumber(RandomNumber));
}

void UMyUserWidget::OnGenerateButtonClicked() {
	GenerateRandom();
	UE_LOG(LogTemp, Warning, TEXT("Hello"));
}

void UMyUserWidget::UpdateFill() {

}

void UMyUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime) {
	Super::NativeTick(MyGeometry, InDeltaTime);
	APlayerController* player = GetWorld()->GetFirstPlayerController();
	if (player->WasInputKeyJustPressed(EKeys::G)) {
		if (TestLabel)
			TestLabel->SetText(FText::FromString(FString("PRESSED G")));
	}

}

void UMyUserWidget::ChangeColor(FColor color) {
	//float r = FMath::RandRange(0.0f, 1.0f);
	//FLinearColor color = FLinearColor(r, r, r, r);
	//GenerateButton->SetBackgroundColor(color);
	//FSlateColor slateColor = FSlateColor(color);
	//RandomNumberLabel->SetColorAndOpacity(slateColor);
}

void UMyUserWidget::Show()
{

}

void UMyUserWidget::Hide()
{
}

void UMyUserWidget::OnKeyClicked() {
	UE_LOG(LogTemp, Warning, TEXT("KEY PRESSED"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("This message will appear on the screen!"));

}
