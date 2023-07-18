#include <iostream>
#include<fstream>
#include<string>
using namespace std; 


class tms
{
//	customer* cust;
//	driver* dri;
//	vehicle* veh;
//
//	tms()
//	{
//		cust = new customer[15];
//		dri = new driver[20];
//		veh = new vehicle[20];
//		cust = nullptr;
//		dri = nullptr;
//		veh = nullptr;
//		//load data
//	}
// 	   ~tms()
//	{
//	cust = delete ;
// 	   cust =  nullptr ;
	//		dri = delete ;
	// dri = nullptr ;
	//		veh = delete ;
	// veh = 
	//		cust = nullptr;
	//		dri = nullptr;
	//		veh = nullptr;


	//}//





};





//CLASS 1
class name
{
private :
	char* fname;
	char* lname;

public :
	name()
	{

	}
	

	void setterN(char [], char []);
	char* getterName();
	char* getterNameLast();
	friend ostream& operator << (ostream& out, const name& N);
};

void name :: setterN(char a[] , char b[])
{

	
	fname = a;
	lname = b;
}

char* name::getterName()
{
	return fname;
}

char* name::getterNameLast()
{
	return lname;
}

ostream& operator << (ostream& out, const name& N)
{
	out << N.fname << " " << N.lname << endl; 
	return out; 
}


//CLASS 2
class date
{
	int day;
	int month; 
	int year;
public :
	date()
	{
		day = 0; 
		month = 0; 
		year = 0;
	}

	int setdate(int x, int y, int  z)
	{
		day = x; 
		month = y; 
		year = z; 
		return 0; 
	}

	int* getday()
	{
		int  *arr=  new int[3];
		arr[0] = day;
		arr[1] = month;
		arr[2] = year;
		return arr;
	}

	friend  ostream& operator <<(ostream& outi, const date& d); 
	
};


ostream& operator <<(ostream& outi, const date& d)
{
	outi << endl;
	outi << d.day << "/" << d.month << "/" << d.year << endl;
	return outi;
}


//CLASS 3
class mtime 
{
	int hour;
	int min;
	int secs;
public :

	mtime()
	{
		hour = 0;
		min = 0;
		secs = 0;
	}

	int settime(int x, int y, int z)
	{
		hour = x; 
		min = y; 
		secs = z; 
	}
    
	int gettime(int& x, int& y, int& z)
	{
		 x= hour;
		 y = min;
	     z = secs;

	}

	 friend ostream& operator <<(ostream& outime, const mtime& d);



};

ostream& operator <<(ostream& outime, const mtime& t)
{
	outime << t.hour << ":" << t.min << " : " << t.secs << endl; 
	return outime;

}



//CLASS 4
class service
{
	char* source;
	char* destination ;
	float distance; 
	date bookingdate; 
	mtime bookingtime; 
	bool status; 
	float fuelrate;

	int cId, dId, vId; 

public :
	service()
	{
		 source = nullptr;
		 destination = nullptr;
		 distance = 0 ;
		date bookingdate;
		mtime bookingtime;
		 status  = 0 ;
		 fuelrate = 0 ;

		 cId = 0;
		 dId = 0; 
	     vId = 0;

	}
};


//CLASS 5
class ride : public service
{
	int noofpassengers;
	char* ridetype;
	float driverranking;
	float vehicleranking;

public :
	ride()
	{
		noofpassengers = 0;
	    ridetype = nullptr;
	    driverranking = 0 ;
		vehicleranking= 0 ;
	}

};


//CLASS 6 
class delivery : public service
{
	float goodsweight;
	char* goodstype; 

public :
	delivery()
	{
		goodsweight = 0;
		goodstype = nullptr;
	}
};

//CLASS 7
class person
{
	name pname;
	date DOB;
	int age;
	int nid;

public :
		person()
		{
			age= 0;
			nid = 0;
		}

	void add_new(char fn[], char ln[], int day, int month, int year, int a, int n)
	{
		pname.setterN(fn,ln);
		DOB.setdate(day, month, year);
		age = a;
		nid = n;
		
		
	}

