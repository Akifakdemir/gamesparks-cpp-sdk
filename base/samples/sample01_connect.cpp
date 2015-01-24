#include <iostream>

#include <GameSparks/GS.h>
#include <GameSparks/IGSPlatform.h>

#include "./extra/usleep.h"
#include "sample_configuration.h"

int main(int argc, const char* argv[])
{
	using namespace GameSparks::Core;

	GS_ gs;
    SampleConfiguration::NativePlatformDescription platform;
	gs.Initialise(&platform);

	int cyclesLeft = 200;
	while (cyclesLeft-- > 0)
	{
		gs.Update(100);

		usleep(100);
	}

	gs.ShutDown();
}
