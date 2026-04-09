// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/ Script / Engine.StaticMesh'/Game/Resources/Props/Floor_400x400.Floor_400x400'"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Script/Engine.Material'/Game/Resources/Materials/M_Ground_Moss.M_Ground_Moss'"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	
	MoveSpeed = 100.0f;
	MaxRange = 100.0f;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(FVector(0.0f, MoveSpeed * DeltaTime, 0.0f));

	DistanceMoved = FVector::Dist(StartLocation, GetActorLocation());

	if (DistanceMoved >= MaxRange)
	{
		StartLocation = GetActorLocation();
		MoveSpeed = -MoveSpeed;

		DistanceMoved = FVector::Dist(StartLocation, GetActorLocation());
		if (DistanceMoved >= MaxRange)
		{
			MoveSpeed = MoveSpeed;
		}
	}
	
	
}

