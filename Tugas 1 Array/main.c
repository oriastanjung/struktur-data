#include <stdio.h>

void inputToData(int *ID_input, int *Age_input, char Name_input[][20], int *posisi_input);
void showData(int *ID_input, int *Age_input, char Name_input[][20], int *posisi_input);


int main()
{
    int id[100];
    int age[100];
    char name[100][20];
    int option;
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