#include "../../headers/mrt.h"

static	bool	verify_range(double value, double min_value, double max_value)
{
	if (value < min_value || value > max_value)
		return (false);
	else
		return (true);
}

bool	verify_value_range(t_mrt *mrt)
{
    bool    b_parse_success;

    b_parse_success = verify_range(mrt->amb.ratio, 0.0, 1.0);

    b_parse_success &= verify_range(mrt->cam.at.x, -1, 1);
    b_parse_success &= verify_range(mrt->cam.at.y, -1, 1);
    b_parse_success &= verify_range(mrt->cam.at.z, -1, 1);
    b_parse_success &= verify_range(mrt->cam.fov, 0, 180);

    b_parse_success &= verify_range(mrt->lit.bright, 0.0, 1.0);
    return (b_parse_success);
}
