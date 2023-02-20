
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <string>
#pragma warning(disable:4996)


using namespace std;
int main() {
    FILE* fp, * ft;
    char another, choice;

    std::string username, password;

    struct student {

        char first_name[50];
        char last_name[50];
        char student_num[50];
        char course[100];
        char student_grades[2];
        int year;

    };

    struct student e;
    char xlast_name[50];
    long int recsize;

    fp = fopen("database.txt", "rb+");

    if (fp == NULL) {
        fp = fopen("database.txt", "wb+");

        if (fp == NULL)
        {
            puts("Cannot open file");
            return 0;
        }
    }

    recsize = sizeof(e);

    while (1) {
        system("cls");

        cout << "\n";
        cout << "\n";
        cout << "                                   CGB STUDENT INFORMATION SYSTEM PROJECT\n";
        cout << "\n";
        cout << "                                                    Menu\n";
        cout << "\n";
        cout << "\n\n";
        cout << "        For Students:\n";
        cout << "\n 1 --> Add New Student                            5 --> Exit";
        cout << "\n 2 --> View Records";
        cout << "\n\n";
        cout << "\n";
        cout << "       For Teachers:\n";
        cout << "\n 3 --> Modify Records";
        cout << "\n\n";
        cout << "\n";
        cout << "       For Admin:\n";
        cout << "\n 4 --> Delete Records\n";
        cout << "\n";
        cout << "\n\n";
        cout << "\nSelect your Choice:";
        fflush(stdin);
        choice = getche();
        switch (choice)
        {
        case '1':

            fseek(fp, 0, SEEK_END);
            another = 'Y';
            while (another == 'Y' || another == 'y')
            {
                system("cls");
                cout << "\n";
                cout << "\n";
                cout << "                                                 Sign-up\n";
                cout << "\n";
                cout << "\n";
                cout << "                                           Enter the First Name : ";
                cin >> e.first_name;
                cout << "                                           Enter the Last Name : ";
                cin >> e.last_name;
                cout << "                                           Enter the Student Number : ";
                cin >> e.student_num;
                cout << "                                           Enter the Course    : ";
                cin >> e.course;
                cout << "                                           Enter the Year   : ";
                cin >> e.year;
                fwrite(&e, recsize, 1, fp);
                cout << "\n Add Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;

        case '2':

            system("cls");
            rewind(fp);
            cout << "                                           View Records ";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            while (fread(&e, recsize, 1, fp) == 1) {
                cout << "\n";
                cout << "\nName : " << e.first_name << " " << e.last_name;
                cout << "\nCourse : " << e.course;
                cout << "\nStudent Number: " << e.student_num;
                cout << "\nYear : " << e.year;
                cout << "\nGrade : " << e.student_grades;

            }
            cout << "\n\n";
            system("pause");
            break;

        case '3':

            system("cls");
            cout << "                                           For Teachers\n";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            std::cout << "                                      Username: ";
            std::cin >> username;
            std::cout << "                                      Password: ";
            std::cin >> password;

            if (username == "Instructors" && password == "12345") {

                std::cout << "                                      You have successfully logged in!" << std::endl;
            }
            else {
                std::cout << "Invalid Username or Password, Please try again" << std::endl;

                return main();
            }
            another = 'Y';
            while (another == 'Y' || another == 'y')
            {
                system("cls");
                cout << "\n";
                cout << "\n";
                cout << "\n                                                 Input Grades";
                cout << "\n";
                cout << "\n";
                cout << "\n";
                cout << "\n                                  Please input the Student's Lastname : ";
                cin >> xlast_name;

                rewind(fp);
                while (fread(&e, recsize, 1, fp) == 1)
                {
                    if (strcmp(e.last_name, xlast_name) == 0)
                    {
                        cout << "\n";
                        cout << "\n";
                        cout << "                                Enter the Student Grades : ";
                        cin >> e.student_grades;                      
                            fseek(fp, -recsize, SEEK_CUR);
                            fwrite(&e, recsize, 1, fp);
                        break;
                    }
                    else
                        cout << "No Results Found";
                }
                cout << "\n Modify Another Record (Y/N) ";

                fflush(stdin);
                another = getchar();

            }
            break;

        case '4':

            system("cls");
            cout << "\n";
            cout << "\n";
            cout << "                                    For Admin\n";
            cout << "\n";
            cout << "\n";
            std::cout << "Admin Username: ";
            std::cin >> username;
            std::cout << "Password: ";
            std::cin >> password;

            if (username == "Administrator" && password == "12345") {

                std::cout << "You have successfully logged in!" << std::endl;
            }
            else {
                std::cout << "Invalid Username or Password, Please try again" << std::endl;

                return main();
            }
            system("cls");

            another = 'Y';
            while (another == 'Y' || another == 'y')
            {
                cout << "\n";
                cout << "                                              Delete Records\n";
                cout << "\n";
                cout << "\n";
                cout << "                               \nPlease input the Student's Lastname to delete : ";
                cin >> xlast_name;

                ft = fopen("temp.dat", "wb");

                rewind(fp);
                while (fread(&e, recsize, 1, fp) == 1)

                    if (strcmp(e.last_name, xlast_name) != 0)
                    {
                        fwrite(&e, recsize, 1, ft);
                    }
                fclose(fp);
                fclose(ft);
                remove("database.txt");

                int result = rename("temp.dat", "database.txt");

                fp = fopen("database.txt", "rb+");

                cout << "\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();

            }

            break;

        case '5':
            fclose(fp);
            cout << "\n";
            cout << "\n";
            cout << "\n";
            cout << "\n                                                                 #######EXIT######            ";
            cout << "\n";
            cout << "\n";
            cout << "\n";
            exit(0);



        }

    }

    return 0;
}

