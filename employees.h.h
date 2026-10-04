#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50
#define DEPARTMENT_LENGTH 30

   double for all monetary values (greater precision than float) */
typedef struct {
    int id;
    char name[NAME_LENGTH];
    char department[DEPARTMENT_LENGTH];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
} Employee;

extern Employee employees[MAX_EMPLOYEES];   
extern int employeeCount;

void employeeMenu(void);
void addEmployee(void);
void displayEmployees(void);
void displayEmployeesRecursive(int index);  
void searchEmployee(void);
void sortEmployeesBySalary(void);           
void showPayslip(void);

double calculateSalary(double basic, double housing, double transport);
double calculateTax(double grossSalary);
double calculateNetSalary(const Employee *employee);
int findEmployeeIndex(int employeeId);      

#endif
