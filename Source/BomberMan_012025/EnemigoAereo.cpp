// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAereo.h"
#include "Components/StaticMeshComponent.h"

AEnemigoAereo::AEnemigoAereo()
{
    MallaAereo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaAereo"));
    RootComponent = MallaAereo;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMalla(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));
    if (ObjetoMalla.Succeeded())
    {
        MallaAereo->SetStaticMesh(ObjetoMalla.Object);
    }

    LimiteMovimiento = 1000.0f;
    AlturaVuelo = 100.0f;
    VelocidadVuelo = 2.0f;
    Tiempo = 0.0f;
}

void AEnemigoAereo::BeginPlay()
{
    Super::BeginPlay();
    CentroMovimiento = GetActorLocation();
}

void AEnemigoAereo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    Tiempo += DeltaTime * VelocidadVuelo;

    float PosicionX = CentroMovimiento.X + LimiteMovimiento * FMath::Sin(Tiempo);
    float PosicionY = CentroMovimiento.Y + LimiteMovimiento * FMath::Sin(Tiempo * 0.5f) * FMath::Cos(Tiempo);
    float PosicionZ = CentroMovimiento.Z;


    SetActorLocation(FVector(PosicionX, PosicionY, PosicionZ));

    //UE_LOG(LogTemp, Warning, TEXT("Enemigo aéreo moviéndose en trayectoria de infinito: X=%f, Y=%f, Z=%f"), PosicionX, PosicionY, PosicionZ);
}