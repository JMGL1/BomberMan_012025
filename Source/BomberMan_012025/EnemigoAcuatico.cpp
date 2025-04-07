// EnemigoAcuatico.cpp
#include "EnemigoAcuatico.h"
#include "Components/StaticMeshComponent.h"

AEnemigoAcuatico::AEnemigoAcuatico()
{
    MallaAcuatica = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaAcuatica"));
    RootComponent = MallaAcuatica;
	if (MallaAcuatica)
	{
		static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMalla(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
		if (ObjetoMalla.Succeeded())
		{
			MallaAcuatica->SetStaticMesh(ObjetoMalla.Object);
		}
	}

    VelocidadMovimiento = 100.0f;
    AmplitudOscilacion = 50.0f;
    FrecuenciaOscilacion = 2.0f;
    DireccionMovimiento = FVector(1.0f, 0.0f, 0.0f);
    DistanciaMaxima = 2000.0f; // Define cu�nto se mover� antes de regresar
}

void AEnemigoAcuatico::BeginPlay()
{
    Super::BeginPlay();

    PosicionInicial = GetActorLocation(); // Guarda la posici�n inicial
}

void AEnemigoAcuatico::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector PosicionActual = GetActorLocation();
    FVector MovimientoHorizontal = DireccionMovimiento * VelocidadMovimiento * DeltaTime;

    // Oscilaci�n vertical para simular movimiento en el agua
    float OffsetVertical = AmplitudOscilacion * FMath::Sin(FrecuenciaOscilacion * GetWorld()->TimeSeconds);
    FVector NuevaPosicion = PosicionActual + MovimientoHorizontal;
    NuevaPosicion.Z = PosicionInicial.Z + OffsetVertical;

    // Calcular distancia recorrida
    float DistanciaRecorrida = FVector::Dist(PosicionInicial, PosicionActual);

    // DEBUG: Verificar valores de distancia y direcci�n
    UE_LOG(LogTemp, Warning, TEXT("PosicionActual: X=%f, Y=%f, Z=%f | Direccion: X=%f, Y=%f, Z=%f | DistanciaRecorrida=%f"),
        PosicionActual.X, PosicionActual.Y, PosicionActual.Z,
        DireccionMovimiento.X, DireccionMovimiento.Y, DireccionMovimiento.Z,
        DistanciaRecorrida);

    // Cambiar direcci�n si se alcanza la distancia m�xima
    if (DistanciaRecorrida >= DistanciaMaxima)
    {
        UE_LOG(LogTemp, Warning, TEXT("Cambiando direcci�n del enemigo"));
        DireccionMovimiento *= -1; // Cambia la direcci�n del movimiento
        PosicionInicial = PosicionActual; // �No actualizar con NuevaPosicion!
    }

    // Actualizar la posici�n del enemigo
    SetActorLocation(NuevaPosicion);
}