# include "rtv1.h"

t_cylinder	*new_cylinder(t_vec3 *center, const double radius)
{
	t_cylinder	*c;

	c = malloc(sizeof(t_cylinder));
	c->center = center;
	c->radius = radius;
	c->radius2 = radius * radius;
	c->rot = v3_new_vec(0, 1, 0);
	v3_normalize(c->rot);
	return (c);
}
/*
BOOL    bound_box_cylinder(void *obj, t_bound_box *box, const double t0, \
		const double t1)
{
	t_cylinder    *cyl;
	t_vec3      *vmin;
	t_vec3      *vmax;

	(void)t0;
	(void)t1;
	cyl = (t_cylinder*)obj;
	vmin = v3_sub_vec(*(cyl->center), \
			v3(cyl->radius, cyl->radius, cyl->radius));
	vmax = v3_add_vec(*(cyl->center), \
			v3(cyl->radius, cyl->radius, cyl->radius));
	box = new_bound_box(vmin, vmax);
	return (TRUE);
}
*/

BOOL	hit_cylinder(void *obj, const t_ray *ray, const double t_min, \
		const double t_max, t_hit *param)
{
	t_cylinder	*cyl;
	t_vec3	*oc;
	t_vec3	*v;
	t_vec3	*set;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	temp;
	t_vec3	yo;
	t_vec3	tmp;

	cyl = (t_cylinder*)obj;
	oc = v3_sub_vec(*(ray->orig), *(cyl->center));
	a = v3_dot_double(*(ray->dir), *(ray->dir)) - \
		pow(v3_dot_double(*(ray->dir), *(cyl->rot)), 2);
	b = 2 * (v3_dot_double(*(ray->dir), *oc) - v3_dot_double(*(cyl->rot), *(ray->dir)) * v3_dot_double(*oc, *(cyl->rot)));
	c = v3_dot_double(*oc, *oc) - pow(v3_dot_double(*(cyl->rot), *oc), 2) - cyl->radius2;
	discriminant = b * b - (4 * a * c);
	v3_free(oc);
	if (discriminant > 0)
	{
		temp = (-b - sqrt(discriminant) / (2 * a));
		if (temp < t_max && temp > t_min)
		{
			param->t = temp;
			set = ray_point_at(ray, param->t);
			v3_set(param->pos, set->x, set->y, set->z);
			v3_free(set);
			v = v3_sub_vec(*(param->pos), *(cyl->center));
			set = v3_div_vec(*v, cyl->radius);
			yo = v3_scale_vec(((param->rot, v3_dot_double(*ray->dir, *(param->rot) * param->t + v3_dot_double(v3_sub_vec(*(ray->orig) , *(param->pos), *(param->rot));
			tmp = v3_sub_vec(ray, *(param->pos);
			set = v3_sub_vec(*(tmp), *(yo));
			v3_set(param->normal, set->x, set->y, set->z);
			v3_free(set);
			v3_free(v);
			return (TRUE);
		}
		temp = (-b + sqrt(discriminant) / (2 * a));
		if (temp < t_max && temp > t_min)
		{
			param->t = temp;
			set = ray_point_at(ray, param->t);
			v3_set(param->pos, set->x, set->y, set->z);
			v3_free(set);
			v = v3_sub_vec(*(param->pos), *(cyl->center));
			set = v3_div_vec(*v, cyl->radius);
			v3_set(param->normal, set->x, set->y, set->z); // normale a changer ?
			cylinder_norm(param->normal);
			v3_free(set);
			v3_free(v);
			return (TRUE);
		}
	}
	return (FALSE);
}
