// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoSubterraneo.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigoSubterraneo : public AEnemigo
{
	GENERATED_BODY()
	
public:
    AEnemigoSubterraneo();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visual")
    UStaticMeshComponent* ConoMesh;

    FVector PuntosPatrulla[4];
    int PuntoActual;

    UPROPERTY(EditAnywhere, Category = "Movimiento")
    float Velocidad;

    UPROPERTY(EditAnywhere, Category = "Movimiento")
    float AnchoRectangulo;

    UPROPERTY(EditAnywhere, Category = "Movimiento")
    float AltoRectangulo;

    FVector PuntoInicial;
};