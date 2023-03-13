#include <iostream>
#include <iterator>
#include <cstdlib>

using namespace std;

class Wielomian
{
private:
	int i = 0;
	int deg1;
	int deg2;
	int poly1[10];
	int poly2[10];

public:
	void Get();
	void Add();
	void Subtract();
	void Multiply();
	void Polyvalue(double, double);
};

void Wielomian::Get()
{

	cout << "Podaj stopien wielomianu : " << endl;
	cin >> deg1;

	cout << "Podaj wspolczynniki wielomianu : " << endl;
	for (int j = 0; j <= deg1; j++)
	{
		cin >> poly1[j];
	}

	cout << "Podaj stopien wielomianu 2 : " << endl;
	cin >> deg2;

	cout << "Podaj wspolczynniki wielomianu 2: " << endl;
	for (int j = 0; j <= deg2; j++)
	{
		cin >> poly2[j];
	}

	cout << "\n"

	//Wypisanie wielomianu 1
		 << "Wielomian 1: ";
	if(poly1[deg1] != 0){ cout << poly1[deg1] << "x^" << deg1;}

	for (int j = deg1 - 1; j > 0; j--)
	{

		if(poly1[j] != 0){
			if (poly1[j] > 0)
			{	
				cout << " + " << poly1[j] << "x^" << j;
			}
			else
			{
				cout << " - " << abs(poly1[j]) << "x^" << j;
			}
		}
	}

	if(poly1[0] != 0){
		if (poly1[0] > 0)
		{
			cout << " + " << poly1[0] << endl;
		}
		else
		{
			cout << " - " << abs(poly1[0]) << endl;
		}
	}	

	// Wypisanie wielomianu 2
	cout << "Wielomian 2: ";
	if(poly2[deg2] != 0){ cout << poly2[deg2] << "x^" << deg2;}

	for (int j = deg2 - 1; j > 0; j--)
	{
		if(poly2[j] != 0){
			if (poly2[j] > 0)
			{	
				cout << " + " << poly2[j] << "x^" << j;
			}
			else
			{
				cout << " - " << abs(poly2[j]) << "x^" << j;
			}
		}	
	}
	if(poly2[0] != 0){
		if (poly2[0] > 0)
		{
			cout << " + " << poly2[0] << endl;
		}
		else
		{
			cout << " - " << abs(poly2[0]) << endl;
		}
	}
}

void Wielomian::Add()
{
	//Obliczenie sumy wielomianu
	int max = deg1 > deg2 ? deg1 : deg2;
	int sum[max];

	for (int j = 0; j <= max; j++)
	{

		if (poly1[j] == 0){ sum[j] = poly2[j]; }
		else if (poly2[j] == 0){ sum[j] = poly1[j]; }
		else if (j <= deg1 && j <= deg2){ sum[j] = poly1[j] + poly2[j]; }
		else if (j <= deg1 && j >= deg2){ sum[j] = poly1[j]; }
		else{ sum[j] = poly2[j]; }

	}

	//Wypisanie sumy wielomianow
	cout << "Suma wielomianow : ";
	if(sum[max] != 0){
		cout << sum[max] << "x^" << max;
	}
	for (int j = max - 1; j > 0; j--)
	{

		if (sum[j] != 0)
		{
			if (sum[j] > 0)
			{
				cout << " + " << sum[j] << "x^" << j;
			}
			else
			{
				cout << " - " << abs(sum[j]) << "x^" << j;
			}
		}
	}
	if(sum[0] != 0){
		if (sum[0] > 0)
		{
			cout << " + " << sum[0] << endl;
		}
		else
		{
			cout << " - " << abs(sum[0]) << endl;
		}
	}
	cout<<endl;
}

void Wielomian::Subtract()
{
	//Obliczenie roznicy wielomianow
	int max = deg1 > deg2 ? deg1 : deg2;
	int diff[max];

	for (int j = 0; j <= max; j++)
	{

		if (poly2[j] == 0){ diff[j] = poly1[j]; }
		else if (poly1[j] == 0){ diff[j] = poly2[j]; }
		else if (j <= deg1 && j <= deg2) { diff[j] = poly1[j] - poly2[j]; }
		else if (j <= deg1 && j >= deg2) { diff[j] = poly1[j]; }
		else { diff[j] = poly2[j]; }

	}

	//Wypisanie roznicy wielomianow
	cout << "Roznica wielomianow : ";
	if(diff[max] != 0){
		cout << diff[max] << "x^" << max;
	}	
	for (int j = max - 1; j > 0; j--)
	{
		if (diff[j] != 0)
		{
			if (diff[j] > 0)
			{
				cout << " + " << diff[j] << "x^" << j;
			}
			else
			{
				cout << " - " << abs(diff[j]) << "x^" << j;
			}
		}
	}
	if(diff[0] != 0){
		if (diff[0] > 0)
		{
			cout << " + " << diff[0] << endl;
		}
		else
		{
			cout << " - " << abs(diff[0]) << endl;
		}
	}	
}

void Wielomian::Multiply()
{
	
	int prod[deg1 + deg2 + 1];

	for (int i = 0; i<=deg1+deg2; i++){
    	prod[i] = 0;		//zainicjowanie zerami tablicy ktora bedzie zawierac iloczyny
	}

	//Obliczenie iloczynu
	for(int n = 0; n <= deg1; n++){
		for(int m = 0; m <= deg2; m++){
			if(poly1[n]*poly2[m] != 0){
				prod[n + m] += poly1[n]*poly2[m];
			}
		}
	}

	cout << "\n"

	//Wypisanie iloczynu wielomianow
		 << "Iloczyn: ";
	if(prod[deg1 + deg2] != 0){
		cout << prod[deg1 + deg2] << "x^" << deg1+deg2;
	}

	for (int j = deg1 + deg2 - 1; j > 0; j--)
	{

		if (prod[j] > 0)
		{
			cout << " + " << prod[j] << "x^" << j;
		}
		else if (prod[j] < 0)
		{
			cout << " - " << abs(prod[j]) << "x^" << j;
		}
		else
		{
			continue;
		}
	}

	if(prod[0] != 0){
		if (prod[0] > 0)
		{
			cout << " + " << prod[0] << endl;
		}
		else
		{
			cout << " - " << abs(prod[0]) << endl;
		}
	}
}

void Wielomian::Polyvalue(double arg1, double arg2)
{
	//Obliczenie wartosci wielomianu stosujac schemat Hornera

	//Zainicjowanie value1 oraz value2 wspolczynnikiem wielomianu przy najwyzszej potedze 
	int value1 = poly1[deg1];
	int value2 = poly2[deg2];

	for(int i = deg1-1 ; i >= 0; i--)
	{
		value1 = value1*arg1 + poly1[i];	//mnozymy wartosc przez argument oraz dodajemy wspolczynnik przy nizszej potedze
	}	

	for(int i = deg2-1; i >= 0; i--)
	{
		value2 = value2*arg2 + poly2[i];
	}	

	cout<<"Wartosc pierwszego wielomiany to : "<<value1<< "\n" << "Wartosc drugiego wielomianu to : "<<value2<<endl;	
	
}

int main()
{

	Wielomian s;

	double arg1;
	double arg2;
	s.Get();
	s.Add();
	s.Subtract();
	s.Multiply();
	cout<<"Podaj argument wielomianu 1: ";
	cin>>arg1;
	cout<<"\n"<<"Podaj argument wielomianu 2: ";
	cin>>arg2;
	s.Polyvalue(arg1, arg2);
	

	return 0;
}