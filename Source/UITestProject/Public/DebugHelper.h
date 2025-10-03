#pragma once

namespace Debug
{
		static void Print(const FString& Message, int32 InKey = -1, const FColor& Color = FColor::MakeRandomColor())
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(InKey, 8.f, Color, Message);
				UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
			}
		}
}
