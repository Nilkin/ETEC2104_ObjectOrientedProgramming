#include "stdafx.h"
#include "Number.h"

using namespace std;

float NumToConvert = 32.53, Base = 15;

int main()
{
	Number<float> *NumToComp = new Number<float>(NumToConvert, Base);

	cout << "myBase:" << to_string(Base) << " Number Converted: ";
	cout << NumToComp->Convert() << "\n" << endl;

	delete NumToComp;

	return 0;
}