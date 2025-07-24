#include "fileio.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

void saveToFile(const vector<Student*>& students, const string& filename) {
    ofstream out(filename);
    if (!out) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (const auto& s : students) {
        // Save in format: name,id,grade
        out << s->getName() << "," << s->getId() << "," << s->getGrade() << endl;
    }

    out.close();
    cout << "Data saved successfully to " << filename << endl;
}

void loadFromFile(vector<Student*>& students, const string& filename) {
    ifstream in(filename);
    if (!in) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string name;
        int id;
        float grade;

        getline(ss, name, ',');
        ss >> id;
        ss.ignore(1, ',');
        ss >> grade;

        Student* s = new Student(name, id, grade);
        students.push_back(s);
    }

    in.close();
    cout << "Data loaded successfully from " << filename << endl;
}
