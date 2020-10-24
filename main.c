#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void initializeEmployees(int *employeeID,int empNum);
void printEmp(int *empID, int empNum);
void initializeDepartment(char *deptName[],int deptNum);
void printDepartment(char *deptName[],int deptNum);
void addingAndRemoving(int *employeeID, int empNum, char *deptCode[], int deptNum);
void printTable(int *employeeId,int empNum, char *deptCode[], int deptNum);
int employeeIndex;
int deptIndex;
int number;
int table[10][10];


int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    int empNum;
    int deptNum;
    printf("Enter the number of employees: ");
    scanf("%d", &empNum);
    int *employeeID[empNum];
    int i;
    for(i=0; i<empNum;i++){
        employeeID[i]=(int*)malloc(sizeof(int));
    }
    initializeEmployees(*employeeID, empNum);
    printEmp(*employeeID, empNum);

    printf("Enter number of departments: ");
    scanf("%d", &deptNum);
    char *departmentName[deptNum];
    int l;
    for (l = 0; l < deptNum ; l++) {
        departmentName[l]=(char*)malloc(sizeof(char));
    }
    initializeDepartment(departmentName, deptNum);
    printDepartment(departmentName, deptNum);

    printTable(*employeeID,empNum,departmentName,deptNum);

    int selc;
    int quit = 1;
    while(quit){
        printf("\n1. Adding an employee to a department.\n");
        printf("2. Removing an employee from a department.\n");
        printf("3. See Association table.\n");
        printf("4. Quit the program\n");
        scanf("%d", &selc);
        if(selc==1){
            addingAndRemoving(*employeeID,empNum,departmentName, deptNum);
            number=1;
            printf("\n");
        }else if(selc==2){
            addingAndRemoving(*employeeID,empNum,departmentName, deptNum);
            number=0;
            printf("\n");}
        else if(selc==3){
            printTable(*employeeID,empNum,departmentName,deptNum);
        }else if(selc==4){
            quit=0;
        }else{
            printf("Invalid character, input again");
        }
    }

    return 0;
}
void initializeEmployees(int *employeeID,int empNum){
    int i;
    for(i=0;i<empNum;i++){
        int loop=1;
        while(loop){
            printf("Enter employee ID %d :",i+1);
            scanf("%d",&employeeID[i]);
            if(employeeID[i]/10000 >=10 || employeeID[i]/10000<=0){
                printf("Employee ID must be 5 digits\n");
            }else{
                loop=0;
            }
        }
    }
}

void printEmp(int *empID, int empNum) {
    int i ;
    printf("[");
    for (i = 0; i < empNum; i++) {
        printf("%d", empID[i]);
        if (i < empNum - 1 ){
            printf(", ");
        }
    }
    printf("]\n");
}
void initializeDepartment(char *deptName[],int deptNum){
    int i;
    for(i=0;i<deptNum;i++){
        int loop=1;
        while(loop){
            printf("Enter name of department %d :",i+1);
            scanf("%s",deptName[i]);
            if(strlen(deptName[i])!=7) {
                printf("Department name must be 7 digits\n");
            }else {
                loop=0;
            }
        }

    }
}
void printDepartment(char *deptName[], int deptNum) {
    int j ;
    printf("[");
    for (j = 0; j < deptNum; j++) {
        printf("%s", deptName[j]);
        if (j < deptNum- 1 ){
            printf(", ");
        }
    }
    printf("]\n");
}

void addingAndRemoving(int *employeeID, int empNum, char *deptCode[], int deptNum) {
    int empID;
    char *depttCode;
    printf("Enter Department code that you wish to alter: ");
    scanf("%s", &depttCode);

    printf("Enter Employee Id you want to add: ");
    scanf("%d", &empID);

    int i;
    for (i = 0; i < empNum; i++) {
        if (empID == employeeID[i]) {
            employeeIndex = i;
        }
    }
    int j = 0;
    for (j = 0; j < deptNum; j++) {
        if (strcmp(deptCode[j], &depttCode) == 0) {
            deptIndex = j;
        }
    }
    return;
}



void printTable(int *employeeId,int empNum, char *deptCode[], int deptNum){
    table[employeeIndex][deptIndex]=number;
    printf("--------------------- Table-------------------------\n\n");
    printf("Employee Number\t| ");
    printf("\tDepartment Code\n");
    printf("               \t| ");

    int i;
    for ( i =0; i<deptNum; i++){
        printf("\t%s\t|",deptCode[i]);
    }
    printf("\n---------------\t");
    int l;
    for (l = 0; l <deptNum ; ++l) {
        printf("------------");
    }
    int k;
    for (k = 0; k < empNum; k++)
    {
        printf("\n");
        printf(" %d\t\t\t", employeeId[k]);
        int j;
        for(j = 0; j<deptNum;j++)
        {
            if(table[k][j]==1){
                printf("YES\t\t\t");
            } else{
                printf("NO\t\t\t");
            }
        }
    }
}