	void add_new(char fn[], char ln[], int day, int month, int year)
	{
		pname.setterN(fn, ln);
		DOB.setdate(day, month, year);
		
	}
	//storing in file 
	void Store(fstream *file)
	{
		*file << pname.getterName() << " "; 
		*file << pname.getterNameLast() << " ";
		int* arr = new int(3);
		arr = DOB.getday();
		*file <<arr[0] << "/" << arr[1] << "/" << arr[2] << " ";
		*file <<"Age: "<< age << " ";
		*file << "NID: " << nid << " ";
	}
	void Store(fstream* driverfile, int dI, int nooflicence, char type, int rank, int sal, int stat, int exp)
	{
		*driverfile << pname.getterName() << " ";
		*driverfile << pname.getterNameLast() << " ";
		int* arr = new int(3);
		arr = DOB.getday();
		*driverfile << arr[0] << "/" << arr[1] << "/" << arr[2] << " ";

		*driverfile << dI<<" ";
		*driverfile << nooflicence<<" ";
		*driverfile << type<<" ";
		*driverfile << rank<<" ";
		*driverfile << sal<<" ";
		*driverfile << stat<<" ";
		*driverfile << exp<<" ";


	}

	void Store(fstream* vehiclefile, int vI, int regno, float avg, float ltype, bool stati, float ranki)
	{

		*vehiclefile << vI <<"  ";
		*vehiclefile << regno <<"  ";
		*vehiclefile << avg << "  ";
		*vehiclefile << ltype << "  ";
		*vehiclefile << stati << "  ";
		*vehiclefile << ranki << "  ";
		


	}
		

};

//CLASS 8
class customer : public person
{
	int cId;
	service** bookinghistory;
	fstream *file;

public:

	customer()
	{

	}
	customer(fstream &f)
	{
		cId = 0;
		file = &f;
	}

	void SETperson(char fn[], char ln[], int day, int month, int year, int a, int n)
	{
		add_new(fn, ln, day, month, year, a, n);
		Store(file);
	}

};


//CLASS 9
class driver : public person
{
	int dId;
	char* licenceslist;
	int nooflicences; 
	float overalranking;
	float salary;
	int experience;
	int status;
	service** servicehist; 
	fstream* driverfile; 

public :
	driver()
	{

	}
	driver(fstream &dive  )
	{
		dId = 0 ;
	    licenceslist = nullptr;
	    nooflicences = 0 ;
		overalranking = 0;
	    salary = 0 ;
		experience = 0;
	    status = 0;
		servicehist = nullptr;
		driverfile = &dive;
	}

	 virtual void setdriver(char fn[], char ln[], int day, int month, int year)
	{
		cout << "input driver ID \n";
		int dI;
		cin >> dI;
		dId = dI;
		
		cout << "input number of licences \n";
		int nooflicence;
		cin >> nooflicence;
	 
		licenceslist = new char[nooflicence];
		char type; 
		for (int i = 0; i < nooflicence; i++)
		{
			cin >> type; 
			licenceslist[i] = type; 
		}

		cout << "input rank \n";
		float rank= 0.0;
		cin >> rank; 
		overalranking = rank; 

		cout << "input salary \n";
		double sal = 0;
		cin >> sal; 
		salary  = sal;

		cout << "input status \n"; 
		int stat = 0; 
		cin >> stat;
		status = stat; 

		cout << "input exprince \n"; 
		double exp = 0;
		cin >> exp; 
		experience = exp; 

		add_new(fn, ln, day, month, year);
		Store(driverfile, dI, nooflicence, type, rank, sal, stat, exp);
	}

};

//CLASS 10

class feature
{
	int fId;
	char* description;
	float cost;

public :
	feature()
	{
		fId = 0 ;
		description = nullptr;
		cost = 0;
	}
};

//CLASS 11
class vehicle : public person
{
	int vId; 
	int registrationno; 
	float avgmileage;
	float licencetype;
	bool status; 
	char* fueltype;
	float overalranking;
	date manufacturingdate;
	feature* list; 
	fstream *vehiclefile; 
	//service** servicehist;


public :
	vehicle()
	{

	}

