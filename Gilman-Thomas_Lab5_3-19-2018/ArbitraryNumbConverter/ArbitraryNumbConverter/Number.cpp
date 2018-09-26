#include "stdafx.h"
#include "Number.h"

template<typename N>
Number<N>::Number(N passedNumber, int Base)
{
	numToConvert = passedNumber;
	myBase = Base;
};
template<typename N>
void Number<N>::reverse(std::vector<char>* passedVec)
{
	std::vector<char>::iterator vecBeg = passedVec->begin(), vecFin = passedVec->end() - 1;
	while (vecBeg < vecFin)
		std::swap(*vecBeg++, *vecFin--);
};
template<typename N> 
std::string Number<N>::Convert()
{
	int index = 0;
	N firstNum = 0, secondNum = 0;
	bool negative = false;
	N remaining;

	if (numToConvert == 0)
	{
		myString.push_back('0');
		myString.push_back('\0');
		for (std::vector<char>::iterator begining = myString.begin(); begining < myString.end(); begining++)
			stringToReturn.push_back(*begining);
		stringToReturn.push_back('\0');
		return stringToReturn;
	}
	if (numToConvert < 0)
		negative = true;

	if (std::string(typeid(N).name()) == "float" || std::string(typeid(N).name()) == "double")
	{
		//Seperate the Number based off its decimal point
		std::string firstHalf = std::to_string(numToConvert);
		firstHalf.erase(firstHalf.begin() + firstHalf.find('.'), firstHalf.end());				//erase the decimal point and everything after

		std::string secondHalf = std::to_string(numToConvert);
		secondHalf.erase(secondHalf.begin(), secondHalf.begin() + secondHalf.find('.') + 1);	//erase up to the decimal point

		std::cout << "\nfirst half:" << firstHalf << "\n" << "second half:" << secondHalf << std::endl;

		std::string::iterator begining = secondHalf.begin(), fin = secondHalf.end() - 1;
		while (begining < fin)
			std::swap(*begining++, *fin--); //swap the items at each index

		std::cout << "Second half reversed: " << secondHalf << "\n" << std::endl;

		int firstNum = std::stoi(firstHalf), secondNum = std::stoi(secondHalf);

		while (secondNum != 0)
		{
			remaining = fmod(secondNum, myBase);
			myString.push_back((remaining > 9) ? (remaining - 10) + 'a' : remaining + '0');
			secondNum = secondNum / myBase;
		}
		reverse(&myString);

		myString.push_back('.');
		while (firstNum != 0)
		{
			remaining = firstNum % myBase;
			myString.push_back((remaining > 9) ? (remaining - 10) + 'a' : remaining + '0');
			firstNum = firstNum / myBase;
		}
		if (negative)
			myString.push_back('-');	//Number is negative
		reverse(&myString);
	}
	else
	{
		while (numToConvert != 0)
		{
			remaining = (int)fmod(numToConvert, myBase);
			myString.push_back((remaining > 9) ? (remaining - 10) + 'a' : remaining + '0');
			numToConvert = numToConvert / myBase;
		}
		if (negative)
			myString.push_back('-');	//Number is negative
		reverse(&myString);
	}
	//PRINT THE CONVERTED VALUE
	for (std::vector<char>::iterator begining = myString.begin(); begining < myString.end(); begining++)
		stringToReturn.push_back(*begining);
	stringToReturn.push_back('\0');

	return stringToReturn;
};
template<typename N> 
Number<N>::~Number()
{};

template class Number<int>;
template class Number<float>;
template class Number<double>;
template class Number<long>;
template class Number<long long>;