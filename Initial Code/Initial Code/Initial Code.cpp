// Initial Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>

using namespace std;
int main()
{
    int choice;

    struct add {
        char firstname;
        char lastname;
        char student_num;
        char course;
        float grades;
        int year;
    };
    struct student a;
    int a = 0;

    std::cout << "Hello World!\n";
    cout << "1 add \n";
    cout << "2 view \n";
    cout << "3 delete \n";
    cout << "4 edit \n";
    cin >> choice;

    if (choice == 1) {
        cout << "Add Record\n";
        cout << "Firstname\n";
        cin >> a.firstname;
        cout << "Lastname \n";
        cin >> a.lastname ;

    }

    if (choice == 2) {
        cout << "view";
    }

    if (choice == 3) {
        cout << "delete";
    }

    if (choice == 4) {
        cout << "edit";
    }

    /*
    else if (file > 1) {
        cout << "view";
    }

    else if (file > 2) {
        cout << "delete";
    }

    else if (file > 3) {
        cout << "add";
    }

    else if (file > 4) {
        cout << "wrong";
        return 1;
    }

    else {
        cout << "wrong";
    }

            return 0;
    */


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
