#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Student{
    private:
        int Roll;
        string Name, LastName;
        int English, Math, Science, SecondLanguage, ComputerScience;

    public:
        Student(int roll, string name, string lastName, int engMark, int mathMark, int sciMark, int secLangMark, int csMark);
        string ToString();
        //Setters
        void SetRoll(int roll);
        void SetName(string name);
        void SetLastName(string lastName);
        void setEnglishMark(int engMark);
        void SetMathMark(int mathMark);
        void SetScienceMark(int sciMark);
        void SetSecondLanguageMark(int secLangMark);
        void SetComputerScienceMark(int csMark);
        //Getters
        int GetRoll();
        string GetName();
        string GetLastName();
        int GetEnglishMark();
        int GetMathMark();
        int GetScienceMark();
        int GetSecondLanguageMark();
        int GetComputerScienceMark();
};