#include <fstream>
#include <iostream>
#include <FileRW.h>
#include <string.h>
#include <ChessBoard.h>

using namespace std;

string myFileName = "newText.txt";
bool writing = true;
char userInput[32];

int main()
{
    //FileRW *myTestFile = new FileRW(myFileName);
    //myTestFile->fileReader();
    std::cout<<"\nFINISHED writing and reading from file"<<std::endl;
    //delete myTestFile;
    ChessBoard *myBoard = new ChessBoard();
    myBoard->printBoard();
    myBoard->printBoard("newBoardFile.txt");
    while(writing)
    {
        std::cout<<"if you want to make a move press enter, otherwise type quite\n"<<
        fgets(userInput,sizeof(userInput),stdin);
        if(userInput=="quite\n")
            writing = false;

    }
    delete myBoard;
    return 0;
}
