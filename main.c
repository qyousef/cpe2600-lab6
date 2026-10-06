/**********************************************
* Filename: main.c
* Description: defines functions for LAB4
* Author: Yousef Qamhia
* Date: 9/20/2026
* used make for this app
* gcc -o LAB4 main.c ainfo.c
**********************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ainfo.h"

int main(int argc, char* argv[])
{
    int cols = 8;

    switch(argc)
    {
        case 1:
            displayASCII(cols);
            break;

        case 2:
            if (strlen(argv[1]) == 1)
            {
                displayCharValues(argv[1]);
            }
            else 
            {
                printf("Invalid command.\n");
            }
            break;

        case 3:
            if (strcmp(argv[1], "-c") == 0)
            {   
                cols = atoi(argv[2]);
                if (cols >  8 || cols < 1)
                {
                    printf("Invalid number of columns\n");
                }
                else 
                {
                    displayASCII(cols);
                }
            }
            else
            {
                printf("Invalid run command\n");
            }
            break;

        default:
            printf("Invalid run command\n");
            break;
    }

    return 0;
}