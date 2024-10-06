#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Student
{
	string name;
	int registrationNumber;
	map<string, int> grades;

	Student(string studentName, int regNumber) : name(studentName), registrationNumber(regNumber) {}

	// добавляет оценку студента по данной дисциплине
	void addGrade(string subject, int grade);

	// возвращает оценку студента по переданной дисциплине
	int getGrade(string subject);

	// вычисляет среднюю оценку студента по всем дисциплинам
	double calculateAverageGrade();

	// возвращает минимальную оценку студента по всем дисциплинам
	int getMinGrade();

	// возвращает максимальную оценку студента по всем дисциплинам
	int getMaxGrade();

	// выводит всю информацию о студенте
	void printSummary();
};

// проверяет условия
void checkStudents(vector<Student>);