// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "EnginePrivate.h"
#include "AI/Navigation/NavAgentInterface.h"
#include "AI/Navigation/NavigationPathGenerator.h"
#include "AI/Navigation/NavNodeInterface.h"
#include "AI/Navigation/NavLinkHostInterface.h"
#include "AI/Navigation/NavPathObserverInterface.h"
#include "AI/Navigation/NavRelevantInterface.h"
#include "AI/Navigation/NavLinkCustomInterface.h"

uint32 INavLinkCustomInterface::NextUniqueId = 1;

UNavAgentInterface::UNavAgentInterface(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}

UNavigationPathGenerator::UNavigationPathGenerator(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}

UNavNodeInterface::UNavNodeInterface(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}

UNavLinkHostInterface::UNavLinkHostInterface(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}

UNavLinkCustomInterface::UNavLinkCustomInterface(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}

uint32 INavLinkCustomInterface::GetUniqueId()
{
	return NextUniqueId++;
}

void INavLinkCustomInterface::UpdateUniqueId(uint32 AlreadyUsedId)
{
	NextUniqueId = FMath::Max(NextUniqueId, AlreadyUsedId + 1);
}

FNavigationLink INavLinkCustomInterface::GetModifier(const INavLinkCustomInterface* CustomNavLink)
{
	FNavigationLink LinkMod;
	LinkMod.AreaClass = CustomNavLink->GetLinkAreaClass();
	LinkMod.UserId = CustomNavLink->GetLinkId();

	ENavLinkDirection::Type LinkDirection = ENavLinkDirection::BothWays;
	CustomNavLink->GetLinkData(LinkMod.Left, LinkMod.Right, LinkDirection);
	LinkMod.Direction = LinkDirection;

	return LinkMod;
}

UNavPathObserverInterface::UNavPathObserverInterface(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}

UNavRelevantInterface::UNavRelevantInterface(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}
