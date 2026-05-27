// Fill out your copyright notice in the Description page of Project Settings.


#include "Simulation/Public/Telemetry/TelemetryGenerator.h"

#include "Serialization/ArrayWriter.h"


// Sets default values
ATelemetryGenerator::ATelemetryGenerator()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATelemetryGenerator::BeginPlay()
{
	Super::BeginPlay();
	
	FIPv4Address IPAddress = FIPv4Address::InternalLoopback;
	RemoteEndpoint = FIPv4Endpoint(IPAddress, 8080);
	
	UdpSocket = FUdpSocketBuilder(TEXT("TelemetrySocket"))
		.AsNonBlocking()
		.AsReusable()
		.WithBroadcast();
	
}

// Called every frame
void ATelemetryGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATelemetryGenerator::SendTelemetryPacket()
{
	if (!UdpSocket) return;
	
	float ChamberPressure = 101.3f;
	float BusVoltage = 28.0f;
	
	FArrayWriter Writer;
	Writer << ChamberPressure;
	Writer << BusVoltage;
	
	int32 BytesSent = 0;
	UdpSocket->SendTo(Writer.GetData(), Writer.Num(), BytesSent, *RemoteEndpoint.ToInternetAddr());
}

