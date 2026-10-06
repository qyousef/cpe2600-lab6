/**********************************************
* Filename: vector.c
* Description: defines functions for vectors in LAB5
* Author: Yousef Qamhia
* Date: 9/29/2026
**********************************************/
#include "vector.h"
#include "stdio.h"


Vector add(Vector a, Vector b)
{
    Vector result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}


Vector subtract(Vector a, Vector b)
{
    Vector result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result; 
}


Vector multiply(Vector a, double scalar)
{
    Vector result;
    result.x = a.x * scalar;
    result.y = a.y * scalar;
    result.z = a.z * scalar;
    return result;
}


double dot(Vector a, Vector b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z); 
}


Vector cross(Vector a, Vector b)
{
    Vector result;
    result.x = (a.y * b.z) - (a.z * b.y);
    result.y = (a.z * b.x) - (a.x * b.z);
    result.z = (a.x * b.y) - (a.y * b.x);
    return result;
}


void printVector(Vector v)
{
    printf("%c = (%d, %d, %d)", v.name, v.x, v.y, v.z);
}
