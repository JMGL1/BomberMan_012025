// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/CapsulaEnergia.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCapsulaEnergia() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ACapsula();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ACapsulaEnergia();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ACapsulaEnergia_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ACapsulaEnergia
void ACapsulaEnergia::StaticRegisterNativesACapsulaEnergia()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACapsulaEnergia);
UClass* Z_Construct_UClass_ACapsulaEnergia_NoRegister()
{
	return ACapsulaEnergia::StaticClass();
}
struct Z_Construct_UClass_ACapsulaEnergia_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "CapsulaEnergia.h" },
		{ "ModuleRelativePath", "CapsulaEnergia.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACapsulaEnergia>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ACapsulaEnergia_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACapsula,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACapsulaEnergia_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACapsulaEnergia_Statics::ClassParams = {
	&ACapsulaEnergia::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACapsulaEnergia_Statics::Class_MetaDataParams), Z_Construct_UClass_ACapsulaEnergia_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACapsulaEnergia()
{
	if (!Z_Registration_Info_UClass_ACapsulaEnergia.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACapsulaEnergia.OuterSingleton, Z_Construct_UClass_ACapsulaEnergia_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACapsulaEnergia.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ACapsulaEnergia>()
{
	return ACapsulaEnergia::StaticClass();
}
ACapsulaEnergia::ACapsulaEnergia() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACapsulaEnergia);
ACapsulaEnergia::~ACapsulaEnergia() {}
// End Class ACapsulaEnergia

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Magne_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_CapsulaEnergia_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACapsulaEnergia, ACapsulaEnergia::StaticClass, TEXT("ACapsulaEnergia"), &Z_Registration_Info_UClass_ACapsulaEnergia, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACapsulaEnergia), 2543818118U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Magne_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_CapsulaEnergia_h_1466412528(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_Magne_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_CapsulaEnergia_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Magne_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_CapsulaEnergia_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
