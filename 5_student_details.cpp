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
    Write and execute a C++ program to read n students
    details- Name, USN, and marks in 3 subjects.
    Calculate and display the total, percentage
    and grade obtained for each student. Refer the following table for grading.        
    >=80            Grade A        
    >=70  and  <80  Grade B        
    >=60  and  <70  Grade C
    Create a STUDENT class; initialize the student details using constructors.

    @author Darshan
    
*/
#include <stdlib.h>

#include <iostream>
#include <string>

using namespace std;

class Student {
   private:
    string name;
    string usn;
    int marks[3];
    int maxMarks, totalMarks;
    double percentage;
    char grade;

   public:
    // Functions to find total marks, grade and percentage
    void calculate() {
        totalMarks = marks[0] + marks[1] + marks[2];
        int maxTot = 3 * maxMarks;
        percentage = (totalMarks * 100) / maxTot;         // total_marks / sum of max marks in all subjects * 100 for percentage
        if (percentage >= 80.00) {
            grade = 'A';
        } else if (percentage >= 70 && percentage < 80) {
            grade = 'B';
        } else if (percentage >= 60 && percentage < 70) {
            grade = 'C';
        }

        else {
            grade = 'F';
        }
    }

    string getName() { return name; }
    string getUSN() { return usn; }
    char getGrade() { return grade; }
    int getTotal() { return totalMarks; }
    double getPercentage() { return percentage; }
    // Constructor - default
    Student() {
        name = "name";
        usn = "usn";
        marks[0] = 0;
        marks[1] = 0;
        marks[2] = 0;
        maxMarks = 1;
    }
    // Constructor - Parametric
    Student(string n, string u, int marks1, int marks2, int marks3, int maxMrks) {
        name = n;
        usn = u;
        marks[0] = marks1;
        marks[1] = marks2;
        marks[2] = marks3;
        maxMarks = maxMrks;
        calculate();
    }
};

// Util functions

void printStudents(Student* record, int n) {
    printf("\n\n\nStudent Records:");
    printf("\n--------------------------------------------------------------------------------------");
    printf("\n\tName\t\tUSN\t\tTotal Scored\tPercentage\tGrade");
    printf("\n--------------------------------------------------------------------------------------");
    for (int i = 0; i < n; i++) {
        Student s = record[i];
        cout << "\n\t" << s.getName();
        if (s.getName().length() < 7) {
            cout << "\t";
        }
        cout << "\t" << s.getUSN() << "\t\t      " << s.getTotal() << "\t\t   " << s.getPercentage() << "%\t\t  " << s.getGrade();
    }
    printf("\n--------------------------------------------------------------------------------------");
}

int main() {
    int n = 1;
    printf("\nPlease enter the number of students:\t");
    cin >> n;
    Student* students = new Student[n];
    for (int i = 0; i < n; i++) {
        string na, un;
        int m1, m2, m3, maxMarks;
        cout << "\n\nEnter details for student" << i + 1;
        printf("\nName:\t");
        cin >> na;
        printf("USN:\t");
        cin >> un;
        printf("Marks for subject 1:\t");
        cin >> m1;
        printf("Marks for subject 2:\t");
        cin >> m2;
        printf("Marks for subject 3:\t");
        cin >> m3;
        printf("Maximun marks that can be scored in one subject:\t");
        cin >> maxMarks;
        cout << "\nSaved details for student " << na << "( " << i + 1 << " out of " << n << " )";
        students[i] = Student(na, un, m1, m2, m3, maxMarks);
    }
    printStudents(students, n);
    free(students);
    return 9;         // ENDGAME
}