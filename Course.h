#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
using namespace std;

class Course {
private:
    string id; // Course ID as string
    string name;
    int credits;
    vector<int> enrolledStudents; // Student IDs as integers

public:
    Course(); // Default constructor
    Course(const string& id, const string& name, int credits);

    // Getters (const-correct)
    string getId() const;
    string getName() const;
    int getCredits() const;

    // Student management
    bool hasStudent(int studentId) const;
    bool addStudent(int studentId);
    bool dropStudent(int studentId);

    // Display
    void printDetails() const;
};

#endif // COURSE_H