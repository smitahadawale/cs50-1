#include<stdio.h>
#include <cs50.h>
int main(void)
{
   
    printf("Minutes: ");
    int minutes = GetInt();
    printf("Bottles: %d\n",minutes*12);
}