import cs50

    
print("Number: ",end = '');
x = cs50.get_int();
    
tmp = x;
    
    
cnt = 0;
curr = 0;
sum1 = 0;
sum2 = 0;
first = -1;
sec = -1;
while tmp != 0:
    rem = tmp % 10; 
    cnt = cnt + 1;
    if(curr == 0):
        sum2 += rem;
    if(curr == 1):
        prod = 2 * rem;
        if(prod >= 10):
            sum1 += 1 + (prod % 10);
        else:
            sum1 += prod;
            
         
    curr = 1-curr;
    tmp //= 10;
    sec = first;
    first = rem;
        
    
valid = 0;

if(cnt == 15):
    if((first == 3 and sec == 4) or (first == 3 and sec == 7)):
        if((sum1 + sum2)%10 == 0):
                valid = 1;
if(cnt == 16):
    if(first == 5 and ( sec == 1 or sec == 2 or sec == 3 or sec == 4 or sec == 5)):
        if((sum1 + sum2)%10 == 0):
             valid = 2;
        
    
if(cnt == 13 or cnt == 16):
    if(first == 4):
        if((sum1 + sum2)%10 == 0):
                valid = 3;
        
    
if(valid == 1):
        print("AMEX");
elif(valid == 2):
        print("MASTERCARD");
elif(valid == 3):
        print("VISA");
else: 
        print("INVALID");
  
    
