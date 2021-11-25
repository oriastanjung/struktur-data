#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long ID;
char name[20];

struct node
{
    long ID;
    char name[20];
    struct node *link;
};
void showData(struct node *head)
{
    struct node *ptr;
    ptr = head;
    printf("\nStudent ID\t\t\tStudent Name\n");
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
        printf("%ld\t\t\t%s\n", ptr->ID, ptr->name);
    }
    ptr->link = NULL;
}

void insertData(struct node *head, long inputID, char inputName[20], int *restart)
{
    int count = 1;
    struct node *ptr, *temp;
    ptr = head;

    temp = malloc(sizeof(struct node));
    temp->ID = inputID;
    strcpy(temp->name, inputName);
    temp->link = NULL;

    while (ptr->link != NULL)
    {
        ptr = ptr->link;
        if (ptr->ID == temp->ID)
        {
            count++;
        }
    }
    if (count > 1)
    {

        printf("\nInput Denied.\nStudent's ID Number already in the record\n\n");
        *restart = 1;
    }
    else
    {
        ptr->link = temp;
    }
}

void searchRecord(struct node *head)
{
    char opsi[3];
    long idSearch;
    char nameSearch[20];
    printf("\nSearch based on ID [I] or name [N] ?: ");
    scanf("%s", opsi);
    if (*opsi == 73 || *opsi == 105)
    {
        printf("\nType Student's ID Number to look for : ");
        scanf("%ld", &idSearch);
        int tmpCount = 0;
        struct node *ptr;
        ptr = head;
        printf("Student ID\t\t\tStudent Name\n");
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
            if (ptr->ID == idSearch)
            {

                printf("%ld\t\t\t%s\n", ptr->ID, ptr->name);
                ++tmpCount;
            }
        }

        ptr->link = NULL;
        if (tmpCount == 0)
        {
            printf("\n\tData Not Found\n");
        }
    }
    else if (*opsi == 78 || *opsi == 110)
    {
        printf("\nType Student's Name to look for : ");
        scanf("%*c%[^\n]%*c", nameSearch);

        int tmpCount = 0;
        struct node *ptr;
        ptr = head;
        printf("Student ID\t\t\tStudent Name\n");
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
            if (strcmp(&(ptr->name), &nameSearch) == 0)
            {

                printf("%ld\t\t\t%s\n", ptr->ID, ptr->name);
                ++tmpCount;
            }
        }

        ptr->link = NULL;
        if (tmpCount == 0)
        {
            printf("\n\tData Not Found\n");
        }
    }
    char opsiReset[3];
    printf("Search Again ?[Y/N] : ");

    scanf("%s", opsiReset);
    if (*opsiReset == 89 || *opsiReset == 121)
    {
        searchRecord(head);
    }
}

void updateData(struct node *head, long idToChange)
{
    struct node *ptr, *tmpCheckDouble;
    char repeat[3];
    long tmpID;
    char tmpName[20];
    ptr = head;
    tmpCheckDouble = head;
    int count = 1;
    int totalData = 0;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
        if (ptr->ID == idToChange)
        {
            totalData++;
            printf("\nID Number : %ld\n", ptr->ID);
            printf("Name : %s\n", ptr->name);
            printf("Type New Student's ID Number to update: ");
            scanf("%ld", &tmpID);
            printf("\nType New Student's Name : ");
            scanf("%*c%[^\n]%*c", tmpName);

            while (tmpCheckDouble->link != NULL)
            {
                tmpCheckDouble = tmpCheckDouble->link;
                if (tmpCheckDouble->ID == tmpID)
                {
                    count++;
                }
            }
            if (count > 1)
            {

                printf("\nUpdate Denied.\nThere is another same ID Number already in the record\n\n");
                printf("\nUpdate Another Data ? [Y/N] : ");
                scanf("%s", repeat);
                if (*repeat == 89 || *repeat == 121)
                {
                    printf("Type Student's ID Number to update: ");
                    scanf("%ld", &tmpID);
                    updateData(head, tmpID);
                }
                else
                {
                    break;
                }
            }

            ptr->ID = tmpID;
            strcpy(ptr->name, tmpName);
        }
    }
    if (totalData == 0)
    {
        printf("ID Number is not found.\n");
    }

    ptr->link = NULL;
}

void deleteData(struct node *head, long idToDelete)
{
    struct node *ptr;
    ptr = head;
    int posisiData = 0;
    int dataKe = 1;
    struct node *previous;
    previous = head;
    // previous = previous->link;
    struct node *current;
    current = head;
    // current = current->link;
    char confirm[1];
    int isFound = 0;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
        if (ptr->ID == idToDelete)
        {
            posisiData = dataKe;
            printf("\nID Number : %ld\n", ptr->ID);
            printf("Name : %s\n", ptr->name);
            isFound = 1;
        }
        dataKe++;
    }

    if (isFound == 0)
    {
        printf("\nID Number not Found\n");
    }
    else
    {
        printf("\nAre you sure to delete this data ? [Y/N] : ");
        scanf("%s", confirm);
        if (*confirm == 89 || *confirm == 121)
        {
            if (posisiData == 0)
            {
                head = current->link;
                free(current);
                current = NULL;
            }
            else
            {
                while (posisiData != 0)
                {
                    previous = current;
                    current = current->link;
                    posisiData--;
                }
                previous->link = current->link;
                free(current);
                current = NULL;
            }
        }
    }
}

int main(int argc, char const *argv[])
{

    struct node *head = malloc(sizeof(struct node));
    head->ID = 12;
    strcpy(head->name, "dummy");
    head->link = NULL;
    int option;

    menu:
    printf("\nSTUDENT RECORD SYSTEM\n");
    printf("1. Input New Record\n");
    printf("2. Search Record\n");
    printf("3. Update Record\n");
    printf("4. Show Record\n");
    printf("9. Delete Record\n");
    printf("Your choice : ");
    scanf("%d", &option);

    if (option == 1)
    {
        int restart = 0;
        char opsi[3];
    opsi1:

        printf("Type Student's ID Number : ");
        scanf("%ld", &ID);
        printf("Type Student's Name : ");
        scanf("%*c%[^\n]%*c", name);

        insertData(head, ID, name, &restart);
        if (restart == 1)
        {
            printf("Input another data ?[Y/N] : ");
            scanf("%s", opsi);
            if (*opsi == 89 || *opsi == 121)
            {
                restart = 0;
                goto opsi1;
            }
        }

        printf("\n");
        goto menu;
    }
    else if (option == 2)
    {
        searchRecord(head);
        goto menu;
    }
    else if (option == 3)
    {
        long updateID;
        printf("\nType Student's ID Number to update: ");
        scanf("%ld", &updateID);
        updateData(head, updateID);
        goto menu;
    }
    else if (option == 4)
    {
        showData(head);
        printf("\n");
        goto menu;
    }
    else if (option == 9)
    {
        char tryAgain[1];
        long idToDelete;
        delete : printf("Type Student's ID Number to be deleted : ");
        scanf("%ld", &idToDelete);
        deleteData(head, idToDelete);
        printf("\ndelete another data? [y/n] : ");
        scanf("%s", tryAgain);
        if (*tryAgain == 89 || *tryAgain == 121)
        {
            goto delete;
        }
        goto menu;
    }
    else
    {
        printf("INPUT OPTION WRONG, TRY AGAIN");
        goto menu;
    }

    return 0;
}
