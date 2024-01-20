#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student{
    private:
        string name;
        string surname;
        vector<int> grades;
    public:
        Student(string Newname, string Newsurname)
        {
            name = Newname;
            surname = Newsurname;
        }
        string getname() { return name; }
        vector<int> getgrades() { return grades; }
        void add_grade(int NewGrade) { grades.push_back(NewGrade); }
        bool Excelent_student()
        {
            float average;
            for(int i = 0; i < grades.size(); i++) average += grades[i];
            average /= (grades.size());

            if(average >= 4.5) return true; else return false;
        }
};

class Teacher
{
    private:
        string subject;

    public:
        Teacher(string NewSubject) { this->subject = NewSubject; }
        void giveGrade(Student& student, int grade){
            student.add_grade(grade);
        }

        string getSubject(){
            return this->subject;
        }
};

int main()
{
    Student s1("Misha", "Petrov");
    Teacher t("Math");
    t.giveGrade(s1, 5);
    s1.add_grade(3);
    s1.add_grade(2);
    s1.add_grade(5);
    cout << (s1.Excelent_student()?"Excellent":"Not excellent") << endl;
    cout << t.getSubject() << endl;
    return 0;
}