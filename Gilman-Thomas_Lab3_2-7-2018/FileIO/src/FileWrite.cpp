#include "FileWrite.h"
/*
    FILEWRITE class functions
            Constructor
OPEN, CLOSE, WRITE, ISOPEN, WRITELINE
             ~Destruct
*/
FileWrite::FileWrite()
{};
void FileWrite::openFile(const std::string& filename)
{
    myFile.open(filename.c_str());
};
void FileWrite::closeFile()
{
    myFile.close();
};
void FileWrite::writeToFile(const std::string& filename)
{
    if(getIsOpen())
        closeFile();

    openFile(filename);
    std::string LineToInput;
    std::cout<<"Type to file "<<filename.c_str()<<" below: \n"<<std::endl;
    while(getIsOpen())
    {
        std::getline(std::cin,LineToInput);
        if(LineToInput == "escape")
            closeFile();

        writeLine(LineToInput+"\n");
    }
};
bool FileWrite::getIsOpen() //Returns True if the file is open
{
    return myFile.is_open();
};
bool FileWrite::writeLine(const std::string& line)
{
    if(getIsOpen()==false)
        return false;
    myFile.write(line.c_str(),sizeof(char)*line.size());
    return true;
};
FileWrite::~FileWrite()
{
    if(getIsOpen());
    {
        std::cout<<"file still open, closing now"<<std::endl;
        closeFile();
    }
    std::cout<<"goodbye!!"<<std::endl;
};
