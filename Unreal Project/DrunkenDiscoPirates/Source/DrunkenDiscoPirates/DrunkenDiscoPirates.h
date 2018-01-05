// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"

//Default content.

#define CREATEROOT() if (!RootComponent) RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

#define PRINTSTRING(STRINGTOPRINT) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, STRINGTOPRINT);

#define GETMATERIALASSET(PATH) ConstructorHelpers::FObjectFinder<UMaterial> assetObject(TEXT(PATH)).Object;

#define COMPONENTSIGNATURE UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true), Category = "Components")