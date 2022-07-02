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
#include <stdlib.h>

#include <iostream>
#include <string>

using namespace std;

class Accounts {
   public:
    int accountNumber;
    string userName;
    long int balance;
};

int acNum = 0;
// Users
Accounts userAccounts[9];

// Custom functions
void clr() {
    system("cls");
}
void showBalance() {
    int c;
    cout << "\n"
         << "Dear " << userAccounts[acNum].userName << ", your current balance is " << userAccounts[acNum].balance << "\n";
    cout << "Enter 1 to  continue..."
         << "\t";
    cin >> c;
    return;
}
void withdraw() {
    int c;
    cout << "\n"
         << "Dear " << userAccounts[acNum].userName << ", your current balance is " << userAccounts[acNum].balance << "\n";
    cout << "How much do you want to withdraw?"
         << "\t";
    cin >> c;
    while (c > userAccounts[acNum].balance || c < 0) {
        cout << "Invalid Amount. Enter valid amount "
             << "\t";
        cin >> c;
    }
    userAccounts[acNum].balance -= c;
    cout << "Amount Debited"
         << "\n";
    cout << "Press 1 to continue"
         << "\t";
    cin >> c;
    return;
}
void deposit() {
    int c;
    cout << "\n"
         << "Dear " << userAccounts[acNum].userName << ", your current balance is " << userAccounts[acNum].balance << "\n";
    cout << "How much do you want to deposit?"
         << "\t";
    cin >> c;
    while (c < 1) {
        cout << "Invalid Amount. Enter valid amount "
             << "\t";
        cin >> c;
    }
    userAccounts[acNum].balance += c;
    cout << "Amount Credited"
         << "\n";
    cout << "Press 1 to continue"
         << "\t";
    cin >> c;
    return;
}

int main() {
    // Vars
    int choice;
    // Load users
    userAccounts[0].accountNumber = 100;
    userAccounts[0].userName = "Yoshio Yoshimura";
    userAccounts[0].balance = 6449;

    userAccounts[1].accountNumber = 101;
    userAccounts[1].userName = "Chiyoko Numata";
    userAccounts[1].balance = 6419;

    userAccounts[2].accountNumber = 102;
    userAccounts[2].userName = "Lea Shannon";
    userAccounts[2].balance = 6917;

    userAccounts[3].accountNumber = 103;
    userAccounts[3].userName = "Christina Lebel";
    userAccounts[3].balance = 22170;

    userAccounts[4].accountNumber = 104;
    userAccounts[4].userName = "Saisuni Saithong";
    userAccounts[4].balance = 69420;

    userAccounts[5].accountNumber = 105;
    userAccounts[5].userName = "Mek Ngu";
    userAccounts[5].balance = 7016;

    userAccounts[6].accountNumber = 106;
    userAccounts[6].userName = "Lynn Barratt";
    userAccounts[6].balance = 37079;

    userAccounts[7].accountNumber = 107;
    userAccounts[7].userName = "Marian Walter";
    userAccounts[7].balance = 10647;

    userAccounts[8].accountNumber = 108;
    userAccounts[8].userName = "Darshan Patel";
    userAccounts[8].balance = 999999;

    // Now ask for entry
    cout << "-------------------------------------------------------"
         << "\n";
    cout << "Welcome to the Royal Duke's Bank"
         << "\n";
    cout << "-------------------------------------------------------"
         << "\n";
    cout << "Please enter your account number :";
    cin >> acNum;
    acNum = acNum % 100;
    while (1) {
        clr();
        cout << "-------------------------------------------------------"
             << "\n";
        cout << "Welcome to the Royal Duke's Bank"
             << "\n";
        cout << "-------------------------------------------------------"
             << "\n";
        cout << "-------------------------------------------------------"
             << "\n";
        cout << "Welcome " << userAccounts[acNum].userName << ". How can we help you today?"
             << "\n";
        cout << "-------------------------------------------------------"
             << "\n";
        cout << "1. Check Account Balance";
        cout << "\n"
             << "2. Withdraw Amount";
        cout << "\n"
             << "3. Deposit Amount";
        cout << "\n"
             << "4. Exit";
        cout << "\n \n";
        cout << "Your choice is: "
             << "\t";
        cin >> choice;
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

            default:
                cout << "\n"
                     << "Thank you for visiting the bank. Have a nice day."
                     << "\n"
                     << "Press 1 to exit"
                     << "\t";
                cin >> choice;
                exit(9);
                break;
        }
    }

    return 9;
}