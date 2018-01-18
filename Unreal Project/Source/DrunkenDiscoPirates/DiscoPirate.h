// © Copyright Spoonvalley Interactive 2018.

#pragma once

#include "GameFramework/Character.h"
#include "PaperFlipbookComponent.h"
#include "RumBottle.h"
#include "DiscoPirate.generated.h"

//Enumeration for the pirate states.
UENUM(BlueprintType, Category = "Code")
enum class States : uint8
{
	Idle,
	Walking,
	Running,
	JumpingStart,
	JumpingLoop,
	Attacking,
	Damaged,
	Stunned,
	JumpingAttacking
};

//Forward declarations.
class ACamera;

UCLASS()
class DRUNKENDISCOPIRATES_API ADiscoPirate : public ACharacter
{
	GENERATED_BODY()

public:

	//Move vertically.
	UFUNCTION(BlueprintCallable, Category = "Code")
	void MoveVertical(float value);

	//Initiate an attack.
	UFUNCTION(BlueprintCallable, Category = "Code")
	void InitiateAttack();

	//Initiate a jump.
	UFUNCTION(BlueprintCallable, Category = "Code")
	void InitiateJump();

	//Toggles pause.
	void TogglePause();

	//Move up UI.
	void MoveUpUI();

	//Move down UI.
	void MoveDownUI();

	//On select UI.
	void OnSelectUI();

private:

	//The paper flipbook component.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true), Category = "Components")
	UPaperFlipbookComponent *flipbook;

	//The box collision component (used for melee attacks).
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true), Category = "Components")
	UBoxComponent *attackBox;

	//The current state that the pirate is in.
	States currentState;

	//Array containing all attackable pirates.
	TArray<ADiscoPirate*> attackablePirates;

	//Keep track of if this pirate has the rum.
	bool hasRum;

	//Keep track of if the pirate has performed an attack.
	bool hasAttacked;

	//Reference to the spawned klunk component.
	UAudioComponent *klunkAudio;

	//Reference to the spawned skvalp component.
	UAudioComponent *skvalpAudio;

	//Keeps track of if the character is stunned.
	bool isStunned;

	//Keeps track of how long the pirate has been stunned.
	float stunTimer;

	//Update the animation.
	void UpdateAnimation();

	//Perform an attack.
	void PerformAttack();

	//Called on begin overlap.
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	//Called on end overlap.
	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex);

	//Called on animation finish.
	UFUNCTION()
	void OnAnimationFinished();

	//Called on klunk audio finished.
	UFUNCTION()
	void OnKlunkAudioFinished() { if (hasRum && !klunkAudio->IsPlaying()) klunkAudio->Play(); }

	//Called when the pickup bottle sound has finished playing.
	UFUNCTION()
	void OnPickupBottleAudioFinished() { klunkAudio->Play(); skvalpAudio->Play(); }

protected:

	//Reference to the camera.
	ACamera* camera;

	//The player index.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Code")
	int32 uniquePlayerIndex;

	//Reference to the skvalp sound.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Code")
	TSubclassOf<ARumBottle> rumBottleClass;

	//The level Y boundary.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Code")
	float levelYBoundary;

	//The level Z boundary.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Code")
	float levelZBoundary;

	//Reference to the idle flipbook.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flipbooks")
	UPaperFlipbook *idleFlipbook;

	//Reference to the walking flipbook.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flipbooks")
	UPaperFlipbook *walkingFlipbook;

	//Reference to the running flipbook.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flipbooks")
	UPaperFlipbook *runningFlipbook;

	//Reference to the jumping start flipbook.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flipbooks")
	UPaperFlipbook *jumpingStartFlipbook;

	//Reference to the jumping loop flipbook.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flipbooks")
	UPaperFlipbook *jumpingLoopFlipbook;

	//Reference to the attacking flipbook.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flipbooks")
	UPaperFlipbook *attackingFlipbook;

	//Reference to the damaged flipbook.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flipbooks")
	UPaperFlipbook *damagedFlipbook;

	//Reference to the idle drinking flipbook.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flipbooks")
	UPaperFlipbook *idleDrinkingFlipbook;

	//Reference to the running drinking flipbook.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flipbooks")
	UPaperFlipbook *runningDrinkingFlipbook;

	//Reference to the jumping start drinking flipbook.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flipbooks")
	UPaperFlipbook *jumpingStartDrinkingFlipbook;

	//Reference to the jumping loop drinking flipbook.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flipbooks")
	UPaperFlipbook *jumpingLoopDrinkingFlipbook;

	//Reference to the stunned flipbook.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flipbooks")
	UPaperFlipbook *stunnedFlipbook;

	//Reference to the jumping attacking flipbook.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flipbooks")
	UPaperFlipbook *jumpingAttackingFlipbook;

	//Reference to the jumping sound.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sounds")
	USoundBase *jumpingSound;

	//Reference to the attacking sound.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sounds")
	USoundBase *attackingSound;

	//Reference to the damaged sound.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sounds")
	USoundBase *damagedSound;

	//Reference to the klunk sound.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sounds")
	USoundBase *klunkSound;

	//Reference to the skvalp sound.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sounds")
	USoundBase *skvalpSound;

	//Reference to the pickup bottle sound.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sounds")
	USoundBase *pickupBottleSound;

	/*
	*
	*/

	//Call a blueprint timeline to simulate a fallback effect when damaged.
	UFUNCTION(BlueprintImplementableEvent, Category = "Code")
	void DamagedFallback(AActor *attackingPirate);

	//Sets the different flipbooks of this pirate.
	UFUNCTION(BlueprintCallable, Category = "Code")
	void SetFlipbooksImplementation(UPaperFlipbook *newIdleFlipbook, UPaperFlipbook *newWalkingFlipbook, UPaperFlipbook *newRunningFlipbook, UPaperFlipbook *newJumpingStartFlipbook, UPaperFlipbook *newJumpingLoopFlipbook, UPaperFlipbook *newAttackingFlipbook, UPaperFlipbook *newDamagedFlipbook, UPaperFlipbook *newIdleDrinkingFlipbook, UPaperFlipbook *newRunningDrinkingFlipbook, UPaperFlipbook *newJumpingStartDrinkingFlipbook, UPaperFlipbook *newJumpingLoopDrinkingFlipbook, UPaperFlipbook *newStunnedFlipbook, UPaperFlipbook *newJumpingAttackingFlipbook);

public:

	//Default constructor.
	ADiscoPirate();

	//Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	//Called every frame.
	virtual void Tick(float DeltaTime) override;

	//Called to bind functionality to input.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Blueprint implementable event of the set flipbooks function.
	UFUNCTION(BlueprintImplementableEvent, Category = "Code")
	void SetFlipbooks(int32 playerIndex);

	//Called when pirate has picked up rum.
	UFUNCTION(BlueprintCallable, Category = "Code")
	bool PickUpRum();

	//Called when the pirate gets attacked.
	UFUNCTION(BlueprintCallable, Category = "Code")
	void Attack(AActor *attackingPirate);
};