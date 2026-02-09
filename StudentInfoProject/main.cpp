#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <format>

using namespace std;
class Lesson {
    public:
        string name;
        int unit;
        float mark;
};

class Student {
    public:
        string id;
        string username;
        string password;
        string name;
        string family;
        int age;
        vector<Lesson> lessonsVec;
        float average = 0;
};

vector<Student> students;
string Path = "data.txt";
string greenColor = "\033[32m";
string redColor = "\033[31m";
string resetColor = "\033[0m";
bool loggedIn = false;

string username;
string password;

void showChoices();
void doChoice();
void loadData();
void showStudents();
bool checkLogin();
Student searchStudent();
void insertStudent();
void insertLessons();
void updateStudent();
void updateLesson();
void deleteStudent();
void deleteLesson();
void calculateAvg();
void saveData();


int main(){
    while (true)
    {
        showChoices();
        doChoice();
        sleep(5);
    }
    
    return 0;
}

void showChoices(){

    std::cout << "-------------------------- Student Info ------------------------------------" << endl;
    std::cout << "-------------------------- Enter 1 to load data ----------------------------" << endl;
    std::cout << "-------------------------- Enter 2 to see all students ---------------------" << endl;
    std::cout << "-------------------------- Enter 3 to search a student ---------------------" << endl;
    std::cout << "-------------------------- Enter 4 to insert a student ---------------------" << endl;
    std::cout << "-------------------------- Enter 5 to insert lessons -----------------------" << endl;
    std::cout << "-------------------------- Enter 6 to update a student ---------------------" << endl;
    std::cout << "-------------------------- Enter 7 to update student lessons ---------------" << endl;
    std::cout << "-------------------------- Enter 8 to delete a student ---------------------" << endl;
    std::cout << "-------------------------- Enter 9 to delete a lesson ----------------------" << endl;
    std::cout << "-------------------------- Enter 10 to calculate student average -----------" << endl;
    std::cout << "-------------------------- Enter 11 to save data ---------------------------" << endl;
    std::cout << "-------------------------- Enter 12 to exit --------------------------------" << endl;
}

void doChoice(){
    int choice;
    std::cout << "Enter your option: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        std::cout << "Loading data..." << endl;
        loadData();
        break;
    case 2:
        checkLogin();
        std::cout << "Printing all students:" << endl;
        showStudents();
        break;
    case 3:
        checkLogin();
        std::cout << "search a student" << endl;
        searchStudent();
        break;
    case 4:
        checkLogin();
        std::cout << "Insert a student: " << endl;
        insertStudent();
        break;
    case 5:
        checkLogin();
        std::cout << "Insert Lesson(s): " << endl;
        insertLessons();
        break;
    case 6:
        checkLogin();
        std::cout << "Update Student: " << endl;
        updateStudent();
        break;
    case 7:
        checkLogin();
        std::cout << "Update a Student Lesson: " << endl;
        updateLesson();
        break;
    case 8:
        checkLogin();
        std::cout << "Delete a Student: " << endl;
        deleteStudent();
        break;
    case 9:
        checkLogin();
        std::cout << "Delete a Lesson: " << endl;
        deleteLesson();
        break;
    case 10:
        checkLogin();
        std::cout << "Calculate Student's Average: " << endl;
        calculateAvg();
        break;
    case 11:
        checkLogin();
        std::cout << "Saving data..." << endl;
        saveData();
        break;
    case 12:
        std::cout << "Exiting program..." << endl;
        exit(0);
        break;
    
    default:
        std::cout << "please select a valid option" << endl;
        break;
    }
}


void loadData(){
    string line;
    ifstream file("data.txt");
    
    while (std::getline(file, line)) {
        Student student;

        int start = 0;
        int end;

        // id
        end = line.find('|', start);
        student.id = line.substr(start, end - start);
        start = end + 1;

        // username
        end = line.find('|', start);
        student.username = line.substr(start, end - start);
        start = end + 1;
        // std::cout << student.username << endl;

        // password
        end = line.find('|', start);
        student.password = line.substr(start, end - start);
        start = end + 1;
        // std::cout << student.password << endl;

        // name
        end = line.find('|', start);
        student.name = line.substr(start, end - start);
        start = end + 1;
        
        // family
        end = line.find('|', start);
        student.family = line.substr(start, end - start);
        start = end + 1;
        
        // age
        end = line.find('|', start);
        student.age = std::stoi(line.substr(start, end - start));
        start = end + 1;
        
        // lessons
        string lessonsPart = line.substr(start);
        int lpos = 0;

        // std::cout << lessonsPart << endl;

        if (lessonsPart.size() != 0){}
        while (lpos < lessonsPart.size()) {
            Lesson lesson;

            // lesson name
            end = lessonsPart.find(':', lpos);
            lesson.name = lessonsPart.substr(lpos, end - lpos);
            lpos = end + 1;

            // unit
            end = lessonsPart.find(':', lpos);
            lesson.unit = std::stoi(lessonsPart.substr(lpos, end - lpos));
            lpos = end + 1;

            // mark
            end = lessonsPart.find(',', lpos);


            if (end == string::npos) {
                // if end of the string and we dont have other lessons
                lesson.mark = std::stof(lessonsPart.substr(lpos));
                lpos = lessonsPart.size();
            } else {
                // if we have other lessons too.
                lesson.mark = std::stof(lessonsPart.substr(lpos, end - lpos));
                lpos = end + 1;
            }

            student.lessonsVec.push_back(lesson);
        }


        students.push_back(student);

    }

    std::cout << greenColor << "Data loaded successfully." << resetColor << endl;

}

