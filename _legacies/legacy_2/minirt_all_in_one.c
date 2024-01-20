/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_all_in_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jho <jho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:56:12 by jho               #+#    #+#             */
/*   Updated: 2024/01/20 22:28:05 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include <stdbool.h>

/**************************************************/
/*	vectors										  */
/**************************************************/

typedef struct s_vec
{
	double x;
	double y;
	double z;
}	t_vec;

t_vec	vec_init(double x, double y, double z)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec	vec_add(t_vec u, t_vec v)
{
	return vec_init(u.x + v.x, u.y + v.y, u.z + v.z);
}

t_vec	vec_cross(t_vec u, t_vec v)
{
	return vec_init(u.y * v.z - u.z * v.y,
					u.z * v.x - u.x * v.z,
					u.x * v.y - u.y * v.x);
}

double	vec_dot(t_vec u, t_vec v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

double	vec_len(t_vec u)
{
	return (sqrt(u.x * u.x + u.y * u.y + u.z * u.z));
}

t_vec	vec_norm(t_vec u)
{
	double	len;

	len = vec_len(u);
	return vec_init(u.x / len, u.y / len, u.z / len);
}

t_vec	vec_sub(t_vec u, t_vec v)
{
	return vec_init(u.x - v.x, u.y - v.y, u.z - v.z);
}

t_vec	vec_scale(t_vec u, double k)
{
	return vec_init(u.x * k, u.y * k, u.z * k);
}

/**************************************************/
/* canvas 										  */
/**************************************************/

typedef struct s_canvas
{
	int 	width;
	int 	height;
	double aspect_ratio;
}	t_canvas;

t_canvas	canvas_init(int width, int height)
{
	t_canvas canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

/**************************************************/
/* camera 										  */
/**************************************************/

typedef struct s_camera
{
	t_vec	eye;
	t_vec	at;
	t_vec	up;
	double	viewport_height;
	double	viewport_width;
	t_vec	viewport_horizontal;
	t_vec	viewport_vertical;
	double	focal_length;
	t_vec	viewport_leftbottom;
	double	field_of_view;
}	t_camera;

t_camera	camera_init(t_canvas canvas, t_vec origin)
{
	t_camera camera;

	camera.eye = origin;
	camera.at = vec_init(0, 0, -1);
	camera.up = vec_init(0, 1, 0);
	camera.viewport_height = 2.0;
	camera.viewport_width = 2.0 * canvas.aspect_ratio;
	camera.viewport_horizontal = vec_init(camera.viewport_width, 0, 0);
	camera.viewport_vertical = vec_init(0, camera.viewport_height, 0);
	camera.focal_length = 1.0;
	camera.field_of_view = 90;
	camera.viewport_leftbottom = vec_sub(vec_sub(vec_sub(camera.eye, vec_scale(camera.viewport_horizontal, 0.5)),
                                vec_scale(camera.viewport_vertical, 0.5)), vec_init(0, 0, camera.focal_length));
	return (camera);
}

/**************************************************/
/* objects 										  */
/**************************************************/

typedef int t_object_type;
#define SP 0

typedef struct s_ray
{
	t_vec	origin;
	t_vec	direction;
}	t_ray;

typedef struct s_sphere
{
	t_vec	center;
	double	radius;
}	t_sphere;

typedef struct s_object
{
	t_object_type type;
	void		*element;
	void		*next;
	t_vec	albedo;
}	t_object;

typedef struct s_light
{
	t_vec	origin;
	t_vec	color;
	double	bright_ratio;
}	t_light;

typedef struct s_hit_record
{
	t_vec	p;
	t_vec	normal;
	double	tmin;
	double	tmax;
	double	t;
	bool	front_face;
	t_vec	albedo;
}	t_hit_record;

t_light     *light_init(t_vec light_origin, t_vec light_color, double bright_ratio)
{
    t_light *light;

    if(!(light = (t_light *)malloc(sizeof(t_light))))
        return (NULL);
    light->origin = light_origin;
    light->color = light_color;
    light->bright_ratio = bright_ratio;
    return (light);
}

t_sphere	*sphere_init(t_vec center, double radius)
{
	t_sphere *sp;

	 if(!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
        return (NULL);
    sp->center = center;
    sp->radius = radius;
    return (sp);
}

t_object	*object_init(t_object_type type, void *element, t_vec albedo)
{
	t_object *new;

	if (!(new = (t_object *)malloc(sizeof(t_object))))
        return (NULL);
    new->type = type;
    new->element = element;
    new->next = NULL;
	new->albedo = albedo;
    return (new);
}

void        oadd(t_object **list, t_object *new)
{
    t_object    *cur;

    if (*list == NULL)
    {
        *list = new;
        return ;
    }
    cur = *list;
    while (cur->next)
        cur = cur->next;
    cur->next = new;
}

t_object    *olast(t_object *list)
{
    if (list == NULL)
        return (NULL);
    while (list->next)
        list = list->next;
    return (list);
}

t_vec	ray_at(t_ray ray, double t);

bool     hit_sphere(t_object *world, t_ray ray, t_hit_record *record)
{
	t_vec  oc;
    double  a;
    double  b;
    double  c;
    double  discriminant;
	t_sphere *sphere;


	sphere = world->element;
	record->albedo = world->albedo;
    oc = vec_sub(ray.origin, sphere->center);
    a = vec_dot(ray.direction, ray.direction);
    b = 2.0 * vec_dot(oc, ray.direction);
    c = vec_dot(oc, oc) - (sphere->radius * sphere->radius);
    discriminant = b * b - 4 * a * c;
	if (discriminant < 0) // 구와 광선이 교차하지 않는다.
		return (false);
	double root_min = (-b - sqrt(discriminant)) / (2.0 * a);
	double root_max = (-b + sqrt(discriminant)) / (2.0 * a);
	if (root_min < record->tmin || record->tmax < root_min)
	{
		if (root_max < record->tmin || record->tmax < root_max)
		{
			return (false);
		}
	}
	record->t = root_min;
	record->p = ray_at(ray, root_min);
	record->normal = vec_scale(vec_sub(record->p, sphere->center), 1.0 / sphere->radius);
  	record->front_face = vec_dot(ray.direction, record->normal) < 0;
	record->normal = (record->front_face) ? record->normal : vec_scale(record->normal, -1);
	return (true);
}

bool	hit_obj(t_object *world, t_ray *ray, t_hit_record *record);

bool	hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	bool          hit_anything;
    t_hit_record    temp_rec;

    temp_rec = *rec; // temp_rec의 tmin, tmax 값 초기화를 위해.
    hit_anything = false;
    while(world)
    {
        if (hit_obj(world, ray, &temp_rec))
        {
            hit_anything = true;
            temp_rec.tmax = temp_rec.t;
            *rec = temp_rec;
        }
        world = world->next;
    }
    return (hit_anything);
	return false;
}

bool	hit_obj(t_object *world, t_ray *ray, t_hit_record *record)
{
	bool  hit_result;

    hit_result = false;
    if (world->type == SP)
        hit_result = hit_sphere(world, *ray, record); //hit_sphere의 첫번째 인자도 t_sphere *에서 t_object *로 수정해주자.
    return (hit_result);
}

/**************************************************/
/* ray 											  */
/**************************************************/

t_ray	ray_init(t_vec origin, t_vec direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = direction;
	return ray;
}

t_vec	ray_at(t_ray ray, double t)
{
	return vec_add(ray.origin, vec_scale(ray.direction, t));
}

t_ray	ray_primary(t_camera camera, double h_ratio, double v_ratio)
{
	t_ray ray;

	ray.origin = camera.eye;
	ray.direction = vec_norm(vec_sub(vec_add(vec_add(camera.viewport_leftbottom,
							vec_scale(camera.viewport_horizontal, h_ratio)), vec_scale(camera.viewport_vertical, v_ratio)),
							camera.eye));
    return (ray);
}

t_vec    ray_color(t_ray ray, t_object *world)
{
    double  t;
	t_hit_record	record;

	record.tmin = 0;
	record.tmax = INFINITY;
	if (hit(world, &ray, &record))
	{
		return (vec_scale(vec_add(record.normal, vec_init(1, 1, 1)), 0.5));
	}
    t = 0.5 * (ray.direction.y + 1.0);
    return (vec_add(vec_scale(vec_init(1, 1, 1), 1.0 - t), vec_scale(vec_init(0.5, 0.7, 1.0), t)));
}

/**************************************************/
/* main 										  */
/**************************************************/

int main(void)
{
	// mlx
	void	*ptr;
	void	*win;
	int		bpp;
	int		len;
	void	*img;
	int		endian;
	char	*addr;
	char	*loc;
	int		**buffer;

	ptr = mlx_init();
	win = mlx_new_window(ptr, 1000, 750, "miniRT");
	img = mlx_new_image(ptr, 1000, 750);
	addr = mlx_get_data_addr(img, &(bpp), &(len), &(endian));
	buffer = malloc(sizeof(int *) * 1000);
	int index = 0;
	while (index < 750)
	{
		(buffer)[index] = malloc(sizeof(int) * 1000);
		++index;
	}

    int         row;
    int         col;
    double      u;
    double      v;
    t_vec    	pixel_color;
    t_canvas    canvas;
    t_camera    camera;
    t_ray       ray;
	t_object	*world;
	t_object	*lights;
	t_vec		ambient;
	double ka = 0.1;

    canvas = canvas_init(1000, 750);
    camera = camera_init(canvas, vec_init(0, 0, 0));
	world = object_init(SP, sphere_init(vec_init(-2, 0, -5), 2), vec_init(0.5, 0, 0)); // world 에 구1 추가
    oadd(&world, object_init(SP, sphere_init(vec_init(2, 0, -5), 2), vec_init(0, 0.5, 0))); // world 에 구2 추가
    oadd(&world, object_init(SP, sphere_init(vec_init(0, -1000, 0), 990), vec_init(1, 1, 1))); // world 에 구3 추가
    lights = object_init(1, light_init(vec_init(0, 5, 0), vec_init(1, 1, 1), 0.5), vec_init(0, 0, 0)); // 더미 albedo
	ambient = vec_scale(vec_init(1,1,1), ka);
	col = canvas.height - 1;
    while (col >= 0)
    {
        row = 0;
        while (row < canvas.width)
        {
            u = (double)row / (canvas.width - 1);
            v = (double)col / (canvas.height - 1);
            ray = ray_primary(camera, u, v);
			t_vec color = ray_color(ray, world);
			int r = (int)(color.x * 255);
			int g = (int)(color.y * 255);
			int b = (int)(color.z * 255);
            loc = addr + ((canvas.height - col - 1) * len + row * bpp / 8);
			*(unsigned int *)loc = (r << 16) | (g << 8) | b;
            ++row;
        }
        --col;
    }
	mlx_put_image_to_window(ptr, win, img, 0, 0);
	mlx_loop(ptr);
}
