#include <stdio.h>

void inputToData (int *ID_input, int *Age_input , char Name_input[][20], int *posisi_input){
            printf("\n\tInput New Data\n");
            printf("\nInput Customer ID : ");
            scanf("%d",ID_input + *posisi_input);
            printf("\nInput Customer Name : ");
            scanf("%*c%[^\n]%*c", Name_input + *posisi_input);
            printf("\nInput Customer Age : ");
            scanf("%d",Age_input + *posisi_input); 
            *posisi_input = *posisi_input + 1;
}
void showData(int *ID_input, int *Age_input , char Name_input[][20], int *posisi_input){
    for (int i = 0; i < *posisi_input; i++)
    {
        printf("\nID : %d\n",*(ID_input + i));
        printf("Name : %s\n",*(Name_input + i));
        printf("Age : %d\n",*(Age_input + i));
    }
}
int main()
{   
    int id[100];
    int age[100];
    char name[100][20];
    int option;
    int  posisi = 0;

     inputToData(id, age, name, &posisi);
    inputToData(id, age, name, &posisi);

    showData(id, age, name, &posisi);
}