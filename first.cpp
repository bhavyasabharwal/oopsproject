#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <memory> // For smart pointers
#include <exception>
using namespace std;

// Namespace for utility functions
namespace utils {
    void printLine(char ch = '-', int width = 50) {
        cout << string(width, ch) << endl;
    }
}

// Abstract Base Class
class Person {
protected:
    int id;
    string name;

public:
    Person(int id, const string& name) : id(id), name(name) {}
    virtual ~Person() = default;

    virtual void displayInfo() const = 0; // Pure virtual function
};

// Derived Class - Student
class Student : public Person {
private:
    map<string, int> marks;
    char grade;

    void calculateGrade() {
        if (marks.empty()) {
            grade = 'N'; // No grade available
            return;
        }

        int totalMarks = 0;
        for (const auto& subject : marks) {
            totalMarks += subject.second;
        }

        float average = static_cast<float>(totalMarks) / marks.size();

        if (average >= 90) grade = 'A';
        else if (average >= 80) grade = 'B';
        else if (average >= 70) grade = 'C';
        else if (average >= 60) grade = 'D';
        else grade = 'F';
    }

public:
    // Constructors
    Student(int id, const string& name) : Person(id, name), grade('N') {}

    // Adding marks
    void addMarks(const string& subject, int score) {
        if (score < 0 || score > 100) throw invalid_argument("Invalid score! Must be between 0 and 100.");
        marks[subject] = score;
        calculateGrade();
    }

    // Operator overloading for comparison
    bool operator<(const Student& other) const {
        return grade < other.grade;
    }

    // Overridden function to display student info
    void displayInfo() const override {
        cout << "Student ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Marks:" << endl;
        for (const auto& subject : marks) {
            cout << "  " << subject.first << ": " << subject.second << endl;
        }
        cout << "Grade: " << grade << endl;
    }
};

// Function template to display a list of objects
template <typename T>
void displayList(const vector<shared_ptr<T>>& list) {
    for (const auto& obj : list) {
        obj->displayInfo();
        utils::printLine();
    }
}

// Main Function
int main() {
    try {
        vector<shared_ptr<Person>> people; // List of students

        // Add students
        auto student1 = make_shared<Student>(1, "Alice");
        auto student2 = make_shared<Student>(2, "Bob");

        // Add marks
        student1->addMarks("Math", 85);
        student1->addMarks("Science", 92);

        student2->addMarks("Math", 72);
        student2->addMarks("Science", 68);

        // Add students to list
        people.push_back(student1);
        people.push_back(student2);

        // Display all students
        utils::printLine('=', 50);
        cout << "Student Details:\n";
        utils::printLine('=', 50);
        displayList(people);

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}


