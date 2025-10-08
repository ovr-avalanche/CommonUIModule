// Avalanche All Rights Reserved


#include "Controllers/MyFrontendController.h"

#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

void AMyFrontendController::OnPossess(APawn* aPawn)
{           
    Super::OnPossess(aPawn);
    TArray<AActor*> Cameras;
    UGameplayStatics::GetAllActorsOfClassWithTag(this, ACameraActor::StaticClass(), FName("MyCameraTag"), Cameras);

    if (!Cameras.IsEmpty())
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Found Camera with Tag Default")));
        SetViewTarget(Cameras[0]);
    }
}