	vehicle(fstream & vehifile)
	{
	     vId = 0;
		registrationno = 0;
		 avgmileage = 0;
		 licencetype = 0 ;
		 status = 0;
		 fueltype = nullptr;
		 overalranking = 0;
		 vehiclefile = & vehifile;

	}

	void setvehicle(int vI, int regno, float avg, float ltype, bool stati, float ranki)
	{
		cout << "plz enter vehicle id \n";
		cin >> vI;
		vId = vI;

		cout << "plz enter vehicle registration number \n";
		cin >> regno;
		registrationno = regno;

		cout << "plz enter vehicle average \n ";
		cin >> avg;
		avgmileage = avg;

		cout << "plz enter vehicle licence type \n";
		cin >> ltype;
		licencetype = ltype;

		cout << "plz enter vehicle activity \n";
		cin >> stati;
		status = stati;

		cout << "plz enter vehicle ranking \n";
		cin >> ranki;
		overalranking = ranki;



		Store( vehiclefile,  vI,  regno, avg,  ltype, stati,  ranki);
	

		









	}
	

};




int main()
{

	cout << "\t\t\t\t\t WELCOME TO TMS {WE MOVE YOU AND YOURS} \n";
	cout << "[1] : ADD A NEW CUSTOMER \n";
	cout << "[2] : ADD A NEW DRIVER \n";
	cout << "[3] : REMOVE A  DRIVER \n";
	cout << "[4] : ADD  A NEW  VEHICLE \n";
	cout << "[5] : REMOVE A VEHICLE \n";
	cout << "[6] : PRINT LIST OF ALL CUSTOMERS \n";
	cout << "[7] : PRINT LIST OF ALL DRIVERS \n";
	cout << "[8] : PRINT LIST OF ALL VEHICLES WITH DETAILS BY THEIR CATEGORY \n";
	cout << "[9] : PRINT DETAILS AND SERVICE HISTORY OF A VEHICLE  \n";
	cout << "[10]: PRINT HISTORY OF A CUSTOMER  \n";
	cout << "[11]: PRINT HISTORY OF A DRIVER AND HIS SERVICES \n";
	cout << "[12]: PRINT LIST OF ALL DRIVERS WITH RANKING 4.5+ \n";
	cout << "[13]: PRINT LIST OF ALL DRIVERS WITH MULTIPLE LICENCES  \n";
	cout << "[14]: PRINT UPDATED SALARY OF ALL DRIVERS  \n";
	cout << "[15]: ADD A SERVICE REQUEST  \n";
	cout << "[16]: CANCEL A SERVICE  \n";
	cout << "[17]: COMPLETE  A SERVICE  \n";
	cout << "[18]: PRINT LIST OF ALL CUSTOMERS WHO USED THE SAME VEHICLES  \n";
	cout << "[19]: PRINT LIST OF ALL DRIVERS WHO COMPLETED DELIVERY SERVICE SAME DAY  \n";
	cout << "[20]: PRINT DETAILS OF ALL PENDING SERVICES ON A PARTICULAR DATE    \n";
	cout << "[21]: PRINT DETAILS OF ALL PENDING SERVICES OF A PARTICULAR DRIVER   \n";
	cout << "[22]: PRINT DETAILS OF ALL CANCELLED SERVICES OF A PARTICULAR CUSTOMER    \n";
	cout << " \t\t\t\t\t EXITING TMS    \n";

	int choices =  0 ;
	cout << "choice \n";
	cin >> choices;
	if (choices == 1)
	{
		//STORING A CUSTOMER
		fstream file;
		file.open("customers", ios_base::app);
		customer c(file);

		string aa; 
		char* a;
		string bb; 
		char* b;
		cout << "plz enter first name \n";
		cin >> aa;
		cout << "plz enter last name \n";
		cin >> bb;
		

		int n = aa.length() , nn = bb.length();
		a = new char[n + 1];
		b = new char[nn + 1];

		//strcpy(a, aa.c_str());
		for (int i = 0; i < n + 1; i++)
		{
			a[i] = aa[i];
		}
		
		for (int i = 0; i < nn + 1; i++)
		{
			b[i] = bb[i];
		}

		int dayy,  monthh,  yearr,  aii,  nnn; 
		cout << "input day \n ";
		cin >> dayy;

		cout << "input month \n ";
		cin >> monthh;
		cout << "input year \n ";
		cin >> yearr;
		cout << "input age \n ";
		cin >> aii;
		cout << "input N :ID \n ";
		cin >> nnn;

		
		if (!file)
		{
			cout << "NO FILE";
		}
		else
		{	
			file << endl;
			c.SETperson(a, b, dayy, monthh, yearr, aii, nnn);
		}
	}

	else if (choices == 2)
	{
		//STORING A DRIVER 
		fstream driverfile;
		driverfile.open("driver", ios_base::app);
		driver d(driverfile);



		string ad;
		char* add;
		string bd;
		char* bdd;
		cout << "plz enter first name \n";
		cin >> ad;
		cout << "plz enter last name \n";
		cin >> bd;

		int nd = ad.length(), nnd = bd.length();
		add = new char[nd + 1];
		bdd = new char[nnd + 1];

		//strcpy(a, aa.c_str());
		for (int i = 0; i < nd + 1; i++)
		{
			add[i] = ad[i];
		}

		for (int i = 0; i < nnd + 1; i++)
		{
			bdd[i] = bd[i];
		}

		int dayyd, monthhd, yearrd;
		cout << "input day \n ";
		cin >> dayyd;
		cout << "input month \n ";
		cin >> monthhd;
		cout << "input year \n ";
		cin >> yearrd;





		if (!driverfile)
		{
			cout << "NO FILE";
		}
		else
		{
			driverfile << endl;
			d.setdriver(add, bdd, dayyd, monthhd, yearrd);
		}
	}

	else if (choices == 4)
	{
		//	add a new vehicle 
		int aaa = 0, bbb = 0;
		float cc = 0, dd = 0, ff = 0;
		bool ee = 0;
		fstream vehiclefile;
		vehiclefile.open("vehicle", ios_base::app);
		vehicle v(vehiclefile);

		if (!vehiclefile)
		{
			cout << "NO FILE";
		}
		else
		{
			vehiclefile << endl;
			v.setvehicle(aaa, bbb, cc, dd, ee, ff);
		}
	}


	//string line;
	////For writing text file
	////Creating ofstream & ifstream class object
	//ifstream ini_file{ "customers.txt" };
	//ofstream out_file{ "copy.txt" };

	//if (ini_file && out_file) {

	//	while (getline(ini_file, line)) {
	//		out_file << line << "\n";
	//	}

	//	cout << "Copy Finished \n";

	//}
	//else {
	//	//Something went wrong
	//	printf("Cannot read File");
	//}

	////Closing file
	//ini_file.close();
	//out_file.close();
	// 
	

	else if (choices == 6)
	{
		//printing customers
		string a1, b1 , trash1;
		char trash;
		int day, month, year, ageee, iddi;
		ifstream in( "customers.txt" );
		{
			for (int i = 0 ; i<10 ; i++)
			{
				in >> a1;
				in >> b1;
				in >> day;
				in >> trash;
				in >> month;
				in >> trash;
				in >> year;
				in >> trash1;
				in >> ageee;
				in >> trash1;
				in >> iddi;

				cout << a1 << " ";
				cout << b1 << " ";
				cout << day << " ";
				cout << month << " ";
				cout << year << " ";
				cout << ageee << " ";
				cout << iddi << " ";

				cout << endl; 


			}

		}
	}

	else if (choices == 7)
	{ 

	string a12, b12, trash12;
	char trash123;
	int day1, month1, year1, ageee1, iddi1;
	ifstream in1("driver.txt");
	{
		for (int i = 0; i < 10; i++)
		{
			in1 >> a12;
			in1 >> b12;
			in1 >> day1;
			in1 >> trash123;
			in1 >> month1;
			in1 >> trash123;
			in1 >> year1;
			in1 >> trash12;
			in1 >> ageee1;
			in1 >> trash12;
			in1 >> iddi1;

			cout << a12 << " ";
			cout << b12 << " ";
			cout << day1 << " ";
			cout << month1 << " ";
			cout << year1 << " ";
			cout << ageee1 << " ";
			cout << iddi1 << " ";

			cout << endl;


		}

	}
	}


}