// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/GestorDeEnemigos.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGestorDeEnemigos() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AGestorDeEnemigos();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AGestorDeEnemigos_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class AGestorDeEnemigos
void AGestorDeEnemigos::StaticRegisterNativesAGestorDeEnemigos()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGestorDeEnemigos);
UClass* Z_Construct_UClass_AGestorDeEnemigos_NoRegister()
{
	return AGestorDeEnemigos::StaticClass();
}
struct Z_Construct_UClass_AGestorDeEnemigos_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "GestorDeEnemigos.h" },
		{ "ModuleRelativePath", "GestorDeEnemigos.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGestorDeEnemigos>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AGestorDeEnemigos_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGestorDeEnemigos_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AGestorDeEnemigos_Statics::ClassParams = {
	&AGestorDeEnemigos::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGestorDeEnemigos_Statics::Class_MetaDataParams), Z_Construct_UClass_AGestorDeEnemigos_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AGestorDeEnemigos()
{
	if (!Z_Registration_Info_UClass_AGestorDeEnemigos.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGestorDeEnemigos.OuterSingleton, Z_Construct_UClass_AGestorDeEnemigos_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AGestorDeEnemigos.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<AGestorDeEnemigos>()
{
	return AGestorDeEnemigos::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AGestorDeEnemigos);
AGestorDeEnemigos::~AGestorDeEnemigos() {}
// End Class AGestorDeEnemigos

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Magne_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_GestorDeEnemigos_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGestorDeEnemigos, AGestorDeEnemigos::StaticClass, TEXT("AGestorDeEnemigos"), &Z_Registration_Info_UClass_AGestorDeEnemigos, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGestorDeEnemigos), 2048100508U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Magne_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_GestorDeEnemigos_h_1733728772(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_Magne_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_GestorDeEnemigos_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Magne_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_GestorDeEnemigos_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
