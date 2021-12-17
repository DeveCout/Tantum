#pragma once

enum e_particle_level
{
	PARTICLE_NONE = 0,
	PARTICLE_MINIMISED = 1,
	PARTICLE_ALL = 2,
};

static class GraphicsSettings
{

	static e_particle_level particleLevel;
	
public :


	static e_particle_level particleLevelUp();
	static e_particle_level particleLevelDown();


};

