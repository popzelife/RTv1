#include <stdlib.h>		// clang++ -O3 -o minirt minirt.cpp
#include <stdio.h>		// time ./minirt > minirt.ppm
#include <math.h>

#define PPM_X		1024
#define PPM_Y		512
#define OBJ_NB		9
#define POSX_OBJ	19
#define POSY_OBJ	0
#define POSZ_OBJ	12
#define	DIST_REF	.01
#define B(x)		str_to_binary(#x)
#define	MAT_SKY		0
#define	MAT_FLOOR	1
#define	MAT_MIR		2

static inline unsigned long long str_to_binary(const char *s)
{
	unsigned long long i = 0;

	while (*s)
	{
		i <<= 1;
		i += *s++ - '0';
	}
	return i;
}

struct vec3
{
	vec3(){}

	vec3(float a, float b, float c)
	{
		x = a; //b
		y = b; //g
		z = c; //r
	}

	//add
	vec3 operator+(vec3 r)
	{
		return vec3(x + r.x, y + r.y, z + r.z);
	}

	//scale
	vec3 operator*(float r)
	{
		return vec3(x * r, y * r, z * r);
	}

	//cross-product
	vec3 operator^(vec3 r)
	{
		return vec3(y * r.z - z * r.y, \
			z * r.x - x * r.z, \
			x * r.y - y * r.x);
	}

	//normalize
	vec3 operator!()
	{
		return *this * (1 / sqrt(*this % *this));
	}

	//dot
	float operator%(vec3 r)
	{
		return x * r.x + y * r.y + z * r.z;
	}

	float		x,y,z;
};

int		obj[OBJ_NB] = {	B(1000000000000000000),
						B(0100000000000111100),
						B(0100010110001000010),
						B(0100011001001000010),
						B(0100010001000111100),
						B(0100010001000001000),
						B(0100010001000001110),
						B(0011000000000010001),
						B(0000000000000001110) };

float		f_random()
{
	return(float)rand() / RAND_MAX;
}

int		get_material(vec3 v_orig, vec3 v_dir, float &t, vec3 &v_normal)
{
	int		material = MAT_SKY;
	float	p = -v_orig.z / v_dir.z;
	t = 1e9; //infinite dist
	if(.01 < p)
	{
		//intersect_plane
		t = p;
		v_normal = vec3(0, 0, 1);
		material = MAT_FLOOR;
	}
	//obj_list
	for(int k = POSX_OBJ; k--;)
	{
		for(int j = OBJ_NB; j--;)
		{
			if(obj[j] & 1 << k)
			{
				//intersect_sphere
				vec3	v_pos = v_orig + vec3(-k, POSY_OBJ, j - POSZ_OBJ);
				float	b = v_pos % v_dir;
				float	c = v_pos % v_pos - 1;
				float	q = b * b - c;
				if(q > 0)
				{
					float	s = -b - sqrt(q); //rounded reflection
					if(s < t && s > DIST_REF) 
					{
						t = s;
						v_normal = !(v_pos + v_dir * t);
						material = MAT_MIR;
					}
				}
			}
		}
	}
	return material;
}

vec3		scene(vec3 v_orig, vec3 v_dir)
{
	float		t;
	vec3		v_normal;
	int			material = get_material(v_orig, v_dir, t, v_normal);
	//skybox
	if(material == MAT_SKY)
		return vec3(.7, .6, 1) * pow(1 - v_dir.z, 4);
	//get_light && emission_reflect
	vec3	v_emission = v_orig + v_dir * t;
	vec3	v_light = !(vec3(9 + f_random(),9 + f_random(),16) + \
		v_emission * -1);
	vec3	v_reflect = v_dir + v_normal * (v_normal % v_dir * -2);
	float	shadow = v_light % v_normal;
	//shadow
	if(shadow < 0 || get_material(v_emission, v_light, t, v_normal))
		shadow = 0;
	if(material == MAT_FLOOR)
	{
		//floor
		v_emission = v_emission * .2;
		if ((int)(ceil(v_emission.x) + ceil(v_emission.y)) & 1)
			return vec3(3, 3, 3) * (shadow * .2 + .1);
		else
			return vec3(3, 1, 1) * (shadow * .2 + .1);
	}
	//mirror_specular
	float	specular = pow(v_light % v_reflect * (shadow > 0), 99);
	return vec3(specular, specular, specular) + \
		scene(v_emission, v_reflect) * (shadow ? .5 : shadow + .2);
}

int		main(void)
{
	printf("P6 %d %d 255 ", PPM_X, PPM_Y);
	vec3	cam_pos = !vec3(-12, -15, 0);
	vec3	cam_up = vec3(0, 0, 1);
	vec3	cam_rotate = !(cam_up ^ cam_pos) * .002;
	vec3	b = !(cam_pos ^ cam_rotate) * .002;
	vec3	c = (cam_rotate + b) * -256 + cam_pos;
	for(int y = PPM_Y; y--;)
	{
		for(int x = PPM_X; x--;)
		{
			vec3	p(13, 13, 13);
			for(int r = 64; r--;)
			{
				//add_noise
				vec3	v_noise = cam_rotate * (f_random() - .5) * 99 + b * (f_random() - .5) * 99;
				p = scene(vec3(17, 16, 8) + v_noise, \
					!(v_noise * -1 + (cam_rotate * (f_random() + x) + b * \
					(y + f_random()) + c) * 16)) * 3.5 + p;
			}
			printf("%c%c%c",(int)p.x, (int)p.y, (int)p.z);
		}
	}
	return (0);
}
