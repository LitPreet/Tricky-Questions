
#include<iostream>
         

using namespace std;

int main()
{

int ARR[10] = {4,3,8,0,12,4,14,43,10,9};

for(int i = 0; i < 10 -1; i++)
{
    for(int j= i + 1 ; j < 10 ;j++) 
    {
    if(ARR[j] > ARR[i])
    {
       int temp = ARR[i];
       ARR[i] = ARR[j];
       ARR[j] = temp;
    }
    }
    
}
 
cout<<"\n Result after sorting array in assending order:- \n "; 
for(int i = 0; i< 10; i++)
{
    cout<<" " << ARR[i];
}
    
return 0;
}
