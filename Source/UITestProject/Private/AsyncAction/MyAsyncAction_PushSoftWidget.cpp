// Avalanche All Rights Reserved


#include "AsyncAction/MyAsyncAction_PushSoftWidget.h"

UMyAsyncAction_PushSoftWidget* UMyAsyncAction_PushSoftWidget::PushSoftWidget(const UObject* WorldContextObject,
	APlayerController* OwningPlayerController,
	TSoftClassPtr<UWidget_ActivatableBase> InSoftWidgetClass,
	UPARAM(meta = (Categories = "UI.WidgetStack")) FGameplayTag InWidgetStackTag,
	bool bFocusOnNewlyPushedWidget)
{
	checkf(!InSoftWidgetClass.IsNull(), TEXT("MyAsyncAction_PushSoftWidget::PushSoftWidget checkf failed"));

	if (GEngine)
	{
		if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
		{
			UMyAsyncAction_PushSoftWidget* Node = NewObject<UMyAsyncAction_PushSoftWidget>();
			Node->RegisterWithGameInstance(World);
			return Node;
		}
	}
	
	return nullptr;
}
