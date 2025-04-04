// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAereo.generated.h"
class UStaticMeshComponent;
/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigoAereo : public AEnemigo
{
	GENERATED_BODY()

public:
    AEnemigoAereo();
protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;


    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
    UStaticMeshComponent* MallaAereo;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento A�reo")
    FVector CentroMovimiento;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento A�reo")
    float LimiteMovimiento;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento A�reo")
    float AlturaVuelo;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento A�reo")
    float VelocidadVuelo;

private:
	float Tiempo;
};
