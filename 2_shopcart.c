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
    Implement a shopping cart system for an e-store in C using array of structures with the
    following functionalities.
    (i)     Add item
    (ii)    Delete an item
    (iii)   Display items
    (iv)    Billing information

    Write a flow chart. Also include sample input output in the submission document.

    @author Darshan

*/
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Custom Data Structures to hold cart information
#define maxItems 99
#define maxStock 12

// stock
int inventory[maxStock][3] = {
    {00, 0, 0},         // Just empty option for item 0. Could be avoided but....
    {01, 50, 70},
    {02, 60, 52},
    {03, 120, 60},
    {04, 110, 34},
    {05, 122, 52},
    {06, 36, 81},
    {07, 42, 90},
    {8, 36, 72},
    {9, 36, 84},
    {10, 25, 42},
    {11, 110, 220},
};

int itemIndex = 0;

// Then create an instance of our cart
/**
 *  A cart structure holding my list of items
 * 
 */
typedef struct shopCart {
    int iCode;
    int quantity;           // Just quantity
    int totalPrice;         // Price
} cart;

/**
 * My Active cart
 * 
 */
cart myCart[maxItems];         // A global variable. Just to make life easy

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Functions

/**
 *  Exit the program
 * 
 */
void end() {
    int e = 1;
    printf("\nThank You for visiting the shop.\n\n");
    printf("\t\t\tHave a GOOD DAY ;)\n\n\n\n");
    fflush(stdin);
    printf("\nPress 1 to exit...");
    scanf("%d", &e);
    exit(9);         // Custom exit code
}

/**
 * Check if cart is empty
 * 
 *
 */
int isCartEmpty() {
    int c = 0;
    for (int i = 0; i < maxItems; i++) {
        if (myCart[i].quantity != 0) {
            c++;
        }
    }
    return c == 0;
}

/**
 *  Show the inventory with latest items. Simple formatting and display function.
 * 
 */
void showInventory() {
    printf("\n\n");
    printf("---------------------------------------------------------------------------------------------");
    printf("\n");
    printf("\tItem Code\tAvalilable Quantity(KGs)\tPrice per KG");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------");
    printf("\n");
    // Show list from inventory
    for (int i = 1; i < maxStock; i++) {
        printf("\t  %d\t\t", inventory[i][0]);
        printf("\t%d\t", inventory[i][1]);
        printf("\t\t   Rs.%d", inventory[i][2]);
        printf(("\n"));
    }
    printf("---------------------------------------------------------------------------------------------");
    printf("\n\n");
}

/**
 *  Shows the current status of your cart
 * 
 */
