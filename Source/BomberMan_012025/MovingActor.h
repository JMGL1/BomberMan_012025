// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "MovingActor.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AMovingActor : public AEnemigo
{
	GENERATED_BODY()
	
public:
	AMovingActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshM;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	float Speed = 300.0f;

	UPROPERTY(EditAnywhere, Category = "Movimiento")
	float MaxDistance = 500.0f; // Distancia que recorrerá desde su posición inicial

	FVector InitialLocation;
	bool bMovingForward = true; // true = va, false = regresa
};