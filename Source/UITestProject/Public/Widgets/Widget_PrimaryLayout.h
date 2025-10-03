// Avalanche All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "Widget_PrimaryLayout.generated.h"

class UCommonActivatableWidgetContainerBase;

UCLASS(Abstract, BlueprintType, meta = (DisableNativeTick))
class UITESTPROJECT_API UWidget_PrimaryLayout : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UCommonActivatableWidgetContainerBase* FindWidgetStackByTag(const FGameplayTag& InTag) const;
	
protected:
	UFUNCTION(BlueprintCallable)
	void RegisterWidgetStack(UPARAM(meta = (Categories = "UI.WidgetStack"))FGameplayTag InStackTag, UCommonActivatableWidgetContainerBase* InStack);
	// The UPARAM restricts what can be selected in the editor to only tags that are in the UI.WidgetStack hierarchy.
private:
	UPROPERTY(Transient) // Transient = will not be saved or loaded; non-Transient properties are saved to disk for cooked builds.
	TMap<FGameplayTag, UCommonActivatableWidgetContainerBase*> RegisteredWidgetStackMap;
};
