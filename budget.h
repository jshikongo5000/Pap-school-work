#ifndef BUDGET_H
#define BUDGET_H

#include "employees.h"
#define MAX_BUDGETS 50

typedef struct {
    char department[DEPARTMENT_LENGTH];
    double allocatedBudget;
    double expenditure;
} Budget;

extern Budget budgets[MAX_BUDGETS];
extern int budgetCount;

void budgetMenu(void);
void enterDepartmentBudget(void);
void recordExpenditure(void);
void displayBudgets(void);
void displayExceedingBudgets(void);

double calculateBudget(double revenue, double expenses);
int findBudgetIndex(const char *department);
#endif