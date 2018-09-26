#include "FileRead.h"
/*
    FILEREAD class functions
            Constructor
READER, Open, ISOPEN, READLINE, GETLINE
             ~Destruct
*/
FileRead::FileRead()
{
    std::cout<<"IM IN READER CONSTRUCTOR"<<std::endl;
};
void FileRead::Reader(const std::string& fileName)
{
    if(getIsOpen()==false) //file is not open yet
        openFile(fileName);
    while(getIsOpen()&&readLine())
    {
        std::cout<<getLine()<<std::endl;
    }
    closeFile();
};
void FileRead::openFile(const std::string& fileName)
{
    myFile.open(fileName.c_str()); //opens the file specified
};
void FileRead::closeFile()
{
    myFile.close();
};
bool FileRead::getIsOpen()
{
    return myFile.is_open();
};
bool FileRead::readLine()
{
    if(std::getline(myFile,LineLookedAt).good())
        return true;
    return false;
};
const std::string& FileRead::getLine()
{
    return LineLookedAt;
};
FileRead::~FileRead()
{
    if(getIsOpen())
    {
        std::cout<<" still open closing now."<<std::endl;
        closeFile();
    }
    std::cout<<"Goodbye"<<std::endl;
};
