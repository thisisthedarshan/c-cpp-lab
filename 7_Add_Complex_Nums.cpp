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
    Write and execute a C++ program to implement the COMPLEX
    number class and perform the following operations.
    
    (i)     Read a complex number
    (ii)    Display a complex number
    (iii)   Add two complex numbers
    
    Use objects as function arguments.

    @author Darshan
*/
#include <iostream>

using namespace std;

class complex_number {
   public:
    int real, imag;
};

complex_number addTwoCompleNumbers(complex_number c1, complex_number c2) {
    complex_number sum;
    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;
    return sum;
}

int main() {
    complex_number num1, num2, result;
    cout << "\n\n";

    cout << "Enter real and imaginary parts of first complex number:\t";
    cin >> num1.real >> num1.imag;

    cout << "\nEnter real and imaginary parts of second complex number:";
    cin >> num2.real >> num2.imag;

    result = addTwoCompleNumbers(num1, num2);

    if (result.imag >= 0)
        cout << "\nSum of two complex numbers = " << result.real << " + " << result.imag << "i";
    else
        cout << "\nSum of two complex numbers = " << result.real << " - " << result.imag << "i";

    cout << "\n\n";

    return 9;
}