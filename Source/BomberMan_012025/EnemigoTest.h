// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemigo.h"
#include "EnemigoTest.generated.h"
UCLASS()
class BOMBERMAN_012025_API AEnemigoTest : public AEnemigo
{
	GENERATED_BODY()

public:
    AEnemigoTest();

private:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* CubeVisual;

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    FVector MoveDirection;
    float MoveSpeed;
    int Contador;

    UFUNCTION()
    void OnCapsuleHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, FVector NormalImpulse,
        const FHitResult& Hit);
};