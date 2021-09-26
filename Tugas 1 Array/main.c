#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inputToData(int *ID_input, int *Age_input, char Name_input[][20], int *posisi_input);
void showData(int *ID_input, int *Age_input, char Name_input[][20], int *posisi_input);
void deleteData(int *ID_input, int *Age_input, char Name_input[][20], int *posisi_input);


int main()
{
    int option;

    int *id;
    id = (int *)malloc(100 * sizeof(int));

    int *age;
    age = (int *)malloc(100 * sizeof(int));
    
    char name[100][20];
    
    int posisi = 0;
    menu :
    printf("\n\t\tActivity\n1. Input new data\n2. Delete data\n3. Show data list\n4. Exit Program\nYour choice: ");
    scanf("%d", &option);

    if (option == 1)
    {
        inputToData(id, age, name, &posisi);
        goto menu;
    }

    else if (option == 2)
    {
        printf("\nDelete Data\n");
        
        deleteData(id, age, name, &posisi);
        goto menu;
    }

    else if (option == 3)
    {
        if(posisi == 0){
            printf("\nSorry, there is no data to show\n");
        }else{
            printf("\nShow Data List\n");
            showData(id, age, name, &posisi);
        }
        goto menu;
    }

    else if (option == 4)
    {
        printf("\nExiting Program ....");
    }

    else
    {
        printf("\ninput salah\n");
    }

    return 0;
}

// all method using prototypes function
void inputToData(int *ID_input, int *Age_input, char Name_input[][20], int *posisi_input)
{
    printf("\n\tInput New Data\n");
    printf("\nInput Customer ID : ");
    scanf("%d", ID_input + *posisi_input);
    printf("\nInput Customer Name : ");
    scanf("%*c%[^\n]%*c", Name_input + *posisi_input);
    printf("\nInput Customer Age : ");
    scanf("%d", Age_input + *posisi_input);
    *posisi_input = *posisi_input + 1;
}

void showData(int *ID_input, int *Age_input, char Name_input[][20], int *posisi_input)
{
    for (int i = 0; i < *posisi_input; i++)
    {
        printf("\nID : %d\t\t", *(ID_input + i));
        printf("Name : %s\t\t", *(Name_input + i));
        printf("Age : %d\t\t\n", *(Age_input + i));
    }
}

void deleteData(int *ID_input, int *Age_input, char Name_input[][20], int *posisi_input)
{
    int isFound = 0;
    int indexFound;
    int search;

   

    printf("\nInput Customer ID to Delete : ");
    scanf("%d", &search);

    for (int i = 0; i <= *posisi_input; i++)
    {
        if (search == *(ID_input + i))
        {
            isFound = 1;
            indexFound = i;
        }
    }
    if (isFound == 1)
    {
        for (int c = indexFound; c < *posisi_input - 1; c++)
        {
            ID_input[c] = ID_input[c + 1];
            Age_input[c] = Age_input[c + 1];
            strcpy(Name_input[c], Name_input[c + 1]);
        }
        --(*posisi_input);
        printf("\tData Deleted Successfully\n");
    }else{
         printf("\tID Not Found\n");
    }
}
