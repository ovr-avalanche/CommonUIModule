// Avalanche All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OptionsDataRegistry.generated.h"

class UListDataObject_Collection;

/**
 * 
 */
UCLASS()
class UITESTPROJECT_API UOptionsDataRegistry : public UObject
{
	GENERATED_BODY()
	
public:
	// called by OptionScreen right after the UOptionsDataRegistry Object is created.
	void InitOptionsDataRegistry(ULocalPlayer* InOwningLocalPlayer);

	const TArray<UListDataObject_Collection*>& GetRegisteredTabCollections() const { return RegisteredTabCollections; }
private:
	void InitGameplayCollectionTab();
	void InitAudioCollectionTab();
	void InitVideoCollectionTab();
	void InitControlCollectionTab();

	UPROPERTY(Transient)
	TArray<UListDataObject_Collection*>RegisteredTabCollections;
};
