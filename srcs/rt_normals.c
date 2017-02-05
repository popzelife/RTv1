#include "../includes/rtv1.h"

t_vec3		normale(t_obj *obj, t_env *env, t_vec cam)
{
	t_vec3	result;
	t_vec3	tmp;
	t_vec3	temp;

	if (obj->type == OBJ_PLANE)
	{
		result = obj->rot;
		result = inv(result, env, obj);
	}
	else
	{
		if (obj->type == OBJ_SPHERE)
			result = sub_vect(cam, obj->pos);
		else
		{
			temp = scale_vect(obj->rot, dot_vect(env->ray_dir, obj->rot) * \
					env->d + dot_vect(sub_vect(env->cam_pos, obj->pos), obj->rot));
			if (obj->type == OBJ_CONE)
				temp = scale_vect(temp, \
						(1 + powf(tanf(deg_to_rad(obj->size)), 2)));
			tmp = sub_vect(cam, obj->pos);
			result = sub_vect(tmp, temp);
		}
	}
	return (norm_vect(result));
}

cylinder_normal()
{

}

void		get_normal(t_vector3 *norm, t_obj *hit_obj, t_vector3 *hit_pt)
{
	if (hit_obj->type == OBJ_PLANE)
		plane_normal(norm, hit_obj);
	else if (hit_obj->type == OBJ_SPHERE)
		sphere_normal(norm, hit_obj, hit_pt);
	else if (hit_obj->type == OBJCONE)
		cone_normal(norm, hit_obj, hit_pt);
	else if (hit_obj->type == OBJ_CYLINDER)
		cylinder_normal(norm, hit_obj, hit_pt);
}
