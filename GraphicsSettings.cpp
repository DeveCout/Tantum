#include "GraphicsSettings.h"

e_particle_level GraphicsSettings::particleLevelUp()
{
	switch (particleLevel)
	{
	case PARTICLE_NONE:
		particleLevel = PARTICLE_MINIMISED;
		break;
	case PARTICLE_MINIMISED:
		particleLevel = PARTICLE_ALL;
		break;
	}

	return particleLevel;
}

e_particle_level GraphicsSettings::particleLevelDown()
{
	switch (particleLevel)
	{
	case PARTICLE_ALL:
		particleLevel = PARTICLE_MINIMISED;
		break;
	case PARTICLE_MINIMISED:
		particleLevel = PARTICLE_NONE;
		break;
	}

	return particleLevel;

}
