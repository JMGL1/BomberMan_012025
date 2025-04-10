// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/EnemigoAcuatico.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemigoAcuatico() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigo();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigoAcuatico();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigoAcuatico_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class AEnemigoAcuatico
void AEnemigoAcuatico::StaticRegisterNativesAEnemigoAcuatico()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemigoAcuatico);
UClass* Z_Construct_UClass_AEnemigoAcuatico_NoRegister()
{
	return AEnemigoAcuatico::StaticClass();
}
struct Z_Construct_UClass_AEnemigoAcuatico_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "EnemigoAcuatico.h" },
		{ "ModuleRelativePath", "EnemigoAcuatico.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AmplitudOscilacion_MetaData[] = {
		{ "Category", "Movimiento" },
		{ "ModuleRelativePath", "EnemigoAcuatico.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrecuenciaOscilacion_MetaData[] = {
		{ "Category", "Movimiento" },
		{ "ModuleRelativePath", "EnemigoAcuatico.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DireccionMovimiento_MetaData[] = {
		{ "Category", "Movimiento" },
		{ "ModuleRelativePath", "EnemigoAcuatico.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanciaMaxima_MetaData[] = {
		{ "Category", "Movimiento" },
		{ "ModuleRelativePath", "EnemigoAcuatico.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AmplitudOscilacion;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FrecuenciaOscilacion;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DireccionMovimiento;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DistanciaMaxima;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemigoAcuatico>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemigoAcuatico_Statics::NewProp_AmplitudOscilacion = { "AmplitudOscilacion", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemigoAcuatico, AmplitudOscilacion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AmplitudOscilacion_MetaData), NewProp_AmplitudOscilacion_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemigoAcuatico_Statics::NewProp_FrecuenciaOscilacion = { "FrecuenciaOscilacion", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemigoAcuatico, FrecuenciaOscilacion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrecuenciaOscilacion_MetaData), NewProp_FrecuenciaOscilacion_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEnemigoAcuatico_Statics::NewProp_DireccionMovimiento = { "DireccionMovimiento", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemigoAcuatico, DireccionMovimiento), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DireccionMovimiento_MetaData), NewProp_DireccionMovimiento_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemigoAcuatico_Statics::NewProp_DistanciaMaxima = { "DistanciaMaxima", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemigoAcuatico, DistanciaMaxima), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanciaMaxima_MetaData), NewProp_DistanciaMaxima_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemigoAcuatico_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigoAcuatico_Statics::NewProp_AmplitudOscilacion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigoAcuatico_Statics::NewProp_FrecuenciaOscilacion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigoAcuatico_Statics::NewProp_DireccionMovimiento,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigoAcuatico_Statics::NewProp_DistanciaMaxima,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoAcuatico_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEnemigoAcuatico_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AEnemigo,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoAcuatico_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemigoAcuatico_Statics::ClassParams = {
	&AEnemigoAcuatico::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AEnemigoAcuatico_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoAcuatico_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoAcuatico_Statics::Class_MetaDataParams), Z_Construct_UClass_AEnemigoAcuatico_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEnemigoAcuatico()
{
	if (!Z_Registration_Info_UClass_AEnemigoAcuatico.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemigoAcuatico.OuterSingleton, Z_Construct_UClass_AEnemigoAcuatico_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEnemigoAcuatico.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<AEnemigoAcuatico>()
{
	return AEnemigoAcuatico::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemigoAcuatico);
AEnemigoAcuatico::~AEnemigoAcuatico() {}
// End Class AEnemigoAcuatico

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Magne_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_EnemigoAcuatico_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEnemigoAcuatico, AEnemigoAcuatico::StaticClass, TEXT("AEnemigoAcuatico"), &Z_Registration_Info_UClass_AEnemigoAcuatico, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemigoAcuatico), 3954846409U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Magne_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_EnemigoAcuatico_h_1975423226(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_Users_Magne_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_EnemigoAcuatico_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Magne_Documents_Unreal_Projects_BomberMan_012025_Source_BomberMan_012025_EnemigoAcuatico_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
