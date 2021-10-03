#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

int function_push(char **Parameter, int *Position, int *NumParam, char **inputString);
void function_pop(char **Parameter, int *indexLoop, int *totalData);

int main(int numberOfParam, char **inputParameter)
{   printf("\t\tTUGAS STACK \n\tO. Riastanjung\n\t2001020039\n");
    if (numberOfParam <= 1)
    {
        printf("No input\nthe Correct Format is\n\t./fileName.o param1 param2 param3...\n");
    }
    else
    {
        int posIndex = 0;
        char **Parameter;   // Parameter[m][n]
        int lenString = 16; // panjang parameter dibatasi hingga 16

        Parameter = malloc(numberOfParam * sizeof(char *)); // menetapkan nilai m = banyakParameter
        for (int i = 0; i < numberOfParam; i++)
        {
            Parameter[i] = malloc((lenString + 1) * sizeof(char)); // menetapkan nilai n = lensString + 1;
        }

        // push data
        if (!function_push(Parameter, &posIndex, &numberOfParam, inputParameter))
        {
            printf("\n\033[0;90mpush failed\n\033[0m");
        }
        else
        {
            printf("\n\033[0;90msuccess created the stack\n\033[0m");
        }




        //pop data
        for (int k = posIndex; k >= 0; k--)
        {   
            function_pop(Parameter, &k, &posIndex);
            
        }
        
    }

    return 0;
}
int function_push(char **Parameter, int *Position, int *NumParam, char **inputString)
{
    if (NumParam != 0)
    {
        for (int j = 1; j < *NumParam; j++)
        {
            strcpy(Parameter[j], inputString[j]);
            ++(*Position);
        }

        return 1;
    }
    else
    {
        return 0;
    }
}

void function_pop(char **Parameter, int *indexLoop, int *totalData)
{
    if (*indexLoop != 0)
    {
        printf("\033[0;92mPop Stack index %d => \033[0m \033[0;44m%s\033[0m\n", (*indexLoop)-1, Parameter[(*indexLoop)]);
        --(*totalData);
    }

    else
    {
        printf("\033[0;31mstack empty\033[0m\n");
    }
}