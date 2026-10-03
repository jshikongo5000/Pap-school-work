#include <stdio.h>
#include <string.h>
#include "budget.h"
#include "utils.h"

Budget budgets[MAX_BUDGETS];
int budgetCount = 0;


double calculateBudget(double revenue, double expenses) {
    return revenue - expenses;                
}

int findBudgetIndex(const char *department) {
    for (int i = 0; i < budgetCount; i++) {
        if (strcmp(budgets[i].department, department) == 0) {
            return i;
        }
    }
    return -1;
}


void enterDepartmentBudget(void) {
    char department[DEPARTMENT_LENGTH];
    readLine("Enter department name: ", department, DEPARTMENT_LENGTH);
    if (strlen(department) == 0) {
        printf("Department cannot be empty.\n");
        return;
    }

    double amount = readNonNegativeDouble("Enter allocated budget (N$): ");

    int index = findBudgetIndex(department);
    if (index != -1) {                         
        budgets[index].allocatedBudget = amount;
        budgets[index].expenditure = 0.0;
        printf("Budget updated for %s.\n", department);
    } else if (budgetCount < MAX_BUDGETS) {    
        strcpy(budgets[budgetCount].department, department);   
        budgets[budgetCount].allocatedBudget = amount;
        budgets[budgetCount].expenditure = 0.0;
        budgetCount++;
        printf("Budget recorded for %s.\n", department);
    } else {
        printf("Budget list is full!\n");
    }
}


void recordExpenditure(void) {
    char department[DEPARTMENT_LENGTH];
    readLine("Enter department name: ", department, DEPARTMENT_LENGTH);
    int index = findBudgetIndex(department);
    if (index == -1) {
        printf("Department '%s' not found.\n", department);
        return;
    }
    double amount = readNonNegativeDouble("Enter expenditure amount (N$): ");
    budgets[index].expenditure += amount;      
    printf("Expenditure recorded.\n");
}

void displayBudgets(void) {
    if (budgetCount == 0) {
        printf("No budgets recorded.\n");
        return;
    }
    printf("\n%-20s %15s %15s %15s %-15s\n",
           "Department", "Allocated", "Spent", "Remaining", "Status");
    printf("-----------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < budgetCount; i++) {
        double remaining = calculateBudget(budgets[i].allocatedBudget,
                                           budgets[i].expenditure);
        
        printf("%-20s %15.2f %15.2f %15.2f %-15s\n",
               budgets[i].department, budgets[i].allocatedBudget,
               budgets[i].expenditure, remaining,
               remaining >= 0 ? "WITHIN BUDGET" : "OVER BUDGET");
    }
}


void displayExceedingBudgets(void) {
    int found = 0;
    printf("\nDepartments that have EXCEEDED their budget:\n");
    for (int i = 0; i < budgetCount; i++) {
        double remaining = calculateBudget(budgets[i].allocatedBudget,
                                           budgets[i].expenditure);
        if (remaining < 0) {                   
            printf("  %-20s over by N$%.2f\n",
                   budgets[i].department, -remaining);
            found = 1;
        }
    }
    if (!found) {                             
        printf("  None. All departments are within budget.\n");
    }
}

void budgetMenu(void) {
    int choice;
    do {
        printf("\n========== BUDGET MANAGEMENT ==========\n");
        printf("1. Enter / update department budget\n");
        printf("2. Record expenditure\n");
        printf("3. Display budget information\n");
        printf("4. Show departments exceeding budget\n");
        printf("0. Back to main menu\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: enterDepartmentBudget();   break;
            case 2: recordExpenditure();       break;
            case 3: displayBudgets();          break;
            case 4: displayExceedingBudgets(); break;
            case 0: break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);
}
