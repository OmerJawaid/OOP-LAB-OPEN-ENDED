#include<iostream>
#include "Student.h"
#include "Course.h"

Student::Student(int ID, std::string na, std::string mail) : studentID(ID), name(na), email(mail) {};

void Student::enrollCourse(Course* course) {
    coursesEnrolled.push_back(course);
}

//void Student::dropCourse(Course* course) {
//    auto it = std::find(coursesEnrolled.begin(), coursesEnrolled.end(), course);
//    if (it != coursesEnrolled.end()) {
//        coursesEnrolled.erase(it);
//    }
//    else {
//        std::cout << "Course not found" << std::endl;
//    }
//}
void Student::dropCourse(Course* course) {
    for (auto it = coursesEnrolled.begin(); it != coursesEnrolled.end(); ++it) {
        if ((*it)->getCourseName() == course->getCourseName()) { // Access pointer members using ->
            coursesEnrolled.erase(it);
            return;
        }
    }
    std::cout << "Course not found" << std::endl; // Use std::cout and std::endl
}

void Student::viewCourses() const {
    for (const auto& course : coursesEnrolled) {
        std::cout << course->getCourseName() << std::endl;
    }
}
