// insertion deletion , searching and traversing in an array
#include<stdio.h>
int main(int argc, char const *argv[])
{
    // insertion at a given position  of an array : 
    printf("Enter the position where you want to insert new item \n -->"); 
    int position, array[7] ={1,34,23,1,2,8}; 
    printf("total elements in the array is 7\n"); 
    scanf("%d",&position); 
    int i =6 ; 
    while (i>=position)
    {
        array[i+1]=array[i]; 
        i=i-1; 
    }
    array[i]=51; 
    for (int i = 0; i < 7; i++)
    {
        printf("array[%d]=%d\n",i,array[i]); 
    }

    
    return 0;
}