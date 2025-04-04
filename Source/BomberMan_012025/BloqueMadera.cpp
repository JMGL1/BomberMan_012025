// Fill out your copyright notice in the Description page of Project Settings.

#include "BloqueMadera.h"

ABloqueMadera::ABloqueMadera()
{
   PosicionInicial = FVector::ZeroVector; // Inicializar PosicionInicial

   if (MallaBloque)
   {
       static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Wood_Floor_Walnut_Polished.M_Wood_Floor_Walnut_Polished'"));

       if (MaterialBase.Succeeded())
       {
           MallaBloque->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
       }
   }
}

void ABloqueMadera::BeginPlay()
{
   Super::BeginPlay();
   PosicionInicial = GetActorLocation(); // Asignar la posici�n inicial al comenzar el juego
}

void ABloqueMadera::Tick(float DeltaTime)
{
   Super::Tick(DeltaTime);

   float NuevaAltura = PosicionInicial.Z + FMath::Sin(GetWorld()->GetTimeSeconds() * 2.0f) * 50.0f;
   SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, NuevaAltura));
}
