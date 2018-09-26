#include "ChessBoard.h"

ChessBoard::ChessBoard(const std::string& fileName)
{
    myBoardFile = new FileRW(fileName);
    myBoard = new Piece**[8];
    for(int row = 0 ; row < 8 ; row++)
    {
        myBoard[row] = new Piece*[8];
        for(int col = 0 ; col < 8 ; col++)
        {
            if(row == 0 || row == 7)
            {
                if(col == 0 || col == 7) //rook
                {
                    if(row == 0) //white
                        myBoard[row][col] = new Piece(row,col,'R',white);
                    else
                        myBoard[row][col] = new Piece(row,col,'R',black);
                }
                else if(col == 1 || col == 6) //knight
                {
                    if(row == 0) //white
                        myBoard[row][col] = new Piece(row,col,'N',white);
                    else
                        myBoard[row][col] = new Piece(row,col,'N',black);
                }
                else if(col == 2 || col == 5) //Bishop
                {
                    if(row == 0) //white
                        myBoard[row][col] = new Piece(row,col,'B',white);
                    else
                        myBoard[row][col] = new Piece(row,col,'B',black);
                }
                else if(col == 3) //king
                {
                    if(row == 0)//white
                        myBoard[row][col] = new Piece(row,col,'K',white);
                    else
                        myBoard[row][col] = new Piece(row,col,'K',black);
                }
                else //Queen
                {
                    if(row == 0)
                        myBoard[row][col] = new Piece(row,col,'Q',white);
                    else
                        myBoard[row][col] = new Piece(row,col,'Q',black);
                }
            }
            else if(row == 1 || row == 6) //pawns
            {
                if(row == 1)//white
                    myBoard[row][col] = new Piece(row,col,'P',white);
                else
                    myBoard[row][col] = new Piece(row,col,'P',black);
            }
            else
                myBoard[row][col] = new Piece(row,col); //blank spot
        }
    }
};
void ChessBoard::movePiece(int row, int col, Piece* pieceMoved)
{
    int oldRow = pieceMoved->getRow(), oldCol = pieceMoved->getCol();
    char pieceType = pieceMoved->getType();
    Color pieceColor = pieceMoved->getColor();
    bool canMove = false;

    switch(pieceType)
    {
    case('P'): //Pawn
        if(pieceColor == black && row == oldRow+1 && col == oldCol)
        {
            canMove = true;
        }
        else if(pieceColor == white && row == oldRow-1 && col == oldCol)
        {
            canMove = true;
        }
        break;
    case('R'): //Rook
        if((pieceColor == black || pieceColor == white) && (((row > oldRow || row < oldRow) && col == oldCol)
           || (row == oldRow && (col > oldCol || col < oldCol))))
        {
            canMove = true;
        }
        break;
    case('N'): //Knight
        if((pieceColor == black || pieceColor == white) &&
           (((row == oldRow+2 || row == oldRow-2) && (col == oldCol+1 || col == oldCol-1)) ||
           ((row == oldRow+1 || row == oldRow-1) && (col == oldCol+2 || col == oldCol-2))) )
        {
            canMove = true;
        }
        break;
    case('B'): //Bishop
        if((pieceColor == black || pieceColor == white))
        {
            for(short i = 0 ; i < 8 ; i++)
            {
                if(((row == oldRow+i || row == oldRow-i) && (col == oldCol+i || col == oldCol-i)))
                    canMove = true;
            }
        }
        break;
    case('Q'): //Queen
        if((pieceColor == black || pieceColor == white))
        {
            for(short i = 0 ; i < 8 ; i++)
            {
                if(((row == oldRow+i || row == oldRow-i) && (col == oldCol+i || col == oldCol-i))||
                    ((pieceColor == black || pieceColor == white) &&
                    (((row == oldRow+2 || row == oldRow-2) && (col == oldCol+1 || col == oldCol-1)) ||
                    ((row == oldRow+1 || row == oldRow-1) && (col == oldCol+2 || col == oldCol-2)))))
                {
                    canMove = true;
                }
            }
        }
        break;
    case('K'): //King
        if((pieceColor == black || pieceColor == white)
           && ((row == oldRow || row == oldRow+1 || row == oldRow-1)
           && (col == oldCol+1 || col == oldCol-1)))
        {
            if(row!= oldRow && col!= oldCol)
                canMove = true;
        }
        break;
    }
    if(canMove==true)
    {
        pieceMoved->setRow(row); pieceMoved->setCol(col);

        myBoard[row][col] = pieceMoved; //change the piece spot
        myBoard[oldRow][oldCol] = new Piece(oldRow, oldCol);
    }
    else
        std::cout<<"spot wanting to be moved to is either out of range of piece or is not legal"<<std::endl;
};
void ChessBoard::getMove(FileRW *FileIter)
{
    /*int row = 0, col = 0;
    int *myPtr;
    char PieceType='P';
    while(FileIter->getIsOpen())
    {
        std::string LineLookedAt = FileIter->LineLookedAt;
        myPtr = LineLookedAt;
        while(myPtr++ != "\n")
        {
            if(*myPtr >= 'A' || *myPtr <= 'H')//col
                col = *myPtr - 65;
            else if(*myPtr >= 0 || *myPtr <= 7)//row
                row = *myPtr;
            else if(*myPtr == 'N' || *myPtr == 'R' || *myPtr == 'B' || *myPtr == 'Q' || *myPtr == 'K')//pieceType
                PieceType = *myPtr;
            if(*myPtr == ',' || *myPtr == ' ')//space or comma between moves
            {

            }
        }
    }*/
};
void ChessBoard::printBoard()
{
    FileRW *myBoardFile = new FileRW("newBoardFile.txt");
    for(int r = 0 ; r < 8 ; r++)
    {
        for(int c = 0 ; c < 8 ; c++)
        {
            if(myBoard[r][c]->getColor() == black)
                myBoardFile->appendFile('B');
            else if(myBoard[r][c]->getColor() == white)
                myBoardFile->appendFile('W');
            else
                myBoardFile->appendFile('_');
            myBoardFile->appendFile(myBoard[r][c]->getType()); //cast a char as a string
            myBoardFile->appendFile(' ');
        }
        myBoardFile->appendFile('\n');
    }
    myBoardFile->appendFile('\n');
    delete myBoardFile;
};
void ChessBoard::printBoard(const std::string& fileName) //prints out the contents of the file
{
    if(!myBoardFile->getIsOpen())
        myBoardFile->changeFile(fileName);
    myBoardFile->fileReader();
};
ChessBoard::~ChessBoard()
{
    for(short r = 0 ; r < 8 ; r++)//deletes the 2d array of Piece object
    {
        for(short c = 0 ; c < 8 ; c++)
            delete myBoard[r][c]; //deletes the 2d array of Piece object
    }
    delete myBoard;
    delete myBoardFile;
};