void showStudents() {
    for (int i = 0; i < students.size(); i++) {
        string color;
        // 33 = yellow, 34 = blue`
        if (i % 2 == 0){
            color = "\033[33m";
        }
        else{
            color = "\033[34m";
        }

       
        string reset = "\033[0m"; // reset color

        std::cout << color << "ID: " << students[i].id << reset << endl;
        std::cout << color << "Name: " << students[i].name << " " << students[i].family << reset << endl;
        std::cout << color << "Age: " << students[i].age << reset << endl;
        std::cout << color << "Average: " << students[i].average << reset << endl;

        std::cout << color << "Lessons:" << reset << endl;
        for (int j = 0; j < students[i].lessonsVec.size(); j++) {
            std::cout << color << "  - " << students[i].lessonsVec[j].name
                 << "  unit: " << students[i].lessonsVec[j].unit
                 << "  mark: " << students[i].lessonsVec[j].mark
                 << reset << endl;
        }

        std::cout << "------------------------" << endl;
    }
}



bool checkLogin(){
    if (!loggedIn){
        std::cout << "Please login." << endl;
        std::cout << "Username: ";
        cin >> username;
        std::cout << "Password: ";
        cin >> password;
        for (Student student: students){
            if (username == student.username && password == student.password){
                loggedIn = true;
                return true;
            }
        }
        return false;
    }
    else {
        return true;
    }
}

Student searchStudent(){
    string name;
    string family;
    std::cout << "Enter student's name to search: " << endl;
    std::cout << "Name: ";
    cin >> name;
    std::cout << "Family: ";
    cin >> family;

    for (Student student : students){
        if (student.name == name && student.family == family){
            string color = "\033[33m";
            string reset = "\033[0m";
            std::cout << color << "ID: " << student.id << reset << endl;
            std::cout << color << "Name: " << student.name << " " << student.family << reset << endl;
            std::cout << color << "Age: " << student.age << reset << endl;
            std::cout << color << "Average: " << student.average << reset << endl;

            std::cout << color << "Lessons:" << reset << endl;
            for (int j = 0; j < student.lessonsVec.size(); j++) {
                std::cout << color << j << "- " << student.lessonsVec[j].name
                    << "  unit: " << student.lessonsVec[j].unit
                    << "  mark: " << student.lessonsVec[j].mark
                    << reset << endl;
            }
            return student;
        }
    }
    
    std::cout << redColor << "The student was not found" << resetColor <<  endl;
    return Student();
}


void insertStudent(){
    Student student;
    int numLessons;

    std::cout << "ID: ";
    cin >> student.id;
    std::cout << "Username: ";
    cin >> student.username;
    std::cout << "Password: ";
    cin >> student.password;
    std::cout << "Name: ";
    cin >> student.name;
    std::cout << "Family: ";
    cin >> student.family;
    std::cout << "Age: ";
    cin >> student.age;

    std::cout << "Enter the number of lessons to be added: ";
    cin >> numLessons;
    for (int i=0; i < numLessons; i++){
        Lesson lesson;
        std::cout << "Lesson Name: ";
        cin >> lesson.name;
        std::cout << "Lesson Unit: ";
        cin >> lesson.unit;
        std::cout << "Lesson Mark: ";
        cin >> lesson.mark;

        student.lessonsVec.push_back(lesson);
    }

    students.push_back(student);
    std::cout << greenColor << "Student added Successfully" << resetColor << endl; 
    
}



