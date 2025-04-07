// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAcuatico.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigoAcuatico : public AEnemigo
{
	GENERATED_BODY()
	
public:
    // Constructor
    AEnemigoAcuatico();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

public:
    UStaticMeshComponent* MallaAcuatica;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
    float AmplitudOscilacion;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
    float FrecuenciaOscilacion;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
    FVector DireccionMovimiento;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
    float DistanciaMaxima; // Límite antes de cambiar dirección

    FVector PosicionInicial;
};