#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
#include "Teacher.h"
#include "Student.h"
using namespace std;
void saveDataToFile(const vector<Student>& students, const vector<Teacher>& teachers, const vector<Course>& courses) {
    ofstream file("/home/ahmad/Desktop/c++.txt");
    if (!file.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (const auto& student : students) {
        student.saveToFile(file);
    }

    for (const auto& teacher : teachers) {
        teacher.saveToFile(file);
    }

    for (const auto& course : courses) {
        course.saveToFile(file);
    }

    file.close();
}
void readDataFromFile(vector<Student>& students, vector<Teacher>& teachers, vector<Course>& courses) {
    ifstream file("/home/ahmad/Desktop/c++.txt");
    if (!file.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string type;
        getline(ss, type, ','); 

        if (type == "Student") {
            int ID;
            string name, email;
            char comma;
            ss >> ID >> comma; 
            getline(ss >> ws, name, ','); 
            getline(ss >> ws, email); 
            students.push_back(Student(ID, name, email));
        }
        else if (type == "Teacher") {
            int ID;
            string name, email;
            char comma;
            ss.ignore(); 
            getline(ss >> ws, name, ','); 
            ss >> ID >> comma; 
            getline(ss >> ws, email); 
            teachers.push_back(Teacher(name, ID, email));
        }
        else if (type == "Course") {
            int code;
            string name;
            char comma;
            ss.ignore(); 
            getline(ss >> ws, name, ','); 
            ss >> code; 
            courses.push_back(Course(name, code));
        }
        else {
            cerr << "Unknown type: " << type << endl;
        }
    }

    file.close();
}


int main()
{
    vector<Student> students;
    vector<Course> courses;
    vector<Teacher> teachers;

    int choice;
    do {
        cout << "\nChoose an option:\n";
        cout << "1. Add Student\n";
        cout << "2. Add Course\n";
        cout << "3. Add Teacher\n";
        cout << "4. Display Info\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int studentID;
            string name, email;
            cout << "Enter student ID: ";
            cin >> studentID;
            cout << "Enter student name: ";
            cin.ignore(); // Ignore previous newline character
            getline(cin, name);
            cout << "Enter student email: ";
            cin >> email;
            students.push_back(Student(studentID, name, email));
            break;
        }
        case 2: {
            string name;
            int code;
            cout << "Enter course name: ";
            cin.ignore(); // Ignore previous newline character
            getline(cin, name);
            cout << "Enter course code: ";
            cin >> code;
            courses.push_back(Course(name, code));
            break;
        }
        case 3: {
            string name, email;
            int teacherID;
            cout << "Enter teacher name: ";
            cin.ignore(); // Ignore previous newline character
            getline(cin, name);
            cout << "Enter teacher ID: ";
            cin >> teacherID;
            cout << "Enter teacher email: ";
            cin >> email;
            teachers.push_back(Teacher(name, teacherID, email));
            break;
        }
        case 4: {
            cout << "Students:" << endl;
            for (auto& student : students) {
                cout << "ID: " << student.getStudentID() << ", Name: " << student.getStudentName() << ", Email: " << student.getEmail() << endl;
            }

            cout << "Courses:" << endl;
            for (auto& course : courses) {
                cout << "Code: "  << course.getCourseCode() << ", Name: " << course.getCourseName() << endl;
            }

            cout << "Teachers:" << endl;
            for (auto& teacher : teachers) {
                cout << "ID: " << teacher.getTeacherID() << ", Name: " << teacher.getTeacherName() << ", Email: " << teacher.getEmail() << endl;
            }
            break;

        }
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    saveDataToFile(students, teachers, courses);
    
vector<Student> studentsFromFile;
    vector<Teacher> teachersFromFile;
    vector<Course> coursesFromFile;
readDataFromFile(studentsFromFile, teachersFromFile, coursesFromFile);

    cout << "Students read from file:" << endl;
    for (auto& student : studentsFromFile) {
        cout << "ID: " << student.getStudentID() << ", Name: " << student.getStudentName() << ", Email: " << student.getEmail() << endl;
    }

    cout << "Teachers read from file:" << endl;
    for (auto& teacher : teachersFromFile) {
        cout << "ID: " << teacher.getTeacherID() << ", Name: " << teacher.getTeacherName() << ", Email: " << teacher.getEmail() << endl;
    }

    cout << "Courses read from file:" << endl;
    for (auto& course : coursesFromFile) {
        cout << "Code: " << course.getCourseCode() << ", Name: " << course.getCourseName() << endl;
    }
    
   
    return 0;
}
