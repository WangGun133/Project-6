// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floor1.generated.h"

UCLASS()
class SPARTAPROJECT_API AFloor1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloor1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floor1|Components")
	float RotationSpeed;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
