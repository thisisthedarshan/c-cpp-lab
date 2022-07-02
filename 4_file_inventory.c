/*
************************************************************************************************
************************************************************************************************
***                                                                                          ***
***          Copyright (C) 2022  Darshan                                                     ***
***                                                                                          ***
***          This program is free software: you can redistribute it and/or modify            ***
***          it under the terms of the GNU General Public License as published by            ***
***          the Free Software Foundation, either version 3 of the License, or               ***
***          (at your option) any later version.                                             ***
***                                                                                          ***
***          This program is distributed in the hope that it will be useful,                 ***
***          but WITHOUT ANY WARRANTY; without even the implied warranty of                  ***
***          MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                   ***
***          GNU General Public License for more details.                                    ***
***                                                                                          ***
***          You should have received a copy of the GNU General Public License               ***
***          along with this program.  If not, see https://www.gnu.org/licenses.             ***
***                                                                                          ***
***                                                                                          ***
************************************************************************************************
************************************************************************************************
*/

/**
 * @file file_invetory.c
 * @author Darshan (thisisthedarshan.github.io)
 * @brief An Inventory application capable of dynamically loading data from a file, along with capabilities  to perform CRUD Operations.
 * @version 0.1.2
 * @date 2022-06-07
 * 
 * @copyright Copyright (c) 2022 - Darshan;  licensed under GNU GPL v3 and later
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Some constants
#define maxChars 21

// Define data structure
typedef struct file_invetory {
    int id;
    char productName[maxChars];
    int price;
    int quantity;
} Inventory;

// Global Variables
Inventory* myInventory;
int inventorySize = 0;

// Define custom functions

/**
 * Loads inventory from file into the inventory dataset.
 * 
 * Features a dynamic data laoding system.
 * 
 */
int loadInventory() {
    FILE* fp;
    fp = fopen("inventory.dsp", "ab+");         // read inventory.dsp file
    int count = 1;                              // Count Values
    char ch;
    if (fp == NULL) {
        printf("File Doesn't exist !");
        return -1;
    }
    // Char to hold hold val
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n')
            count++;         // Read Counts and increase it. For dynamic memory allocation
    }
    fclose(fp);         // Temporarily close

    fp = fopen("inventory.dsp", "r");         // read inventory.dsp file

    inventorySize = count;         // Set for global access
    // Now create a dynamic array to hold any number of elements
    myInventory = calloc(count, sizeof(Inventory));
    if (myInventory == NULL) {
        printf("Memory Allocation Failed");
        return -2;
    }

    // Now fill in the inventory
    char line[256], amt[18], quan[18];
    int c = 0, d = 0;
    myInventory[0].id = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        line[255] = '\0';
        char load = 'n';
        // get the name
        char product[256];
        for (int i = 0; i < 256; i++) {
            char n = line[i];
            if (n == '.') {         // End of line
                quan[d] = '\0';
                d = 0;
                load = 'n';
                break;
            }
            if (load == 'o') {
                amt[d] = n;
                d++;
            }
            if (load == 'e') {
                quan[d] = n;
                d++;
            }
            if (n == '*') {
                product[i] = '\0';
                load = 'o';
            }
            if (n == '>') {
                amt[d] = '\0';
                load = 'e';
                d = 0;
            }
            if (load == 'n') {
                product[i] = n;
            }
        }

        myInventory[c].id = c + 1;
        strcpy(myInventory[c].productName, product);
        myInventory[c].price = atoi(amt);             // Get amount
        myInventory[c].quantity = atoi(quan);         // Get quantity
        c++;
    }
    fclose(fp);
    // ENDS

    //for (int pos = 0; pos < inventorySize; pos++) {
    //    int price;
    //    char product[maxChars];         // Set ID
    //    // Read pattern
    //
    //    fscanf(fp, "%c*%d", product, &price);         // File Read
    //    printf("%s %d", product, price);
    //
    //    strcpy(myInventory[pos].productName, product);
    //    myInventory[pos].price = price;
    //    //getchar();
    //    return 1;         // Treat success
    //}
    //
    //// Don't know why we came here. Maybe a failure?
    return 1;
}
/**
 * @brief Display's Inventory on console
 * 
 */
void showInventory() {
    printf("\n\n--------------------------------------------------------------------------\n");
    printf("\tID\tProduct Name\t\tPrice\t\tQuantity\n");
    printf("--------------------------------------------------------------------------\n");
    for (int i = 0; i < inventorySize; i++) {
        printf("\t%d\t%s\t\t",
               myInventory[i].id,
               myInventory[i].productName);

        if (strlen(myInventory[i].productName) <= 7) {
            printf("\t");
        }
        printf("Rs.%d",
               myInventory[i].price);

        if (myInventory[i].price < 9999) {
            printf("\t");
        }
        printf("\t   %d\n",
               myInventory[i].quantity);
    }
    printf("--------------------------------------------------------------------------\n");
}
/**
 * @brief Writes the inventory file back to the file system.
 * 
 */
