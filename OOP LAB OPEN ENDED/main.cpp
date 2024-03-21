#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class Student;
class Teacher;
class Course {
private:
    int courseCode;
    string courseName;

public:
    vector<Student> studentEnrolled;
    Course(string name, int code) : courseName(name), courseCode(code) {}
    string getCourseName() {
        return courseName;
    }
    int getCourseCode() {
        return courseCode;
    }
    void addStudent(Student student);
    void removeStudent(Student student);
    void viewStudents();
    void saveToFile(ofstream& file) const {
        file << "Course," << courseName << "," << courseCode << endl;
    }

    static Course createFromInput(const string& input) {
    stringstream ss(input);
    string type, name;
    int code;
    char comma;
    ss >> type >> comma;
    getline(ss, name, ','); // Read name until comma
    ss >> code;
    return Course(name, code);
}

};

class Teacher {
private:
    int teacherID;
    string name, email;
    

public:
    Teacher(string n, int ID, string em) : name(n), teacherID(ID), email(em) {}
    vector<Course> coursesAssigned;
    string getEmail() { return email; }
    string getTeacherName() {
        return name;
    }
    int getTeacherID() {
        return teacherID;
    }
    void assignCourses(Course course) {
        coursesAssigned.push_back(course);
    }
    void removeCourse(Course course) {
        for (auto it = coursesAssigned.begin(); it != coursesAssigned.end(); ++it) {
            if (it->getCourseName() == course.getCourseName()) {
                coursesAssigned.erase(it);
                return;
            }
        }
        cout << "Course not found" << endl;
    }
    void viewCourses() {
        for (int i = 0; i < coursesAssigned.size(); i++) {
            cout << coursesAssigned[i].getCourseName() << endl;
        }
    }
    void saveToFile(ofstream& file) const {
        file << "Teacher," << name << "," << teacherID << "," << email << endl;
    }

    static Teacher createFromInput(const string& input) {
    stringstream ss(input);
    string type, name, email;
    int ID;
    char comma;
    ss >> type >> comma >> name >> comma >> ID >> comma;
    getline(ss, email); // Read email until the end of the line
    return Teacher(name, ID, email);
}


    
};

class Student {
private:
    int studentID;
    string name, email;
    vector<Course> coursesEnrolled;

public:
    Student(int ID, string na, string mail) : studentID(ID), name(na), email(mail) {}
    void enrollCourse(Course course) {
        coursesEnrolled.push_back(course);
    }
	string getEmail() { return email; }
    int getStudentID() {
        return studentID;
    }
    void dropCourse(Course course);
    void viewCourses();
    string getStudentName() {
        return name;
    }
    void saveToFile(ofstream& file) const {
        file << "Student," << studentID << "," << name << "," << email << endl;
    }

   static Student createFromInput(const string& input) {
    stringstream ss(input);
    string type, name, email;
    int ID;
    char comma;
    ss >> type >> comma >> ID >> comma;
    getline(ss, name, ','); // Read name until comma
    getline(ss, email); // Read email until the end of the line
    return Student(ID, name, email);
}

};
void Course::addStudent(Student student) {
    studentEnrolled.push_back(student);
}

void Course::removeStudent(Student student) {
    for (auto it = studentEnrolled.begin(); it != studentEnrolled.end(); ++it) {
        if (it->getStudentName() == student.getStudentName()) {
            studentEnrolled.erase(it);
            return;
        }
    }
    cout << "Student not found" << endl;
}
void Course::viewStudents() {
    for (int i = 0; i < studentEnrolled.size(); i++) {
        cout << studentEnrolled[i].getStudentName() << endl;
    }
}
void Student::dropCourse(Course course) {
    for (auto it = coursesEnrolled.begin(); it != coursesEnrolled.end(); ++it) {
        if (it->getCourseName() == course.getCourseName()) {
            coursesEnrolled.erase(it);
            return;
        }
    }
    cout << "Course not found" << endl;
}

void Student::viewCourses() {
    for (int i = 0; i < coursesEnrolled.size(); i++) {
        cout << coursesEnrolled[i].getCourseName() << endl;
    }
}
