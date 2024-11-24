#include <iostream>
#include <string>
using namespace std;

// Namespace for utility functions
namespace utils
{
    void printLine(char ch = '-', int width = 50)
    {
        cout << string(width, ch) << endl;
    }
}

// Abstract Base Class
class Person
{
protected:
    int id;      // Unique ID for each person
    string name; // Name of the person

public:
    // Constructor for Person
    Person(int id, const string &name) : id(id), name(name) {}

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Person() = default;

    // Pure virtual function to be overridden by derived classes
    virtual void displayInfo() const = 0;

    // Virtual function to add marks, default does nothing
    virtual void addMarks(int math, int science)
    {
        cout << "This operation is not supported for this person type.\n";
    }
};

// Derived Class - Student
class Student : public Person
{
private:
    int mathScore;    // Math score for the student
    int scienceScore; // Science score for the student
    char grade;       // Grade calculated based on scores

    // Private function to calculate the grade based on scores
    void calculateGrade()
    {
        if (mathScore == -1 && scienceScore == -1)
        {
            grade = 'N'; // No grade available
            return;
        }

        float average = 0;
        int count = 0;

        if (mathScore != -1)
        {
            average += mathScore;
            count++;
        }

        if (scienceScore != -1)
        {
            average += scienceScore;
            count++;
        }

        average /= count;

        if (average >= 90)
            grade = 'A';
        else if (average >= 80)
            grade = 'B';
        else if (average >= 70)
            grade = 'C';
        else if (average >= 60)
            grade = 'D';
        else
            grade = 'F';
    }

public:
    // Constructor for Student
    Student(int id, const string &name)
        : Person(id, name), mathScore(-1), scienceScore(-1), grade('N') {}

    // Overridden function to add marks for the student
    void addMarks(int math, int science) override
    {
        if (math < 0 || math > 100 || science < 0 || science > 100)
        {
            throw invalid_argument("Invalid score! Must be between 0 and 100.");
        }
        mathScore = math;
        scienceScore = science;
        calculateGrade(); // Update grade after adding marks
    }

    // Overridden function to display student info
    void displayInfo() const override
    {
        cout << "Student ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Math: " << (mathScore != -1 ? to_string(mathScore) : "Not Assigned") << endl;
        cout << "Science: " << (scienceScore != -1 ? to_string(scienceScore) : "Not Assigned") << endl;
        cout << "Grade: " << grade << endl;
    }
};

// Main Function
int main()
{
    try
    {
        // Create base class pointers pointing to derived class objects
        Person *people[2]; // Array of base class pointers
        people[0] = new Student(1, "Alice");
        people[1] = new Student(2, "Bob");

        // Add marks using polymorphic calls
        people[0]->addMarks(85, 92); // Polymorphic call to Student's addMarks()
        people[1]->addMarks(72, 68); // Polymorphic call to Student's addMarks()

        // Display details of all persons
        utils::printLine('=', 50);
        cout << "Student Details (Polymorphism Example):\n";
        utils::printLine('=', 50);

        for (int i = 0; i < 2; ++i)
        {
            people[i]->displayInfo(); // Polymorphic call to displayInfo()
            utils::printLine();
        }

        // Clean up memory
        for (int i = 0; i < 2; ++i)
        {
            delete people[i];
        }
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
