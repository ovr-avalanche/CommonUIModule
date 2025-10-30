// Avalanche All Rights Reserved


#include "Widgets/Widget_PrimaryLayout.h"
#include "DebugHelper.h"

UCommonActivatableWidgetContainerBase* UWidget_PrimaryLayout::FindWidgetStackByTag(const FGameplayTag& InTag) const
{
	checkf(RegisteredWidgetStackMap.Contains(InTag), TEXT("no Widget Stack by the Tag %s"), *InTag.ToString());
	return RegisteredWidgetStackMap.FindRef(InTag); //FindRef returns a copy of the value associated with you key..
} 

void UWidget_PrimaryLayout::RegisterWidgetStack(UPARAM(meta = (Categories = "UI.WidgetStack"))FGameplayTag InStackTag, UCommonActivatableWidgetContainerBase* InStack)
{
	if (!IsDesignTime())
	{
		if (!RegisteredWidgetStackMap.Contains(InStackTag))
		{
			RegisteredWidgetStackMap.Add(InStackTag, InStack);
		}
	}
}
