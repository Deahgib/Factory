// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Belt.generated.h"

UCLASS()
class FACTORY_API ABelt : public AActor
{
  GENERATED_BODY()
public:	

  UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
  TArray<UShapeComponent*> conveyers;

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  float beltSpeed;

	// Sets default values for this actor's properties
	ABelt();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;



};
