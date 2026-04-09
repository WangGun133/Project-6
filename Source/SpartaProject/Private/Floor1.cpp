// Fill out your copyright notice in the Description page of Project Settings.


#include "Floor1.h"

// Sets default values
AFloor1::AFloor1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	RotationSpeed = 90.0f;

	

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/ Script / Engine.StaticMesh'/Game/Resources/Props/Wall_400x400.Wall_400x400'"));
		if (MeshAsset.Succeeded()) 
		{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
		}

		static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/ Script / Engine.Material'/Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold'"));
		if (MaterialAsset.Succeeded())
		{
			StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
		}
}

// Called when the game starts or when spawned
void AFloor1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (RotationSpeed != 0.0f)
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}

