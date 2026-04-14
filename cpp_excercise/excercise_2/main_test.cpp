#include "student.h"
#include <iostream>
#include <cassert>
#include <vector>

void TestParseCSV() {
    auto students = parseCSV("grades.csv");
    
    assert(students.size() == 30 && "Student list size should be 30");

    Student fs = {"Kaylen", "Johnson", "Duke University", 52, 47, 35, 38};
    assert(students[0] == fs && "First student should be Kaylen");

    Student ls = {"Solomon", "Hunter", "Boston University", 45, 62, 32, 58};
    assert(students[29] == ls && "Last student should be Solomon");

    std::cout << "[PASS] TestParseCSV" << std::endl;
}

void TestCalculateGrade() {
    auto graded = calculateGrade(parseCSV("grades.csv"));

    std::vector<float> expScore = {43, 59.25, 53, 58.25, 52.25, 50.75, 54.75, 49.25, 64.75, 43.25, 68.5, 57.75, 68.25, 66.75, 45.5, 45.75, 45.5, 58, 56, 60.25, 61, 62.5, 80.5, 53, 30.75, 57.5, 70.75, 48.5, 60.25, 49.25};
    std::vector<Grade> expGrade = {C, B, B, B, B, B, B, C, B, C, B, B, B, B, C, C, C, B, B, B, B, B, A, B, F, B, A, C, B, C};

    assert(graded.size() == 30);
    for (size_t i = 0; i < graded.size(); ++i) {
        assert(graded[i].finalScore == expScore[i]);
        assert(graded[i].grade == expGrade[i]);
    }
    std::cout << "[PASS] TestCalculateGrade" << std::endl;
}

void TestFindOverallTopper() {
    auto graded = calculateGrade(parseCSV("grades.csv"));
    Student got = findOverallTopper(graded);
    Student want = {"Bernard", "Wilson", "Boston University", 90, 85, 76, 71};

    assert(got == want);
    std::cout << "[PASS] TestFindOverallTopper" << std::endl;
}

void TestFindTopperPerUniversity() {
    auto tpu = findTopperPerUniversity(calculateGrade(parseCSV("grades.csv")));

    Student bostonTopper = {"Bernard", "Wilson", "Boston University", 90, 85, 76, 71};
    Student dukeTopper = {"Tamara", "Webb", "Duke University", 73, 62, 90, 58};

    assert(tpu["Boston University"] == bostonTopper);
    assert(tpu["Duke University"] == dukeTopper);
    // ... add others as needed following the same pattern

    std::cout << "[PASS] TestFindTopperPerUniversity" << std::endl;
}

int main() {
    try {
        TestParseCSV();
        TestCalculateGrade();
        TestFindOverallTopper();
        TestFindTopperPerUniversity();
        std::cout << "\nALL TESTS PASSED!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Tests failed with error: " << e.what() << std::endl;
    }
    return 0;
}