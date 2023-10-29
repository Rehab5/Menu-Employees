#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define null -32
#define size 50

void gotoxy(int x, int y){
    COORD coord = {0,0};
    coord.X= x;
    coord.Y= y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textattr(int i){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
}

void newEmployee();
void displayEmployee();
void deleteEmployeeById();
void deleteEmployeeByName();

struct employee{
    int id;
    char name[50];
    int age;
    int salary;
};
struct employee emps[size];

int numEmployees=0;
int main()
{
    char menu[5][20]={"New","Display","Delete by Id","Delete by Name","Exit"};

    char ch;
    int flag = 0;
    int cursor = 0;

    struct employee *emp = (struct employee *)malloc(sizeof(size) * sizeof(struct employee ));

    do{
        system("cls");
        for(int i=0; i<5;i++){
            gotoxy(20,5+i);
            if(i == cursor)
                textattr(0x57);
            printf("%s ",menu[i]);
            textattr(0x07);
        }

        ch= getch();
        switch(ch){
        case -32:
            ch = getch();
            switch(ch){
            case 72:
                cursor--;
                if(cursor <0)
                    cursor = 4;
                break;
            case 71:
                cursor=0;
                break;
            case 79:
                cursor = 4;
                break;
            case 80:
                cursor++;
                if(cursor >4)
                    cursor = 0;
                break;
            }
            break;
        case 27:
            flag = 1;
            break;
        case 13:
            system("cls");

            switch(cursor){
            case 0:
                newEmployee();
                break;
            case 1:
                displayEmployee();
                break;
            case 2:
                deleteEmployeeById();
                break;
            case 3:
                deleteEmployeeByName();
                break;
            }
            //printf("%s is selected",menu[cursor]);
            getch();
            if(cursor == 4)
                flag = 1;
            break;

        }
    }while(flag ==0);



    printf("\n");
    return 0;
}
void newEmployee(){
    struct employee emp;
    printf("***** Enter the details of employee.*****\n");
    printf("Enter the name of employee: \n");
    scanf("%s",emp.name);
    printf("Enter the ID of employee: \n");
    scanf("%d",&emp.id);
    printf("Enter the age of employee: \n");
    scanf("%d",&emp.age);
    printf("Enter the salary of employee: \n");
    scanf("%d",&emp.salary);
    printf("----------------------------------------------\n");
    numEmployees++;
    emps[numEmployees++]=emp;

}
void displayEmployee(){

    printf(" -The details of the employee -__- .\n\n");
    for(int i=1;i<numEmployees;++i){
        printf(" Name : %s \n",emps[i].name);
        printf(" ID : %d \n",emps[i].id);
        printf(" Age : %d \n",emps[i].age);
        printf(" Salary : %d \n",emps[i].salary);
        printf("------------------------------------------\n");
    }

}

void deleteEmployeeById(){
    int id;
    printf("Enter employee ID: ");
    scanf("%d",&id);
    for (int i = 0; i < numEmployees; i++) {
        if ( emps[i].id == id) {
            for (int j = i; j < numEmployees - 1; j++) {
                emps[j] = emps[j + 1];
            }
            numEmployees--;
            printf("Employee deleted successfully.\n");
            return;
        }
    }

    printf("Employee not found.\n");

}
void deleteEmployeeByName(){
    char name[50];
    printf("Enter employee Name: ");
    scanf("%s",name);

    int deleted = 0;
    for (int i = 0; i < numEmployees; i++) {
        if (strcmp(name, emps[i].name) == 0) {
            for (int j = i; j < numEmployees - 1; j++) {
                emps[j] = emps[j + 1];
            }
            numEmployees--;
            deleted = 1;
        }
    }

    if (deleted) {
        printf("Employee(s) deleted successfully.\n");
    } else {
        printf("Employee(s) not found.\n");
    }

}

