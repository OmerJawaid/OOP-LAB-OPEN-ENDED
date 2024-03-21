#include "Teacher.h"
#include "Course.h" 

Teacher::Teacher(std::string n, int ID, std::string em) : name(n), teacherID(ID), email(em) {}

std::string Teacher::getTeacherName() const {
    return name;
}

void Teacher::assignCourses(Course* course) {
    coursesAssigned.push_back(course);
}

void Teacher::removeCourse(Course* course) {
    auto it = std::find(coursesAssigned.begin(), coursesAssigned.end(), course);
    if (it != coursesAssigned.end()) {
        coursesAssigned.erase(it);
    }
    else {
        std::cout << "Course not found" << std::endl;
    }
}

void Teacher::viewCourses() const {
    for (const auto& course : coursesAssigned) {
        std::cout << course->getCourseName() << std::endl;
    }
}
