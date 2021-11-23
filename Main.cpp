#include "Main.h"

int main(){
    bool isStillWorking = true;
    int userChoice = 0;

    do{
        ShowMainMenu();
        userChoice = GetUserChoice();
        switch(userChoice){
            case 0:
                cout << "Program closed. Please, wait..." << endl;
                isStillWorking = false;
                break;

            case 1:
                CreateStudent();
                break;
        }
    }while(isStillWorking);

    return 0;
}

void ShowMainMenu(){
    cout << "MAIN MENU" << endl;
    cout << "1) Create student record;" << endl;
    cout << "2) Search student record;" << endl;
    cout << "3) Display all students record;" << endl;
    cout << "4) Delete student record;" << endl;
    cout << "5) Modify student record;" << endl;
    cout << "0) Exit." << endl;
    cout << "Enter your choice: ";
}

/**
 * @brief Get and validate the user choice.
 * 
 * @return int (validated choice)
 */
int GetUserChoice(){
    int choice;
    cin >> choice;
    if(choice < 0 || choice > 5){
        cout << "Invalid choice. Please, try again..." << endl;
    }
    cin.ignore();
    return choice;
}

void CreateStudent(){
    string studentName, studentLastName;
    int studentRoll, englishMark, mathMark, scienceMark, secondLanguageMark, computerScienceMark;
    ROLL = ROLL+1;
    studentRoll = ROLL;
    cout << "Enter student's name: ";
    studentName = GetUserString();
    cout << "Enter student's last name: ";
    studentLastName = GetUserString();
    englishMark = GetUserMark("english");
    mathMark = GetUserMark("math");
    secondLanguageMark = GetUserMark("second language");
    computerScienceMark = GetUserMark("computer science");
}

string GetUserString(){
    string data;
    getline(cin, data);
    return data;
}

/**
 * @brief Get and validate user's mark.
 * 
 * @param subject Subject's name
 * @return int (validated mark)
 */
int GetUserMark(string subject){
    bool isValid = false;
    int mark = 0;
    do{
        cout << "Enter " << subject << " mark: ";
        cin >> mark;
        if(mark < 0 || mark > 10){
            cout << "Invalid value. Please, try again..." << endl;
            isValid = false;
        }else{
            isValid = true;
        }
    }while(!isValid);
    return mark;
}