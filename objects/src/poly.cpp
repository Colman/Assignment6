/*
Author:  Herb Yang, Oct. 22, 2018
Purpose:
Scene Object: Polygon
The polygon is specified by n vertices, p1, p2, ...
*/

#include <math.h>
#include "poly.h"
#include "vector3.h"
#include "plucker.h"


// ========================================================================
//     getNormal of polygon
// ========================================================================

// Return the normal vector for the given point on the surface
// The vertices are specified in CCW direction.
//
// point is here because to be consistent with other objects.
Vector3 Poly::getNormal(Vector3 *point) {


    return normal;// already computed when the attributes are set
} // getNormal
// ========================================================================
//     return true if specular
// ========================================================================
bool Poly::isSpecular()
{
    return( specular.r>0 || specular.g>0 || specular.b>0);
}
// ========================================================================
//     return true if diffuse
// ========================================================================
bool Poly::isDiffuse()
{
    return( diffuse.r>0 || diffuse.g>0 || diffuse.b>0);
}

// ========================================================================
//    Plucker test to check if the ray goes through the object
// ========================================================================
bool Poly::pluckerTest(Ray *ray){
    bool flag = false;
    // Complete this function
    return flag;
}

// Find and return, in t, the earliest intersection point, in the
// range [t0,t1), along the given ray. Returns 1 if such a t exists,
// false otherwise
bool Poly::intersect(RTfloat *t,  Ray *ray, RTfloat t0,  RTfloat t1)
{
    bool flag = false;
    // complete this function

    return flag;
} // intersect()
// getDiffuse() - return the diffuse coefficient
Color Poly::getDiffuse() {
    return diffuse;
}
// getSpecular() - return the specular coefficient
Color Poly::getSpecular() {
    return specular;
}
// getDiffuse() - return the ambient coefficient
Color Poly::getAmbient() {
    return ambient;
}
// getSpecularExp() - return the Specular Exponent coefficient
RTfloat Poly::getSpecularExp() {
    return specularExp;
}
// set the attributes of the polygon
// The order of the attributes is given below:
// nVertices
// vertices[0].x, vertices[0].y, vertices[0].z
// vertices[1].x, vertices[1].y, vertices[1].z
// ...
// vertices[nVertices-1].x, vertices[nVertices-1].y, vertices[nVertices-1].z
// diffuse.r
// diffuse.g
// diffuse.b
// ambient.r
// ambient.g
// ambient.b
// specular.r
// specular.g
// specular.b
// specularExp
void Poly::setAttributes(vector<double> a) {
    int i = 0;
    nVertices =a[i++];
    vertices = new Vector3[nVertices];
    for(int j=0;j<nVertices;j++){
        vertices[j].x = a[i++];
        vertices[j].y = a[i++];
        vertices[j].z = a[i++];
    }
    diffuse.r = a[i++];
    diffuse.g = a[i++];
    diffuse.b = a[i++];
    ambient.r = a[i++];
    ambient.g = a[i++];
    ambient.b = a[i++];
    specular.r = a[i++];
    specular.g = a[i++];
    specular.b = a[i++];
    specularExp = a[i++];
    Vector3 aa = vertices[1]-vertices[0];
    Vector3 bb = vertices[nVertices-1]-vertices[0];
    normal = aa*bb; // cross product
    normal.normalize();
}
