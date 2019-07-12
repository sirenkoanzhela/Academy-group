#pragma once
#include "Student.h"

namespace Academy_Group
{
	class AcademyGroup
	{
		Student** pSt;
		int count;
	public:
		AcademyGroup();
		AcademyGroup(const AcademyGroup& obj);
		AcademyGroup(AcademyGroup&& obj)noexcept;
		~AcademyGroup();
		void AddStudents(Student*);
		void DeleteStudent(Student*);
		void EditStudent(Student*);
		void Print();
		Student* FindStudent(std::string, std::string);
		void Sort();
		void Save();
		void Load();
		AcademyGroup& operator=(const AcademyGroup& obj);
		AcademyGroup& operator=(AcademyGroup&& obj);
		Student& operator[](int index);
		friend std::ostream& operator<<(std::ostream& os, AcademyGroup& obj);
	private:
		bool IsStudent(Student*);
	};
}