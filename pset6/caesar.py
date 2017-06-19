import cs50
import sys


if(len(sys.argv) != 2):
  print("Invalid Command Line Arguments");
  exit(1);

x = int(sys.argv[1]);
print("plaintext: ",end='');
inp = cs50.get_string();
length = len(inp);
out = "";

for i in range(0,length):
   
       if(inp[i] >= 'a' and inp[i] <= 'z'):
        out += chr(ord('a') + (((ord(inp[i])-ord('a'))+x)%26));
       elif(inp[i] >= 'A' and inp[i] <= 'Z'): 
        out += chr(ord('A') + (((ord(inp[i])-ord('A'))+x)%26));
       else:
        out += inp[i];
   
  
print("ciphertext:",out);
