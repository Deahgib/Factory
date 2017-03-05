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

  beltInfluence = false;
  direction = FVector();
  speed = 0;
  others = TArray<AActor*>();
  otherComponents = TArray<UPrimitiveComponent*>();
}

// Called every frame
void AItem::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
  beltInfluence = false;
  direction = FVector::ZeroVector;
  speed = 0;
  others.Reset();
  meshShape->GetOverlappingActors(others);
  for (AActor* other : others) {
    ABelt* belt = Cast<ABelt>(other);
    if (belt) {
      otherComponents.Reset();
      meshShape->GetOverlappingComponents(otherComponents);
      for (UPrimitiveComponent* otherComponent : otherComponents) {
        for (UShapeComponent* conveyer : belt->conveyers) {
          if (otherComponent == conveyer) {
            if (meshShape->GetComponentVelocity().Size() < belt->beltSpeed || meshShape->GetComponentVelocity() != conveyer->GetForwardVector()) {
              beltInfluence = true;
              speed = belt->beltSpeed + belt->beltSpeed*0.1f;
              direction += conveyer->GetForwardVector();
              break;
            }
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

