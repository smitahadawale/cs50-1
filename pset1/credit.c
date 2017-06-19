#include<stdio.h>
#include <cs50.h>

int main(void)
{
    
    printf("Number: ");
    long long x = get_long_long();
    
    long long tmp = x;
    
    
    int cnt = 0;
    int curr = 0;
    int sum1 = 0;
    int sum2 = 0;
    int first = -1;
    int sec = -1;
    while(tmp != 0)
    {
        int rem = tmp % 10; 
        cnt++;
        if(curr == 0)
            sum2 += rem;
        if(curr == 1)
            {
                int prod = 2 * rem;
                if(prod >= 10)
                {
                    sum1 += 1 + (prod % 10);
                   
                }
                else
                {
                    sum1 += prod;
                }
            }
        curr = 1-curr;
        tmp /= 10;
        sec = first;
        first = rem;
        
    }
    int valid = 0;
  
    if(cnt == 15)
    {
        if((first == 3 && sec == 4) || (first == 3 && sec == 7))
        {
            if((sum1 + sum2)%10 == 0)
                valid = 1;
        }
    }
    if(cnt == 16)
    {
        if(first == 5 && ( sec == 1 || sec == 2 || sec == 3 || sec == 4 || sec == 5))
        {
            if((sum1 + sum2)%10 == 0)
                valid = 2;
        }
    }
    if(cnt == 13 || cnt == 16)
    {
        if(first == 4)
        {
            if((sum1 + sum2)%10 == 0)
                valid = 3;
        }
    }
    if(valid == 1)
        printf("AMEX\n");
    else if(valid == 2)
        printf("MASTERCARD\n");
    else if(valid == 3)
        printf("VISA\n");
    else 
        printf("INVALID\n");
  
    
}