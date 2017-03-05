// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class FACTORY_API AItem : public AActor
{
	GENERATED_BODY()
	
private:
  bool beltInfluence;
  FVector direction;
  float speed;
  TArray<AActor*> others;
  TArray<UPrimitiveComponent*> otherComponents;

public:	

  UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
  UMeshComponent* meshShape;

	// Sets default values for this actor's properties
	AItem();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
