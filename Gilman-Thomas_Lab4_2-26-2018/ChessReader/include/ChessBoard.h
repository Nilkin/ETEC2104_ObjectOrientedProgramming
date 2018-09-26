#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <iostream>
#include <Piece.h>
#include <FileRW.h>

class ChessBoard
{
    public:
        ChessBoard(const std::string& fileName="newChessBoard.txt");
        void movePiece(int row, int col, Piece* pieceMoved);
        void getMove(int *FileIter);
        void printBoard();
        void printBoard(const std::string& fileName);
        Piece getPiece(int row, int col);
        virtual ~ChessBoard();
    private:
        Piece*** myBoard; //A 2by2 array of Piece objects
        FileRW *myBoardFile; //my BOARD.txt
};

#endif // CHESSBOARD_H
