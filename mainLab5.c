/**********************************************
* Filename: mainLab7.c
* Description: main file for LAB7
* Author: Yousef Qamhia
* Date: 9/29/2026
* gcc vector.c mainLab5.c storage.c -o miniMat7
**********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "storage.h"

//Check whether a word is a number and gets its value
int getNumber(char *word, double *number)
{
    return sscanf(word, "%lf", number) == 1;
}

//Perform operation after parsing  
//Return 0 if operation can't be done
int calculate(char *left, char *op, char *right, Vector *result)
{
    Vector a, b;
    double number;

    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0)
    {
        a = findvect(left);
        b = findvect(right);

        if (a.name[0] == '\0')
        {
            printf("Vector %s not found.\n", left);
        }

        if (b.name[0] == '\0')
        {
            printf("Vector %s not found.\n", right);
        }

        if (a.name[0] == '\0' || b.name[0] == '\0')
        {
            return 0;
        }
        

        if (strcmp(op, "+") == 0)
            *result = add(a, b);
        else
            *result = subtract(a, b);

        return 1;
    }

    if (strcmp(op, "*") == 0)
    {
        
        if (getNumber(right, &number))
        {
            a = findvect(left);
        }
        else if (getNumber(left, &number))
        {
            a = findvect(right);
        }
        else
        {
            printf("Scalar multiplication needs a number.\n");
            return 0;
        }

        if (a.name[0] == '\0')
        {
            printf("Vector not found.\n");
            return 0;
        }

        *result = multiply(a, number);
        return 1;
    }

    printf("Invalid operation.\n");
    return 0;
}

//parsing 
void calculator(void)
{
    char line[100];
    char *words[8];
    char *word;
    int count;
    Vector result;
    double x, y, z;


    printf("hello!\n");
    while (1)
    {
        printf("MiniMat> ");
        // Get user input
        if (fgets(line, sizeof(line), stdin) == NULL)
        break;

        //get input
        count = 0;
        word = strtok(line, " ,\n");
        while (word != NULL && count < 8)
        {
            words[count] = word;
            count++;
            word = strtok(NULL, " ,\n");

        }

        if (count == 0)
            continue;

        if (count == 1)
        {
            if (strcmp(words[0], "quit") == 0){
                printf("Thank you for using this app :)\n");
                break;
            }
            else if (strcmp(words[0], "clear") == 0)
            {
                clearVectors();
            }
            else if (strcmp(words[0], "list") == 0)
            {
                listVectors();
            }
            else
            {
                result = findvect(words[0]);
                if (result.name[0] == '\0')
                {
                    printf("Vector not found.\n");
                }
                else
                {
                    printVector(result);
                }
            }
        }


        // Load or save vectors
        else if (count == 2 && strcmp(words[0], "load") == 0)
        {
            loadVectors(words[1]);
        }
        else if (count == 2 && strcmp(words[0], "save") == 0)
        {
            saveVectors(words[1]);
        }

        // a + b, ans =.....
        else if (count == 3)
        {
            if (calculate(words[0], words[1], words[2], &result))
            {
                strcpy(result.name, "ans");
                printVector(result);
            }
        }

        // make vect  or operation
        else if (count == 5 && strcmp(words[1], "=") == 0)
        {
            if (strlen(words[0]) > 7)
            {
                printf("Vector name must be at most 7 characters.\n");
                continue;
            }

            // c = a + b
            if (count == 5 &&
                (strcmp(words[3], "+") == 0 ||
                 strcmp(words[3], "-") == 0 ||
                 strcmp(words[3], "*") == 0))
            {
                if (calculate(words[2], words[3], words[4], &result))
                {
                    strcpy(result.name, words[0]);
                    newVect(result.name, result.x, result.y, result.z);
                    printVector(result);
                }
            }
            // a = 1 2 3 or b = 4, 5, 6.
            else
            {
                if (getNumber(words[2], &x) &&
                    getNumber(words[3], &y) &&
                    getNumber(words[4], &z))
                {
                    if (newVect(words[0], x, y, z))
                    {
                        printVector(findvect(words[0]));
                    }
                }
                else
                {
                    printf("Invalid assignment.\n");
                }
            }
        }
        else
        {
            printf("Invalid command.\n");
        }
    }
    clearVectors();
}

// Show usage for -h or start app
int main(int argc, char *argv[])
{
    if (argc == 2 && strcmp(argv[1], "-h") == 0)
    {
        printf("Usage: minimat -h\n");
        printf("Assign: a = 1 2 3  or  a = 1,2,3\n");
        printf("Math: a + b, a - b, a * 2, 2 * a\n");
        printf("Save result: c = a + b\n");
        printf("Commands: name, list, clear, quit\n");
        printf("Load vectors: load <filename>\n");
        printf("Save vectors: save <filename>\n");
        printf("Use spaces around =, +, -, and *.\n");
        return 0;
    }
    if (argc != 1)
    {
        printf("Usage: minimat -h\n");
        return 1;
    }

    calculator();
    return 0;
}