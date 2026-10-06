/**********************************************
* Filename: vector.h
* Description: declares functions for vectors in LAB5
* Author: Yousef Qamhia
* Date: 9/29/2026
**********************************************/
#ifndef VECTOR_H
#define VECTOR_H

typedef struct 
{
    char name[8];
    double x;
    double y;
    double z;
} Vector; 

Vector add(Vector a, Vector b);
Vector subtract(Vector a, Vector b);
Vector multiply(Vector a, double scalar);

double dot(Vector a, Vector b);
Vector cross(Vector a, Vector b);

void printVector(Vector v);

#endif