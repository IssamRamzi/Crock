# TODO - Math Library for OpenGL Game Engine

## Vecteurs (Améliorations/Corrections)
- [ ] **Vec2/Vec3/Vec4**
  - [ ] Ajouter produits scalaires (`dot`)
  - [ ] Ajouter produits vectoriels (`cross`, pour Vec3)
  - [ ] Normalisation (`normalize()`, `length()`, `lengthSquared()`)
  - [ ] Swizzling (ex: `vec3.xy()`, `vec4.yz()`)
  - [ ] Méthodes de réflexion/réfraction
  - [ ] Distance entre 2 vecteurs
  - [ ] Lerp/Slerp (interpolation)
  - [ ] Angles entre vecteurs
  - [ ] Projection (d'un vecteur sur un autre)

## Matrices
- [ ] **Matrix Générique**
  - [ ] Transposition
  - [ ] Déterminant
  - [ ] Inversion matricielle
  - [ ] Méthodes de décomposition (LU, QR)
  - [ ] Opérateurs manquants (`==`, `!=`)

- [ ] **Matrix3 (Spécialisation 3x3)**
  - [ ] Constructeurs spécifiques
  - [ ] Conversion depuis/vers Quaternion
  - [ ] Méthodes pour les transformations 2D

- [ ] **Matrix4 (Spécialisation 4x4)**
  - [ ] Constructeurs spécifiques
  - [ ] Méthodes pour transformations 3D :
    - [ ] `perspective()` (projection perspective)
    - [ ] `ortho()` (projection orthographique)
    - [ ] `lookAt()` (matrice de vue)
    - [ ] `rotate()`, `translate()`, `scale()`
  - [ ] Décomposition TRS (Translation/Rotation/Scale)

## Quaternions
- [ ] Classe `Quaternion`
  - [ ] Représentation (x, y, z, w)
  - [ ] Normalisation
  - [ ] Conjugaison
  - [ ] Multiplication
  - [ ] Conversion depuis/vers :
    - [ ] Matrice 3x3/4x4
    - [ ] Angles d'Euler
    - [ ] Axe + Angle
  - [ ] Interpolation (Slerp)
  - [ ] Rotation de vecteurs

## Transformations
- [ ] Classe `Transform`
  - [ ] Combinaison position (vec3), rotation (quaternion), échelle (vec3)
  - [ ] Génération de matrice modèle
  - [ ] Méthodes pour :
    - [ ] Parent/enfant
    - [ ] Transformation de points/vecteurs
    - [ ] Calcul des directions (forward/right/up)

## Géométrie
- [ ] **Primitives**
  - [ ] `Ray` (origine + direction)
  - [ ] `Plane` (normal + distance)
  - [ ] `Sphere` (centre + rayon)
  - [ ] `AABB` (boîte alignée aux axes)
  - [ ] `Frustum` (pour le culling)
  
- [ ] **Tests d'intersection**
  - [ ] Ray-Sphere
  - [ ] Ray-AABB
  - [ ] Ray-Plane
  - [ ] Sphere-Sphere
  - [ ] AABB-AABB
  - [ ] Frustum-Sphere
  - [ ] Frustum-AABB

## Utilitaires Mathématiques
- [ ] Fonctions de base :
  - [ ] `clamp()`, `lerp()`, `smoothstep()`
  - [ ] `min()`, `max()`, `abs()`
  - [ ] Fonctions trigonométriques
  - [ ] Conversion degrés/radians
  - [ ] Génération de bruit (Perlin/Simplex)
  - [ ] Randomisation

## Optimisations
- [ ] Compatibilité SIMD (SSE/AVX)
- [ ] Précalcul de valeurs fréquentes
- [ ] Compilation conditionnelle pour la précision (float/double)
- [ ] Benchmark des opérations critiques

## Intégration OpenGL
- [ ] Upload vers les shaders :
  - [ ] `glUniform` compatible
  - [ ] Buffer objects (VBO/UBO)
- [ ] Conversion depuis/vers GLM (si besoin)
- [ ] Alignement mémoire pour OpenGL

## Tests
- [ ] Tests unitaires pour toutes les opérations
- [ ] Validation numérique (stabilité)
- [ ] Benchmarks de performance

## Documentation
- [ ] Doxygen/commentaires détaillés
- [ ] Exemples d'utilisation
- [ ] Guide d'optimisation

## Organisation du code
- [ ] Namespace dédié (ex: `Math` ou `CrockMath`)
- [ ] Fichiers séparés pour :
  - [ ] Vecteurs
  - [ ] Matrices
  - [ ] Quaternions
  - [ ] Transformations
  - [ ] Géométrie