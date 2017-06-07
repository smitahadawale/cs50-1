#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    
    string name = get_string();
    int len = strlen(name);
    char ans[len];  int k = 0;  
    if(name[0] != ' ')
     ans[k++] = toupper(name[0]);
    for(int i=1; i<len; i++)
        if(name[i-1] == ' ' && name[i] != ' ')
            ans[k++] = toupper(name[i]);
    ans[k++] = '\0';
    printf("%s\n",ans);
}