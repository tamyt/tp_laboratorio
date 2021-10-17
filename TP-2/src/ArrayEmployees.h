#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdlib.h>
//#include <stdio_ext.h>
#include <string.h>
#include <stdio.h>
#include "utn.h"

#define TRUE 1
#define FALSE 0
#define NAME 51

struct
{
    int id;
    char name[NAME];
    char lastName[NAME];
    float salary;
    int sector;
    int isEmpty;
}typedef Employee;

int initEmployees(Employee* list, int len);
int getEmptyPosition(Employee* list, int len);
int addEmployeeForced(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int addEmployee(Employee* list, int len, int* id);
int findEmployeeById(Employee* list, int len,int id);
int modifyEmployee(Employee* list, int len, int id);
int printEmployees(Employee* list, int len);

int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int getTotalAndAverageSalaries(Employee* list, int len, float* acum, float* promSalaries, int* contPromEmployees);
int informEmployeesAndAverageSalary(Employee* list, int len);
#endif /* ARRAYEMPLOYEES_H_ */
