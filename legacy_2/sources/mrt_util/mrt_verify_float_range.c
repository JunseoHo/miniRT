#include "../../includes/mrt.h"

bool	mrt_verify_float_range(float f, float min, float max)
{
	if (f < min || f > max)
		return (false);
	else
		return (true);
}