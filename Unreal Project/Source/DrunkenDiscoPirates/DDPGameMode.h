// © Copyright Spoonvalley Interactive 2018.

#pragma once

#include "GameFramework/GameMode.h"
#include "DDPGameInstance.h"
#include "DiscoPirate.h"
#include "DDPGameMode.generated.h"

UCLASS()
class DRUNKENDISCOPIRATES_API ADDPGameMode : public AGameMode
{
	GENERATED_BODY()
	
protected:

	//Reference to the disco pirate class.
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<ADiscoPirate> discoPirateClass;

	//Number of players.
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 playerCount;

	//Array of transforms for the different players.
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FTransform> playerTransforms;

public:

	//Default constructor.
	ADDPGameMode();

	//Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	//Create players.
	UFUNCTION(BlueprintCallable, Category = "Code")
	void CreatePlayers();
};