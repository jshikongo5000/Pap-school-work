#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "utils.h"

supplier suppliers[MAX_SUPPLIERS];
int supplierCount = 0;

void addSupplier(void){
  if (supplier >= MAX_SUPPLIERS){
    printf("Supplier list is full!\n");
      return;
  }

  supplier newSupplier;
  newSupplier.id = readpositiveInt("Enter Supplier ID: ");
  for (int 1 = 0; 1 < supplierCount; 1++) {
    if(suppliers[i].id == newSupplierCount; i++) {
        printf("Error: Suppliers ID %d adready exist.\n");  
    }
  }
  readLine("Enter supplier name: ", newSupplier.name, NAME_LENGTH);
  if (strlen(newSupplier.name) == 0) {      
      printf("Error: Name cannot be empty.\n");
      return;
  }
  readLine("Enter email: ", newSupplier.email, EMAIL_LENGTH);
  if (strchr(newSupplier.email, '@') == NULL) {
      printf("Error: invalid email (must contain @).\n");
       return;
  }

  readLine("Enter telephone number: ", newSupplier.telephone, PHONE_LENGTH);
  readLine("Enter town / location: ", newSupplier.town, TOWN_LENGTH);

  suppliers[supplierCount] = newSupplier;
  supplierCount++;
  printf("Supplier added successfully.\n");
}

void displaySuppliers(void) {
    if (supplierCount == 0) {
        printf("No suppliers registered.\n");
        return;
    }
    printf("\n%-6s %-22s %-28s %-15s %-15s\n",
           "ID", "Name", "Email", "Telephone", "Town");
    printf("--------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < supplierCount; i++) {
        printf("%-6d %-22s %-28s %-15s %-15s\n",
               suppliers[i].id, suppliers[i].name, suppliers[i].email,
               suppliers[i].telephone, suppliers[i].town);
    }
}

void searchSupplierByName(void) {
    if (supplierCount == 0) {
        printf("No suppliers registered.\n");
        return;
    }
    char searchName[NAME_LENGTH];
    int found = 0;
    readLine("Enter supplier name to search: ", searchName, NAME_LENGTH);
    for (int i = 0; i < supplierCount; i++) {
        if (strcmp(suppliers[i].name, searchName) == 0) {
            printf("Supplier found:\n");
            printf("  ID    : %d\n", suppliers[i].id);
            printf("  Email : %s\n", suppliers[i].email);
            printf("  Phone : %s\n", suppliers[i].telephone);
            printf("  Town  : %s\n", suppliers[i].town);
            found = 1;
        }
    }
    if (!found) {
        printf("No supplier named '%s' found.\n", searchName);
    }
}

void searchSuppliersByTown(void) {
    if (supplierCount == 0) {
        printf("No suppliers registered.\n");
        return;
    }
    char town[TOWN_LENGTH];
    int found = 0;
    readLine("Enter town to search: ", town, TOWN_LENGTH);
    for (int i = 0; i < supplierCount; i++) {
        if (strcmp(suppliers[i].town, town) == 0) {
            printf("  %-22s (%s)\n", suppliers[i].name, suppliers[i].email);
            found = 1;
        }
    }
    if (!found) {
        printf("No suppliers found in '%s'.\n", town);
    }
}

void buildSupplierDescription(const Supplier *supplier,
                              char *description, int maxLength) {
    strcpy(description, supplier->name);       
    strcat(description, " - supplies the municipality in ");
    strcat(description, supplier->town);       
    strcat(description, ". Contact: ");
    strcat(description, supplier->email);
    (void)maxLength;   
}

void showSupplierDescription(void) {
    if (supplierCount == 0) {
        printf("No suppliers registered.\n");
        return;
    }
    char searchName[NAME_LENGTH];
    char description[DESCRIPTION_LENGTH];
    int found = 0;
    readLine("Enter supplier name: ", searchName, NAME_LENGTH);
    for (int i = 0; i < supplierCount; i++) {
        if (strcmp(suppliers[i].name, searchName) == 0) {
            buildSupplierDescription(&suppliers[i], description, DESCRIPTION_LENGTH);
            printf("\nDescription: %s\n", description);
            found = 1;
        }
    }
    if (!found) {
        printf("No supplier named '%s' found.\n", searchName);
    }
}

void supplierMenu(void) {
    int choice;
    do {
        printf("\n========== SUPPLIER MANAGEMENT ==========\n");
        printf("1. Add supplier\n");
        printf("2. Display suppliers\n");
        printf("3. Search supplier by name\n");
        printf("4. Search suppliers by town\n");
        printf("5. Show supplier description (strcpy/strcat)\n");
        printf("0. Back to main menu\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: addSupplier();            break;
            case 2: displaySuppliers();       break;
            case 3: searchSupplierByName();   break;
            case 4: searchSuppliersByTown();  break;
            case 5: showSupplierDescription(); break;
            case 0: break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);
}