void writeInventory() {
    FILE* fp;
    fp = fopen("inventory.dsp", "w");         // open inventory.dsp file
    if (fp == NULL) {
        printf("\nFailed to write to file...\nUnable to open\n");
        return;
    }
    for (int i = 0; i < inventorySize; i++) {
        fprintf(fp, "%s*%d>%d.", myInventory[i].productName, myInventory[i].price, myInventory[i].quantity);
        if (i + 1 != inventorySize) {
            fprintf(fp, "\n");
        }
    }
    printf("\nFile written successfully!");
    fclose(fp);
}

/**
 * @brief Modify name of the product
 * 
 * @param pos 
 */
void modifyName(int pos) {
    char* prev = myInventory[pos].productName;
    char new[21];
    unsigned int valid = 0;
    printf("\nThe choice made is: %s", prev);
    printf("\nWhat do you want it to be replaced with?\t");
    scanf("%s", new);
    strcpy(myInventory[pos].productName, new);

    //while (!valid) {
    //    scanf("%s", new);
    //    if (strlen(new) > 255) {
    //        printf("\nInvalid Size. Please keep the name under 250 characters.");
    //    } else {
    //        valid = 1;
    //        strcpy(myInventory[pos].productName, new);
    //    }
    //}
}
/**
 * @brief Modifies the price at position
 * 
 * @param pos position
 */
void modifyPrice(int pos) {
    int price;
    printf("\nThe price for %s is %d.", myInventory[pos].productName, myInventory[pos].price);
    printf("\nWhat should be the new price?\t");
    scanf("%d", &price);
    myInventory[pos].price = price;
    // Complete
}
/**
 * @brief Modifies the quantity at position
 * 
 * @param pos position
 */
void modifyQuantity(int pos) {
    int quan;
    printf("\nThe quantity for %s is %d.", myInventory[pos].productName, myInventory[pos].quantity);
    printf("\nWhat should be the new price?\t");
    scanf("%d", &quan);
    myInventory[pos].quantity = quan;
    // Complete
}

void addNewProduct() {
    inventorySize++;
    myInventory = realloc(myInventory, inventorySize);         // Extend memory
    // Now add new product
    char name[21];
    int price, quantity;
    printf("\nEnter product name:\t");
    scanf("%s", &name);
    printf("\nNow enter the price and quantity seperated by a space:\t");
    scanf("%d %d", &price, &quantity);
    // Now add it to inventory
    myInventory[inventorySize - 1].id = inventorySize;
    strcpy(myInventory[inventorySize - 1].productName, name);
    myInventory[inventorySize - 1].price = price;
    myInventory[inventorySize - 1].quantity = quantity;
    // Completed
}

/**
 * @brief Modifies and saves the inventory as per the inputs 
 * 
 */
void modifyInventory() {
    int choice, pos;
    printf("\nOption to change inventory was selected.");
    printf("\nWhat do you want to do?\n");
    printf("\n1. Modify name");
    printf("\n2. Modify price");
    printf("\n3. Modify quantity");
    printf("\n4. Add new product");
    printf("\nYour choice:\t");
    scanf("%d", &choice);
    while (choice > 4 && choice < 1) {
        printf("\nInvalid choice. Please choose a valid option:\t");
        scanf("%d", &choice);
    }
    // clear disp & show inventory?
    if (choice != 4) {
        printf("\nPlease enter the position of the element you want to modify\t");
        scanf("%d", &pos);
        while (pos >= inventorySize) {
            printf("\nInvalid position. Please select a valid id:\t");
            scanf("%d", &pos);
        }
    }
    pos--;
    switch (choice) {
        case 1:
            modifyName(pos);
            break;
        case 2:
            modifyPrice(pos);
            break;
        case 3:
            modifyQuantity(pos);
            break;
        case 4:
            addNewProduct();
            break;
        default:
            break;
    }
    // Now write to inventory
    writeInventory();
}

int main() {
    int res = loadInventory();
    char c;
    while (res == -1) {
        // File doesn't exist. Maybe an internal error occured? Exit :(
        return 0;
    }

    while (1) {         // Run Forever??
        // Main code
        system("cls");         // clear inventory
        showInventory();
        printf("\n\nDo you intend to modify the inventory?");
        printf("\nEnter y to modify, n to exit\t");
        scanf("%c", &c);
        if (c == 'y' || c == 'Y') {
            // Clear screen
            modifyInventory();
        } else if (c == 'n' || c == 'N') {
            break;
        }
    }

    // Clear inventory on end.
    free(myInventory);
    return 9;
}
