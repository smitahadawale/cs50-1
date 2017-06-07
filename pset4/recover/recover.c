  
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
   
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./copy file \n");
        return 1;
    }

    
    char *file = argv[1];
    

    
    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", file);
        return 2;
    }
    
	int cnt = 0;
	FILE *out  ;
    int first = 1;
    BYTE curr_block[512];
    
    while(fread(curr_block, 512, 1, fp) > 0)
		{
				
			if(curr_block[0] == 0xff && curr_block[1] == 0xd8 && curr_block[2] == 0xff && 
                                    ((curr_block[3] & 224) == 224) )
				{
					 if (!first)
        			 {
        			 	fclose(out);
        			 }
        			 else
        			 {	
        			 	first = 0;
        			 	
        			 }
            
        		 char name[8];
            	sprintf(name, "%03d.jpg", cnt);
            	out = fopen(name,"w");
            	cnt++;
						
				}
				if (!first)
    			 {
    			 	fwrite(&curr_block,512,1,out);
				 }
		}
    
	
	if(out)
      fclose(out);
    

		fclose(fp);
		return 0;
}