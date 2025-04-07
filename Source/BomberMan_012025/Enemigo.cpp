// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo.h"

// Sets default values
AEnemigo::AEnemigo()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	VelocidadMovimiento = 200.0f;
	RadioPatrullaje = 500.0f;
	bPatrullajeHabilitado = true;

}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();
	if (bPatrullajeHabilitado) {
		Patrullar();
	}
}

// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bPatrullajeHabilitado)
	{
		Mover(DeltaTime);
	}

}

// Called to bind functionality to input
void AEnemigo::Mover(float DeltaTime)
{
	//Test
}
void AEnemigo::Patrullar()
{
	UE_LOG(LogTemp, Warning, TEXT("El enemigo esta patrullando en un area de radio %f"), RadioPatrullaje);
}