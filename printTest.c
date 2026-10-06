#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
int rows = 11;
// make sure there is an arg
if(argc>1)
{
rows = atoi(argv[1]);
}
printf("-----------------------\n");
for (int i=0; i<rows; i++)
{
printf("|%10d|%10x|\n",i,i);
}
printf("-----------------------\n\n");
printf("-----------------------\n");
for (int i=0; i<rows; i++)
{
printf("|%-10d|%-10x|\n",i,i);
}
printf("-----------------------\n\n");
return 0;
}