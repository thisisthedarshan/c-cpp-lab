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
    Write and execute a C++ program with function
    overloading to calculate the area of a circle, rectangle and a triangle.

    @author Darshan
*/

#include <stdlib.h>

#include <iostream>
#include <string>

using namespace std;

class Shapes {
   public:
    // Double inputs
    float area(double r) {
        return 3.141592 * (r * r);
    }
    int area(int length, int width) {
        return length * width;
    }
    float area(double base, double height) {
        return (base * height) / 2;
    }
};

int main() {
    // Test program
    Shapes shapes;
    double traingleBase = 12.1233, triangleHeight = 13.142;
    int rectangleLen = 9, rectangleWidth = 4;
    double circleRadius = 9.99;
    float triangleTest = shapes.area(traingleBase, triangleHeight);
    float rectangleTest = shapes.area(rectangleLen, rectangleWidth);
    float circleTest = shapes.area(circleRadius);
    cout << "\n"
         << "Test results are as follows:"
         << "\n"
         << "Traingle Area is = " << triangleTest
         << "\n"
         << "Rectangle Area is = " << rectangleTest
         << "\n"
         << "Circle area is = " << circleTest
         << "\n\n";

    return 9;
}