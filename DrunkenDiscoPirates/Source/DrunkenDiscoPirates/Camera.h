// © Copyright Spoonvalley Interactive 2018.

#pragma once

#include "GameFramework/Pawn.h"
#include "Camera.generated.h"

UCLASS()
class DRUNKENDISCOPIRATES_API ACamera : public APawn
{
	GENERATED_BODY()

private:

	//The camera component.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true), Category = "Components")
	UCameraComponent *camera;

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

};