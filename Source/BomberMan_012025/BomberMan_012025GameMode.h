// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BomberMan_012025GameMode.generated.h"

class ABloque;
class ABloqueLadrillo;

UCLASS(minimalapi)
class ABomberMan_012025GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABomberMan_012025GameMode();

public: 
	virtual void BeginPlay() override;

public:
	// Declarar la posici�n del siguiente bloque
	FVector posicionSiguienteBloque = FVector(1000.0f, 500.0f, 20.0f);

	// Declarar un mapa de bloques como un array bidimensional
	TArray<TArray<int32>> aMapaBloques = {
		{4, 4, 4, 4, 4, 4, 4, 4},
		{4, 0, 0, 0, 0, 0, 0, 4},
		{4, 1, 1, 1, 1, 1, 5, 4},
		{4, 0, 0, 0, 0, 0, 0, 4},
		{4, 5, 2, 2, 2, 2, 2, 4},
		{4, 0, 0, 0, 0, 0, 0, 4},
		{4, 3, 3, 3, 3, 3, 5, 4},
		{4, 4, 4, 4, 4, 4, 4, 4},
	};

	float XInicial = 500.00f;
	float YInicial = 500.00f;
	float AnchoBloque = 100.0f;
	float LargoBloque = 100.0f;
	ABloque* BloqueActual = nullptr;
	// Declarar un array de punteros a objetos de tipo BloqueMadera
	TArray<ABloque*> aBloques;
	
	FTimerHandle tHDestruirBloques;

	//void SpawnBloques();
	void SpawnBloque(FVector posicion, int32 tipoBloque);
	void DestruirBloque();
};

/*
for (AActor* bloque : aBloques)
{
	if (bloque)
	{
		// Haz algo con cada bloque
		bloque->Destroy(); // Ejemplo: destruir el bloque
	}
}*/

/*
if (aBloques.Num() > 0)
{
	AActor* primerBloque = aBloques[0]; // Obt�n el primer bloque
	if (primerBloque)
	{
		// Realiza operaciones con el bloque
		primerBloque->SetActorLocation(FVector(100.0f, 100.0f, 100.0f));
	}
}
*/

