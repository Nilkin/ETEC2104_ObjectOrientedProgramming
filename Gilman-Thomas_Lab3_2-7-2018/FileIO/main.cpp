#include <fstream>
#include <iostream>
#include <FileWrite.h>
#include <FileRead.h>

using namespace std;

std::string myReaderFile = "Hello.txt", myWriterToFile = "newFile.txt";

int main()
{
    FileRead *myReader = new FileRead();
    FileWrite *myWriter = new FileWrite();
    myReader->Reader(myReaderFile);
    myWriter->writeToFile(myWriterToFile);
    cout << "Your Out!" << endl;
    delete myReader; delete myWriter; //delete pointer variables
    return 0;
}
