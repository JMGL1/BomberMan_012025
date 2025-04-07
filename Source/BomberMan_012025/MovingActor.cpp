#include "MovingActor.h"

AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// Crear y asignar la malla como RootComponent
	MeshM = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshM;
	if (MeshM)
	{
		static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMalla(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
		if (ObjetoMalla.Succeeded())
		{
			MeshM->SetStaticMesh(ObjetoMalla.Object);
		}
	}
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = GetActorLocation();
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	FVector Direction = GetActorForwardVector();
	FVector TargetLocation;

	// Determinar la direcci�n del movimiento
	if (bMovingForward)
	{
		TargetLocation = InitialLocation + Direction * MaxDistance;

		// Mover hacia adelante
		CurrentLocation += Direction * Speed * DeltaTime;

		// Si lleg� o super� la distancia m�xima, cambiar direcci�n
		if (FVector::Dist(CurrentLocation, InitialLocation) >= MaxDistance)
		{
			CurrentLocation = TargetLocation;
			bMovingForward = false;
		}
	}
	else
	{
		// Mover hacia atr�s (hacia InitialLocation)
		CurrentLocation -= Direction * Speed * DeltaTime;

		// Si lleg� o pas� el punto inicial, cambiar direcci�n
		if (FVector::Dist(CurrentLocation, InitialLocation) <= 1.0f)
		{
			CurrentLocation = InitialLocation;
			bMovingForward = true;
		}
	}

	SetActorLocation(CurrentLocation);
}