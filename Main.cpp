#include "Main.h"

int main(){
    bool isStillWorking = true;
    int userChoice = 0;

    Setup();

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

            case 2:
                SearchRecord();
                break;

            case 3:
                ShowArchive();
                break;
        }
    }while(isStillWorking);

    return 0;
}

void ShowMainMenu(){
    cout << "MAIN MENU" << endl;
    cout << "1) Create student record;" << endl;
    cout << "2) Search student record; (?)" << endl;
    cout << "3) Display all students record;" << endl;
    cout << "4) Delete student record;" << endl;
    cout << "5) Modify student record;" << endl;
    cout << "0) Exit." << endl;
    cout << "Enter your choice: ";
}

/**
 * @brief Setup function. Create "students.txt" if needed.
 *        Get max ROLL from existing file.
 * 
 */
void Setup(){
    ofstream students;
    ifstream rollFile;
    students.open(STUDENTS, ofstream::app);
    students.close();
    rollFile.open(STUDENTS);
    if(rollFile.is_open()){
        int maxRoll = ROLL;
        string rollKey, rollValue;
        while(rollFile >> rollKey >> rollValue){
            if(rollKey.compare("ID:") == 0){
                int value = std::stoi(rollValue);
                if(maxRoll < value){
                    maxRoll = value;
                }
            }
        }
        ROLL = maxRoll;
    }else{
        perror(STUDENTS);
    }
    rollFile.close();
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

/**
 * @brief Get student related data. Then create a Student object.
 * 
 */
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
    scienceMark = GetUserMark("science");
    secondLanguageMark = GetUserMark("second language");
    computerScienceMark = GetUserMark("computer science");
    Student student(studentRoll, studentName, studentLastName, englishMark, mathMark, scienceMark, secondLanguageMark, computerScienceMark);
    if(RecordStudent(&student)){
        cout << "Record added." << endl;
    }else{
        perror("Registration failed");
    }
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

/**
 * @brief After record's creation, write it on archive.
 * 
 * @param student Student pointer
 * @return true if file's write succeded.
 * @return false if file's write failed.
 */
bool RecordStudent(Student* student){
    bool recorded = false;
    if(student != nullptr){
        ofstream students(STUDENTS, ofstream::app);
        if(students.is_open()){
            string record = student -> ToString();
            if(!record.empty()){
                students << record << endl;
                recorded = true;
            }else{
                perror("Empty record");
            }
        }else{
            perror(STUDENTS);
        }
    }else{
        perror("Student pointer");
    }
    return recorded;
}

void SearchRecord(){
    int searchedId;
    ifstream students;
    cout << "Enter the ID you're looking for: ";
    cin >> searchedId;
    students.open(STUDENTS);
    if(students.is_open()){
        string line;
        while(getline(students, line)){
            //TODO: tokenize string.
        }
    }else{
        perror(STUDENTS);
    }
}

void ShowArchive(){
    string line;
    ifstream students(STUDENTS);
    if(students.is_open()){
        cout << "ARCHIVE:" << endl;
        while(getline(students, line)){
            cout << line << endl;
        }
    }
    students.close();
}