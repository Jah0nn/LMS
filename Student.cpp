#include "Student.h"
#include "Course.h"
#include <iostream>
using namespace std;

// Default constructor
Student::Student() : id(0), name(""), totalCredits(0) {}

// Parameterized constructor
Student::Student(int id, const string& name) : id(id), name(name), totalCredits(0) {}

// Getters
int Student::getId() const { return id; }
string Student::getName() const { return name; }
vector<std::string> Student::getEnrolledCourses() const { return enrolledCourses; }

// Check if student is enrolled in a course
bool Student::takesCourse(const string& courseId) const {
    for (const auto& c : enrolledCourses) {
        if (c == courseId) return true;
    }
    return false;
}

// Enroll in a course
bool Student::takeCourse(Course& course) {
    if (takesCourse(course.getId()) ||
        (totalCredits + course.getCredits() > MAX_ALLOWED_CREDITS)) {
        return false;
        }
    enrolledCourses.push_back(course.getId());
    totalCredits += course.getCredits();
    course.addStudent(id); // Link student to course
    return true;
}

// Drop a course
void Student::dropCourse(Course& course) {
    auto it = std::remove(enrolledCourses.begin(), enrolledCourses.end(), course.getId());
    if (it != enrolledCourses.end()) {
        enrolledCourses.erase(it);
        totalCredits -= course.getCredits();
        course.dropStudent(id);
    }
}

// Print student details
void Student::printDetails() const {
    cout << "Student ID: " << id << ", Name: " << name << endl;
    cout << "Enrolled Courses: ";
    for (const auto& c : enrolledCourses) {
        cout << c << " ";
    }
    cout << endl;
}