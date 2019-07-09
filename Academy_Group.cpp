#include "Academy_Group.h"
#include "Vector.h"

AcademyGroup::AcademyGroup() :pSt(nullptr), count(0) {}

AcademyGroup::AcademyGroup(const AcademyGroup & obj)
{
	count = obj.count;
	const short int k = 1;

	pSt = new Student*[count];

	for (int i = 0; i < count; i++)
	{
		pSt[k][i] = obj.pSt[k][i];
	}
}

AcademyGroup::AcademyGroup(AcademyGroup && obj)
{
	count = obj.count;
	const short int k = 1;

	pSt = new Student*[count];

	for (int i = 0; i < count; i++)
	{
		pSt[k][i] = obj.pSt[k][i];
		obj.pSt[k] = nullptr;
	}
}
