// © Copyright Chrysalis Interactive 2017.

#include "DrunkenDiscoPirates.h"
#include "Camera.h"


//Default constructor.
ACamera::ACamera()
	:
	camera(CreateDefaultSubobject<UCameraComponent>(TEXT("Camera")))
{
 	//Setup pawnn.
	CREATEROOT()
	PrimaryActorTick.bCanEverTick = false;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	//Setup camera component.
	camera->SetupAttachment(RootComponent);
	camera->ProjectionMode = ECameraProjectionMode::Orthographic;
	camera->bConstrainAspectRatio = true;
	camera->AspectRatio = 1920.0f / 1080.0f;
	camera->OrthoWidth = 5000.0f;
}

//Called when the game starts or when spawned.
void ACamera::BeginPlay()
{
	Super::BeginPlay();
	
}

//Called every frame.
void ACamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Called to bind functionality to input.
void ACamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}