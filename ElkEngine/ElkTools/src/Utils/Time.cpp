#include "Time.h"

#include "ElkTools/Utils/Time.h"
#include "ElkTools/Debug/Log.h"

std::chrono::steady_clock::time_point	ElkTools::Utils::Time::__START_TIME;
std::chrono::steady_clock::time_point	ElkTools::Utils::Time::__LAST_TIME;
std::chrono::steady_clock::time_point	ElkTools::Utils::Time::__CURRENT_TIME;
std::chrono::duration<double>			ElkTools::Utils::Time::__ELAPSED;

bool	ElkTools::Utils::Time::__INITIALIZED	= false;
float	ElkTools::Utils::Time::__TIME_SCALE		= 1.0f;
float	ElkTools::Utils::Time::__DELTA_TIME		= 0.0;

float ElkTools::Utils::Time::GetFramerate()
{
	return 1.0f / (__DELTA_TIME);
}

float ElkTools::Utils::Time::GetDeltaTime()
{
	return __DELTA_TIME * __TIME_SCALE;
}

float ElkTools::Utils::Time::GetDeltaTimeUnscaled()
{
	return __DELTA_TIME;
}

void ElkTools::Utils::Time::SetTimeScale(float p_timeScale)
{
	__TIME_SCALE = p_timeScale;
}

void ElkTools::Utils::Time::Initialize()
{
	__DELTA_TIME = 0.0f;

	__START_TIME	= std::chrono::steady_clock::now();
	__CURRENT_TIME	= __START_TIME;
	__LAST_TIME		= __START_TIME;

	__INITIALIZED = true;
}

void ElkTools::Utils::Time::Update()
{
	__LAST_TIME		= __CURRENT_TIME;
	__CURRENT_TIME	= std::chrono::steady_clock::now();
	__ELAPSED		= __CURRENT_TIME - __LAST_TIME;

	if (__INITIALIZED)
		__DELTA_TIME = static_cast<float>(__ELAPSED.count());
	else
		Initialize();
}
