#include "LMS.h"
#include <iostream>
using namespace std;

// Default constructor
LMS::LMS() : name("") {}

// Parameterized constructor
LMS::LMS(const string& name) : name(name) {}

// Add a student
void LMS::addStudent(const Student& student) {
    students.push_back(student);
}

// Add a course
void LMS::addCourse(const Course& course) {
    courses.push_back(course);
}

// Link student to course
bool LMS::addStudentToCourse(int studentId, const string& courseId) {
    for (auto& student : students) {
        if (student.getId() == studentId) {
            for (auto& course : courses) {
                if (course.getId() == courseId) {
                    return student.takeCourse(course); // Handles linking
                }
            }
        }
    }
    return false;
}

// Print LMS details
void LMS::printDetails() const {
    cout << "LMS Name: " << name <<endl;
    
    cout << "Students:" << endl;
    for (const Student& student : students) {
        student.printDetails();

    }
    
    cout << "Courses:" << endl;
    for (const Course& course : courses) {
        course.printDetails();

    }

}