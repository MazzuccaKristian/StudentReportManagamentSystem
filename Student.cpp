#include "Student.h"

Student::Student(int roll, string name, string lastName, int engMark, int mathMark, int sciMark, int secLangMark, int csMark){
    SetRoll(roll);
    SetName(name);
    SetLastName(lastName);
    setEnglishMark(engMark);
    SetMathMark(mathMark);
    SetScienceMark(sciMark);
    SetSecondLanguageMark(secLangMark);
    SetComputerScienceMark(csMark);
}

string Student::ToString(){
    return "ID: " + std::to_string(GetRoll()) + " Name: " + GetName() + " LastName: " +
            GetLastName() + " English: " + std::to_string(GetEnglishMark()) +
            " Math: " + std::to_string(GetMathMark()) + " Science: " +
            std::to_string(GetScienceMark()) + " SecondLanguage: " +
            std::to_string(GetSecondLanguageMark()) + " ComputerScience: " +
            std::to_string(GetComputerScienceMark());
}

void Student::SetRoll(int roll){
    Roll = roll;
}

void Student::SetName(string name){
    Name = name;
}

void Student::SetLastName(string lastName){
    LastName = lastName;
}

void Student::setEnglishMark(int engMark){
    English = engMark;
}

void Student::SetMathMark(int mathMark){
    Math = mathMark;
}

void Student::SetScienceMark(int sciMark){
    Science = sciMark;
}

void Student::SetSecondLanguageMark(int secLangMark){
    SecondLanguage = secLangMark;
}

void Student::SetComputerScienceMark(int csMark){
    ComputerScience = csMark;
}

int Student::GetRoll(){
    return Roll;
}

string Student::GetName(){
    return Name;
}

string Student::GetLastName(){
    return LastName;
}

int Student::GetEnglishMark(){
    return English;
}

int Student::GetMathMark(){
    return Math;
}

int Student::GetScienceMark(){
    return Science;
}

int Student::GetSecondLanguageMark(){
    return SecondLanguage;
}

int Student::GetComputerScienceMark(){
    return ComputerScience;
}