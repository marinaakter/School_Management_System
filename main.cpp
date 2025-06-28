#include <bits/stdc++.h>
using namespace std;
class Person {
protected:
	string name;
	int age;
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	virtual void showInfo() {
		cout << "Name: " << name << endl;
		cout << "age: " << age << endl;
	}
};

class Student:public Person {
private:
	int studentID;
	string course_Name;
public:
	Student(string name, int age, int studentID, string course_name): Person(name, age) {
		this->studentID = studentID;
		this->course_Name = course_Name;
	}
	void showInfo() override {
		cout << "[Student] Name: " << name << endl;
		cout << "age: " << age << endl;
		cout << "ID: " << studentID << endl;
		cout << "Course: " << course_Name << endl;
	}
};

class Teacher:public Person {
private:
	string subject;
public:
	Teacher(string name, int age, string subject) : Person(name, age) {
		this->subject = subject;
	}
	void showInfo() override {
		cout << "[Teacher] Name: " << name << endl;
		cout << "age: " << age << endl;
		cout << "Subject: " << subject << endl;
	}

};

int main() {
	vector<Student> students;
	vector<Teacher> teachers;
	int choice;
	while (true) {
		cout << "===== School Management Menu =====" << endl;
		cout << "1. Add Student" << endl;
		cout << "2. Show All Students" << endl;
		cout << "3. Add Teacher" << endl;
		cout << "4. Show All Teachers" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1) {
			string name, course;
			int age, id;
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter age: ";
			cin >> age;
			cout << "Enter Student ID: ";
			cin >> id;
			cout << "Course Name: ";
			cin >> course;
			students.emplace_back(name, age, id, course);
			cout << "Student added successfully!\n";
		}
		else if (choice == 2) {
			cout << "\n--- Student List ---\n";
			for (Student& s:students) {
				s.showInfo();
			}
		}
		else if (choice == 3) {
			string name, subject;
			int age;
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter age: ";
			cin >> age;
			cout << "Subject Name ";
			cin >> subject;
			teachers.emplace_back(name, age, subject);
			cout << "Teacher added successfully!\n";
		}
		else if (choice == 4) {
			cout << "\n--- Teacher Lists ---\n";
			for (Teacher& t:teachers) {
				t.showInfo();
			}
		}
		else if (choice == 5) {
			cout << "Exiting --- Goodbye!!\n";
			break;
		}
		else {
			cout << "Invalid Choice. Try again.\n";
		}
	}


	return 0;
}