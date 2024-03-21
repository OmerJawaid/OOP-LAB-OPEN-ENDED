#pragma once

#include <string>
#include <vector>
using namespace std;
class Course; // Forward declaration

class Student
{
private:
    int studentID;
    std::string name, email;
    std::vector<Course*> coursesEnrolled;

public:
    Student(int ID, std::string na, std::string mail); // Declare the constructor
    void enrollCourse(Course* course);
    void dropCourse(Course* course);
    void viewCourses() const;
    std::string getStudentName() {
        return name;
    }
};
