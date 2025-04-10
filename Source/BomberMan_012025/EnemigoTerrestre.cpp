// EnemigoTerrestre.cpp
#include "EnemigoTerrestre.h"

AEnemigoTerrestre::AEnemigoTerrestre()
{
    MallaTerrestre = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaTerrestre"));
    RootComponent = MallaTerrestre;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMalla(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe'"));
    if (ObjetoMalla.Succeeded())
    {
        MallaTerrestre->SetStaticMesh(ObjetoMalla.Object);
    }
    DireccionMovimiento = FVector(1.0f, 0.0f, 0.0f); // Movimiento en línea recta en el eje X
    VelocidadVuelo = 600.0f;
    DistanciaMaxima = 2000.0f; // Definir límite antes de regresar
}

void AEnemigoTerrestre::BeginPlay()
{
    Super::BeginPlay();

    PosicionInicial = GetActorLocation(); // Guardamos la posición inicial
}

void AEnemigoTerrestre::Tick(float DeltaTime)
{

    Super::Tick(DeltaTime);

    FVector NuevaPosicion = GetActorLocation() + (DireccionMovimiento * VelocidadVuelo * DeltaTime);
    SetActorLocation(NuevaPosicion);

    float DistanciaRecorrida = FVector::Dist(NuevaPosicion, PosicionInicial);

    if (DistanciaRecorrida >= DistanciaMaxima)
    {
        DireccionMovimiento *= -1; // Invertimos la dirección
        PosicionInicial = NuevaPosicion; // Actualizamos el punto de referencia
    }

    UE_LOG(LogTemp, Warning, TEXT("Posicion: X=%f, Y=%f, Z=%f | Direccion: X=%f, Y=%f, Z=%f"),
        NuevaPosicion.X, NuevaPosicion.Y, NuevaPosicion.Z, DireccionMovimiento.X, DireccionMovimiento.Y, DireccionMovimiento.Z);
}