#pragma once

#include <string>
#include <vector>


class Course; 


class Teacher {
private:
    int teacherID;
    std::string name, email;

    std::vector<Course*> coursesAssigned; // Vector of Course pointers

public:
    Teacher(std::string n, int ID, std::string em);
    std::string getTeacherName() const; // Function to get teacher name
    void assignCourses(Course* course); // Function to assign a course to the teacher
    void removeCourse(Course* course); // Function to remove a course from the teacher's assignments
    void viewCourses() const; // Function to view courses assigned to the teacher
    int getTeacherID() const; // Function to get teacher ID
    std::string getEmail() const; // Function to get teacher email

};