void showCart() {
    printf("\n\n");
    printf("-----------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("\tItem Code\tQuantity Added(KGs)\t\tPrice per KG\tTotal Price");
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------");
    printf("\n");
    // Show list from inventory
    for (int i = 0; i < itemIndex; i++) {
        cart item = myCart[i];
        if (item.quantity != 0) {
            printf("\t  %d\t\t\t%d\t\t\t   Rs.%d\t Rs.%d", i + 1, item.quantity, inventory[item.iCode][2], item.totalPrice);
            printf(("\n"));
        }
    }
    printf("-----------------------------------------------------------------------------------------------------------------");
    printf("\n\n");
}

/**
 *  Do the user checkout.
 * 
 */
void checkout() {
    int totalWeight = 0, totalCost = 0;
    for (int i = 0; i < itemIndex; i++) {
        totalWeight = totalWeight + myCart[i].quantity;
        totalCost = totalCost + (myCart[i].totalPrice);
    }

    printf("\n\n");
    printf("Hello User. Your current bill is as follows:\n");
    printf("\nTotal Weight of items is = %d KGs\n\nYour Total Bill amount comes to Rs.%d\n\n", totalWeight, totalCost);
    end();
}

/**
 *  Add an item to the cart
 * 
 */
void addItem() {
    int itemCode = 0, itemQuantity = 0, maxQuantity = 0;
    showInventory();
    printf("\n\n");

    // Read ItemCode
    printf("Enter an Item code from the inventory:\t");
    scanf("%d", &itemCode);
    while (itemCode > maxItems || itemCode < 1) {
        printf("Invalid item code. Please enter a valid Item code from the inventory:\t");
        scanf("%d", &itemCode);
    }
    maxQuantity = inventory[itemCode][1];
    if (maxQuantity == 0) {
        printf("\nSorry, the product is out of stock!");
        return;
    }

    // Read quantity
    printf("\n");
    printf("Currently, you have selected %d\nEnter quantity to add (max of %d):\t", itemCode, maxQuantity);
    scanf("%d", &itemQuantity);
    while (itemQuantity > maxQuantity || itemQuantity < 1) {
        printf("Invalid quantity. Please enter a valid quantity from the inventory:\t");
        scanf("%d", &itemQuantity);
    }
    printf("\n");

    // Do the math
    myCart[itemIndex].quantity = itemQuantity;
    myCart[itemIndex].totalPrice = (itemQuantity * inventory[itemCode][2]);
    myCart[itemIndex].iCode = itemCode;

    // Subtract from inventory... Obviously
    inventory[itemCode][1] = inventory[itemCode][1] - itemQuantity;

    printf("Successfuly added to cart:  %d KG of %d\n", itemQuantity, inventory[itemCode][0]);

    itemIndex++;

    return;
}

/**
 *  Removes item from the cart.
 * 
 */
void removeItem() {
    int itemCode = 0, itemQuantity = 0, maxQuantity = 0;
    if (isCartEmpty()) {
        printf("\n\nYour cart is empty!");
        return;
    }
    showCart();
    printf("\n\n");

    // Read ItemCode
    printf("Enter an Item code from the cart:\t");
    scanf("%d", &itemCode);
    int myQ = myCart[itemCode - 1].quantity;         // Check if quantity exists and is greater than 0
    while (!myQ >= 1 || itemCode < 1) {
        printf("Invalid item code. Please enter a valid Item code from the cart:\t");
        scanf("%d", &itemCode);
    }
    itemCode--;         // remove 1
    maxQuantity = myCart[itemCode].quantity;

    // Read quantity
    printf("\n");
    printf("Currently, you have selected %d\nEnter -1 to remove all or just Enter quantity to remove (max of %d): \t", itemCode, maxQuantity);
    scanf("%d", &itemQuantity);
    while (itemQuantity > maxQuantity || itemQuantity < -1 || itemQuantity == 0) {
        printf("Invalid quantity. Please enter a valid quantity from the inventory:\t");
        scanf("%d", &itemQuantity);
    }
    printf("\n");
    itemQuantity = (itemQuantity == -1 ? maxQuantity : itemQuantity);

    // Do the math
    myCart[itemCode].quantity = myCart[itemCode].quantity - itemQuantity;
    myCart[itemCode].totalPrice = myCart[itemCode].quantity * inventory[myCart[itemCode].iCode][2];

    // Subtract from inventory... Obviously
    inventory[myCart[itemCode].iCode][1] = inventory[myCart[itemCode].iCode][1] + itemQuantity;

    printf("Successfuly removed from cart:  %d KG of %d\n", itemQuantity, itemCode);

    return;
}

/**
 * Displays a neat view of cart. Also provides checkout features.
 * 
 */
void displayCart() {
    int c = 0;
    if (isCartEmpty()) {
        printf("\n\nYour cart is empty!");
        return;
    }
    printf("\n\n");
    printf("Hello User. This is your cart.\n");
    showCart();
    printf("\n\n");
    printf("So, do you want to checkout?\nPress 1 to checkout or just press any other number to go back to home.\t");
    scanf("%d", &c);
    if (c == 1) {
        checkout();
    } else {
        return;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main Code

int main() {
    // Local variables
    int choice;
    // In a do-while llop to keep the instance active till end
    do {
        printf("\nWelcome to Darshan's Shop.\n");
        printf("Please feel free to check the inventory and shop for what you need.\n");
        printf("Have a great day :)\n");
        // Now show the actual inventory
        showInventory();
        // Options
        printf("So, what do you plan to to today?\n");
        printf("1. Add an Item to my cart...\n");
        printf("2. Remove an Item from my cart....\n");
        printf("3. View my cart...\n");
        printf("4. Leave the shop...\n");
        printf("What are you planning to do today?\t");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                displayCart();
                break;
            case 4:
                end();
                break;
            default:
                printf("\nInvalid Option.\n");
                return 0;
                break;
        }
    } while (1);

    return 9;
}
