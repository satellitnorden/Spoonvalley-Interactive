// © Copyright Spoonvalley Interactive 2018.

#include "DrunkenDiscoPirates.h"
#include "AnimatedImage.h"

void UAnimatedImage::UpdateFrame()
{
	int32 endFrame = images.Num() - 1 > loopEnd ? loopEnd : images.Num() - 1;

	if (currentFrame + 1 == endFrame)
	{
		if (shouldLoop)
		{
			currentFrame = loopStart;
		}

		else
		{
			Stop();
		}
	}

	else
	{
		++currentFrame;
	}

	UpdateImage();
}

void UAnimatedImage::Play()
{
	if (!isPlaying)
	{
		isPlaying = true;

		Reset();
		UpdateImage();
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UAnimatedImage::UpdateFrame, 1.0f / framesPerSecond, true);
	}
}

void UAnimatedImage::Stop()
{
	GetWorld()->GetTimerManager().ClearTimer(timerHandle);
	isPlaying = false;
}

void UAnimatedImage::Reset()
{
	currentFrame = 0;
}

void UAnimatedImage::UpdateImage()
{
	SetBrushFromTexture(images[currentFrame]);
}