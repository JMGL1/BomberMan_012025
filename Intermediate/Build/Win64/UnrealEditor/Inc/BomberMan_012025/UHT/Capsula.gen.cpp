// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/Capsula.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCapsula() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ACapsula();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ACapsula_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ACapsula
void ACapsula::StaticRegisterNativesACapsula()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACapsula);
UClass* Z_Construct_UClass_ACapsula_NoRegister()
{
	return ACapsula::StaticClass();
}
struct Z_Construct_UClass_ACapsula_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Capsula.h" },
		{ "ModuleRelativePath", "Capsula.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACapsula>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ACapsula_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACapsula_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACapsula_Statics::ClassParams = {
	&ACapsula::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACapsula_Statics::Class_MetaDataParams), Z_Construct_UClass_ACapsula_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACapsula()
{
	if (!Z_Registration_Info_UClass_ACapsula.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACapsula.OuterSingleton, Z_Construct_UClass_ACapsula_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACapsula.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ACapsula>()
{
	return ACapsula::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACapsula);
ACapsula::~ACapsula() {}
// End Class ACapsula

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Magne_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Capsula_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACapsula, ACapsula::StaticClass, TEXT("ACapsula"), &Z_Registration_Info_UClass_ACapsula, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACapsula), 2503646718U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Magne_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Capsula_h_2763623380(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_Magne_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Capsula_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Magne_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_Capsula_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
