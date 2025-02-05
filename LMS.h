#ifndef LMS_H
#define LMS_H

#include <string>
#include <vector>
#include "Student.h"
#include "Course.h"
using namespace std;

class LMS {
private:
    string name;
    vector<Student> students;
    vector<Course> courses;

public:
    LMS(); // Default constructor
    explicit LMS(const string& name);

    // Add student/course
    void addStudent(const Student& student);
    void addCourse(const Course& course);

    // Link student to course
    bool addStudentToCourse(int studentId, const string& courseId);

    // Display
    void printDetails() const;
};

#endif // LMS_H