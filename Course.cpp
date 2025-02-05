#include "Course.h"
#include <algorithm>
#include <iostream>
using namespace std;

// Default constructor
Course::Course() : id(""), name(""), credits(0) {}

// Parameterized constructor
Course::Course(const string& id, const string& name, int credits)
    : id(id), name(name), credits(credits) {}

// Getters
string Course::getId() const { return id; }
string Course::getName() const { return name; }
int Course::getCredits() const { return credits; }

// Check if a student is enrolled
bool Course::hasStudent(int studentId) const {
    for (int s : enrolledStudents) {
        if (s == studentId) return true;
    }
    return false;
}

// Add a student to the course
bool Course::addStudent(int studentId) {
    if (!hasStudent(studentId)) {
        enrolledStudents.push_back(studentId);
        return true;
    }
    return false;
}

// Drop a student from the course
bool Course::dropStudent(int studentId) {
    auto it = std::remove(enrolledStudents.begin(), enrolledStudents.end(), studentId);
    if (it != enrolledStudents.end()) {
        enrolledStudents.erase(it);
        return true;
    }
    return false;
}

// Print course details
void Course::printDetails() const {
    cout << "Course ID: " << id << ", Name: " << name << ", Credits: " << credits << endl;
    cout << "Enrolled Students: ";
    for (int s : enrolledStudents) {
        std::cout << s << " ";
    }
    cout << endl;
}