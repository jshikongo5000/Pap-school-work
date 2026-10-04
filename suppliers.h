#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#include "employees.h"

#define MAX_SUPPLIERS 100
#define EMAIL_LENGTH 60
#define PHONE_LENGTH 20
#define TOWN_LENGTH 30
#define DESCRIPTION_LENGTH 140

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
    char telephone[PHONE_LENGTH];
    char town[TOWN_LENGTH];
} Supplier;

extern Supplier suppliers[MAX_SUPPLIERS];
extern int supplierCount;

void supplierMenu(void);
void addSupplier(void);
void displaySuppliers(void);
void searchSupplierByName(void);
void searchSuppliersByTown(void);
void showSupplierDescription(void);

void buildSupplierDescription(const Supplier *supplier, char *description, int maxLength);

#endif
