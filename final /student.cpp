#include "student.h"
#include <iostream>
using namespace std;

Student::Student() {}

Student::Student(int i, string n, float g) : id(i), name(n), gpa(g) {}

void Student::display() const {
    cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;
}

int Student::getId() { return id; }
string Student::getName() { return name; }
float Student::getGPA() { return gpa; }

void Student::writeToFile(ofstream &ofs) const {
    ofs << id << "," << name << "," << gpa << endl;
}

Student Student::fromLine(const string& line) {
    int id;
    string name;
    float gpa;

    size_t pos1 = line.find(',');
    size_t pos2 = line.rfind(',');

    id = stoi(line.substr(0, pos1));
    name = line.substr(pos1 + 1, pos2 - pos1 - 1);
    gpa = stof(line.substr(pos2 + 1));

    return Student(id, name, gpa);
}
