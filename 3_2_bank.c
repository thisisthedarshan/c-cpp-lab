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
     Implement a simple Banking Application in C by making
     use of array of structures. Include the modules to
           (i)  Deposit amount
          (ii)  Withdraw amount
          (iii) Balance Enquiry

     Draw the flowchart. Include Sample Input Output in the submission document. 

     @author Darshan

*/

// Standard Include
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants:
#define MAXUSERS 9
#define newline printf("\n")         // User Macro

int acNum = 0;

// Users
char userNames[MAXUSERS][21];         // Contains user names
int userDetails[MAXUSERS][2];         // Contains the account number & balance

// Custom functions
void clr() {
    system("cls");         // Windows keyword
}
void showBalance() {
    int c;
    newline;
    printf("Dear %s, your current balance is %d", userNames[acNum], userDetails[acNum][1]);
    newline;
    printf("Enter 1 to  continue...\t");
    scanf("%d", &c);
    return;
}
void withdraw() {
    int c;
    newline;
    printf("Dear %s, your current balance is %d", userNames[acNum], userDetails[acNum][1]);
    newline;
    printf("How much do you want to withdraw:\t");
    scanf("%d", &c);
    while (c > userDetails[acNum][1] || c < 0) {
        newline;
        printf("Invaild Entry. Enter appropriate amount:\t");
        scanf("%d", &c);
    }
    userDetails[acNum][1] -= c;
    newline;
    printf("Amount Debited!");
    newline;
    printf("Your new balance is %d", userDetails[acNum][1]);
    newline;
    printf("Press 1 to continue\t");
    scanf("%d", &c);         // Wait till exit accepted
    return;
}
void deposit() {
    int c;
    newline;
    printf("Dear %s, your current balance is %d", userNames[acNum], userDetails[acNum][1]);
    newline;
    printf("How much do you want to deposit:\t");
    scanf("%d", &c);
    while (c < 1) {
        newline;
        printf("Invaild Entry. Enter appropriate amount:\t");
        scanf("%d", &c);
    }
    userDetails[acNum][1] += c;
    newline;
    printf("Amount Credited!");
    newline;
    printf("Your new balance is %d", userDetails[acNum][1]);
    newline;
    printf("Press 1 to continue\t");
    scanf("%d", &c);         // Wait till exit accepted
    return;
}

int main() {
    // Vars
    int choice;

    // Load users
    strncpy(userNames[0], "Yoshio Yoshimura", sizeof("Yoshio Yoshimura"));
    userDetails[0][0] = 100;          // Account Number
    userDetails[0][1] = 6449;         // Balance

    strncpy(userNames[1], "Chiyoko Numata", sizeof("Chiyoko Numata"));
    userDetails[1][0] = 101;          // Account Number
    userDetails[1][1] = 6419;         // Balance

    strncpy(userNames[2], "Lea Shannon", sizeof("Lea Shannon"));
    userDetails[2][0] = 102;          // Account Number
    userDetails[2][1] = 6917;         // Balance

    strncpy(userNames[3], "Christina Lebel", sizeof("Christina Lebel"));
    userDetails[3][0] = 103;           // Account Number
    userDetails[3][1] = 22170;         // Balance

    strncpy(userNames[4], "Saisuni Saithong", sizeof("Saisuni Saithong"));
    userDetails[4][0] = 104;           // Account Number
    userDetails[4][1] = 69420;         // Balance

    strncpy(userNames[5], "Mek Ngu", sizeof("Mek Ngu"));
    userDetails[5][0] = 105;          // Account Number
    userDetails[5][1] = 7016;         // Balance

    strncpy(userNames[6], "Lynn Barratt", sizeof("Lynn Barratt"));
    userDetails[6][0] = 106;           // Account Number
    userDetails[6][1] = 37079;         // Balance

    strncpy(userNames[7], "Marian Walter", sizeof("Marian Walter"));
    userDetails[7][0] = 107;           // Account Number
    userDetails[7][1] = 10647;         // Balance

    strncpy(userNames[8], "Darshan Patel", sizeof("Darshan Patel"));
    userDetails[8][0] = 108;            // Account Number
    userDetails[8][1] = 999189;         // Balance

    // Now ask for entry
    newline;
    printf("-------------------------------------------------------");
    newline;
    printf("Welcome to the Royal Duke's Bank");
    newline;
    printf("-------------------------------------------------------");
    newline;
    printf("Please enter your account number :\t");
    scanf("%d", &acNum);
    acNum = acNum % 100;         // Get last digit

    while (1) {
        clr();

        printf("-------------------------------------------------------");
        newline;
        printf("Hello %s. Welcome to the Royal Duke's Bank.", userNames[acNum]);
        newline;
        printf("How can we help you today?");
        newline;
        printf("-------------------------------------------------------");
        newline;
        printf("1. Check Account Balance");
        newline;
        printf("2. Withdraw Amount");
        newline;
        printf("3. Deposit Amount");
        newline;
        printf("4. Exit");
        newline;
        newline;
        printf("Your choice is: ");
        scanf("%d", &choice);
        clr();         // Clear Screen
        switch (choice) {
            case 1:
                showBalance();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                deposit();
                break;
            case 4:
                newline;
                printf("Thank you for visiting the bank. Have a nice day.");
                newline;
                printf("Press 1 to exit\t");
                scanf("%d", &choice);
                exit(9);
                break;

            // Wrong Entry
            default:
                newline;
                printf("Invalid Entry. Please retry. Enter any number to continue:\t");
                scanf("%d", &choice);

                break;
        }
    }

    return 9;
}