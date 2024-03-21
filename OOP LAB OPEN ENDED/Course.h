#pragma once

#include <iostream>
#include <string>
#include <vector>

class Student;

class Course {
private:
    int courseCode;
    std::string courseName;

public:
    std::vector<Student> studentEnrolled;
    Course(std::string name, int code);
    std::string getCourseName();
    void addStudent(Student* student);
    void removeStudent(Student student);
    void viewStudents();
    int getCourseCode() {
        return courseCode;
    }
};
