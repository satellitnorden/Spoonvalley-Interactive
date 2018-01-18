// © Copyright Spoonvalley Interactive 2018.

#include "DrunkenDiscoPirates.h"
#include "DiscoPirate.h"
#include "Camera.h"

//Update the animation.
void ADiscoPirate::UpdateAnimation()
{
	switch (currentState)
	{
		case States::Idle:
		{
			if (hasRum)
				flipbook->SetFlipbook(idleDrinkingFlipbook);

			else
				flipbook->SetFlipbook(idleFlipbook);

			break;
		}

		case States::Walking:
		{
			if (hasRum)
				flipbook->SetFlipbook(runningDrinkingFlipbook);

			else
				flipbook->SetFlipbook(walkingFlipbook);

			break;
		}

		case States::Running:
		{
			if (hasRum)
				flipbook->SetFlipbook(runningDrinkingFlipbook);

			else
				flipbook->SetFlipbook(runningFlipbook);

			break;
		}

		case States::JumpingStart:
		{
			if (hasRum)
				flipbook->SetFlipbook(jumpingStartDrinkingFlipbook);

			else
				flipbook->SetFlipbook(jumpingStartFlipbook);

			break;
		}

		case States::JumpingLoop:
		{
			if (hasRum)
				flipbook->SetFlipbook(jumpingLoopDrinkingFlipbook);

			else
				flipbook->SetFlipbook(jumpingLoopFlipbook);

			break;
		}

		case States::Attacking:
		{
			flipbook->SetFlipbook(attackingFlipbook);

			break;
		}

		case States::Damaged:
		{
			flipbook->SetFlipbook(damagedFlipbook);

			break;
		}

		case States::Stunned:
		{
			flipbook->SetFlipbook(stunnedFlipbook);

			break;
		}

		case States::JumpingAttacking:
		{
			flipbook->SetFlipbook(jumpingAttackingFlipbook);

			break;
		}
	}
}

//Move vertically.
void ADiscoPirate::MoveVertical(float value)
{
	if (currentState != States::Attacking && currentState != States::Damaged  && currentState != States::Stunned)
		AddMovementInput(GetActorRightVector(), value);
}

//Initiate an attack.
void ADiscoPirate::InitiateAttack()
{
	if ((currentState == States::JumpingStart || currentState == States::JumpingLoop) && !hasRum) 
	{
		currentState = States::JumpingAttacking;
		flipbook->SetLooping(false);

		UGameplayStatics::PlaySoundAtLocation(this, attackingSound, GetActorLocation());
	}

	else if ((currentState == States::Idle || currentState == States::Walking || currentState == States::Running) && !hasRum)
	{
		currentState = States::Attacking;
		flipbook->SetLooping(false);

		UGameplayStatics::PlaySoundAtLocation(this, attackingSound, GetActorLocation());
	}
}

//Perform an attack.
void ADiscoPirate::PerformAttack()
{
	if (!hasAttacked)
	{
		hasAttacked = true;

		if (attackablePirates.Num() > 0)
		{
			attackablePirates[0]->Attack(this);
		}
	}
}

//Initiate a jump.
void ADiscoPirate::InitiateJump()
{
	if (currentState != States::JumpingStart && currentState != States::JumpingLoop && currentState != States::Stunned)
	{
		Jump();

		currentState = States::JumpingStart;
		flipbook->SetLooping(false);

		UGameplayStatics::PlaySoundAtLocation(this, jumpingSound, GetActorLocation());
	}
}

//Toggles pause.
void ADiscoPirate::TogglePause()
{
	camera->TogglePause(uniquePlayerIndex);
}

//Move up UI.
void ADiscoPirate::MoveUpUI()
{
	camera->MoveUpUI(uniquePlayerIndex);
}

//Move down UI.
void ADiscoPirate::MoveDownUI()
{
	camera->MoveDownUI(uniquePlayerIndex);
}

//On select UI.
void ADiscoPirate::OnSelectUI()
{
	camera->OnSelectUI(uniquePlayerIndex);
}

//Called on begin overlap.
void ADiscoPirate::OnBeginOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor != this)
		attackablePirates.Add(Cast<ADiscoPirate>(OtherActor));
}

//Called on end overlap.
void ADiscoPirate::OnEndOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor != this)
		attackablePirates.Remove(Cast<ADiscoPirate>(OtherActor));
}

//Called on animation finish.
void ADiscoPirate::OnAnimationFinished()
{
	switch (currentState)
	{
		case States::Attacking:
		{
			currentState = States::Idle;
			flipbook->SetLooping(true);
			flipbook->PlayFromStart();
			hasAttacked = false;

			break;
		}

		case States::JumpingStart:
		{
			currentState = States::JumpingLoop;
			flipbook->SetLooping(true);
			flipbook->PlayFromStart();

			break;
		}

		case States::Damaged:
		{
			currentState = States::Idle;
			flipbook->SetLooping(true);
			flipbook->PlayFromStart();

			break;
		}

		case States::JumpingAttacking:
		{
			currentState = States::Idle;
			flipbook->SetLooping(true);
			flipbook->PlayFromStart();

			break;
		}
	}
}

