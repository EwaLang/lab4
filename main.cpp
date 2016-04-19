#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <vector>

using namespace std;

string toString3(int n);
void toArray(int n, int l, int *digits);
void toArray_(int n, int l, vector<int>& v);
string toString(int n);
void findNumber(int n);
int count (int n);
bool check(int p, vector<int>& v);

int main(int argc, char const *argv[])
{
	int number = atoi(argv[1]);
	cout << toString(number) << endl;
	findNumber(number);
	return 0;
}


void findNumber(int n)
{
	int k, l, i = 1;
	std::vector<int> v;
	bool found = false;
	while(!found)
	{
		k = n * i;
		l = count(k);
		toArray_(k, l, v);
		if(check(k, v))
		{
			found = true;
			cout << "Poszukiwane k to: " << i << endl;
			cout << "czyli " << toString(i) << endl;
			cout << "Iloczyn n*k to: " << k << endl;
			cout << "czyli " << toString(k) << endl;
		}
		v.clear();
		i++;
	}
}

int count (int n)
{
	int counter = 0;
	while (n > 0)
	{
		n /= 10;
		counter++;
	}
	return counter;
}

void toArray_(int n, int l, vector<int>& v)
{
	int b = 10;
	int w;
	for (int i = 0; i < l; ++i)
	{
		w = pow(b, i);
		v.push_back((n / w) % b);
	}
}

bool check(int p, vector<int>& v)
{
	int l = v.size();
	int counter = 0;
	for (int i = 0; i < l; ++i)
	{
		if (v[i] == 1 || v[i] == 0)
		{
			counter++;
		}
	}
	if (counter == v.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

string toString3(int n) //
{
	string ones[] = {"jeden ", "dwa ", "trzy ", "cztery ", "piec ", "szesc ", "siedem ", "osiem ", "dziewiec "};
	string tens[] = {"dziesiec ", "dwadziescia ", "trzydziesci ", "czterdziesci ", "piecdziesiat ", "szescdziesiat ", "siedemdziesiat ", "osiemdziesiat ", "dziewiecdziesiat "};
	string hundreds[] = {"sto ", "dwiescie ", "trzysta ", "czterysta ", "piecset ", "szescset ", "siedemset ", "osiemset ", "dziewiecset "};
	string teens[] = {"jedenascie ", "dwanascie " , "trzynascie ", "czternascie ", "pietnascie ", "szesnascie ", "siedemnascie ", "osiemnascie ", "dziewietnascie "};

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
	{"tysiac ",  "tysiace ",   "tysiecy " }
};
	int* rank = new int[3];    //liczymy trójki kazdej starszej liczby
	rank[0] = n / 1000000;
	rank[1] = n / 1000 % 1000;
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
