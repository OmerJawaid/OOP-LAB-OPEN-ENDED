#pragma once

#include <string>
#include <vector>

class Course; // Forward declaration

class Teacher {
private:
    int teacherID;
    std::string name, email;
    std::vector<Course*> coursesAssigned; // Update: Changed to vector of Course pointers

public:
    Teacher(std::string n, int ID, std::string em);
    std::string getTeacherName() const; // Update: Added const
    void assignCourses(Course* course); // Update: Passed Course pointer
    void removeCourse(Course* course); // Update: Passed Course pointer
    void viewCourses() const; // Update: Added const
};
