void	parse_test_print(t_mrt *mrt)
{
	t_obj *objs = mrt->objs;
	printf("A : [%f] [%f %f %f]\n", mrt->amb.ratio, mrt->amb.color.x, mrt->amb.color.y, mrt->amb.color.z);
	printf("C : [%f %f %f] [%f %f %f] [%f]\n", mrt->cam.eye.x, mrt->cam.eye.y, mrt->cam.eye.z, mrt->cam.at.x, mrt->cam.at.y, mrt->cam.at.z, mrt->cam.fov);
	printf("L : [%f %f %f] [%f] [%f %f %f]\n", mrt->lit.origin.x, mrt->lit.origin.y, mrt->lit.origin.z, mrt->lit.brightness, mrt->lit.color.x, mrt->lit.color.y, mrt->lit.color.z);	
	while (objs)
	{
		if (objs->type == SP)
			printf("sp : [%f %f %f] [%f] [%f %f %f]\n", objs->origin.x, objs->origin.y, objs->origin.z, objs->radius, objs->albedo.x, objs->albedo.y, objs->albedo.z);
		else if (mrt->objs->type == PL)
			printf("pl : [%f %f %f] [%f %f %f] [%f %f %f]\n", objs->origin.x, objs->origin.y, objs->origin.z, objs->axis.x, objs->axis.y, objs->axis.z, objs->albedo.x, objs->albedo.y, objs->albedo.z);
		else if (mrt->objs->type == CY)
			printf("cy : [%f %f %f] [%f %f %f] [%f] [%f] [%f %f %f]\n", objs->origin.x, objs->origin.y, objs->origin.z, objs->axis.x, objs->axis.y, objs->axis.z, objs->radius, objs->height, objs->albedo.x, objs->albedo.y, objs->albedo.z);	
		else if (mrt->objs->type == CN)
			printf("cn : [%f %f %f] [%f %f %f] [%f] [%f] [%f %f %f]\n", objs->origin.x, objs->origin.y, objs->origin.z, objs->axis.x, objs->axis.y, objs->axis.z, objs->radius, objs->height, objs->albedo.x, objs->albedo.y, objs->albedo.z);	
		objs = objs->next;
	}
	exit(1);
}