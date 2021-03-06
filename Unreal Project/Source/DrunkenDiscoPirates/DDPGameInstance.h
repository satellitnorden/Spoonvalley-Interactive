// © Copyright Spoonvalley Interactive 2018.

#pragma once

#include "Engine/GameInstance.h"
#include "DDPGameInstance.generated.h"

UCLASS()
class DRUNKENDISCOPIRATES_API UDDPGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
private:

	//The number of players.
	int32 playerCount;

public:

	//Default constructor.
	UDDPGameInstance();

	//Get the number of players.
	UFUNCTION(BlueprintCallable, Category = "Code")
	int32 GetPlayerCount() { return playerCount; }

	//Set the number of players.
	UFUNCTION(BlueprintCallable, Category = "Code")
	void SetPlayerCount(int32 newPlayerCount) { if (newPlayerCount >= 2 && newPlayerCount <= 4) playerCount = newPlayerCount; }
};