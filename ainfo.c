/**********************************************
* Filename: ainfo.c
* Description: defines functions for LAB4
* Author: Yousef Qamhia
* Date: 9/20/2026
**********************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ainfo.h"


const char string_char[][4] = {
    "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL",
    "BS",  "HT",  "LF",  "VT",  "FF",  "CR",  "SO",  "SI",
    "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB",
    "CAN", "EM",  "SUB", "ESC", "FS",  "GS",  "RS",  "US",

    " ", "!", "\"", "#", "$", "%", "&", "'",
    "(", ")", "*", "+", ",", "-", ".", "/",

    "0", "1", "2", "3", "4", "5", "6", "7",
    "8", "9", ":", ";", "<", "=", ">", "?",

    "@", "A", "B", "C", "D", "E", "F", "G",
    "H", "I", "J", "K", "L", "M", "N", "O",
    "P", "Q", "R", "S", "T", "U", "V", "W",
    "X", "Y", "Z", "[", "\\", "]", "^", "_",

    "`", "a", "b", "c", "d", "e", "f", "g",
    "h", "i", "j", "k", "l", "m", "n", "o",
    "p", "q", "r", "s", "t", "u", "v", "w",
    "x", "y", "z", "{", "|", "}", "~", "DEL"
};

void displayASCII(int cols)
{
    int rows = (128 + cols - 1) / cols;

    for (int c = 0; c < cols; c++)
    {
        printf("Dec Hex     ");
    }
    printf("\n");

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            int value = row + col * rows;

            if (value < 128)
            {
                printf("%3d %02X %-3s  ",
                       value,
                       value,
                       string_char[value]);
            }
        }

        printf("\n");
    }
}

void displayCharValues(char* character)
{
    int value = character[0];
    char hex[3];
    char binary[9] = "";
    
    //found this to make hex[3] get the value of "%02X"
    sprintf(hex, "%02X", value);

    for (int i = 0; i < 2; i++)
    {
        switch (hex[i])
        {
            case '0': strcat(binary, "0000"); break;
            case '1': strcat(binary, "0001"); break;
            case '2': strcat(binary, "0010"); break;
            case '3': strcat(binary, "0011"); break;
            case '4': strcat(binary, "0100"); break;
            case '5': strcat(binary, "0101"); break;
            case '6': strcat(binary, "0110"); break;
            case '7': strcat(binary, "0111"); break;
            case '8': strcat(binary, "1000"); break;
            case '9': strcat(binary, "1001"); break;
            case 'A': strcat(binary, "1010"); break;
            case 'B': strcat(binary, "1011"); break;
            case 'C': strcat(binary, "1100"); break;
            case 'D': strcat(binary, "1101"); break;
            case 'E': strcat(binary, "1110"); break;
            case 'F': strcat(binary, "1111"); break;
        }
    }

    printf("Character %c\n", character[0]);
    printf("Decimal: %d\n", value);
    printf("Hex: %02X\n", value);
    printf("Binary: %s\n", binary);
}


