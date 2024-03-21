#include <iostream>
#include <string>
#include <vector>

using namespace std;

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