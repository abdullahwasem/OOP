
QUESTION 1 




#include <iostream>
#include <string >

using namespace std;



class lambo
{
	string color;
	int cubic_capacity;
	int num_of_seats;
	int year_of_man;
	int eng_num;
	int frame_num;
	string owner_name;

public:
	lambo(string c = "hot red", int cc = 2500, int nos = 4, int yom = 2020, int en = 1717, int fn = 1818, string on = "astad")
	{
		color = c;
		cubic_capacity = cc;
		num_of_seats = nos;
		year_of_man = yom;
		eng_num = en;
		frame_num = fn;
		owner_name = on;
	}

	lambo(const lambo& obj2)
	{
		color = obj2.color;
		cubic_capacity = obj2.cubic_capacity;
		num_of_seats = obj2.num_of_seats;
	}

	void set(int y, int E, int F, string O)
	{

		
		cout << "owner name ::  ";
		cin >> owner_name; 
		cout << endl; 
		owner_name = O; 
		cout << "COLOUR::  ";
		cout << "hot red ! \n";
		cout << "cubic capacity ::  2500cc \n";
		cout << "number of seats ::  4 \n"; 



		
		cout << "   YEAR::   ";
		cin >> year_of_man;
		cout << endl;
		year_of_man = y;

		cout << "   engine num ::  ";
		cin >> eng_num;
		cout << endl;
		eng_num = E;

		cout << "frame number ::   ";
		cin >> frame_num;
		cout << endl;
		frame_num = F;
		
	}

	void get(int& y, int& E, int& F, string& O)
	{
		y = year_of_man;
		eng_num = E;
		frame_num = F;
		owner_name = O;
	}



};







int main()
{
	lambo obj1;
	string O="", c = "";
	int y =0 , E = 0 , F = 0; 
	
	
	cout << "INFORATION OF OBJ1 \n"; 
	obj1.set(y,E , F , O); 
	obj1.get(y , E , F , O); 
	lambo obj2(obj1); 
	cout << "INFORMATION ABOUT OBJ2 \n";
	//lambo obj1(obj2);
	obj2.set(y , E , F  , O); 
	obj2.get(y , E , F , O);



}




QUESTION 2 

#include <iostream>
#include<string>
using namespace std; 

class student
{
		int  *marks;

		public :
			student() 
			{
				marks = new int[5]; 

			}

			void set_marks( int mark , int index )
			{
				marks[index] = mark; 
			}


			void output()
			{

				for (int i = 0; i < 5; i++)
				{


					cout << "your marks for ::" << i + 1 << " "<<"are  " << marks[i] << endl;
				}
			}


			



			~student()
			{
				delete[]marks;
			}
	

};




int main()
{
	int mark; 
	student s1; 
	cout << "YOUR MARKS FOR STUDENT 1 \n"; 
	for (int i = 0; i < 5; i++)
	{
		cout << "plz enter marks \n";
		cin >> mark; 
		s1.set_marks(mark, i);

	}
	student s2(s1); 
	s1.~student();
	s2.output(); 


}

QUESTION 3 
#include <iostream>
#include<string>
using namespace std; 

class student
{
		int  *marks;

		public :
			student() 
			{
				marks = new int[5]; 

			}

			void set_marks( int mark , int index )
			{
				marks[index] = mark; 
			}


			void output()
			{

				for (int i = 0; i < 5; i++)
				{


					cout << "your marks for ::" << i + 1 << " "<<"are  " << marks[i] << endl;
				}
			}


			student(const student& S)
			{
				marks = new int[5];
				for (int i = 0; i < 5; i++)
				{
					marks[i] = S.marks[i]; 

				}
			}



			~student()
			{
			}
	

};




int main()
{
	int mark; 
	student s1; 
	cout << "YOUR MARKS FOR STUDENT 1 \n"; 
	for (int i = 0; i < 5; i++)
	{
		cout << "plz enter marks \n";
		cin >> mark; 
		s1.set_marks(mark, i);

	}
	student s2(s1); 
	s1.~student();
	s2.output(); 


}