// Avalanche All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Widget_ActivatableBase.h"
#include "Widget_OptionsScreen.generated.h"

class UOptionsDataRegistry;
class UFrontendTabListWidgetBase;

/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNativeTick))
class UITESTPROJECT_API UWidget_OptionsScreen : public UWidget_ActivatableBase
{
	GENERATED_BODY()
protected:
	//~ Begin UUserWidget Interface
	virtual void NativeOnInitialized() override;
	//~ End UUserWidget Interface

	//~ Begin UCommonActivatableWidget Interface
	virtual void NativeOnActivated() override;
	//~ End UCommonActivatableWidget Interface
	
private:
	UOptionsDataRegistry* GetOrCreateDataRegistry();
	
	void OnResetBoundActionTriggered();
	void OnBackBoundActionTriggered();

	UFUNCTION()
	void OnOptionTabSelected(FName TabId);
	
	//---Bound Widget---
	UPROPERTY(meta= (BindWidget))
	UFrontendTabListWidgetBase* TabListWidget_OptionTabs;
	//---Bound Widget---
	
	//handles data creation. No direct Access.
	UPROPERTY(Transient)
	UOptionsDataRegistry* CreatedOwningDataRegistry;
	
	UPROPERTY(EditDefaultsOnly, Category = "Frontend Option Screen", meta = (RowType = "/Script/CommonUI.CommonInputActionDataBase"))
	FDataTableRowHandle ResetAction;
	
	FUIActionBindingHandle ResetActionHandle;
};
