#include "Course.h"
#include "Student.h"

Course::Course(std::string name, int code) : courseName(name), courseCode(code) {}

std::string Course::getCourseName() {
    return courseName;
}

void Course::addStudent(Student* student) {
    studentEnrolled.push_back(*student);
}

void Course::removeStudent(Student student) {
    for (auto it = studentEnrolled.begin(); it != studentEnrolled.end(); ++it) {
        if (it->getStudentName() == student.getStudentName()) {
            studentEnrolled.erase(it);
            return;
        }
    }
    std::cout << "Student not found" << std::endl;
}

void Course::viewStudents() {
    for (int i = 0; i < studentEnrolled.size(); i++) {
        std::cout << studentEnrolled[i].getStudentName() << std::endl;
    }
}
