// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoSubterraneo.h"
#include "Components/StaticMeshComponent.h"

AEnemigoSubterraneo::AEnemigoSubterraneo()
{
    MallaSubterranea = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaSubterranea"));
    RootComponent = MallaSubterranea;

    // Inicializar atributos
    VelocidadMovimiento = 150.0f;
    DireccionActual = FVector(1.0f, 0.0f, 0.0f);
    TiempoEntreEmergencias = 3.5f;
    TiempoAcumulado = 0.0f;
    Emergido = false;

    // Cargar una malla con forma de pir�mide
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMalla(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
    if (ObjetoMalla.Succeeded())
    {
        MallaSubterranea->SetStaticMesh(ObjetoMalla.Object);
    }
}

void AEnemigoSubterraneo::BeginPlay()
{
    Super::BeginPlay();

    // Colocar al enemigo bajo tierra al inicio
    FVector PosicionInicial = GetActorLocation();
    PosicionInicial.Z -= 50.0f; // Por debajo de la superficie
    SetActorLocation(PosicionInicial);
}

void AEnemigoSubterraneo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Contador para alternar emergencias
    TiempoAcumulado += DeltaTime;

    // Si el enemigo no est� emergido, se mueve bajo tierra
    if (!Emergido)
    {
        // Mover al enemigo en la direcci�n actual
        FVector NuevaPosicion = GetActorLocation() + (DireccionActual * VelocidadMovimiento * DeltaTime);
        NuevaPosicion.Z = GetActorLocation().Z; // Mantener bajo tierra
        SetActorLocation(NuevaPosicion);
    }

    // Alternar entre emerger y esconderse seg�n el tiempo
    if (TiempoAcumulado >= TiempoEntreEmergencias)
    {
        //AlternarEmergencia();
        TiempoAcumulado = 0.0f; // Reinicia el contador
    }
}