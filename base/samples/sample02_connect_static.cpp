#include <iostream>

#include <GameSparks/GS.h>
#include <GameSparks/IGSPlatform.h>

#include "./extra/usleep.h"
#include "sample_configuration.h"

void CreateSmallGameSparksSession()
{
	using namespace GameSparks::Core;

	GS.Initialise(new SampleConfiguration::NativePlatformDescription());

	int cyclesLeft = 200;
	while (cyclesLeft-- > 0)
	{
		GS.Update(100);

		usleep(100);
	}

	GS.ShutDown();
}


int main(int argc, const char* argv[])
{
	CreateSmallGameSparksSession();
	// double check if GS can run twice in a row without problems
	CreateSmallGameSparksSession();

	return 0;
}
