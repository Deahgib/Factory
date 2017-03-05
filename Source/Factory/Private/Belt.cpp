// Fill out your copyright notice in the Description page of Project Settings.

#include "Factory.h"
#include "Belt.h"


// Sets default values
ABelt::ABelt()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
}

