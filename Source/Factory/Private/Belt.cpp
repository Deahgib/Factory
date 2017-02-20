// Fill out your copyright notice in the Description page of Project Settings.

#include "Factory.h"
#include "Belt.h"


// Sets default values
ABelt::ABelt()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

  //Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
  
  

}

// Called when the game starts or when spawned
void ABelt::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABelt::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

  /*for (UShapeComponent* conveyer : conveyers) {
    TArray<UPrimitiveComponent*> others;
    conveyer->GetOverlappingComponents(others);
    for (UPrimitiveComponent* other : others) {
      FVector acc = (conveyer->GetForwardVector()*beltSpeed - other->GetComponentVelocity()) / DeltaTime;
      other->AddForce(acc, NAME_None, true);
    }
  }*/
}

