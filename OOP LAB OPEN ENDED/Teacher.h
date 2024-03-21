#pragma once

#include <string>
#include <vector>

class Course; 

class Teacher {
private:
    int teacherID;
    std::string name, email;
    std::vector<Course*> coursesAssigned; 

public:
    Teacher(std::string n, int ID, std::string em);
    std::string getTeacherName() const; 
    void assignCourses(Course* course); 
    void removeCourse(Course* course); 
    void viewCourses() const; 
};

