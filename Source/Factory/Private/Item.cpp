// Fill out your copyright notice in the Description page of Project Settings.

#include "Factory.h"
#include "Item.h"
#include "Belt.h"


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
  bool beltInfluence = false;
  FVector direction(0,0,0);
  float speed = 0;
  TArray<AActor*> others;
  meshShape->GetOverlappingActors(others);
  for (AActor* other : others) {
    ABelt* belt = Cast<ABelt>(other);
    if (belt) {
      TArray<UPrimitiveComponent*> otherComponents;
      meshShape->GetOverlappingComponents(otherComponents);
      for (UPrimitiveComponent* otherComponent : otherComponents) {
        for (UShapeComponent* conveyer : belt->conveyers) {
          if (otherComponent == conveyer) {
            beltInfluence = true;
            if (speed < belt->beltSpeed) {
              speed = belt->beltSpeed;
            }
            direction += conveyer->GetForwardVector();
            break;
          }
        }
      }
    }
  }

  if(beltInfluence){
    direction = direction.GetSafeNormal();
    FVector acc = (direction*speed - meshShape->GetComponentVelocity()) / DeltaTime;
    meshShape->AddForce(acc, NAME_None, true);
  }
  /*for (UShapeComponent* conveyer : conveyers) {
    TArray<UPrimitiveComponent*> others;
    conveyer->GetOverlappingComponents(others);
    for (UPrimitiveComponent* other : others) {
      FVector acc = (conveyer->GetForwardVector()*beltSpeed - other->GetComponentVelocity()) / DeltaTime;
      other->AddForce(acc, NAME_None, true);
    }
  }*/
}

