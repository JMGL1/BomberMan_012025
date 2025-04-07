// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueOro.h"

ABloqueOro::ABloqueOro()
{
    PrimaryActorTick.bCanEverTick = true; // Habilita la actualización en cada frame
    PosicionInicial = GetActorLocation();
    if (MallaBloque)
    {
        static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));

        if (MaterialBase.Succeeded())
        {
            MallaBloque->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
        }
    }
    bPuedeMoverse = FMath::RandBool();
    TiempoEntreMovimientos = 2.0f;
    VelocidadMovimiento = 200.0f; // Ajusta para hacerlo más lento o rápido
    TiempoDesdeUltimoMovimiento = 0.0f;
    bMoviendoAObjetivo = false;
}



void ABloqueOro::BeginPlay()
{
    Super::BeginPlay();

    PosicionInicial = GetActorLocation();
    PosicionObjetivo = PosicionInicial;
}

void ABloqueOro::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    TiempoDesdeUltimoMovimiento += DeltaTime;

    if (TiempoDesdeUltimoMovimiento >= TiempoEntreMovimientos)
    {
        ElegirNuevaDireccion();
        TiempoDesdeUltimoMovimiento = 0.0f;
        bMoviendoAObjetivo = true;
    }

    if (bMoviendoAObjetivo)
    {
        FVector PosActual = GetActorLocation();
        FVector NuevaPos = FMath::VInterpTo(PosActual, PosicionObjetivo, DeltaTime, 5.0f);
        SetActorLocation(NuevaPos);

        // Verifica si ya llegó al destino
        if (FVector::Dist(NuevaPos, PosicionObjetivo) < 1.0f)
        {
            // Si está en destino, vuelve al inicio
            if (PosicionObjetivo != PosicionInicial)
            {
                PosicionObjetivo = PosicionInicial;
            }
            else
            {
                bMoviendoAObjetivo = false;
            }
        }
    }
}

void ABloqueOro::ElegirNuevaDireccion()
{
    int Direccion = FMath::RandRange(0, 5);
    FVector Offset(0.0f);

    const float DistanciaMovimiento = 200.0f;

    switch (Direccion)
    {
    case 0: Offset.X += DistanciaMovimiento; break; // Derecha
    case 1: Offset.X -= DistanciaMovimiento; break; // Izquierda
    case 2: Offset.Y += DistanciaMovimiento; break; // Adelante
    case 3: Offset.Y -= DistanciaMovimiento; break; // Atrás
    case 4: Offset.Z += DistanciaMovimiento; break; // Arriba
    case 5: Offset.Z -= DistanciaMovimiento; break; // Abajo
    }

    PosicionObjetivo = PosicionInicial + Offset;
}