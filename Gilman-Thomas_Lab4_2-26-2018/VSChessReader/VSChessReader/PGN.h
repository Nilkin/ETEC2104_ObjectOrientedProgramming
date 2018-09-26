#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#pragma once
class PGN
{
public:
	PGN(const char* filePATH);
	std::string getMove();
	int getIndex();
	int getVectorSize();
	~PGN();
private:
	int moveIndex = 0;
	std::vector<std::string> moveHistory;
	std::string::size_type posIndex = 0, prevIndex = 0;
};

