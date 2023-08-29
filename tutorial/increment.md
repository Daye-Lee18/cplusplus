# a++ vs. ++a 

## a += b vs. a = +b 

a += b is equivalent to a = a+ b \
a = +b is equivalent to a = b 

## a++ vs. ++a 

- increment a by 1 
- In a nutshell, do the same thing but **return** value is different 
- a++: postfix increment,  returns the value of a before the increment 
- ++a: prefix increment, returns the value after the increment 




```c++ 
a = 10;
b = ++a; //a = 11, b = 11

a = 10;
b = a++; //a = 11, b = 10

```