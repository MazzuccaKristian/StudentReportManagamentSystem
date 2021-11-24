#include <iostream>
#include <string>
#include <fstream>

#include "Student.h"

#define STUDENTS "students.txt"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;
using std::ofstream;
using std::ifstream;

int ROLL = 0;

void Setup();

void ShowMainMenu();

int GetUserChoice();

void CreateStudent();

string GetUserString();

int GetUserMark(string subject);

bool RecordStudent(Student* student);

void SearchRecord();