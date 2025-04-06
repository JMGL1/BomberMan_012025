#include "PowerUpTest.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"
#include "BomberMan_012025Character.h"

APowerUpTest::APowerUpTest()
{
    PrimaryActorTick.bCanEverTick = false;

    CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
    CapsuleComponent->InitCapsuleSize(50.f, 100.f);
    RootComponent = CapsuleComponent;
    CapsuleComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &APowerUpTest::OnOverlapBegin);

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComponent->SetupAttachment(RootComponent);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CapsuleMesh(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
    if (CapsuleMesh.Succeeded())
    {
        MeshComponent->SetStaticMesh(CapsuleMesh.Object);
    }
}

void APowerUpTest::BeginPlay()
{
    Super::BeginPlay();
}



void APowerUpTest::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    if (ABomberMan_012025Character* Character = Cast<ABomberMan_012025Character>(OtherActor))
    {
        UCharacterMovementComponent* MoveComp = Character->GetCharacterMovement();
        if (MoveComp && !Character->bTienePowerUpVelocidad)
        {
            float OriginalSpeed = MoveComp->MaxWalkSpeed;

            UE_LOG(LogTemp, Warning, TEXT("Velocidad antes: %f"), OriginalSpeed);

            Character->bTienePowerUpVelocidad = true;
            MoveComp->MaxWalkSpeed += SpeedBoostAmount;

            UE_LOG(LogTemp, Warning, TEXT("Velocidad despu�s: %f"), MoveComp->MaxWalkSpeed);

            // Restaurar despu�s de unos segundos
            FTimerHandle TimerHandle;
            FTimerDelegate TimerDel;
            TimerDel.BindLambda([=]() {
                if (MoveComp) {
                    MoveComp->MaxWalkSpeed = OriginalSpeed;
                    Character->bTienePowerUpVelocidad = false;
                    UE_LOG(LogTemp, Warning, TEXT("Velocidad restaurada a: %f"), OriginalSpeed);
                }
                });

            GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDel, SpeedBoostDuration, false);
        }

        Destroy();
    }
}