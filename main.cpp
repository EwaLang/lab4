#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>

using namespace std;

string toString3(int n);
void toArray(int n, int l, int *digits);
string toString(int n);

int main(int argc, char const *argv[])
{
	int number = atoi(argv[1]);
	cout << toString(number)<<endl;
	return 0;
}


string toString3(int n) //
{
	string ones[] = {"jeden ", "dwa ", "trzy ", "cztery ", "pięć ", "sześć ", "siedem ", "osiem ", "dziewięć "};
	string tens[] = {"dziesięć ", "dwadzieścia ", "trzydzieści ", "czterdzieści ", "pięćdziesiąt ", "sześćdziesiąt ", "siedemdziesiąt ", "osiemdziesiąt ", "dziewięćdziesiąt "};
	string hundreds[] = {"sto ", "dwieście ", "trzysta ", "czterysta ", "pięćset ", "sześćset ", "siedemset ", "osiemset ", "dziewięćset "};
	string teens[] = {"jedenaście ", "dwanaście " , "trzynaście ", "czternaście ", "piętnaście ", "szesnaście ", "siedemnaście ", "osiemnaście ", "dziewiętnaście "};
	
	int* digits = new int[3];
	toArray(n, 3, digits);

	string result = "";
	//dla setek
	if (digits[0] > 0) result += hundreds[digits[0] - 1]; //
	//dla 11-19
	if (digits[1] > 0)
	{
		if ((digits[1] == 1) && (digits[2] != 0))
		{
			result += teens[digits[2] - 1]; 
			return result;
		}
		else result += tens[digits[1] - 1];
	}
	//dla 1-9
	if (digits[2] > 0)
	{
		result += (ones[digits[2] - 1] );
	}
	return result;
}

void toArray(int n, int l, int *digits)
{
	digits[0] = n / 100;
	digits[1] = (n / 10) % 10;
	digits[2] = n % 10;
}

string toString(int n)
{
	string place[2][3] = 	{{"milion ", "miliony ", "milionów " },
	{"tysiąc ",  "tysiące ",   "tysięcy " }};
	int* rank = new int[3];    //liczymy trójki każdej starszej liczby
	rank[0] = n / 1000000;
	rank[1] = n/ 1000 % 1000;
	rank[2] = n % 1000;
	string result = "";
	if (rank[0] > 0)
	{
		result += toString3(rank[0]);
		if (rank[0] / 10 % 10 == 1) result += place[0][2]; //-1-
		else
			switch (rank[0] % 10)
		{
			case 1:
			result += place[0][0];
			break;
			case 2 ... 4:
			result += place[0][1];
			break;
			case 0:
			case 5 ... 9:
			result += place[0][2];
			break;
		}
	}
	if (rank[1] > 0)
	{
		result += toString3(rank[1]);
		if (rank[1] / 10 % 10 == 1) result += place[1][2]; //-2-
		else switch (rank[1] % 10)
		{
			case 1:
			result += place[1][0];
			break;
			case 2 ... 4:
			result += place[1][1];
			break;
			case 0:
			case 5 ... 9:
			result += place[1][2];
			break;
		}
	}
	result += toString3(rank[2]);
	return result;
}

