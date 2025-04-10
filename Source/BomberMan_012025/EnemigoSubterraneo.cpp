#include "EnemigoSubterraneo.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AEnemigoSubterraneo::AEnemigoSubterraneo()
{
    PrimaryActorTick.bCanEverTick = true;

    ConoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ConoMesh"));
    ConoMesh->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> ConoAsset(TEXT("/Engine/BasicShapes/Cone.Cone"));
    if (ConoAsset.Succeeded())
    {
        ConoMesh->SetStaticMesh(ConoAsset.Object);
        ConoMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -100.0f)); // Ajuste visual del cono
    }

    Velocidad = 300.f;
    AnchoRectangulo = 1000.f;
    AltoRectangulo = 500.f;
    PuntoActual = 0;
}

void AEnemigoSubterraneo::BeginPlay()
{
    Super::BeginPlay();

    PuntoInicial = GetActorLocation();

    PuntosPatrulla[0] = PuntoInicial + FVector(0, 0, AltoRectangulo);
    PuntosPatrulla[1] = PuntosPatrulla[0] + FVector(AnchoRectangulo, 0, 0);
    PuntosPatrulla[2] = PuntosPatrulla[1] - FVector(0, 0, AltoRectangulo);
    PuntosPatrulla[3] = PuntoInicial;
}

void AEnemigoSubterraneo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector Objetivo = PuntosPatrulla[PuntoActual];
    FVector PosActual = GetActorLocation();
    FVector Direccion = (Objetivo - PosActual).GetSafeNormal();
    FVector NuevaPos = PosActual + Direccion * Velocidad * DeltaTime;

    SetActorLocation(NuevaPos);

    if (FVector::Dist(NuevaPos, Objetivo) < 10.f)
    {
        PuntoActual = (PuntoActual + 1) % 4;
    }
}