// Copyright Spoonvalley Interactive 2018.

#include "DrunkenDiscoPirates.h"
#include "RumBottle.h"


//Default constructor.
ARumBottle::ARumBottle()
	:
	capsuleCollision(CreateDefaultSubobject<UCapsuleComponent>(TEXT("Sphere Collision"))),
	rumFlipbook(CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Rum Flipbook")))
{
 	//Setup actor.
	PrimaryActorTick.bCanEverTick = true;

	//Setup the capsule collision component.
	SetRootComponent(capsuleCollision);
	
	//Setup the rum flipbook component.
	rumFlipbook->SetupAttachment(capsuleCollision);
}

//Called when the game starts or when spawned.
void ARumBottle::BeginPlay()
{
	Super::BeginPlay();
	
}

//Called every frame.
void ARumBottle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Check if the bottle needs to be teleported to the other side of the level.
	if (GetActorLocation().Y > levelYBoundary)
		AddActorWorldOffset(FVector(0.0f, (-levelYBoundary * 2), 0.0f));

	else if (GetActorLocation().Y < -levelYBoundary)
		AddActorWorldOffset(FVector(0.0f, (levelYBoundary * 2), 0.0f));

	if (GetActorLocation().Z > levelZBoundary)
		AddActorWorldOffset(FVector(0.0f, 0.0f, (-levelZBoundary * 2)));

	else if (GetActorLocation().Z < -levelZBoundary)
		AddActorWorldOffset(FVector(0.0f, 0.0f, (levelZBoundary * 2)));
}