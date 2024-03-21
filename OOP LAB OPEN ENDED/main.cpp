#include <iostream>
#include <string>
#include <vector>

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
    void addStudent(Student student);
    void removeStudent(Student student);
    void viewStudents();
};

class Teacher {
private:
    int teacherID;
    string name, email;
    vector<Course> coursesAssigned;

public:
    Teacher(string n, int ID, string em) : name(n), teacherID(ID), email(em) {}
    string getTeacherName() {
        return name;
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
};


class Student {
private:
    int studentID;
    string name, email;
    vector<Course> coursesEnrolled;

public:
    Student(int ID, string na, string mail) : studentID(ID), name(na), email(mail) {
        cout << "Student constructor called" << endl;
    }
    void enrollCourse(Course course) {
        coursesEnrolled.push_back(course);
    }
    void dropCourse(Course course);
    void viewCourses();
    string getStudentName() {
        return name;
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

