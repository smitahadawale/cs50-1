import cs50


n = 0 ;
while True:
    print("Height: ",end='');
    n = cs50.get_int();
    if n>=0 and n<=23:
        break;

for i in range(1,n+1):
    for j in range(1,n-i+1):
        print(" ",end='');
    for j in range(1,i+2):
        print("#",end='');
    print();
    
    
    
