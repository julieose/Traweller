#include <iostream>
#include <vector>
#include "student.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	vector<Student> students;
	students.push_back(Student("Иван Иванов", 1));
	students.push_back(Student("Пётр Петров", 2));
	students.push_back(Student("Евгений Сидоров", 3));

	students[0].addGrade("Математика", 4);
	students[0].addGrade("Физкультура", 5);
	students[0].addGrade("Химия", 3);
	students[0].addGrade("История", 5);
	students[0].addGrade("Английский язык", 3);

	students[1].addGrade("Математика", 5);
	students[1].addGrade("Физкультура", 5);
	students[1].addGrade("Химия", 5);
	students[1].addGrade("История", 5);
	students[1].addGrade("Английский язык", 5);

	students[2].addGrade("Математика", 3);
	students[2].addGrade("Физкультура", 2);
	students[2].addGrade("Химия", 2);
	students[0].addGrade("История", 4);
	students[0].addGrade("Английский язык", 3);

	int grade = students[0].getGrade("Химия");
	if (grade != -1)
		cout << "Оценка по химии для первого ученика: " << grade << endl;
	else cout << "Оценка по химии для первого студента не найдена" << endl;
	cout << endl;

	for (Student student : students)
	{
		student.printSummary();
		cout << endl;
	}

	checkStudents(students);
}