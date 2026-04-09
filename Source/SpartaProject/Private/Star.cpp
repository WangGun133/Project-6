// Fill out your copyright notice in the Description page of Project Settings.


#include "Star.h"

// Sets default values
AStar::AStar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);
	
	RotationSpeed = 90.0f;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/ Script / Engine.StaticMesh'/Game/Resources/Props/SM_Star_C.SM_Star_C'"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Script/Engine.MaterialInstanceConstant'/Game/Resources/Materials/M_Star_C.M_Star_C'"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
}

// Called when the game starts or when spawned
void AStar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (RotationSpeed != 0.0f)
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}
}

