#include "student.h"
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

float CalculateScore(Student &s){
    float t1 = s.test1, t2 = s.test2, t3 = s.test3, t4 = s.test4;
    return (t1 + t2 + t3 + t4)/4.00;
}

Grade CalculateGrade(float score){
    Grade g;
    if(score < 35){
        g = F;
    }else if(35 <= score  && score < 50){
        g = C;
    }else if(50 <= score && score <= 70){
        g = B;
    }else if(70 <= score){
        g = A;
    }
    return g;
}


std::vector<Student> parseCSV(std::string filePath) {
    std::vector<Student> students;
    ifstream fin(filePath);
    string line;

    if (!fin.is_open()) return students;

    getline(fin, line); // Skip the header row

    while (getline(fin, line)) { // Read the whole line at once
        stringstream ss(line);
        string word;
        vector<string> row;

        while (getline(ss, word, ',')) {
            row.push_back(word);
        }

        if (row.size() < 7) continue; // Basic safety check

        Student s; // Create on the STACK
        s.firstName = row[0];
        s.lastName = row[1];
        s.university = row[2];
        s.test1 = stoi(row[3]);
        s.test2 = stoi(row[4]);
        s.test3 = stoi(row[5]);
        s.test4 = stoi(row[6]);
        
        students.push_back(s); // Vector makes a clean copy
    }
    return students;
}

std::vector<Student> calculateGrade(std::vector<Student> students) {
    for (auto& s : students) {
        // Based on your Go test scores, finalScore = (t1+t2+t3+t4) / 4
        s.finalScore = (s.test1 + s.test2 + s.test3 + s.test4) / 4.0f;
        // TODO: Implement Grade logic based on finalScore
        s.grade = CalculateGrade(s.finalScore);
    }
    return students;
}

Student findOverallTopper(std::vector<Student> students) {
    // Student topper = students[0]; 
    // for(const auto& s : students) {
    //     if(s.finalScore > topper.finalScore) {
    //         topper = s;
    //     }
    // }
    // return topper;

    std::map<std::string, Student> toppers_By_University = findTopperPerUniversity(students);
    Student topper = students[0];
    for(auto [univ, std]: toppers_By_University){
        if(std.finalScore > topper.finalScore){
            topper = std;
        }
    }
    return topper;
}

std::map<std::string, Student> findTopperPerUniversity(std::vector<Student> students) {
    std::map<std::string, Student> toppers;
    // TODO: For each university, find the student with the max score
    for(Student s: students){
        if(toppers.find(s.university) == toppers.end()){
            toppers[s.university] = s;
        }else{
            if(toppers[s.university].finalScore < s.finalScore ){
                toppers[s.university] = s; 
            }
        }
    }
    return toppers;
}