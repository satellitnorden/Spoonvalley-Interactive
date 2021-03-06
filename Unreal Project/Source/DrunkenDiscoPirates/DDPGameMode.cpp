// © Copyright Spoonvalley Interactive 2018.

#include "DrunkenDiscoPirates.h"
#include "DDPGameMode.h"

//Default constructor.
ADDPGameMode::ADDPGameMode()
{
	//Increase the maximum amount of players.
	if (GEngine && GEngine->GameViewport)
		GEngine->GameViewport->MaxSplitscreenPlayers = 5;
}

//Called when the game starts or when spawned.
void ADDPGameMode::BeginPlay()
{
	Super::BeginPlay();
}

//Create players.
void ADDPGameMode::CreatePlayers()
{
	UWorld *world = GetWorld();

	playerCount = Cast<UDDPGameInstance>(UGameplayStatics::GetGameInstance(this))->GetPlayerCount();
	//playerCount = 2;

	for (int32 i = 0; i < playerCount; ++i)
	{
		ADiscoPirate *newDiscoPirate = world->SpawnActor<ADiscoPirate>(discoPirateClass, playerTransforms[i]);
		newDiscoPirate->SetFlipbooks(i + 1);

		APlayerController *newPlayerController = UGameplayStatics::CreatePlayer(this, i + 1);

		if (newPlayerController)
			newPlayerController->Possess(newDiscoPirate);

		else
			UGameplayStatics::GetPlayerController(this, i + 1)->Possess(newDiscoPirate);
	}
}