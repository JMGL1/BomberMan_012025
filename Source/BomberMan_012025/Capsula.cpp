#include "Capsula.h"  
#include "GameFramework/Character.h"  
#include "GameFramework/GameModeBase.h"  
#include "BomberMan_012025GameMode.h"  
#include "Components/SphereComponent.h"  // Agregar esta l�nea para incluir la definici�n de USphereComponent

ACapsula::ACapsula()  
{  
   PrimaryActorTick.bCanEverTick = true;  

   // Crear la malla de la c�psula  
   CapsulaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CapsulaMesh"));  
   RootComponent = CapsulaMesh;  

   // Crear un collider para detectar colisiones  
   USphereComponent* CapsulaCollider = CreateDefaultSubobject<USphereComponent>(TEXT("CapsulaCollider"));  
   CapsulaCollider->SetupAttachment(CapsulaMesh);  
   CapsulaCollider->OnComponentBeginOverlap.AddDynamic(this, &ACapsula::OnOverlapBegin);  

   // Cantidad de velocidad que otorgar� al personaje  
   SpeedBoostAmount = 1000.0f;  
}  

void ACapsula::BeginPlay()  
{  
   Super::BeginPlay();  
}  

void ACapsula::Tick(float DeltaTime)  
{  
   Super::Tick(DeltaTime);  
}  

void ACapsula::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,  
   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,  
   bool bFromSweep, const FHitResult& SweepResult)  
{  
   ACharacter* PlayerCharacter = Cast<ACharacter>(OtherActor);  
   if (PlayerCharacter)  
   {  
       // Obtener el Game Mode y activar el poder  
       ABomberMan_012025GameMode* GameMode = Cast<ABomberMan_012025GameMode>(GetWorld()->GetAuthGameMode());  
       if (GameMode)  
       {  
           GameMode->ActivateSpeedBoost(PlayerCharacter, SpeedBoostAmount);  
       }  

       // Destruir la c�psula despu�s de que el personaje la recoge  
       Destroy();  
   }  
}