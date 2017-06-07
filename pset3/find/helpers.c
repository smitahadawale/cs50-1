/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if(n <= 0)
     return false;
    int left = 0;
    int right = n-1;
    
    while(left <= right)
    {
        long mid = (left+right)/2;
        if(values[mid] == value)
            return true;
        if(values[mid] > value)
            right = mid-1;
        if(values[mid] < value)
            left = mid + 1;
        
    }
    
    return false;
    
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{ 
   int cnt[65536];
   for(int i=0; i<65536; i++)
        cnt[i] = 0;
   for(int i=0; i<n; i++)
        cnt[values[i]]++;
        
    for(int i=1; i<65536; i++)
        cnt[i] = cnt[i-1] + cnt[i];
    int k = 0;
     
    for(int i=0; i<65536; i++)
       {
           while(k <= cnt[i]-1)
            {   
                values[k++] = i;
            }
       }
   
    return;
}
