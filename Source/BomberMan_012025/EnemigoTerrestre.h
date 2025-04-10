// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoTerrestre.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigoTerrestre : public AEnemigo
{
	GENERATED_BODY()
public:
    AEnemigoTerrestre();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
    UStaticMeshComponent* MallaTerrestre;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
    FVector DireccionMovimiento;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
    float VelocidadVuelo;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
    float DistanciaMaxima; // Distancia máxima antes de regresar

private:
    FVector PosicionInicial;
};