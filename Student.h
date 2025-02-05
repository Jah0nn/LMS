#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;

class Course; // Forward declaration

class Student {
private:
    int id;
    string name;
    vector<std::string> enrolledCourses; // Store course IDs as strings
    int totalCredits;
    static const int MAX_ALLOWED_CREDITS = 18; // Static constant

public:
    Student(); // Default constructor
    Student(int id, const string& name); // Parameterized constructor

    // Getters (const-correct)
    int getId() const;
    string getName() const;
    vector<string> getEnrolledCourses() const;

    // Course management
    bool takesCourse(const string& courseId) const;
    bool takeCourse(Course& course);
    void dropCourse(Course& course);

    // Display
    void printDetails() const;
};

#endif // STUDENT_H