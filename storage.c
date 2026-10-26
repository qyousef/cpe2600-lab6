/**********************************************
* Filename: storage.c
* Description: defines functions for mempry in LAB7
* Author: Yousef Qamhia
* Date: 9/29/2026
**********************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "storage.h"

static Vector *vectors = NULL;
static int vectorCount = 0;
static int capacity = 0;

int newVect(char *name, double x, double y, double z)
{
    int i;
    for (i = 0; i < vectorCount; i++) 
    {
        if (strcmp(vectors[i].name, name) == 0)
            break;
    }
    if (i == vectorCount)
    {
        if (vectorCount == capacity)
        {
            int newCapacity;
            if (capacity == 0)
            {
                newCapacity = 10;
            }
            else
            {
                newCapacity = capacity * 2;
            }

            Vector *temp = realloc(vectors, newCapacity * sizeof(Vector));
            if (temp == NULL)
            {
                printf("Not enough memory.\n");
                return 0;
            }
            vectors = temp;
            capacity = newCapacity;
        }
        vectorCount++;
    }

    
    strcpy(vectors[i].name, name);
    vectors[i].x = x;
    vectors[i].y = y;
    vectors[i].z = z;
    return 1;
}

Vector findvect(char *name)
{
    for (int i = 0; i < vectorCount; i++) 
    {
        if (strcmp(vectors[i].name, name) == 0)
        {
            return vectors[i];

        }
    }
    Vector missing = {"", 0, 0, 0};
    return missing;
}

void clearVectors()
{   
    free(vectors);
    vectors = NULL;
    vectorCount = 0;
    capacity = 0;
}

void listVectors()
{
    for (int i = 0; i < vectorCount; i++)
    {
        printVector(vectors[i]);
    }
}

// Load CSV rows and overwrite existing vectors with matching names
// saw this on parsing csv, more simple than using tokens like in file_read_cvs2.c on cavas
// https://codeoftheday.net/docs/c/intermediate/file-io/lab-csv-parser
// sscanf saves makes life a whole lot easier. One tricky part was what goes sscanf(line, **here**), 
// I used chatgpt's help with that part, makes a lot of sense and helps a lot
void loadVectors(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Cannot open file: %s\n", filename);
        return;
    }

    char line[100], name[8], extra;
    double x, y, z;

    while (fgets(line, 100, fp))
    {
        if (line[0] == '\n' || line[0] == '\r')
            continue;

        if (sscanf(line, " %7[^,],%lf,%lf,%lf %c", name, &x, &y, &z, &extra) != 4)
        {
            printf("Invalid CSV line.\n");
            continue;
        }
        newVect(name, x, y, z);
    }
    fclose(fp);
}

//save vectors to a csv file
void saveVectors(char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Cannot save file: %s\n", filename);
        return;
    }

    for (int i = 0; i < vectorCount; i++)
        fprintf(file, "%s,%.2f,%.2f,%.2f\n", vectors[i].name,
                vectors[i].x, vectors[i].y, vectors[i].z);

    fclose(file);
}






