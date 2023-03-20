// C code to determine whether two values are equal instead of using arithmetic or comparison operators  
#include<stdio.h>  
int main ()  
{  
// Taking two variables   
int a = 12;  
int b = 12;  
if ( !( a ^ b ) )  
    printf ( " a is equal to b" );  
else  
    printf ( " a does not match b " );  
return 0;  
}  
