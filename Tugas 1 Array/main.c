#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert(int *inputID, int *inputAge, char inputName[][20], int *inputData);
void show(int *inputID, int *inputAge, char inputName[][20], int *inputData);
void delete(int *inputID, int *inputAge, char inputName[][20], int *inputData);


int main()
{
    int option;
    int numberOfData = 0;
    int *id;
    id = (int *)malloc((numberOfData + 1) * sizeof(int));

    int *age;
    age = (int *)malloc((numberOfData + 1) * sizeof(int));
    
    char name[100][20];
    
   
    Main :
    printf("\n\t\tActivity\n1. Input new data\n2. Delete data\n3. Show data list\n4. Exit Program\nYour choice: ");
    scanf("%d", &option);

    if (option == 1)
    {
        insert(id, age, name, &numberOfData);
        goto Main;
    }

    else if (option == 2)
    {
        printf("\nDelete Data\n");
        
        delete(id, age, name, &numberOfData);
        goto Main;
    }

    else if (option == 3)
    {
        if(numberOfData == 0){
            printf("\nSorry, there is no data to show\n");
        }else{
            printf("\nShow Data List\n");
            show(id, age, name, &numberOfData);
        }
        goto Main;
    }

    else if (option == 4)
    {
        printf("\nExiting Program ....");
    }

    else
    {
        printf("\nOops.. The Option you Choose doesn't exist\n");
        printf("\nPlease Choose the existing Option :)\n");
        goto Main;
    }

    return 0;
}

// all method using prototypes function
void insert(int *inputID, int *inputAge, char inputName[][20], int *inputData)
{   
    printf("\n\tInput New Data\n");
    printf("\nInput Customer ID : ");
    scanf("%d", inputID + *inputData);
    printf("\nInput Customer Name : ");
    scanf("%*c%[^\n]%*c", inputName + *inputData);
    printf("\nInput Customer Age : ");
    scanf("%d", inputAge + *inputData);
    *inputData = *inputData + 1;
}

void show(int *inputID, int *inputAge, char inputName[][20], int *inputData)
{
    for (int i = 0; i < *inputData; i++)
    {
        printf("\nID : %d\t\t", *(inputID + i));
        printf("Name : %s\t\t", *(inputName + i));
        printf("Age : %d\t\t\n", *(inputAge + i));
    }
}

void delete(int *inputID, int *inputAge, char inputName[][20], int *inputData)
{
    int isFound = 0;
    int indexFound;
    int search;

   

    printf("\nInput Customer ID to Delete : ");
    scanf("%d", &search);

    for (int i = 0; i <= *inputData; i++)
    {
        if (search == *(inputID + i))
        {
            isFound = 1;
            indexFound = i;
        }
    }
    if (isFound == 1)
    {
        for (int c = indexFound; c < *inputData - 1; c++)
        {
            inputID[c] = inputID[c + 1];
            inputAge[c] = inputAge[c + 1];
            strcpy(inputName[c], inputName[c + 1]);
        }
        --(*inputData);
        printf("\tData Deleted Successfully\n");
    }else{
         printf("\tID Not Found\n");
    }
}
