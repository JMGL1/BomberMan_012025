// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberMan_012025GameMode.h"
#include "BomberMan_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"
#include "Bloque.h"
#include "BloqueBurbuja.h"
#include "BloqueAcero.h"
#include "BloqueConcreto.h"
#include "BloqueLadrillo.h"
#include "BloqueMadera.h"
#include "BloqueHielo.h"
#include "BloqueVidrio.h"
#include "BloqueOro.h"
#include "BloquePasto.h"
#include "BloqueAgua.h"
#include "EnemigoAereo.h"
#include "EnemigoTerrestre.h"
#include "Engine/World.h"
#include "EnemigoSubterraneo.h"
#include "EnemigoAcuatico.h"
#include "SueloDeAgua.h"
#include "EnemigoTest.h"
#include "PowerUpTest.h"
#include "Math/UnrealMathUtility.h"


ABomberMan_012025GameMode::ABomberMan_012025GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ABomberMan_012025GameMode::BeginPlay()
{
	Super::BeginPlay();

	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Bloque Spawning"));
	//Suelo
	
	SpawnSuelo();

	// Recorremos la matriz para generar los bloques
	for (int32 fila = 0; fila < aMapaBloques.Num(); ++fila)
	{
		for (int32 columna = 0; columna < aMapaBloques[fila].Num(); ++columna)
		{
			int32 valor = aMapaBloques[fila][columna];
			if (valor != 0) // Si no es espacio vacío
			{
				// Calculamos la posición del bloque
				FVector posicionBloque = FVector(
					XInicial + columna * AnchoBloque,
					YInicial + fila * LargoBloque,
					0.0f); // Z queda en 0 (altura del bloque)

				// Llamamos a la función para generar un bloque
				SpawnBloque(posicionBloque, valor);
			}
		}
	}

	//SPAWN DE ENEMIGOS
	// Spawn de enemigos terrestres
	FVector UbicacionTerrestre1 = FVector(860.0f, 3550.0f, 20.0f);
	FVector UbicacionTerrestre2 = FVector(860.0f, 5500.0f, 20.0f);
	SpawnearEnemigoTerrestre(UbicacionTerrestre1);
	SpawnearEnemigoTerrestre(UbicacionTerrestre2);

	// Spawn de enemigos aéreos
	FVector UbicacionAerea1 = FVector(860.0f, 3550.0f, 300.0f);
	FVector UbicacionAerea2 = FVector(860.0f, 5500.0f, 300.0f);
	SpawnearEnemigoAereo(UbicacionAerea1);
	SpawnearEnemigoAereo(UbicacionAerea2);

	// Spawnear enemigos subterráneos
	FVector UbicacionSubterranea1 = FVector(860.0f, 2290.0f, 5.0f);
	FVector UbicacionSubterranea2 = FVector(860.0f, 5800.0f, 5.0f);
	SpawnearEnemigoSubterraneo(UbicacionSubterranea1);
	SpawnearEnemigoSubterraneo(UbicacionSubterranea2);

	//Spawn de enemigos acuáticos
	FVector UbicacionAcuatico1 = FVector(1370.0f, 1950.0f, FMath::RandRange(100.0f, 300.0f));
	FVector UbicacionAcuatico2 = FVector(840.0f, 6800.0f, FMath::RandRange(100.0f, 300.0f));
	SpawnearEnemigoAcuatico(UbicacionAcuatico1);
	SpawnearEnemigoAcuatico(UbicacionAcuatico2);

	// Spawn de enemigos de prueba
	FVector UbicacionTest = FVector(1080.0f, 2320.0f, 100.0f);
	SpawnEnemigosTest(UbicacionTest);

	// Spawn de power-ups
	FVector UbicacionPowerUp = FVector(1080.0f, 2500.0f, 100.0f);
	FVector UbicacionPowerUp2 = FVector(1080.0f, 3700.0f, 100.0f);
	SpawnPowerUp(UbicacionPowerUp);
	SpawnPowerUp(UbicacionPowerUp2);

}

void ABomberMan_012025GameMode::SpawnSuelo() {
	// Código para spawnear bloques
	UWorld* Mundo = GetWorld();
	if (Mundo) {
		Mundo->SpawnActor<ASueloDeAgua>(ASueloDeAgua::StaticClass(), FVector(7960.0f, 5460.0f, -50.0f), FRotator::ZeroRotator);
	}
}

