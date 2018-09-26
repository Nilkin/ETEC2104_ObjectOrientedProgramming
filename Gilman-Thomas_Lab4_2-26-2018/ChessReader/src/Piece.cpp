#include "Piece.h"

Piece::Piece(int rowVal, int colVal, char typeOfPiece, Color Color)
{
    myRow = rowVal; myCol = colVal; //Position of Piece
    myType = typeOfPiece;           //Piece type
    myColor = Color;                //Piece color either black or white
};
Piece::Piece(int rowVal, int colVal)
{
    myRow = rowVal; myCol = colVal;
    myType = '_';
    myColor = blank;
}
void Piece::setEnum(Color Color)
{
    myColor = Color;
}
void Piece::setType(char newType)
{
    if(myType != newType)
        myType = newType;
};
void Piece::setRow(int newRowVal)
{
    myRow = newRowVal;
};
void Piece::setCol(int newColVal)
{
    myCol = newColVal;
};
int Piece::getRow()
{
    return myRow;
};
int Piece::getCol()
{
    return myCol;
}
Color Piece::getColor()
{
    return myColor;
}
char Piece::getType()
{
    return myType;
};
Piece::~Piece()
{};
