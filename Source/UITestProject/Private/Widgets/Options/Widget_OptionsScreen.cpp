// Avalanche All Rights Reserved


#include "Widgets/Options/Widget_OptionsScreen.h"
#include "ICommonInputModule.h"
#include "Input/CommonUIInputTypes.h"
#include "Widgets/Options/OptionsDataRegistry.h"
#include "DebugHelper.h"
#include "Widgets/Options/DataObjects/ListDataObject_Collection.h"
#include "Widgets/Components/FrontendTabListWidgetBase.h"



void UWidget_OptionsScreen::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
	if (!ResetAction.IsNull())
	{
		FSimpleDelegate MyFunc{FSimpleDelegate::CreateUObject(this, &ThisClass::OnResetBoundActionTriggered)};
		FBindUIActionArgs ResetActionArgs{ResetAction, true,  MyFunc};
		ResetActionHandle = RegisterUIActionBinding(ResetActionArgs);
	}
	
	FSimpleDelegate MyBackFunc = FSimpleDelegate::CreateUObject(this, &ThisClass::OnBackBoundActionTriggered);
	FDataTableRowHandle DefaultBackAction = ICommonInputModule::GetSettings().GetDefaultBackAction();
	FBindUIActionArgs BackActionArgs{DefaultBackAction, true, MyBackFunc};
	RegisterUIActionBinding(BackActionArgs);
	
}

void UWidget_OptionsScreen::NativeOnActivated()
{
	Super::NativeOnActivated();
	
	for (UListDataObject_Collection* TabCollection : GetOrCreateDataRegistry()->GetRegisteredTabCollections())
	{
		if (!TabCollection)
		{
			continue;
		}
		//register tab to create
		const FName TabID = TabCollection->GetDataID();
		if (TabListWidget_OptionTabs->GetTabButtonBaseByID(TabID) != nullptr )
		{
			continue;
		}
		TabListWidget_OptionTabs->RequestRegisterTab(TabID, TabCollection->GetDataDisplayName());
	}
}


void UWidget_OptionsScreen::OnResetBoundActionTriggered()
{
	Debug::Print(TEXT("OnResetBoundActionTriggered11111111111"));
}

void UWidget_OptionsScreen::OnBackBoundActionTriggered()
{
	DeactivateWidget();
}

UOptionsDataRegistry* UWidget_OptionsScreen::GetOrCreateDataRegistry()
{
	if (!CreatedOwningDataRegistry)
	{
		CreatedOwningDataRegistry = NewObject<UOptionsDataRegistry>();
		CreatedOwningDataRegistry->InitOptionsDataRegistry(GetOwningLocalPlayer());
	}
	checkf(CreatedOwningDataRegistry, TEXT("DataRegistry for option screen is invalid see Widget_OPtionScreen.cpp l.46"))

	return CreatedOwningDataRegistry;
}
		