//Sets the different flipbooks of this pirate.
void ADiscoPirate::SetFlipbooksImplementation(UPaperFlipbook *newIdleFlipbook, UPaperFlipbook *newWalkingFlipbook, UPaperFlipbook *newRunningFlipbook, UPaperFlipbook *newJumpingStartFlipbook, UPaperFlipbook *newJumpingLoopFlipbook, UPaperFlipbook *newAttackingFlipbook, UPaperFlipbook *newDamagedFlipbook, UPaperFlipbook *newIdleDrinkingFlipbook, UPaperFlipbook *newRunningDrinkingFlipbook, UPaperFlipbook *newJumpingStartDrinkingFlipbook, UPaperFlipbook *newJumpingLoopDrinkingFlipbook, UPaperFlipbook *newStunnedFlipbook, UPaperFlipbook *newJumpingAttackingFlipbook)
{
	idleFlipbook = newIdleFlipbook;
	walkingFlipbook = newWalkingFlipbook;
	runningFlipbook = newRunningFlipbook;
	jumpingStartFlipbook = newJumpingStartFlipbook;
	jumpingLoopFlipbook = newJumpingLoopFlipbook;
	attackingFlipbook = newAttackingFlipbook;
	damagedFlipbook = newDamagedFlipbook;
	idleDrinkingFlipbook = newIdleDrinkingFlipbook;
	runningDrinkingFlipbook = newRunningDrinkingFlipbook;
	jumpingStartDrinkingFlipbook = newJumpingStartDrinkingFlipbook;
	jumpingLoopDrinkingFlipbook = newJumpingLoopDrinkingFlipbook;
	stunnedFlipbook = newStunnedFlipbook;
	jumpingAttackingFlipbook = newJumpingAttackingFlipbook;
}

//Default constructor.
ADiscoPirate::ADiscoPirate()
	:
	flipbook(CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Flipbook"))),
	attackBox(CreateDefaultSubobject<UBoxComponent>(TEXT("Attack Box")))
{
 	//Setup character.
	CREATEROOT()
	PrimaryActorTick.bCanEverTick = true;

	//Setup character movement.
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintAxisSetting(EPlaneConstraintAxisSetting::X);
	GetCharacterMovement()->MaxAcceleration = 9999.0f;
	GetCharacterMovement()->MaxWalkSpeed = 1000.0f;
	GetCharacterMovement()->JumpZVelocity = 2500.0f;
	GetCharacterMovement()->GravityScale = 5.0f;

	//Setup flipbook component.
	flipbook->SetupAttachment(RootComponent);
	flipbook->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
	flipbook->OnFinishedPlaying.AddDynamic(this, &ADiscoPirate::OnAnimationFinished);

	//Setup attack box component.
	attackBox->SetupAttachment(RootComponent);
	attackBox->SetRelativeScale3D(FVector(2.0f));
	attackBox->OnComponentBeginOverlap.AddDynamic(this, &ADiscoPirate::OnBeginOverlap);
	attackBox->OnComponentEndOverlap.AddDynamic(this, &ADiscoPirate::OnEndOverlap);

	//Set default values.
	hasAttacked = false;
	hasRum = false;
	isStunned = false;
	stunTimer = 0.0f;
}

//Called when the game starts or when spawned.
void ADiscoPirate::BeginPlay()
{
	Super::BeginPlay();

	//Set the current state.
	currentState = States::Idle;

	//Spawn and setup the sound cues.
	klunkAudio = UGameplayStatics::SpawnSoundAtLocation(this, klunkSound, GetActorLocation());
	klunkAudio->Deactivate();
	klunkAudio->bAutoDestroy = false;
	klunkAudio->OnAudioFinished.AddDynamic(this, &ADiscoPirate::OnKlunkAudioFinished);

	skvalpAudio = UGameplayStatics::SpawnSoundAtLocation(this, skvalpSound, GetActorLocation());
	skvalpAudio->Deactivate();
	skvalpAudio->bAutoDestroy = false;

	//Retrieve the reference to the camera.
	TArray<AActor*> cameraActors;
	UGameplayStatics::GetAllActorsOfClass(this, ACamera::StaticClass(), cameraActors);
	camera = Cast<ACamera>(cameraActors[0]);
}

//Called every frame.
void ADiscoPirate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Update pirate rotation and attack box position.
	if (currentState != States::Damaged)
	{
		if (GetVelocity().Y > 0.0f)
		{
			flipbook->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
			attackBox->SetRelativeLocation(FVector(0.0f, 100.0f, 0.0f));
		}

		else if (GetVelocity().Y < 0.0f)
		{
			flipbook->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
			attackBox->SetRelativeLocation(FVector(0.0f, -100.0f, 0.0f));
		}
	}

	//Update the state of the pirate.
	if (currentState != States::Stunned)
	{
		if (currentState == States::Attacking)
		{
			if (flipbook->GetPlaybackPositionInFrames() >= 4)
			{
				PerformAttack();
			}
		}

		else if (currentState == States::JumpingAttacking)
		{
			if (flipbook->GetPlaybackPositionInFrames() >= 4)
			{
				PerformAttack();
			}
		}

		else
		{
			if (CanJump() && currentState != States::Attacking && currentState != States::Damaged)
			{
				flipbook->SetLooping(true);

				if (GetVelocity().Size() == 0.0f)
					currentState = States::Idle;

				else if (GetVelocity().Size() > 0.0f && GetVelocity().Size() < 800.0f)
					currentState = States::Walking;

				else
					currentState = States::Running;
			}

			else if (currentState != States::JumpingStart && currentState != States::Damaged)
			{
				currentState = States::JumpingLoop;
				flipbook->SetLooping(true);
			}
		}
	}

	else
	{
		stunTimer += DeltaTime;

		if (stunTimer >= 3.0f)
		{
			currentState = States::Idle;
			flipbook->SetLooping(true);
		}
	}

	UpdateAnimation();

	//Check if the player needs to be teleported to the other side of the level.
	if (GetActorLocation().Y > levelYBoundary)
		AddActorLocalOffset(FVector(0.0f, (-levelYBoundary * 2), 0.0f));

	else if (GetActorLocation().Y < -levelYBoundary)
		AddActorLocalOffset(FVector(0.0f, (levelYBoundary * 2), 0.0f));

	if (GetActorLocation().Z > levelZBoundary)
		AddActorLocalOffset(FVector(0.0f, 0.0f, (-levelZBoundary * 2)));

	else if (GetActorLocation().Z < -levelZBoundary)
		AddActorLocalOffset(FVector(0.0f, 0.0f, (levelZBoundary * 2)));

	//If this pirate has the rum bottle, play appropriate sounds.
	if (hasRum)
	{
		switch (currentState)
		{
			case States::Idle:
			{
				skvalpAudio->SetVolumeMultiplier(0.5f);

				break;
			}

			case States::Walking:
			{
				skvalpAudio->SetVolumeMultiplier(0.75f);

				break;
			}

			case States::Running:
			{
				skvalpAudio->SetVolumeMultiplier(0.75f);

				break;
			}

			case States::JumpingStart:
			{
				skvalpAudio->SetVolumeMultiplier(1.0f);

				break;
			}

			case States::JumpingLoop:
			{
				skvalpAudio->SetVolumeMultiplier(1.0f);

				break;
			}
		}

		//Also, fill this player's rum meter.
		camera->FillRumMeter(uniquePlayerIndex, DeltaTime);
	}
}

