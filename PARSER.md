pour le parser les fichiers qui t'intéresse sont
- rt_scene.c
- rt_object.c
- rt_camera.c

La structure t_scene est la principale pour le parser:
- la camera
- une liste d'obj
- et le nombre d'objet
- il faudra penser a rajouter une skybox qui fonctionne comme lumiere ambiante (ce sera une structure avec 2 vecteurs et un pointeur sur fonction pour dessiner la skybox...)

L'utilisateur peut definir pour la camera:
- sa position
- la position de ce qu'elle regarde
- son fov (le champs de vision en angle, une valeur normale est entre 60 et 90)
- et l'aperture (le pourcentage de flou plus on s'éloigne du centre de vision entre 1.0 et 0.0)

Il peut definir l'objet a créer:
- le type,
- sa position
- et un parametre en fonction du type (edited)


Et le material:
- son type,
- sa couleur,
- et aussi un parametre en fonction


c'est la fonction new object qui s'occupe de creer l'objet et le materiel en meme temps... mais par soucis de norme et d'efficacité on devra la diviser en deux:
- creer le material indépendemment
- et creer l'objet avec un pointeur sur le material


a chaque creation d'objet, celui-ci est stocker dans un tableau t_obj:
- casté comme un void*
- avec son type
- un pointeur sur fonction pour dessiner l'objet a l'ecran
- et un pointeur sur le type de materiel


Le type de materiel est une structure qui possede:
- son type
- la couleur (albedo)
- un vecteur pour l'emission ou reflection du rayon
- un parametre t (specifique au materiel)
- et un pointeur sur fonction pour definir l'action du rayon (scatter)


Bien sur la lumiere est un materiel applicable a n'importe quel objet


Et la couleur et les positions sont des vecteurs detenus dans la structure t_vec3 (xyz peut devenir rgb)