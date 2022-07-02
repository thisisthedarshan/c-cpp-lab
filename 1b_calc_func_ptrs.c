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
    Implement a simple Calculator application in C. Incorporate modularity for the following.
    (i) Read the two numbers and the operation(+, - , * , /).
    (ii) Modules for addition, subtraction, multiplication, and division.
    (iii) Display the results.

    Use pointers to functions for add, subtract, multiply and divide operations.
    
    @author Darshan
*/

#include <stdio.h>
// Function Definitions.
float add(int a, int b) {
    return a + b;
}
float sub(int a, int b) {
    return a - b;
}
float mul(int a, int b) {
    return a * b;
}
float div(int a, int b) {
    return b != 0 ? a / b : 0.0;
}
void display(float d) {
    printf("\nThe answer is %f", d);
    printf("\n\n\n");
}
int main() {
    // Setup the required things
    // Variables
    int a, b;               // Holding variables to play with. Max limited to 99.
    char opr = '+';         // The operation variable. Default is addition.
    float result;
    // Function pointers
    float (*func)(int, int);
    void (*disp)(float f);
    disp = display;
    // Setup a display screen which displays user with beginning screen. Asks  for details
    printf("Welcome to calculator console application.\n\n");
    printf("Choose and operation to begin with.\n");
    printf(" Enter + to choose addition.\n Enter - to choose subtraction.\nEnter * to choose multiplication.\nEnter / to choose division.\n\nChoice is:\t");
    scanf("%s", &opr);
    printf("\n\n");
    printf("\nEnter the number with a space between them\t");
    scanf("%d %d", &a, &b);
    switch (opr) {
        case '+':
            func = add;
            break;
        case '-':
            func = sub;
            break;
        case '*':
            func = mul;
            break;
        case '/':
            func = div;
            break;
        default:
            func = add;
            break;
    }
    result = (*func)(a, b);
    (*disp)(result);

    return 9;
}