//Called to bind functionality to input.
void ADiscoPirate::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Movement", this, &ADiscoPirate::MoveVertical);
	PlayerInputComponent->BindAction("Attack", EInputEvent::IE_Pressed, this, &ADiscoPirate::InitiateAttack);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ADiscoPirate::InitiateJump);
	PlayerInputComponent->BindAction("Pause", EInputEvent::IE_Pressed, this, &ADiscoPirate::TogglePause);
	PlayerInputComponent->BindAction("Move Up", EInputEvent::IE_Pressed, this, &ADiscoPirate::MoveUpUI);
	PlayerInputComponent->BindAction("Move Down", EInputEvent::IE_Pressed, this, &ADiscoPirate::MoveDownUI);
	PlayerInputComponent->BindAction("Select", EInputEvent::IE_Pressed, this, &ADiscoPirate::OnSelectUI);
}

//Called when pirate has picked up rum.
bool ADiscoPirate::PickUpRum()
{
	if (currentState != States::Stunned)
	{
		hasRum = true;

		UAudioComponent *newPickupBottleSound = UGameplayStatics::SpawnSoundAtLocation(this, pickupBottleSound, GetActorLocation());
		newPickupBottleSound->Play();
		newPickupBottleSound->OnAudioFinished.AddDynamic(this, &ADiscoPirate::OnPickupBottleAudioFinished);

		return true;
	}

	else
		return false;
}

//Called when the pirate gets attacked.
void ADiscoPirate::Attack(AActor *attackingPirate)
{
	if (hasRum)
	{
		hasRum = false;

		skvalpAudio->Stop();

		GetWorld()->SpawnActor<ARumBottle>(rumBottleClass, GetActorLocation() + FVector(0.0f, 0.0f, 500.0f), FRotator::ZeroRotator);

		currentState = States::Stunned;
		flipbook->SetLooping(true);

		stunTimer = 1.0f;
	}

	else if (currentState != States::Stunned)
	{
		currentState = States::Damaged;
		flipbook->SetLooping(false);
	}

	UGameplayStatics::PlaySoundAtLocation(this, damagedSound, GetActorLocation());

	DamagedFallback(attackingPirate);
}