// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DRUNKENDISCOPIRATES_AnimatedImage_generated_h
#error "AnimatedImage.generated.h already included, missing '#pragma once' in AnimatedImage.h"
#endif
#define DRUNKENDISCOPIRATES_AnimatedImage_generated_h

#define Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execStop) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Stop(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlay) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Play(); \
		P_NATIVE_END; \
	}


#define Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStop) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Stop(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlay) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Play(); \
		P_NATIVE_END; \
	}


#define Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h_14_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUAnimatedImage(); \
	friend DRUNKENDISCOPIRATES_API class UClass* Z_Construct_UClass_UAnimatedImage(); \
	public: \
	DECLARE_CLASS(UAnimatedImage, UImage, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/DrunkenDiscoPirates"), NO_API) \
	DECLARE_SERIALIZER(UAnimatedImage) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h_14_INCLASS \
	private: \
	static void StaticRegisterNativesUAnimatedImage(); \
	friend DRUNKENDISCOPIRATES_API class UClass* Z_Construct_UClass_UAnimatedImage(); \
	public: \
	DECLARE_CLASS(UAnimatedImage, UImage, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/DrunkenDiscoPirates"), NO_API) \
	DECLARE_SERIALIZER(UAnimatedImage) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAnimatedImage(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAnimatedImage) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAnimatedImage); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAnimatedImage); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAnimatedImage(UAnimatedImage&&); \
	NO_API UAnimatedImage(const UAnimatedImage&); \
public:


#define Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAnimatedImage(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAnimatedImage(UAnimatedImage&&); \
	NO_API UAnimatedImage(const UAnimatedImage&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAnimatedImage); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAnimatedImage); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAnimatedImage)


#define Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__images() { return STRUCT_OFFSET(UAnimatedImage, images); } \
	FORCEINLINE static uint32 __PPO__framesPerSecond() { return STRUCT_OFFSET(UAnimatedImage, framesPerSecond); } \
	FORCEINLINE static uint32 __PPO__shouldLoop() { return STRUCT_OFFSET(UAnimatedImage, shouldLoop); } \
	FORCEINLINE static uint32 __PPO__loopStart() { return STRUCT_OFFSET(UAnimatedImage, loopStart); } \
	FORCEINLINE static uint32 __PPO__loopEnd() { return STRUCT_OFFSET(UAnimatedImage, loopEnd); }


#define Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h_11_PROLOG
#define Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h_14_PRIVATE_PROPERTY_OFFSET \
	Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h_14_RPC_WRAPPERS \
	Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h_14_INCLASS \
	Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h_14_PRIVATE_PROPERTY_OFFSET \
	Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h_14_INCLASS_NO_PURE_DECLS \
	Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Unreal_Project_Source_DrunkenDiscoPirates_AnimatedImage_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS