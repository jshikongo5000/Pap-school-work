#ifndef ASSETS_H
#define ASSETS_H

#include "employees.h"

#define MAX_ASSETS 200
#define TYPE_LENGTH 30
#define CONDITION_LENGTH 20

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char type[TYPE_LENGTH];
    double purchaseValue;
    char department[DEPARTMENT_LENGTH];
    char condition[CONDITION_LENGTH];
} Asset;

extern Asset assets[MAX_ASSETS];
extern int assetCount;

void assetMenu(void);
void addAsset(void);
void displayAssets(void);
void searchAssetByName(void);

#endif