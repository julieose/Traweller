#include <iostream>
#include <vector>
#include <string>
#include "student.h"

using namespace std;

// добавляет оценку студента по данной дисциплине
void Student::addGrade(string subject, int grade)
{
	grades[subject] = grade;
}

// возвращает оценку студента по переданной дисциплине
int Student::getGrade(string subject)
{
	auto it = grades.find(subject);
	if (it != grades.end())
		return it->second;
	return -1;
}

// вычисляет среднюю оценку студента по всем дисциплинам
double Student::calculateAverageGrade()
{
	double sum = 0;
	for (const auto& pair : grades)
		sum += pair.second;
	return (grades.empty() ? 0 : sum / grades.size());
}

// возвращает минимальную оценку студента по всем дисциплинам
int Student::getMinGrade()
{
	int minGrade = INT_MAX;
	for (const auto& pair : grades)
		if (pair.second < minGrade)
			minGrade = pair.second;
	return (grades.empty() ? -1 : minGrade);
}

// возвращает максимальную оценку студента по всем дисциплинам
int Student::getMaxGrade()
{
	int maxGrade = INT_MIN;
	for (const auto& pair : grades)
		if (pair.second > maxGrade)
			maxGrade = pair.second;
	return (grades.empty() ? -1 : maxGrade);
}

// выводит всю информацию о студенте
void Student::printSummary()
{
	cout << "Имя студента: " << name << endl;
	cout << "Регистрационный номер: " << registrationNumber << endl;
	cout << "Средняя оценка:: " << calculateAverageGrade() << endl;
	cout << "Минимальная оценка: " << getMinGrade() << endl;
	cout << "Максимальная оценка: " << getMaxGrade() << endl;
}

// проверяет условия
void checkStudents(vector<Student> students)
{
	cout << "Студенты, которые сдали все предметы на 5:" << endl;
	for (Student student : students)
	{
		bool allGradesAre5 = true;
		for (const auto& pair : student.grades)
			if (pair.second != 5)
			{
				allGradesAre5 = false;
				break;
			}
		if (allGradesAre5)
			student.printSummary();
	}
	cout << endl;

	cout << "Студенты которые имеют хотя бы одну 3:" << endl;
	for (Student student : students)
		for (auto pair : student.grades)
			if (pair.second == 3)
			{
				student.printSummary();
				cout << endl;
				break;
			}
	cout << endl;

	cout << "Студенты которые имеют хотя бы одну 2:" << endl;
	for (Student student : students)
		for (auto pair : student.grades)
			if (pair.second == 2)
			{
				student.printSummary();
				cout << endl;
				break;
			}
}