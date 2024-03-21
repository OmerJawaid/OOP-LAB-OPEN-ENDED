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
void Course::viewStudents() {
    for (int i = 0; i < studentEnrolled.size(); i++) {
        cout << studentEnrolled[i].getStudentName() << endl;
    }
}