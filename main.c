#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct stud
{
    int Roll_no;
    char Name[100];
    char Father_name[100];
    char Mother_name[100];
    char Phone[100];
    float Percentage;
    struct stud *next;

} *head;

void insert(int roll_no, char *name, char *father, char *mother, char *phone, float percentage)
{
    system("cls");
    struct stud * student = (struct stud *) malloc(sizeof(struct stud));
    student->Roll_no = roll_no;
    strcpy(student->Name, name);
    strcpy(student->Father_name, father);
    strcpy(student->Mother_name, mother);
    strcpy(student->Phone, phone);
    student->Percentage = percentage;
    student->next = NULL;

    if(head==NULL)
    {
        head = student;
    }
    else
    {
        student->next = head;
        head = student;
    }

}

void search(int roll_no)
{

    system("cls");
    struct stud * temp = head;
    while(temp != NULL)
    {
        if(temp->Roll_no==roll_no)
        {
            printf("\n\tRoll Number: %d\n", temp->Roll_no);
            printf("\n\tName: %s\n", temp->Name);
            printf("\n\tFather's name : %s\n", temp->Father_name);
            printf("\n\tMother's name : %s\n", temp->Mother_name);
            printf("\n\tPhone: %d\n", temp->Phone);
            printf("\n\tPercentage: %0.4f\n", temp->Percentage);
            return;
        }
        temp = temp->next;

    }

    printf("\n\tStudent with roll number %d is not found !!!\n", roll_no);

}

void update(int roll_no)
{

    struct stud * temp = head;
    while(temp != NULL){

        if(temp->Roll_no == roll_no){
            printf("\n\tRecord with roll number %d Found !!!\n", roll_no);
            printf("\n\tEnter new name: ");
            scanf("%s", temp->Name);
            printf("\n\tRewrite Father name: ");
            scanf("%s", temp->Father_name);
            printf("\n\tRewrite Mother name: ");
            scanf("%s", temp->Mother_name);
            printf("\n\tEnter new phone number: ");
            scanf("%s", temp->Phone);
            printf("\n\tEnter new percentage: ");
            scanf("%f",&temp->Percentage);
            printf("\n\tUpdate Successful!!!\n");
            return;
        }
        temp = temp->next;

    }
    printf("\n\tStudent with roll number %d is not found !!!\n", roll_no);

}

void Delete(int roll_no)
{

    system("cls");
    struct stud * temp1 = head;
    struct stud * temp2 = head;
    while(temp1 != NULL)
    {

        if(temp1->Roll_no == roll_no)
        {

            printf("\n\tRecord with roll number %d is Found !!!\n", roll_no);

            if(temp1==temp2)
            {
                head = head->next;
                free(temp1);
            }
            else
            {
                temp2->next = temp1->next;
                free(temp1);
            }
            printf("\n\tRecord Successfully Deleted !!!\n");
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    printf("\n\tStudent with roll number %d is not found !!!\n", roll_no);
}

void display(struct stud *head)
{

    system("cls");
    struct stud * temp = head;
    while(temp != NULL)
    {

        printf("\n\tRoll Number : %d\n", temp->Roll_no);
        printf("\n\tStudent name : %s\n", temp->Name);
        printf("\n\tFather's name : %s\n", temp->Father_name);
        printf("\n\tMother's name : %s\n", temp->Mother_name);
        printf("\n\tPhone : %d\n", temp->Phone);
        printf("\n\tPercentage : %0.4f\n\n", temp->Percentage);
        printf("\n\t===============================================\n");
        temp = temp->next;
    }
}
int main()
{

    head = NULL;
    int choice;
    char name[100];
    char Father[100];
    char Mother[100];
    char phone[100];
    int roll_no;
    float percentage;
    do
    {
        printf("\n");
        printf("\n\t\t        =============================================");
        printf("\n\t\t        ||                 WELCOME                 ||");
        printf("\n\t\t        ||                    TO                   ||");
        printf("\n\t\t        ||              Student Record             ||");
        printf("\n\t\t        ||                   System                ||");
        printf("\n\t\t        =============================================\n");
        printf("\n\t\t                          Main Menu");
        printf("\n\t\t                         ===========\n");
        printf("\n\t1. to Insert student details\n"
               "\n\t2. to Search for student details\n"
               "\n\t3. to Delete student details\n"
               "\n\t4. to Update student details\n"
               "\n\t5. to Display all student details\n");

        printf("\n\t\tEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            system("cls");
            printf("\n\t\t====================="
                   "\n\t\t|| Student Details ||"
                   "\n\t\t=====================\n");
            printf("\n\tEnter roll number: ");
            scanf("%d", &roll_no);
            printf("\n\tEnter name: ");
            scanf("%s", &name);
            printf("\n\tFather's name : ");
            scanf("%s", &Father);
            printf("\n\tMother's name : ");
            scanf("%s", &Mother);
            printf("\n\tEnter phone number: ");
            scanf("%d", &phone);
            printf("\n\tEnter percentage: ");
            scanf("%f", &percentage);
            insert(roll_no, name, Father, Mother, phone, percentage);
            printf("\n\tpress 1 to go main menu : ");
            scanf("%d", &choice);
            break;
        case 2:
            system("cls");
            printf("\n\tEnter roll number to search: ");
            scanf("%d", &roll_no);
            search(roll_no);
            printf("\n\tpress 1 to go main menu : ");
            scanf("%d", &choice);
            break;
        case 3:
            system("cls");
            printf("\n\tEnter roll number to delete: ");
            scanf("%d", &roll_no);
            Delete(roll_no);
            printf("\n\tpress 1 to go main menu : ");
            scanf("%d", &choice);
            break;
        case 4:
            printf("\n\tEnter roll number to update: ");
            scanf("%d", &roll_no);
            update(roll_no);
            printf("\n\tpress 1 to go main menu : ");
            scanf("%d", &choice);
            break;
        case 5:
            system("cls");
            display(head);
            printf("\n\tpress 1 to go main menu : ");
            scanf("%d", &choice);
            break;
        default:
            printf("\n\tWrong Input!");
        }
    }
    while (choice != 0);

}
