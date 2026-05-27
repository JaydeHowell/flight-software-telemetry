// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include "Common/UdpSocketBuilder.h"
#include "SocketSubsystem.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TelemetryGenerator.generated.h"


UCLASS()
class SIMULATION_API ATelemetryGenerator : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATelemetryGenerator();

protected:
	FSocket* UdpSocket;
	FIPv4Endpoint RemoteEndpoint;
	
	void SendTelemetryPacket();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
