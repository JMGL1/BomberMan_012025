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

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento A�reo")
    FVector CentroMovimiento;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento A�reo")
    FVector DireccionMovimiento;  // Nueva variable para definir la direcci�n de movimiento

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento A�reo")
    float VelocidadVuelo;

private:
    float Tiempo;
};
