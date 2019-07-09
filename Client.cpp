#include <iostream>
#include "Person.h"
#include "Student.h"



int main()
{
	/*Person p;
	p.Input();
	p.Print();

	Person p2;
	std::cin >> p2;
	std::cout << p2;*/

	Student st("Alexa", "Prince", 23, "12345678901230", 4.5);
	st.Print();

	Student st2 = st;
	st.Print();

	
	return 0;
}