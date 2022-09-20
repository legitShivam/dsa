#include<stdio.h>
#include<string.h>

// string manipulation using functions

// string length
int string_length(char *string);

// string copy
int string_copy(char *string1, char *string2);

// string concatanation
int string_concat(char *string1, char *string2);

// string compare
int string_compare(char *string1, char *string2);

// print string
int print_string(char *string);


int main(int argc, char const *argv[])
{   
    while(1){
        // inititalisation of menu
        int menu = 0;

        printf("\n\nSTRING MANIPULATION\n");
        printf("1. String Length\n");
        printf("2. String Copy\n");
        printf("3. String Concatanation\n");
        printf("4. String Compare\n"); 
        printf("5. Exit\n\n");
        printf("Choose an operation:\n --> ");
        scanf("%d", &menu);
        

        // initializing sizes of the strings
        int size1, size2;

        printf("Enter the size of the first string:\n --> ");
        scanf("%d", &size1);
        printf("Enter the size of the second string:\n --> ");
        scanf("%d", &size2);

        // initializing the strings
        char string1[size1], string2[size2];

        printf("Enter the first string:\n --> ");
        scanf("%s", string1);
        printf("Enter the second string:\n --> ");
        scanf("%s", string2);

        // switch case for menu
        switch (menu)
        {
            case 1:
                printf("The length of the first string is %d\n", string_length(string1));
                printf("The length of the second string is %d\n", string_length(string2));
                break;
            
            case 2:
                string_copy(string1, string2);
                printf("The first string is now %s\n", string1);
                printf("The second string is now %s\n", string2);
                break;

            case 3:
                string_concat(string1, string2);
                printf("The first string is now %s\n", string1);
                printf("The second string is now %s\n", string2);
                break;

            case 4:
                printf("The first string is %s\n", string1);
                printf("The second string is %s\n", string2);
                printf("The comparison of the two strings is %d\n", string_compare(string1, string2));
                break;

            case 5:
                return 0;
                break;
        }
    }
    return 0;
}

// string length
int string_length(char *string)
{
    int i=0; 
    while (string[i]!='\0')
    {
        i++; 
    }
    return i; 
}

// string copy
int string_copy(char *string1, char *string2)
{   
    // compare size of string1 and string2
    int size1= sizeof(string1)/sizeof(char)-1;
    int size2= sizeof(string2)/sizeof(char)-1;
    
    if(size1>size2){
        printf("Insufficient size");
        return -1;
    }

    int i=0; 
    while (string1[i]!='\0')
    {
        string2[i]=string1[i]; 
        i++; 
    }
    string2[i]='\0'; 
    return 0;
}

// string concatanation
int string_concat(char *string1, char *string2)
{
    // compare size of string1 and string2
    int size1= sizeof(string1)/sizeof(char)-1;
    int size2= sizeof(string2)/sizeof(char)-1;
    
    if(size1>size2){
        printf("Insufficient size");
        return -1;
    }

    int i=0, j= string_length(string2);
    while (string1[i]!='\0')
    {
        string2[j]=string1[i]; 
        i++;
        j++;
    }
    string2[j]='\0'; 
    return 0;
}

// string compare
int string_compare(char *string1, char *string2){
    int i=0; 
    while (string1[i]!='\0' && string2[i]!='\0')
    {
        if (string1[i]>string2[i])
        {
            return 1;
        }
        else if (string1[i]<string2[i])
        {
            return -1;
        }
        i++; 
    }
    return 0;
}