void insertLessons(){
    Student student;
    student = searchStudent();
    if (student.id.empty()){
        return;
    }
    else{
        int numLessons;
        std::cout << "Enter the number of lessons to be added: ";
        cin >> numLessons;
        for (int i=0; i < numLessons; i++){
            Lesson lesson;
            std::cout << "Lesson Name: ";
            cin >> lesson.name;
            std::cout << "Lesson Unit: ";
            cin >> lesson.unit;
            std::cout << "Lesson Mark: ";
            cin >> lesson.mark;

            student.lessonsVec.push_back(lesson);
        }
    }
    std::cout << greenColor << "Lesson(s) added Successfully" << resetColor << endl; 
}


void updateStudent(){
    Student student;
    student = searchStudent();
    if (student.id.empty()){
        return;
    }
    else {
        std::cout << "Enter new edited properties for the chosen student: " << endl;
        std::cout << "ID: ";
        cin >> student.id;
        std::cout << "Username: ";
        cin >> student.username;
        std::cout << "Password: ";
        cin >> student.password;
        std::cout << "Name: ";
        cin >> student.name;
        std::cout << "Family: ";
        cin >> student.family;
        std::cout << "Age: ";
        cin >> student.age;

        std::cout << greenColor << "Student updated Successfully" << resetColor << endl;
    }
    for (int i = 0; i < students.size(); i++){
        if (students[i].id == student.id)
            {
                students[i].id = student.id;
                students[i].username = student.username;
                students[i].password = student.password;
                students[i].age = student.age;
                students[i].average = student.average;
            }
    }
}


void updateLesson(){
    Student student;
    student = searchStudent();
    if (student.id.empty()){
        return;
    }
    else {
        int chosenLessonId;
        std::cout << "Choose a lesson based by the id: ";
        cin >> chosenLessonId;
        std::cout << "Enter new edited properties for the chosen lesson: " << endl;
        std::cout << "Lesson's Name: ";
        cin >> student.lessonsVec[chosenLessonId].name;
        std::cout << "Unit: ";
        cin >> student.lessonsVec[chosenLessonId].unit;
        std::cout << "Mark: ";
        cin >> student.lessonsVec[chosenLessonId].mark;

        std::cout << greenColor << "Lesson updated Successfully" << resetColor << endl; 
        for (int i = 0; i < students.size(); i++){
            if (students[i].id == student.id)
                {
                    students[i].lessonsVec = student.lessonsVec;
                }
    }
    }
}


void deleteStudent(){
    string name;
    string family;
    std::cout << "Enter student's properties to delete: " << endl;
    std::cout  << "Name: ";
    cin >> name;
    std::cout << "Family: ";
    cin >> family;

    for (int i=0; i<students.size(); i++){
        if (students[i].name == name && students[i].family == family){
            students.erase(students.begin() + i);
            std::cout << greenColor << "Student deleted successfully." << resetColor << endl;
            return;
        }
    }
    std::cout << redColor << "The student was not found" << resetColor <<  endl;
}

void deleteLesson(){
    Student student;
    student = searchStudent();
    if (student.id.empty()){
        return;
    }
    else {
        int chosenLessonId;
        std::cout << "Choose a lesson based by the id to delete: ";
        cin >> chosenLessonId;
        for (int i = 0; i < students.size(); i++){
            if (students[i].id == student.id)
                {
                    students[i].lessonsVec.erase(students[i].lessonsVec.begin() + chosenLessonId);
                }
            }
            std::cout << greenColor << "The student's lesson deleted successfully." << resetColor <<  endl;
    }

}

void calculateAvg(){
    Student student;
    student = searchStudent();
    if (student.id.empty()){
        return;
    }
    else {
        int sumScores = 0;
        int sumUnits = 0;
        for (Lesson lesson: student.lessonsVec){
            sumScores = sumScores + lesson.mark * lesson.unit;
            sumUnits = sumUnits + lesson.unit;
        }
        student.average = sumScores / sumUnits;
        std::cout << "Student Average: " << student.average << endl;
    }

}

void saveData() {
    ofstream file("data.txt");

    if (!file.is_open()) {
        std::cout << "Cannot open file for writing!" << endl;
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        // student main info
        file << students[i].id << "|"
             << students[i].username << "|"
             << students[i].password << "|"
             << students[i].name << "|"
             << students[i].family << "|"
             << students[i].age << "|";

        // lessons
        
        for (int j = 0; j < students[i].lessonsVec.size(); j++) {
            file << students[i].lessonsVec[j].name << ":"
                 << students[i].lessonsVec[j].unit << ":"
                 << students[i].lessonsVec[j].mark;
            // add comma if not last lesson
            if (j != students[i].lessonsVec.size() - 1)
                file << ",";
        }
        if (students[i].lessonsVec.size() != 0){

            file << "|" << endl;
        }
    }

    file.close();
    std::cout << greenColor << "Data saved successfully." << resetColor <<  endl;
}
