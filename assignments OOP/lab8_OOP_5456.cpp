QUESTION 1 

#include <iostream>
#include <string>
using namespace std; 

class box
{
private :
	int length, breath, height; 

public:
	static int objectcount; 
	box(int a = 0, int b = 0, int c = 0)

	{
		length = a; 
		breath = b;
		height = c;
		objectcount++; 
	}
	static int count();
	double volume();
	double area();
	void setlen(int x)
	{
		this->length = x; 
	}
	void setbr(int y) {
		this->breath = y; 
	}
	void seth(int z) {
		this->height = z;
	}
	void getlen(int& x) {
		x = length;
	}
	void getbr(int& y) {
		y = breath; 
	}
	void geth(int& z) {
		z = height;
	}

	void output(); 
















};
int box::objectcount = 0;

double  box :: volume()
{
	double vol = 0 ;
	vol = length * breath * height; 
	return vol; 
}

double box::area()
{
	double  A;
	A = length * breath; 
	return A; 


}






int main()
{
	int l, b, h;
	box o1, o2, o3; 
	cout << "\t\t\t\t\t\t\t HELLO PEOPLE \n"; 
	cout << "plz input length \n"; 
	cin >> l; 
	o1.setlen(l); 
	o1.getlen(l); 
	cout << "plz input breath \n";
	cin>>  b; 
	o1.setbr(b);
	o1.getbr(b); 
	cout << "plz input height  \n";
	cin>>h;
	o1.seth(h);
	o1.geth(h); 
	cout << "your volume is :";
	double v = o1.volume();
	cout << v << endl; 
	cout << "your area is :";
	double a =  o1.area();
	cout << a << endl; 
	cout << "number of objects  "; 
	cout << o3.objectcount;


	system("pause"); 
	return 0; 
}


QUESTION 2 
#include <iostream>
#include <string>
using namespace std; 

class duration 
{
private :
	int date, month, year, dur; 
	double salary; 

public:

	duration()
	{
		date = 0;
		month = 0;
		year = 0;
		salary = 0; 
	}
	duration(int x, int y, int z, double s , int du ) //overloaded 
	{
		date = x; 
		month = y;
		year = z; 
		salary = s; 
		dur = du; 

	}
	

	duration&  setdate(int date ) 
	{
		this->date = date; 
		return *this; 
     }

	duration& setmn(int month )
	{
		this->month = month;
		return *this; 
	}

	duration& setyear(int year)
	{
		this->year = year;
		return *this;
	}
	duration& setsal(double salary)
	{
		this->salary = salary;
		return *this;
	}

	void  getdate(int& date)
	{
		date = this->date; 
		
	}
	void  getmn(int& month)
	{
		month = this->month;

	}
	void  getyear(int& year)
	{
		year = this->year;

	}

	void  getsal(double& salary)
	{
		salary = this->salary;

	}

	int getemployeedur()
	{
		cout << "please enter the date(0-31) , month(0-12) and year(0-2022) in which you joined \n"; 
		int d, m, y;
		cin >> d >> m >> y; 

		y = 2022 - y; 
		if (m >= 4)
		{
			m =  (m- 4 );
		}
		else { m =(4 - m ); }
		if (d >= 15)
		{
			d = d - 15; 
		}

		else { d = 15 - d;  }

		dur  = (y * 365) + (m * 30) + (d); 

		cout << " the duration of your job has been   :  " << dur<<endl ; 
		return dur; 

	}

	void newsalary()
	{
		cout << "your current salary is = 150000 \n "; 
		if (dur > 1095 && dur < 1825)
		{
			salary = salary + ((0.07) * salary);
			cout << "your new salary is :" << salary; 
		}
		else if (dur > 1825 )
		{
			salary = salary + ((0.1) * salary);
			cout << "your new salary is :" << salary;
		}
		else { cout << "your  salary is :" << salary; }
	}







};






int main()
{
	int d, m, y; 
	double s; 
	duration d1; 

	d1.setdate(15); 
	d1.setmn(4); 
	d1.setyear(2022); 
	d1.setsal(150000);
	d1.getemployeedur(); 
	d1.newsalary(); 

	

	system("pause"); 
	return 0; 
}