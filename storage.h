/**********************************************
* Filename: storage.h
* Description: declares functions for mempry in LAB7
* Author: Yousef Qamhia
* Date: 9/29/2026
**********************************************/
#ifndef STORAGE_H
#define STORAGE_H

#include "vector.h"

int newVect(char *name, double x, double y, double z);
Vector findvect(char *name);
void clearVectors(void);
void listVectors(void);

void loadVectors(char *filename);
void saveVectors(char *filename);


#endif