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

            case 4:
                DeleteStudent();
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
 * @brief Setup function. Create "students.txt" if needed.
 *        Get max ROLL from existing file.
 * 
 */
void Setup(){
    // Create file if it doesn't exist.
    ofstream students;
    students.open(STUDENTS, ofstream::app);
    students.close();
    // If the file contains records, extract the max value of roll number.
    ifstream rollFile;
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
    // Student related data entry.
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
    // Object creation ("full" constructor)
    Student student(studentRoll, studentName, studentLastName, englishMark, mathMark, scienceMark, secondLanguageMark, computerScienceMark);
    // Write the student's record.
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
 * @brief After objcet creation, write its record (Student::ToString()) on archive.
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

/**
 * @brief Search in archive a particular record.
 *        If this record exists, show it.
 * 
 */
void SearchRecord(){
    int searchedId;
    bool found = false;
    std::size_t startPosition, endPosition, subStrLength;
    int convertedId;
    ifstream students;
    cout << "Enter the ID you're looking for: ";
    cin >> searchedId;
    students.open(STUDENTS);
    if(students.is_open()){
        string line;
        string idFromRecord;
        while(getline(students, line)){
            // Custom "string tokenizer". Extracts ID's value from readed line.
            startPosition = line.find_first_of(" ") + 1;
            endPosition = line.find_first_of("N");
            subStrLength = (endPosition - 1) - startPosition;
            if(startPosition != string::npos){
                idFromRecord = line.substr(startPosition, subStrLength);
                convertedId = std::stoi(idFromRecord);
                if(convertedId == searchedId){
                    cout << line << endl;
                    found = true;
                }
            }
        }
    }else{
        perror(STUDENTS);
    }
    students.close();
    if(!found){
        cout << "The record with ID " << searchedId << " doesn't exist. Please, try again..." << endl;
    }
}

/**
 * @brief Read archive and show every record.
 * 
 */
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

/**
 * @brief Search an ID and delete the record from archive.
 * 
 */
void DeleteStudent(){
    ifstream students;
    ofstream tempFile;
    int searchedId;
    std::size_t startPosition, endPosition, subStrLength;
    int convertedId;
    cout << "Enter the ID you want to delete: ";
    cin >> searchedId;
    students.open(STUDENTS);
    tempFile.open(TEMP);
    if(students.is_open() && tempFile.is_open()){
        string line;
        string readedId;
        while(getline(students, line)){
            startPosition = line.find_first_of(" ") + 1;
            endPosition = line.find_first_of("N");
            subStrLength = (endPosition - 1) - startPosition;
            if(startPosition != string::npos){
                readedId = line.substr(startPosition, subStrLength);
                convertedId = std::stoi(readedId);
                if(convertedId != searchedId){
                    tempFile << line << endl;
                }
            }
        }
    }else{
        perror("Can't open file");
    }
    students.close();
    tempFile.close();
    if(remove(STUDENTS) != 0 ){
        perror(STUDENTS);
    }
    if(rename(TEMP, STUDENTS) != 0){
        perror(TEMP);
    }
    cout << "ID " << searchedId << " successfully deleted." << endl;
}