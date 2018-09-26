#ifndef PIECE_H
#define PIECE_H

enum Color{white, black, blank};
class Piece
{
    public:
        Piece(int rowVal, int colVal, char typeOfPiece, Color Color);
        Piece(int rowVal, int colVal); //No piece at spot
        void setType(char newType);
        void setEnum(Color Color);
        void setRow(int newRowVal);
        void setCol(int newColVal);
        int getRow();
        int getCol();
        Color getColor();
        char getType();
        virtual ~Piece();
    private:
        char myType;
        int myRow, myCol;
        Color myColor;
};

#endif // PIECE_H
