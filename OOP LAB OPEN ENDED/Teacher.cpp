#include "Teacher.h"
#include "Course.h"

Teacher::Teacher(std::string n, int ID, std::string em)
    : name(n), teacherID(ID), email(em) {}

std::string Teacher::getTeacherName() const {
    return name;
}

void Teacher::assignCourses(Course* course) {
    coursesAssigned.push_back(course);
}

void Teacher::removeCourse(Course* course) {
    // Remove the course from the vector
    coursesAssigned.erase(
        std::remove(coursesAssigned.begin(), coursesAssigned.end(), course),
        coursesAssigned.end()
    );
}

void Teacher::viewCourses() const {
    // Display the courses assigned to the teacher
    std::cout << "Courses assigned to " << name << ":" << std::endl;
    for (const auto& course : coursesAssigned) {
        std::cout << course->getCourseName() << std::endl;
    }
}

int Teacher::getTeacherID() const {
    return teacherID;
}

std::string Teacher::getEmail() const {
    return email;
}
