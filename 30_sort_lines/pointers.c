/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    
    char x = 'a';
    
    char * line = &x;
    char ** linep = &line;
    
    
    printf("%d\n", line);
    printf("%d\n", &x);
    
    printf("%d\n", &line);
    printf("%d\n", linep);

    printf("%d\n", *linep);
    printf("%d\n", line);
    printf("%c\n", *line);
    printf("%c\n", **linep);
    
    

    return 0;
}
