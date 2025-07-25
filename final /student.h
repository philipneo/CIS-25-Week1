#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <fstream>
using namespace std;

class Student {
private:
    int id;
    string name;
    float gpa;
public:
    Student();
    Student(int i, string n, float g);

    void display() const;
    int getId();
    string getName();
    float getGPA();

    void writeToFile(ofstream &ofs) const;
    static Student fromLine(const string& line);
};

#endif
