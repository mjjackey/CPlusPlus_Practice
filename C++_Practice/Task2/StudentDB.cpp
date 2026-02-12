// Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <numeric>
#include "grades.h"


size_t GradesDB::GetStudentCount() const 
{
	return database_.size();
}

GradesDB::AddResult GradesDB::Add(const std::string& name, const std::string& subject, double grade) 
{
    std::cout << "This is debug output " << name << "\n";
	for(auto& obj:database_)
	{
		if (obj.name_ == name)
		{
			auto i = obj.grades_.find(subject);
			if (i != obj.grades_.end())
			{
				i->second = grade;
				return AddResult::GradeOverwritten;
			}
			else
			{
				obj.grades_.insert({ subject,grade });
				return AddResult::NewGrade;
			}
		}
	}
	Student stu;
	stu.name_ = name;
	stu.grades_.insert({ subject,grade });
	database_.emplace_back(stu);
	return AddResult::NewEntry;
}

std::pair<bool, double> GradesDB::GetAverageForStudent(const std::string& name) const 
{
	for (const auto& obj : database_)
	{
		if (obj.name_ == name)
		{
			double sum = 0.0;
			std::for_each(obj.grades_.begin(), obj.grades_.end(), [&sum](const auto& kv) {sum += kv.second; });
			return  obj.grades_.size() > 0 ? std::make_pair(true, sum / obj.grades_.size()) : std::make_pair(false, 0.0);
		}
	}
	return  { false, 0.0 };

	
}

std::pair<bool, double> GradesDB::GetAverageForStudentAlternate(const std::string& name) const
{
	for (const auto& obj : database_)
	{
		if (obj.name_ == name)
		{
			auto sum = std::accumulate(obj.grades_.begin(), obj.grades_.end(), 0.0, [](double sum, const std::pair<const std::string, double>& grade) { return sum + grade.second; });
			return  obj.grades_.size() > 0 ? std::make_pair(true, sum / obj.grades_.size()) : std::make_pair(false, 0.0);
		}
	}
	return  { false, 0.0 };
}


std::pair<bool, double> GradesDB::GetAverageForSubject(const std::string& subject) const
{
	double sum = 0.0;
	int count = 0;
	for (const auto& obj : database_)
	{
		if (obj.grades_.find(subject) != obj.grades_.end())
		{
			sum += obj.grades_.at(subject);
			count++;
		}
	}
	if(count>0)
	{ 
		return { true, sum / count };
	}
	else
	{
		return { false,0.0 };
	}
}

int main()
{
	std::cout << "Hello World!\n";
	GradesDB db;
	db.Add("Alice", "Math", 90);
	db.Add("Alice", "English", 80);
	db.Add("Bob", "Math", 85);
	db.Add("Bob", "English", 75);
	db.Add("Alice", "Math", 95); // Overwrite Alice's Math grade
	db.Add("Jackey", "Math", 100);
	db.Add("Jackey", "English", 95);
	auto num = db.GetStudentCount();
	std::cout << "Student Count: " << num << std::endl;
	auto avg1 = db.GetAverageForStudent("Jackey");
	std::cout << "Jackey's average: " << (avg1.first ? std::to_string(avg1.second) : "N/A") << std::endl;
	avg1 = db.GetAverageForStudentAlternate("Jackey");
	std::cout << "Jackey's average: " << (avg1.first ? std::to_string(avg1.second) : "N/A") << std::endl;
	auto avg2 = db.GetAverageForSubject("Math");
	std::cout << "Math average: " << (avg2.first ? std::to_string(avg2.second) : "N/A") << std::endl;
}


