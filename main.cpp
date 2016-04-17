#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>

using namespace std;

	const string ones[] ={"jeden ", "dwa ", "trzy ", "cztery ", "pięć ", "sześć ", "siedem ", "osiem ", "dziewięć "}; 
	const string teens[] = {"dziesięć ", "jedenaście ", "dwanaście " ,"trzynaście ","czternaście ","piętnaście ","szesnaście ","siedemnaście ","osiemnaście ", "dziewiętnaście "}; 
	const string tens[] = {"dwadzieścia ", "trzydzieści ", "czterdzieści ", "pięćdziesiąt ", "sześćdziesiąt ", "siedemdziesiąt ", "osiemdziesiąt ", "dziewięćdziesiąt "};
	const string hundreds[] = {"sto ", "dwieście ","trzysta ", "czterysta ","pięćset ","sześćset ", "siedemset ", "osiemset ", "dziewięćset "};
	//2-4
	const string thousand[] = {"tysiąc ", "tysiące ", "tysięcy "};
	//2-4
	const string million[] = {"milion ", "miliony ", "milionów "};

int count (int n);
void toArray(int n, int l, int *digits);
void toString(int length, int *digits);
string tens_(int length, int *digits, string& result);
string hundreds_(int length, int *digits, string& result);
string ones_(int length, int *digits, string& result);


int main(int argc, char const *argv[])
{
	int number = atoi(argv[1]);
	int length = count(number);
	//cout<<"digits num is:"<<length<<endl;

	int* digits = new int[length];
	toArray(number, length, digits);
	toString(	length, digits);
}
int count (int n){
	int counter = 0;
	while (n>0){
		n/=10;
		counter++;	
	}
	return counter;
}

void toArray(int n, int l, int *digits){
	int b=10;
	int w;
	for (int i = 0; i < l; ++i)
	{
		w=pow(b,i);
		digits[l-i-1] = (n/w)%b;
	}
}

void toString(int length, int *digits){
	for (int i = 0; i < length; ++i)
	{
		if (i==0)
		{
			cout<<"in array: ";
		}
		cout<<digits[i];
		if (i==length-1)
		{
			cout<<endl;
		}
	}
	string result = "";
	switch (length){
		case 1:
		result = ones_(length, digits, result);
			break;
		case 2:
			result = tens_(length, digits, result);
			break;
		case 3:
			result = hundreds_(length, digits, result);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			break;
	}
	cout<<"num is: "<<result<<endl;
}

string ones_(int length, int *digits, string& result){
	return result = ones[digits[0]-1];
}

string tens_(int length, int *digits, string& result){
//dla 10-19
			if (digits[0]==1)
			{
				result = teens[digits[1]];
			}else{
		//dla 20,30...90		
				if (digits[1]==0)
				{
					result = tens[digits[0]-2];
				}
		//21-99
				else{
					result = tens[digits[0]-2] + ones[digits[1]-1];
				}
			}
return result;
}

string hundreds_(int length, int *digits, string& result){
	//dla 100,200...
	if (digits[1]==0 && digits[2]==0)
	{
		result = hundreds[digits[0]-1];
	}
	//dla 101-109
	else if(digits[1]==0){
		result = hundreds[digits[0]-1]+ones[digits[2]-1];
	}
	//dla 111-999
	else{
		int* tailD = new int[2];
		string tailS = "";
    	std::copy( digits+1, digits+2, tailS);
    	for (int i = 0; i < 2; ++i)
    	{
    		cout<<"tail is :"<<tailD[i]<<endl;
    	}
		result = hundreds[digits[0]-1]+tens_(length, tailD, tailS);
	}
return result;
}