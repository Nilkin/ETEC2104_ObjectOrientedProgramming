#include "stdafx.h"
#include "PGN.h"


PGN::PGN(const char* filePATH)
{
	std::ifstream file(filePATH);
	std::string moves((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());	//fill string with chars in file
	while ((posIndex = moves.find(std::string("\n"), prevIndex)) != std::string::npos)				//parse the file for each set of moves
	{
		moveHistory.push_back(moves.substr(prevIndex, posIndex - prevIndex));
		prevIndex = posIndex + 1;
	}
	moveHistory.push_back(moves.substr(prevIndex));
};
std::string PGN::getMove()
{
	return moveHistory.at(moveIndex++);
};
int PGN::getIndex()
{
	return moveIndex;
};
int PGN::getVectorSize()
{
	return moveHistory.size() - 1;
};
PGN::~PGN()
{
};