void ABomberMan_012025GameMode::SpawnBloque(FVector posicionBloque, int32 tipoBloque)
{
	//ABloque* BloqueGenerado = nullptr;

	ABloque* BloqueGenerado = nullptr;
	// Elegir tipo de bloque basado en el valor
	if (tipoBloque == 10)
	{
		BloqueGenerado = GetWorld()->SpawnActor<ABloqueAgua>(ABloqueAgua::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque == 9)
	{
		BloqueGenerado = GetWorld()->SpawnActor<ABloquePasto>(ABloquePasto::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque == 8)
	{
		BloqueGenerado = GetWorld()->SpawnActor<ABloqueOro>(ABloqueOro::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque == 7)
	{
		BloqueGenerado = GetWorld()->SpawnActor<ABloqueVidrio>(ABloqueVidrio::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque == 6)
	{
		BloqueGenerado = GetWorld()->SpawnActor<ABloqueLadrillo>(ABloqueLadrillo::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque == 5)
	{
		BloqueGenerado = GetWorld()->SpawnActor<ABloqueBurbuja>(ABloqueBurbuja::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque == 4)
	{
		BloqueGenerado = GetWorld()->SpawnActor<ABloqueAcero>(ABloqueAcero::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque == 3)
	{
		BloqueGenerado = GetWorld()->SpawnActor<ABloqueConcreto>(ABloqueConcreto::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque == 2)
	{
		BloqueGenerado = GetWorld()->SpawnActor<ABloqueHielo>(ABloqueHielo::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque == 1)
	{
		BloqueGenerado = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
	}
	else {
		return;
	}
	// Agregar el bloque al TArray si fue generado
	if (BloqueGenerado)
	{
		aBloques.Add(BloqueGenerado);
	}

}

void ABomberMan_012025GameMode::DestruirBloque()
{
	/*
	//Seleccionar aleatoriamente un bloque del array ABloques para su eliminacion
	int numeroBloques = aBloques.Num();
	int NumeroAleatorio = FMath::RandRange(1, numeroBloques);

	if (aBloques.Num() > 0)
	{
		BloqueActual = aBloques[NumeroAleatorio]; // Obtén el primer bloque
		if (BloqueActual)
		{
			BloqueActual->Destroy();
			// Realiza operaciones con el bloque
			//primerBloque->SetActorLocation(FVector(100.0f, 100.0f, 100.0f));
		}
	}
	*/
}

void ABomberMan_012025GameMode::SpawnearEnemigoTerrestre(FVector UbicacionTerrestre)
{
	// Código para spawnear enemigos
	//FVector PosicionInicial1 = FVector(1000.0f, 1000.0f, 120.0f); // Cambia según lo que necesites
	FRotator RotacionInicial1 = FRotator::ZeroRotator;

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	// Spawnea el enemigo
	AEnemigoTerrestre* Enemigo = GetWorld()->SpawnActor<AEnemigoTerrestre>(
		AEnemigoTerrestre::StaticClass(),
		UbicacionTerrestre,
		RotacionInicial1,
		SpawnParams
	);

	if (Enemigo)
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemigo terrestre creado correctamente."));

		//Añadimos el enemigo a la lista de enemigos
		aEnemigos.Add(Enemigo);

	}
}

void ABomberMan_012025GameMode::SpawnearEnemigoAereo(FVector UbicacionAereo) {
	UWorld* Mundo = GetWorld();
	if (Mundo)
	{
		FVector Ubicacion = FVector(0.0f, 0.0f, 300.0f);
		FRotator Rotacion = FRotator(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters ParametrosSpawn;

		AEnemigoAereo* Enemigo = Mundo->SpawnActor<AEnemigoAereo>(AEnemigoAereo::StaticClass(), Ubicacion, Rotacion, ParametrosSpawn);

		if (Enemigo)
		{
			UE_LOG(LogTemp, Warning, TEXT("¡Enemigo Aéreo spawneado exitosamente en la ubicación: %s!"), *Ubicacion.ToString());
			//Añadimos el enemigo a la lista de enemigos
			aEnemigos.Add(Enemigo);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Error al spawnear Enemigo Aéreo."));
		}
	}
}

void ABomberMan_012025GameMode::SpawnearEnemigoSubterraneo(FVector Ubicacion) {
	UWorld* Mundo = GetWorld();
	if (Mundo)
	{
		//FVector Ubicacion = FVector(2000.0f, 2000.0f, -50.0f);
		FRotator Rotacion = FRotator::ZeroRotator;
		FActorSpawnParameters ParametrosSpawn;
		AEnemigoSubterraneo* EnemigoSubterraneo = Mundo->SpawnActor<AEnemigoSubterraneo>(AEnemigoSubterraneo::StaticClass(), Ubicacion, Rotacion, ParametrosSpawn);
		if (EnemigoSubterraneo)
		{
			UE_LOG(LogTemp, Warning, TEXT("¡Enemigo Subterráneo spawneado exitosamente en la ubicación: %s!"), *Ubicacion.ToString());
			//Añadimos el enemigo a la lista de enemigos
			aEnemigos.Add(EnemigoSubterraneo);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Error al spawnear Enemigo Subterráneo."));
		}
	}
}

void ABomberMan_012025GameMode::SpawnearEnemigoAcuatico(FVector UbicacionAcuatico)
{
	UWorld* Mundo = GetWorld();
	if (Mundo)
	{
		//FVector UbicacionAcuatico = FVector(860.0f, 2360.0f, FMath::RandRange(100.0f, 300.0f)); // En rango medio
		FRotator RotacionAcuatico = FRotator::ZeroRotator;
		FActorSpawnParameters ParametrosSpawnAcuatico;

		AEnemigoAcuatico* EnemigoAcuatico = Mundo->SpawnActor<AEnemigoAcuatico>(AEnemigoAcuatico::StaticClass(), UbicacionAcuatico, RotacionAcuatico, ParametrosSpawnAcuatico);

		if (EnemigoAcuatico)
		{
			UE_LOG(LogTemp, Warning, TEXT("¡Enemigo Acuático spawneado exitosamente en la ubicación: %s!"), *UbicacionAcuatico.ToString());
			//Añadimos el enemigo a la lista de enemigos
			aEnemigos.Add(EnemigoAcuatico);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Error al spawnear Enemigo Acuático."));
		}
	}
}

void ABomberMan_012025GameMode::SpawnEnemigosTest(FVector Ubicacion) {
	
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		AEnemigoTest* Enemigo = GetWorld()->SpawnActor<AEnemigoTest>(
			AEnemigoTest::StaticClass(),
			Ubicacion,
			FRotator::ZeroRotator,
			SpawnParams
		);
		

	
}

void ABomberMan_012025GameMode::SpawnPowerUp(FVector ubi)
{
	UWorld* Mundo = GetWorld();
	if (Mundo) {
		Mundo->SpawnActor<APowerUpTest>(APowerUpTest::StaticClass(), ubi, FRotator::ZeroRotator);
	}
}









//int numeroBloqueConMovimiento = 0;

/*
for (int i = 0; i < 20; i++)
{

	ABloque* bloque = GetWorld()->SpawnActor<ABloque>(ABloque::StaticClass(), FVector(500.0f + i * 100 , 2500.0f - i * 100, 20.0f), FRotator(0.0f, 0.0f, 0.0f));
		
	
	if (bloque->bPuedeMoverse)
	{
		numeroBloqueConMovimiento++;
	}

	if (numeroBloqueConMovimiento >= 6)
	{
		bloque->bPuedeMoverse = false;
	}

}
*/
//SpawnBloques();


/*
void ABomberMan_012025GameMode::SpawnBloques()
{
	// recorrer el array de bloques y hacer spawn de cada uno
	for (int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if (aMapaBloques[i][j] == 1)
			{
				FVector PosicionBloque = FVector()
				ABloqueLadrillo* BloqueLadrillo = GetWorld()->SpawnActor<ABloqueLadrillo>(ABloqueLadrillo::StaticClass(), FVector(posicionSiguienteBloque.X + j * AnchoBloque, posicionSiguienteBloque.Y - i * LargoBloque, posicionSiguienteBloque.Z), FRotator(0.0f, 0.0f, 0.0f));
		*/		/*if (BloqueLadrillo)
				{
					aBloques.Add(static_cast<ABloque*>(BloqueLadrillo));
				}*/
	/*		}
		}
		//ABloque* bloque = GetWorld()->SpawnActor<ABloque>(ABloque::StaticClass(), FVector(500.0f + i * 100, 2500.0f - i * 100, 20.0f), FRotator(0.0f, 0.0f, 0.0f));
	}
}
*/