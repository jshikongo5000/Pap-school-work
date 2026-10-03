#include <stdio.h>
#include "reports.h"
#include "utils.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"


void employeeReport(void) {
    printf("\n================ EMPLOYEE REPORT ================\n");
    if (employeeCount == 0) {
        printf("No employees registered.\n");
        return;
    }
    double firstGross = calculateSalary(employees[0].basicSalary,
                                        employees[0].housingAllowance,
                                        employees[0].transportAllowance);
    double total = firstGross;
    double highest = firstGross;
    double lowest  = firstGross;

    for (int i = 1; i < employeeCount; i++) {
        double gross = calculateSalary(employees[i].basicSalary,
                                       employees[i].housingAllowance,
                                       employees[i].transportAllowance);
        total += gross;                        
        if (gross > highest) highest = gross;  
        if (gross < lowest)  lowest  = gross;
    }

    printf("Total Employees : %d\n", employeeCount);
    printf("Average Salary  : N$%.2f\n", total / employeeCount);
    printf("Highest Salary  : N$%.2f\n", highest);
    printf("Lowest Salary   : N$%.2f\n", lowest);
}


void budgetReport(void) {
    printf("\n================= BUDGET REPORT =================\n");
    if (budgetCount == 0) {
        printf("No budgets recorded.\n");
        return;
    }
    double totalAllocated = 0.0;
    double totalSpent = 0.0;
    int overCount = 0;

    for (int i = 0; i < budgetCount; i++) {
        totalAllocated += budgets[i].allocatedBudget;
        totalSpent     += budgets[i].expenditure;
        if (calculateBudget(budgets[i].allocatedBudget,
                            budgets[i].expenditure) < 0) {
            overCount++;                       
        }
    }

    printf("Total Allocated Budget : N$%.2f\n", totalAllocated);
    printf("Total Expenditure      : N$%.2f\n", totalSpent);
    printf("Total Remaining        : N$%.2f\n",
           calculateBudget(totalAllocated, totalSpent));
    printf("Departments exceeding budget: %d\n", overCount);
    displayExceedingBudgets();                 
}

void supplierReport(void) {
    printf("\n=============== SUPPLIER REPORT ===============\n");
    if (supplierCount == 0) {
        printf("No suppliers registered.\n");
        return;
    }
    printf("Total Suppliers : %d\n", supplierCount);
    displaySuppliers();
}

void assetReport(void) {
    printf("\n================ ASSET REPORT ================\n");
    if (assetCount == 0) {
        printf("No assets registered.\n");
        return;
    }
    double totalValue = 0.0;
    for (int i = 0; i < assetCount; i++) {
        totalValue += assets[i].purchaseValue;
    }
    printf("Total Assets        : %d\n", assetCount);
    printf("Total Purchase Value: N$%.2f\n", totalValue);
    displayAssets();
}

void reportsMenu(void) {
    int choice;
    do {
        printf("\n================ REPORTS ================\n");
        printf("1. Employee report\n");
        printf("2. Budget report\n");
        printf("3. Supplier report\n");
        printf("4. Asset report\n");
        printf("0. Back to main menu\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: employeeReport(); break;
            case 2: budgetReport();   break;
            case 3: supplierReport(); break;
            case 4: assetReport();    break;
            case 0: break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);
}
