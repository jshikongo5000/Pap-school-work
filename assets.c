#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "utils.h"

Asset assets[MAX_ASSETS];
int assetCount = 0;

void addAsset(void) {
    if (assetCount >= MAX_ASSETS) {
        printf("Asset list is full!\n");
        return;
    }

    Asset newAsset;
    newAsset.id = readPositiveInt("Enter Asset ID: ");
    for (int i = 0; i < assetCount; i++) {
        if (assets[i].id == newAsset.id) {
            printf("Error: Asset ID %d already exists.\n", newAsset.id);
            return;
        }
    }

    readLine("Enter asset name: ", newAsset.name, NAME_LENGTH);
    if (strlen(newAsset.name) == 0) {
        printf("Error: Name cannot be empty.\n");
        return;
    }

    readLine("Enter asset type (Vehicle/Computer/Building/...): ",
             newAsset.type, TYPE_LENGTH);
    newAsset.purchaseValue = readNonNegativeDouble("Enter purchase value (N$): ");
    readLine("Enter department: ", newAsset.department, DEPARTMENT_LENGTH);
    readLine("Enter condition (Good/Fair/Poor): ", newAsset.condition, CONDITION_LENGTH);

    assets[assetCount] = newAsset;
    assetCount++;
    printf("Asset added successfully.\n");
}

void displayAssets(void) {
    if (assetCount == 0) {
        printf("No assets registered.\n");
        return;
    }
    printf("\n%-6s %-22s %-14s %15s %-14s %-10s\n",
           "ID", "Name", "Type", "Value", "Department", "Condition");
    printf("--------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < assetCount; i++) {
        printf("%-6d %-22s %-14s %15.2f %-14s %-10s\n",
               assets[i].id, assets[i].name, assets[i].type,
               assets[i].purchaseValue, assets[i].department, assets[i].condition);
    }
}

void searchAssetByName(void) {
    if (assetCount == 0) {
        printf("No assets registered.\n");
        return;
    }
    char searchName[NAME_LENGTH];
    int found = 0;
    readLine("Enter asset name to search: ", searchName, NAME_LENGTH);
    for (int i = 0; i < assetCount; i++) {
        if (strcmp(assets[i].name, searchName) == 0) {
            printf("Found: ID %d | %s | %s | N$%.2f | %s | %s\n",
                   assets[i].id, assets[i].name, assets[i].type,
                   assets[i].purchaseValue, assets[i].department,
                   assets[i].condition);
            found = 1;
        }
    }
    if (!found) {
        printf("No asset named '%s' found.\n", searchName);
    }
}

void assetMenu(void) {
    int choice;
    do {
        printf("\n========== ASSET MANAGEMENT ==========\n");
        printf("1. Add asset\n");
        printf("2. Display assets\n");
        printf("3. Search asset by name\n");
        printf("0. Back to main menu\n");
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1: addAsset();          break;
            case 2: displayAssets();     break;
            case 3: searchAssetByName(); break;
            case 0: break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);
}
