#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
#include "Teacher.h"
#include "Student.h"

using namespace std;

int main()
{
    // Creating students
    Student student1(1, "Ahmad", "ahmadiftikhar200536@gmail.com");
    Student student2(2, "Omer", "omerjaweid0@gmail.com");

    // Creating courses
    Course course1("OOP", 2053);
    Course course2("DS", 2054);

    // Creating teacher
    Teacher teacher1("Dr Waleed Ahmad", 1236, "mwaleed.buic@bahria.edu.pk");

    // Adding students to courses
    course1.addStudent(&student1);
    course1.addStudent(&student2);
    course2.addStudent(&student1);

    // Assigning courses to the teacher
    teacher1.assignCourses(&course1);
    teacher1.assignCourses(&course2);

    // Displaying courses taught by the teacher
    cout << "Courses taught by " << teacher1.getTeacherName() << ":" << endl;
    teacher1.viewCourses();
    cout << endl;

    // Displaying students enrolled in course1
    cout << "Students enrolled in " << course1.getCourseName() << ":" << endl;
    course1.viewStudents();
    cout << endl;

    // Displaying courses taught by the teacher again
    cout << "Courses taught by " << teacher1.getTeacherName() << ":" << endl;
    teacher1.viewCourses();
    cout << endl;

    // Displaying students enrolled in course1 again
    cout << "Student enroll in " << course1.getCourseName() << ":" << endl;
    course1.viewStudents();
    cout << endl;

    // Displaying students enrolled in course2
    cout << "Student enroll in " << course2.getCourseName() << ":" << endl;
    course2.viewStudents();
    cout << endl;

    return 0;
}
