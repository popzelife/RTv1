-------
-------
#CAMERA --Creating camera, aperture is for blur
camera:
pos:
	0, 0, -250
lookat:
	0, 0, 1
fov:
	60
aperture:
	0.4
-------
-------
#AMBIENT --Used as horizon and ambient light
ambient:
	skybox_gradient
color1:
	125, 58, 58
color2:
	128, 200, 200
-------
-------
#OBJECT --Object list
sphere:
pos:
	2, 1, 2
radius:
	5
rot:
	1, 1, 1
------- --Material for previous object
mat:
	metal
color:
	255, 255, 120
param:
	0.0

--OTHER METHOD USING NAME AND POINTER TO NAMED OBJECT/MAT
-------
-------
#MATERIAL
mat: fuzzy_grey_metal --name for pointer
	metal
color:
	255, 255, 255
param:
	0.5
-------
mat: red_lambert --name for pointer
	lambertian
color:
	255, 0, 0
-------
mat: white-spot --name for pointer
	diffuse-light
color:
	255, 255, 255
-------
-------
#OBJECT
sphere: spot --name for pointer
pos:
	-200, -100, -250
radius:
	200
rot:
	1, 1, 1
------- --Material for previous object
mat: white_spot --pointer to material
------- --NEW OBJECT
sphere: sphere1 --name for pointer
pos:
	-200, -100, -250
radius:
	200
rot:
	1, 1, 1
------- --Material for previous object
mat: red_lambert --pointer to material
-------
-------
#LIGHT
spot: sphere1, white_spot --pointer to object, material
-------
-------
#OBJECT --Method making copies of already existing object
sphere: sphere1 --pointer to object plus new pos for object
pos:
	0, 0, 0
------ --Material for previous object
mat: white_light --pointer to material plus new color for mat
color:
	128, 250, 250

--Using pointer of material only assign mat to object without copying it
--Using pointer of object will copy the new object but for sake of rendering, it is better for user to assign a new position
--Assigning new parameter to material pointers will then make a copy of the new material