#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <map>

enum Grade { A, B, C, F };

struct Student {
    std::string firstName;
    std::string lastName;
    std::string university;
    int test1, test2, test3, test4;
    float finalScore;
    Grade grade;

    // Helper for easy comparison in tests
    bool operator==(const Student& other) const {
        return firstName == other.firstName && lastName == other.lastName &&
               university == other.university && test1 == other.test1 &&
               test2 == other.test2 && test3 == other.test3 && test4 == other.test4;
    }
};

std::vector<Student> parseCSV(std::string filePath);
std::vector<Student> calculateGrade(std::vector<Student> students);
Student findOverallTopper(std::vector<Student> students);
std::map<std::string, Student> findTopperPerUniversity(std::vector<Student> students);

#endif