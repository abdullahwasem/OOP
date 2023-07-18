// muhammad abdullah waseem 
// assignment 2 
// complex numbers 
#include <iostream>
#include <cmath>

using namespace std;

class ComplexNumber
{
private:
    int real;
    int imaginary;

public:

    ComplexNumber(int, int); //with default arguments
 //~ComplexNumber(); //Does Nothing.
    void Input();
    void Output();
    bool IsEqual(ComplexNumber);
    ComplexNumber Conjugate();
    ComplexNumber Add(ComplexNumber);
    ComplexNumber Subtract(ComplexNumber);
    ComplexNumber Multiplication(ComplexNumber);
    float Magnitude();




};

ComplexNumber::ComplexNumber(int r, int i)
{
    real = r;

    imaginary = i;
};



void ComplexNumber::Input()
{
    cout << "enter real :  ";
    cin >> real;
    cout << endl;
    cout << "enter imaginary :  ";
    cin >> imaginary;

}


void ComplexNumber::Output()
{

    if (imaginary >= 0) {
        cout << real << " +" << imaginary << "i" << endl;
    }
    else {
        cout << real << " " << imaginary << "i" << endl;
    }
}

bool ComplexNumber :: IsEqual(ComplexNumber c2)
{
    if (real== c2.real)

    {
        if (imaginary == c2.imaginary)
        {
            cout << endl;
            cout << "both c1 and c2 are equal \n";
            return 1; 
        }
    }

    else {
        cout << " both c1 and c2 are  not equal \n";
        return 0; 
    }
   }
  
ComplexNumber ComplexNumber:: Conjugate()
{
    ComplexNumber c1(0,0);
    imaginary = -imaginary;
    if (imaginary > 0) {
        cout << real << "+ " << imaginary<<"i" << endl;
    }
    else {
        cout << real << " " << imaginary<<"i" << endl;
    }

    return  c1 ;
    
}

ComplexNumber ComplexNumber::Add(ComplexNumber c2)
{
    ComplexNumber c1(0, 0); 
    imaginary = imaginary * -1;
    c2.imaginary = c2.imaginary * -1;
    real = real + c2.real;
    imaginary = imaginary +( c2.imaginary);


    if (imaginary >= 0) {
        cout <<"C1 + C2 = " << real << " +" << imaginary << "i" << endl;
    }
    else {
        cout<<"C1 + C2 = " << real << " " << imaginary << "i" << endl;
    }
    

    return c1; 

}


ComplexNumber ComplexNumber::Subtract(ComplexNumber c2)
{

    ComplexNumber c1(0, 0);
    
    c2.imaginary = c2.imaginary * -1;
    real = real - c2.real;
    imaginary = imaginary - (c2.imaginary);

    real = real - c2.real;
    imaginary = imaginary - (c2.imaginary);


    if (imaginary >= 0) {
        cout << "C1 - C2 = " << real << " +" << imaginary << "i" << endl;
    }
    else {
        cout << "C1 - C2 = " << real << " " << imaginary << "i" << endl;
    }

     
    return c1;
}

ComplexNumber  ComplexNumber::Multiplication(ComplexNumber c2)
{
    int ca, cb, c2a, c2b;
    ComplexNumber c1(0, 0); 
 c2.imaginary = c2.imaginary * -1;
    real = real + c2.real;
    imaginary = imaginary + (c2.imaginary);
    ca = real; 
    cb = imaginary; 
    c2a = c2.real; 
    c2b = c2.imaginary; 
    real = (ca * c2a) + (cb * (-1 * c2b)); 
    imaginary = (ca * c2b) + (cb * c2a); 
   

    if (imaginary >= 0) {
        cout << "C1 x C2 = " << real << " +" << imaginary<<"i" << endl;
    }
    else {
        cout << "C1 x C2 = " << real << " " << imaginary<<"i" << endl;
    }
    real = ca;
    imaginary = cb; 
    c2.real = c2a; 
    c2.imaginary = c2b; 


    return c1; 

}

float ComplexNumber::Magnitude()
{
    float MAG; 
    real = pow(real, 2); 
    imaginary = pow(imaginary, 2); 
    MAG = sqrt((real + imaginary)); 
    cout << MAG << endl; 
    return MAG; 

}





int main()
{
    
    ComplexNumber c1(7, 8), c2(7, 8);
    cout << "enter c1 :  \n";
    c1.Input();
    cout << "enter c2 :  \n";
    c2.Input();
    cout << "c1 =  ";

    c1.Output();
    cout << "c2 =   ";
    c2.Output();
    c1.IsEqual(c2); 
    cout << "the conjugate of c1 is =  "; 
    c1.Conjugate();
    cout << "the conjugate of c2 is =   ";
    c2.Conjugate();
    c1.Add(c2);
    c1.Subtract(c2); 
    c1.Multiplication(c2); 
    cout << "MAGNITUDE OF C1 = ";
    c1.Magnitude();
    cout << "MAGNITUDE OF C2 = ";
    c2.Magnitude(); 




   


    return 0;
}
