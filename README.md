![42-Project](https://dl.dropboxusercontent.com/u/59532932/48-cole204220logo.png)
# RTv1
Raytracer in C using SDL2 and OpenCL. Generate a 3D view out of a given scene :

- SDL only used to manage windows, hook events and draw a pixel on surface;
- Simple objects, only sphere for now; 
- Materials such as Lambert and Metal (with reflections);
- Objects hold in placeholder list with function pointers according to type and material;
- Generated "Skybox" (radiant) for background; 
- Anti-aliasing with max depth for reflection;
- Multithreading paralelizing raytracing computing by lines (not in available in debugg);
- Open CL to use GPU (planned feature).

# In Developement

- Parser for scene files (for now a default scene is provided);
- Light spots;
- Moveable camera;
- Debugg material function pointers;

# Preview
#### Lambert and Metal Spheres
![preview](rtv1-preview.jpg)

#### Infinite Mirror Surface
![preview2](rtv1-preview2.jpg)
