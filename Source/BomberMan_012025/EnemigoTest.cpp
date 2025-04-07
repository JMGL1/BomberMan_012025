#include "EnemigoTest.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "AIController.h"

AEnemigoTest::AEnemigoTest()
{
    PrimaryActorTick.bCanEverTick = true;

    // Dirección inicial y velocidad
    MoveDirection = FVector(1, 1, 0);
    MoveSpeed = 300.f;

    // Crear componente visual (cubo)
    CubeVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeVisual"));
    CubeVisual->SetupAttachment(RootComponent); // Se adjunta al capsule del Character

    // Cargar la malla del cubo desde los assets del motor
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (CubeMeshAsset.Succeeded())
    {
        CubeVisual->SetStaticMesh(CubeMeshAsset.Object);
        CubeVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight()));
        CubeVisual->SetWorldScale3D(FVector(0.5f)); // Tamaño del cubo visual
    }

    // Detectar colisiones
    GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &AEnemigoTest::OnCapsuleHit);

    // ?? LÍNEAS CLAVE PARA QUE FUNCIONE CUANDO SE SPAWNEA
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    AIControllerClass = AAIController::StaticClass();
}

void AEnemigoTest::BeginPlay()
{
    Super::BeginPlay();
}

void AEnemigoTest::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Mover continuamente en la dirección actual
    AddMovementInput(MoveDirection, 1.0f);
}

void AEnemigoTest::OnCapsuleHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, FVector NormalImpulse,
    const FHitResult& Hit)
{
    // Cambiar dirección horizontal al chocar
    MoveDirection.X *= -1;
	if (Contador < 4)
	{
		Contador++;
	}
	else
	{
		Contador = 0;
		MoveDirection.Y *= -1;
	}
}
