#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#pragma once
template<typename N>
class Number
{
public:
	Number(N passedNumber, int Base = 2);
	void reverse(std::vector<char>* passedVec);
	std::string Convert();
	virtual ~Number();
private:
	N numToConvert;
	int myBase;
	std::vector<char> myString;	//empty string
	std::string stringToReturn; //string to return
};