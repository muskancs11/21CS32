//Write a C Program to define details of the Employee with the fields like EName, EmpID, DOJ(Date,  Month,  Year)  and  Salary(Basic,  DA,  HRA)  
//Read  data  for  5  employees  and display them. 
//Find the Employee who is getting Highest Salary.

#include <stdio.h>
#include <stdlib.h>

struct employee
{
    char EName[25];
    int EmpID;
    struct doj
    {
        int day;
        int month;
        int year;
    }DOJ;
    struct sal
    {
        float basic;
        float DA;;
        float HRA;
    }salary;
};

int main()
{
    int i, j, n=5;
    float total_salary[5] = {}, high;
    struct employee e[n];
    printf("\n\n\tReading Data for 5 Employee\n");
    for (i=0;i<n;i++)
    {
        printf("\n\tEnter Employee %d Name: ", i+1);
        scanf("%s", e[i].EName);
        printf("\tEnter Employee %d ID: ", i+1);
        scanf("%d", &e[i].EmpID);
        printf("\tEnter Employee %d date of joining (day-month-year): ", i+1);
        scanf("%d%d%d", &e[i].DOJ.day, &e[i].DOJ.month, &e[i].DOJ.year);
        printf("\tEnter Employee %d salary (basic-DA-HRA): ", i+1);
        scanf("%f%f%f", &e[i].salary.basic, &e[i].salary.DA, &e[i].salary.HRA);

    }
    for (i=0;i<n;i++)
    {
        total_salary[i]= e[i].salary.basic + e[i].salary.DA + e[i].salary.HRA;
    }
    high = total_salary[0];
    j=0;
    for (i=1;i<n;i++)
    {
        if (total_salary[i]>high)
        {
            high = total_salary[i];
            j=i;
        }
    }
    printf("\n\n\t%s Employee is getting Highest Salary of %f.", e[j].EName, total_salary[j]);
    return 0;
}
