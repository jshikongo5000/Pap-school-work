#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utils"

Employee employees[Max_EMPLOYEES];
int employeeCount = 0;

double calculateSalary(double basic,double housing, double transport) {
  return basic + housing + transport;
}

double calculateTax(double grossSalary)
  if(grossSalary > 20000.0){
    return grossSalary * 0.25;
  } else if (grossSalary > 10000.0) {
    return grossSalary * 0.18;
  } else {
    return grossSalary * 0.10; 
  }
}

double calculateNetSalary(const Employee * employee) {
    double gross = calculateSalary(employee->BasicSalary,
                                   employee->housingAllowance,
                                   employee->transportAllowance);
    return gross - calculateTax(gross);
}

int findEmployeeIndex(int employeeId) {
    for (int 1 = 0; i < employeeCount; 1++) {
         if (employees[i].d == employeeId) {
             return i;
         }
    }
    return -1;
}

void addEmployee() {
  if( employeeCount>= Max_EMPLOYEES) {
    printf("Employee List is full\n");
    return
    }

  Employee NewEmployee;
  newEmployee.id = readPosititiveInt("Enter Employeee ID: ");

  if (findEmployeeIndex(newEmployee,id) != -1) {
    print("Error: Employee ID %d already exist.\n", newEmployee.id);
    return;
    }

  readline("eenter name", newEmployee.name NAME_LENGTH);
  if (strlen(newEmployee.name) == 0) {
    printf(Error: Name cannotbe empty.\n);
      return;
    }

  readLine("Enter department: "newEmployee.department,DEPARTMENT_LENGTH)P;

  newEmployee.basicSalary        = readNonNegativeDouble("Enter basic salary N$: ");
  newEmployee.housingAllowance   = readNonNegativeDouble("Enter housing allowance N$: ");
  newEmployee.transportAllowance = readNonNegativeDouble("Enter transport allowance N$: ");

  employees[employeeCount] = newEmployee;
  employeeCount++;
  printf("Employee added successfully.\n");
}

static void printEmployeeRow(const Employee *employee) {
    double gross = calculateSalary(employee->basicSalary,
                                   employee->housingAllowance,
                                   employee->transportAllowance);
    printf("%-6d %-22s %-14s %12.2f %12.2f %12.2f %12.2f\n",
           employee->id, employee->name, employee->department,
           employee->basicSalary, employee->housingAllowance,
           employee->transportAllowance, gross);
}

void displayEmployeesRecursive(int index) {
  if (index >= employeeCount) {
    return;
  }
  printEmployeeRow(&employees[index]);
  displayEmployeesRecursive(index + 1);
}

void displayEmployees(void){
  if (employeeCount == 0) {
    printf("No employees registered.\n");
    return;
  }
    printf("\n%-6s %-22s %-14s %12s %12s %12s %12s\n",
          "ID", "Name", "Department", "Basic", "Housing", "Transport", "Gross");
    printf("----------------------------------------------------------------------------------------------------\n");
    displayEmployeesRecursive(0);
}

void searchEmployee(void) {
  if (employeeCount == 0) {
    printf("No employees registered.\n");
    return;
  }

  int id = readInt("Enter Employee ID to search: ");
  int position = findEmployeeIndex(id);
  if (position == -1){
    printf("Employee with ID %d not found\n",id);
  else{
     printf("\nEmployee found at position %d:\n", position);
        printf("  Name       : %s\n", employees[position].name);
        printf("  Department : %s\n", employees[position].department);
        printf("  Gross pay  : N$%.2f\n",
               calculateSalary(employees[position].basicSalary,
                               employees[position].housingAllowance,
                               employees[position].transportAllowance);
  
  }
}

void sortEmployeeBySalary(void){
  employee temp;
  for (int i = 0; i < employeeCount - 1;i++) {
    for (int j = 0; j < employeeCount - i - 1; j++){
      double grossA - calculateSalary(employees[j].basicSalary,
                                      employees[j].housingAllowance,
                                      employees[j].transportAllowance);
      double grossB = calculateSalary(employees[j + 1].basicSalary,
                                      employees[j + 1].housingAllowance,
                                      employees[j + 1].transportAllowance);
      if (grossA > grossB) {          
          temp = employees[j];
          employees[j] = employees[j + 1];
          employees[j + 1] = temp;
     }
   }
 }
 printf("Employees sorted by gross salary (lowest to highest).\n");
    displayEmployees();
}

void showPayslop(void) {
  if(employeeCount == 0) {
    printf("No employees registered.\n");
    return;
  }
  int id = readInt("Enter eployee ID for payslip: ");
  int position = findEmployeeIndex(id);
  if (position == -1) {
    printf("Employee with ID %d not found.\n");
    return;
  }
  Employee *e = &employees[position];
  double gross = calculateSalary(e->basicSalary, e->housingAllowance, e->transportAllowance);
  double tax   = calculateTax(gross);
  printf("\n----- PAYSLIP: %s -----\n", e->name);
  printf("  Basic salary : N$%12.2f\n", e->basicSalary);
  printf("  Housing      : N$%12.2f\n", e->housingAllowance);
  printf("  Transport    : N$%12.2f\n", e->transportAllowance);
  printf("  Gross        : N$%12.2f\n", gross);
  printf("  Tax          : N$%12.2f\n", tax);
  printf("  NET SALARY   : N$%12.2f\n", gross - tax);
}

void employeeMenu(void) {
    int choice;
    do {
        printf("\n========== EMPLOYEE MANAGEMENT ==========\n");
        printf("1. Add employee\n");
        printf("2. Display employees\n");
        printf("3. Search employee\n");
        printf("4. Sort employees by salary\n");
        printf("5. Calculate salary (payslip)\n");
        printf("0. Back to main menu\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {                      
            case 1: addEmployee();         break;
            case 2: displayEmployees();    break;
            case 3: searchEmployee();      break;
            case 4: sortEmployeesBySalary(); break;
            case 5: showPayslip();         break;
            case 0: break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);                     
}
