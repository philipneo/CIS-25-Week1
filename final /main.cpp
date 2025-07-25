#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "student.h"
using namespace std;

// Save all students to a file
void saveStudents(const vector<Student>& students, const string& filename) {
    ofstream ofs(filename);
    for (const auto& s : students) {
        s.writeToFile(ofs);  // Works now because writeToFile is marked const
    }
    ofs.close();
}

// Load all students from a file
vector<Student> loadStudents(const string& filename) {
    ifstream ifs(filename);
    vector<Student> students;
    string line;
    while (getline(ifs, line)) {
        if (!line.empty()) {
            students.push_back(Student::fromLine(line));
        }
    }
    ifs.close();
    return students;
}

// Main program loop
int main() {
    vector<Student> students;
    string filename = "student_data.txt";
    students = loadStudents(filename);

    int choice;
    do {
        cout << "\n===== Student Record System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Save and Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            float gpa;

            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter GPA: ";
            cin >> gpa;

            students.push_back(Student(id, name, gpa));
        } else if (choice == 2) {
            if (students.empty()) {
                cout << "No students found.\n";
            } else {
                for (const auto& s : students) {
                    s.display();
                }
            }
        }
    } while (choice != 3);

    saveStudents(students, filename);
    cout << "✅ Data saved to " << filename << ". Goodbye!\n";

    return 0;
}
