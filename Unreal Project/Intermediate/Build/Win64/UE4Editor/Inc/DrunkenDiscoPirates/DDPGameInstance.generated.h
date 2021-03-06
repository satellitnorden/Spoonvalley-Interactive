// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef DRUNKENDISCOPIRATES_DDPGameInstance_generated_h
#error "DDPGameInstance.generated.h already included, missing '#pragma once' in DDPGameInstance.h"
#endif
#define DRUNKENDISCOPIRATES_DDPGameInstance_generated_h

#define Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetPlayerCount) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_newPlayerCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetPlayerCount(Z_Param_newPlayerCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPlayerCount) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=this->GetPlayerCount(); \
		P_NATIVE_END; \
	}


#define Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetPlayerCount) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_newPlayerCount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetPlayerCount(Z_Param_newPlayerCount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPlayerCount) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=this->GetPlayerCount(); \
		P_NATIVE_END; \
	}


#define Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUDDPGameInstance(); \
	friend DRUNKENDISCOPIRATES_API class UClass* Z_Construct_UClass_UDDPGameInstance(); \
	public: \
	DECLARE_CLASS(UDDPGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/DrunkenDiscoPirates"), NO_API) \
	DECLARE_SERIALIZER(UDDPGameInstance) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesUDDPGameInstance(); \
	friend DRUNKENDISCOPIRATES_API class UClass* Z_Construct_UClass_UDDPGameInstance(); \
	public: \
	DECLARE_CLASS(UDDPGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/DrunkenDiscoPirates"), NO_API) \
	DECLARE_SERIALIZER(UDDPGameInstance) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDDPGameInstance(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDDPGameInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDDPGameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDDPGameInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDDPGameInstance(UDDPGameInstance&&); \
	NO_API UDDPGameInstance(const UDDPGameInstance&); \
public:


#define Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDDPGameInstance(UDDPGameInstance&&); \
	NO_API UDDPGameInstance(const UDDPGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDDPGameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDDPGameInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDDPGameInstance)


#define Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h_11_PRIVATE_PROPERTY_OFFSET
#define Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h_8_PROLOG
#define Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h_11_PRIVATE_PROPERTY_OFFSET \
	Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h_11_RPC_WRAPPERS \
	Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h_11_INCLASS \
	Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h_11_PRIVATE_PROPERTY_OFFSET \
	Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h_11_INCLASS_NO_PURE_DECLS \
	Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Unreal_Project_Source_DrunkenDiscoPirates_DDPGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
