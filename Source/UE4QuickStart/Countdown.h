// UE4 C++ Quick Start Tutorials - copyright 2015-2016 Sébastien Rombauts - distributed under the MIT License

#pragma once

#include "GameFramework/Actor.h"
#include "Countdown.generated.h"

UCLASS()
class UE4QUICKSTART_API ACountdown : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACountdown();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// How long, in seconds, the countdown will run
	UPROPERTY(EditAnywhere)
	int32 CountdownTime = 3;

	// Called when count get to zero
	UFUNCTION(BlueprintNativeEvent)
	void CountdownHasFinished();

private:
	virtual void CountdownHasFinished_Implementation();

	UTextRenderComponent* CountdownText = nullptr;

	FTimerHandle CountdownTimerHandle;

	void UpdateTimerDisplay();

	void AdvanceTimer();
};
