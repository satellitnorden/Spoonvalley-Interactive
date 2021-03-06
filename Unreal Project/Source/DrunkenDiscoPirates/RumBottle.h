// © Copyright Spoonvalley Interactive 2018.

#pragma once

#include "GameFramework/Actor.h"
#include "PaperFlipbookComponent.h"
#include "RumBottle.generated.h"

UCLASS()
class DRUNKENDISCOPIRATES_API ARumBottle : public AActor
{
	GENERATED_BODY()
	
private:

	//The capsule collision component.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true), Category = "Components")
	UCapsuleComponent *capsuleCollision;

	//The rum bottle flipbook component.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true), Category = "Components")
	UPaperFlipbookComponent *rumFlipbook;

protected:

	//The level Y boundary.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Code")
	float levelYBoundary;

	//The level Z boundary.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Code")
	float levelZBoundary;

public:	

	//Default constructor.
	ARumBottle();

	//Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	//Called every frame.
	virtual void Tick(float DeltaTime) override;
	
};