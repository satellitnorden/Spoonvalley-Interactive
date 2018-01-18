// © Copyright Spoonvalley Interactive 2018.

#pragma once

#include "GameFramework/Pawn.h"
#include "Camera.generated.h"

UCLASS()
class DRUNKENDISCOPIRATES_API ACamera : public APawn
{
	GENERATED_BODY()

public:

	//Default constructor.
	ACamera();

	//Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	//Called every frame.
	virtual void Tick(float DeltaTime) override;

	//Called to bind functionality to input.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Called to fill up the rum meter for a specific player.
	UFUNCTION(BlueprintImplementableEvent, Category = "Code")
	void FillRumMeter(int32 playerIndex, float deltaTime);

	//On pause.
	UFUNCTION(BlueprintImplementableEvent, Category = "Code")
	void TogglePause(int32 playerIndex);

	//Move up UI.
	UFUNCTION(BlueprintImplementableEvent, Category = "Code")
	void MoveUpUI(int32 playerIndex);

	//Move down UI.
	UFUNCTION(BlueprintImplementableEvent, Category = "Code")
	void MoveDownUI(int32 playerIndex);

	//On select UI.
	UFUNCTION(BlueprintImplementableEvent, Category = "Code")
	void OnSelectUI(int32 playerIndex);

protected:

	//Defines whether or not the game is paused.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Code")
	bool isPaused;

	//The index of the player that has currently paused the game.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Code")
	int32 currentlyPausedPlayerIndex;

private:

	//The camera component.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true), Category = "Components")
	UCameraComponent *camera;

};