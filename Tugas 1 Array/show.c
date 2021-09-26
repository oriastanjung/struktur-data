#include <stdio.h>



int main(int argc, char const *argv[])
{
    int id[]={NULL};
    int age[] = {NULL};
    char *name[16];
    int option;
    int posisi = 0;
    char temp[16];

        while (1)
        {
            printf("\nInput New Data\n");

            printf("\nInput Customer ID : ");
            scanf("%d",&id[posisi]);

            printf("\nInput Customer Name : ");
            scanf(" %*c%[^\n]%*c", temp);
            name[posisi] = temp;

            printf("\nInput Customer Age : ");
            scanf("%d",&age[posisi]); 
            
            posisi+=1;
            if(posisi == 2){
                break;
            }
        }
        
                for (int i = 0; i < 3; i++)
                {
                    printf("id: %d\t\t",id[i]);
                    printf("age: %d\t\t",age[i]);
                    printf("name: %s\t\t\n", name[i]);
                }
                
               

            
    return 0;
}
