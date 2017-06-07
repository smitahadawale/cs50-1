#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc,char *argv[])
{
   if(argc != 2)
   {
       printf("Invalid Command Line Arguments");
       return 1;
   }
   int x = atoi(argv[1]);
   printf("plaintext: ");
   string in = get_string();
   int len = strlen(in);
   char out[len];
  
   for(int i=0; i<len; i++)
   {
       if(in[i] >= 'a' && in[i] <= 'z') 
        out[i] = 'a' + (((in[i]-'a')+x)%26);
       else if(in[i] >= 'A' && in[i] <= 'Z') 
        out[i] = 'A' + (((in[i]-'A')+x)%26);
       else
        out[i] = in[i];
   }
  
    printf("ciphertext: %s\n",out);
}