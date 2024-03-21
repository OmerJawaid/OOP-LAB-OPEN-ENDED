#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student;
class Teacher;
class Course {
private:
    int courseCode;
    string courseName;

public:
    vector<Student> studentEnrolled;
    Course(string name, int code) : courseName(name), courseCode(code) {}
    string getCourseName() {
        return courseName;
    }
    void addStudent(Student student);
    void removeStudent(Student student);
    void viewStudents();
};

class Teacher {
private:
    int teacherID;
    string name, email;
    vector<Course> coursesAssigned;

public:
    Teacher(string n, int ID, string em) : name(n), teacherID(ID), email(em) {}
    string getTeacherName() {
        return name;
    }
    void assignCourses(Course course) {
        coursesAssigned.push_back(course);
    }
    void removeCourse(Course course) {
        for (auto it = coursesAssigned.begin(); it != coursesAssigned.end(); ++it) {
            if (it->getCourseName() == course.getCourseName()) {
                coursesAssigned.erase(it);
                return;
            }
        }
        cout << "Course not found" << endl;
    }
    void viewCourses() {
        for (int i = 0; i < coursesAssigned.size(); i++) {
            cout << coursesAssigned[i].getCourseName() << endl;
        }
    }
};


class Student {
private:
    int studentID;
    string name, email;
    vector<Course> coursesEnrolled;

public:
    Student(int ID, string na, string mail) : studentID(ID), name(na), email(mail) {}
    void enrollCourse(Course course) {
        coursesEnrolled.push_back(course);
    }
    void dropCourse(Course course);
    void viewCourses();
    string getStudentName() {
        return name;
    }
};
void Course::addStudent(Student student) {
    studentEnrolled.push_back(student);
}

void Course::removeStudent(Student student) {
    for (auto it = studentEnrolled.begin(); it != studentEnrolled.end(); ++it) {
        if (it->getStudentName() == student.getStudentName()) {
            studentEnrolled.erase(it);
            return;
        }
    }
    cout << "Student not found" << endl;
}
void Course::viewStudents() {
    for (int i = 0; i < studentEnrolled.size(); i++) {
        cout << studentEnrolled[i].getStudentName() << endl;
    }
}
void Student::dropCourse(Course course) {
    for (auto it = coursesEnrolled.begin(); it != coursesEnrolled.end(); ++it) {
        if (it->getCourseName() == course.getCourseName()) {
            coursesEnrolled.erase(it);
            return;
        }
    }
    cout << "Course not found" << endl;
}

void Student::viewCourses() {
    for (int i = 0; i < coursesEnrolled.size(); i++) {
        cout << coursesEnrolled[i].getCourseName() << endl;
    }
}

int main()
{
    Student student1(1 , "Ahmad" ,"ahmadiftikhar200536@gmail.com" );
    Student student2(2, "Omer","omerjawaid0@gmail.com");

    Course course1("OOP" , 6259);
    Course course2("DS", 6260);

    Teacher teacher1("DR Waleed Ahmad", 1234, "mwaleed.buic@bahria.edu.pk");

    course1.addStudent(student1);
    course1.addStudent(student2);

    course2.addStudent(student1);

    teacher1.assignCourses(course1);
    teacher1.assignCourses(course2);

    cout<<"Courses taught by " << teacher1.getTeacherName() << ":"<< endl;
    teacher1.viewCourses();
    cout<<endl;

    cout<<"Student enroll in " << course1.getCourseName() <<":"<< endl;
    course1.viewStudents();
    cout<< endl;

    cout<<"Student enroll in " << course2.getCourseName() <<":"<< endl;
    course2.viewStudents();
    cout<< endl;

    return 0;

}

