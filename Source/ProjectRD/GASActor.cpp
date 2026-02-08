// Fill out your copyright notice in the Description page of Project Settings.


#include "GASActor.h"
#include "AbilitySystemComponent.h"

// Sets default values
AGASActor::AGASActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

// Called when the game starts or when spawned
void AGASActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

UAbilitySystemComponent* AGASActor::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called every frame
void AGASActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}