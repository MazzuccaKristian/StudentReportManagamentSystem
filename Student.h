#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Student{
    public:
        int Roll;
        string Name, LastName;
        int English, Math, Science, SecondLanguage, ComputerScience;

    public:
        Student(int roll, string name, string lastName, int engMark, int mathMark, int sciMark, int secLangMark, int csMark);
};