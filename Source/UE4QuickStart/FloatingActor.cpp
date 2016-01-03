// UE4 C++ Quick Start Tutorials - copyright 2015-2016 Sébastien Rombauts - distributed under the MIT License

#include "UE4QuickStart.h"
#include "FloatingActor.h"


// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(QuickStart, Log, TEXT("AFloatingActor::AFloatingActor()"));
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(QuickStart, Log, TEXT("AFloatingActor::BeginPlay()"));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "AFloatingActor::BeginPlay()");
}

// Called every frame
void AFloatingActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector Delta;
	Delta.X = (FMath::Sin((RunningTime + DeltaTime) * Period.X) - FMath::Sin(RunningTime * Period.X));
	Delta.Y = (FMath::Sin((RunningTime + DeltaTime) * Period.Y) - FMath::Sin(RunningTime * Period.Y));
	Delta.Z = (FMath::Sin((RunningTime + DeltaTime) * Period.Z) - FMath::Sin(RunningTime * Period.Z));
	RunningTime += DeltaTime;

	const FVector NewLocation = GetActorLocation() + (Delta * Scale);
	SetActorLocation(NewLocation);

	AddActorLocalRotation(Rotation * DeltaTime);
}

