// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloquePasto.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloquePasto : public ABloque
{
	GENERATED_BODY()
	
protected:
	ABloquePasto();
	virtual void BeginPlay();
	    virtual void Tick(float DeltaTime) override;

private:
    FVector PosicionInicial;
    FVector PosicionFinal;
    float DistanciaAvance = 2000.0f;
    float VelocidadAvance = 400.0f; // Velocidad de avance en unidades por segundo
    float AlturaSalto = 200.0f;    // Altura del salto
    float FrecuenciaSalto = 2.0f;  // Frecuencia del salto (número de ciclos por segundo)

    float TiempoTotal = 0.0f;      // Tiempo acumulado para el cálculo del salto

    bool bLlegadoAlFinal = false;
	void MoverYSalto(float DeltaTime);

};
