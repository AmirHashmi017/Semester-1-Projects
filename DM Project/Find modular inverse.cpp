#include<iostream>
using namespace std;
void findBezoutCoefficients(int num1, int num2); 
void findinverse(int s,int t,int smallnumber,int largenumber);
main() 
{
    int num1, num2;
    cout << "Enter 1st number: ";
    cin >> num1;
    cout << "Enter 2nd number: ";
    cin >> num2;
    findBezoutCoefficients(num1,num2); 
}
//This function will calculate the bezout coefficients.
void findBezoutCoefficients(int num1, int num2) 
{
    int dividend, divisor,gcd,s,t;
    int olds,oldt,quotient,bez;
    /*These if statements will check which number from two enter numbers is greater.
    And assign the greater number to dividend and smaller one to divisor.*/
    if (num1 > num2) 
	{
    dividend = num1;
    divisor = num2;
    } 
	else if (num1 < num2) 
	{
    dividend = num2;
    divisor = num1;
    } 
    else if(num1=num2)
	{
		gcd=num1;
	}
	int smallnumber=divisor;
	int largenumber=dividend;
    s=0;
    olds=1;
    t=1;
    oldt=0;
    //This while loop will calculate both GCD and bezout coefficients.
    while(dividend%divisor!=0&&num1!=num2)
	{
        quotient=dividend/divisor;
        bez=s;
        s=olds-quotient*s;
        olds=bez;
        bez=t;
        t=oldt-quotient*t;
        oldt=bez;
        gcd=dividend%divisor;
        dividend=divisor;
        divisor=gcd;
    }
    /*This if statement will check that GCD is equal to 1 or not.
    If GCD=1 then the program will calculate inverse otherwise, 
    the program will print message inverse does'nt exist.*/
	if(gcd==1)
	findinverse(s,t,smallnumber,largenumber);
	else
	cout<<"Inverse does not exist.";
}
//This function will take bezout coefficients and find which one is inverse.
void findinverse(int s,int t,int smallnumber,int largenumber)
{
	int bezout1,bezout2;
	if(s<0)
	bezout1=-1*(smallnumber*s-1);
	else
	bezout1=smallnumber*s-1;
	if(s<0)
	bezout2=-1*(smallnumber*t-1);
	else
	bezout2=smallnumber*t-1;
	/*These if statements will check that which bezout coefficient is satisfying,
	thoerem: m|a-b and will declare that bezout coefficient as inverse.*/
	if(bezout1%largenumber==0)
	cout<<"Modular Inverse= "<<s;
	if(bezout2%largenumber==0)
	cout<<"Modular Inverse= "<<t;
}
