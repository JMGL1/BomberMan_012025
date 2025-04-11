// Fill out your copyright notice in the Description page of Project Settings.


#include "BloquePasto.h"

ABloquePasto::ABloquePasto()
{
    PrimaryActorTick.bCanEverTick = true; // Activar el Tick
    if (MallaBloque)
    {
        static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Ground_Moss.M_Ground_Moss'"));

        if (MaterialBase.Succeeded())
        {
            MallaBloque->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
        }
    }
}

void ABloquePasto::BeginPlay()
{
    Super::BeginPlay();

    // Establecer las posiciones inicial y final
    PosicionInicial = GetActorLocation();
    PosicionFinal = PosicionInicial + FVector(DistanciaAvance, 0.0f, 0.0f);
}

void ABloquePasto::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!bLlegadoAlFinal)
    {
        MoverYSalto(DeltaTime);
    }
}

void ABloquePasto::MoverYSalto(float DeltaTime)
{
    // Calcula el avance en el eje X (hacia adelante)
    FVector PosicionActual = GetActorLocation();
    FVector NuevaPosicion = PosicionActual;

    if (FVector::Dist(PosicionActual, PosicionFinal) > 1.0f)
    {
        // Interpola la posición hacia adelante usando la velocidad
        NuevaPosicion.X = FMath::FInterpTo(PosicionActual.X, PosicionFinal.X, DeltaTime, VelocidadAvance);
    }
    else
    {
        // Cuando se alcanza la posición final, detén el movimiento
        bLlegadoAlFinal = true;
    }

    // Calcula el movimiento vertical (salto)
    TiempoTotal += DeltaTime;
    NuevaPosicion.Z = PosicionInicial.Z + FMath::Sin(TiempoTotal * FrecuenciaSalto * PI * 2) * AlturaSalto;

    // Actualiza la posición del actor
    SetActorLocation(NuevaPosicion);
}