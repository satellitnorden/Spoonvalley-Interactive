// © Copyright Spoonvalley Interactive 2018.

#pragma once

#include "Components/Image.h"
#include "AnimatedImage.generated.h"

/**
 * 
 */
UCLASS()
class DRUNKENDISCOPIRATES_API UAnimatedImage : public UImage
{
	GENERATED_BODY()

protected:

	void UpdateFrame();

	UFUNCTION(BlueprintCallable, Category = "Animation")
	void Play();
	
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void Stop();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	TArray<UTexture2D*> images;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	float framesPerSecond;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	bool shouldLoop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	int32 loopStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	int32 loopEnd;

private:

	int32 currentFrame{ 0 };
	FTimerHandle timerHandle{ };
	bool isPlaying{ false };

	void Reset();
	void UpdateImage();

};
