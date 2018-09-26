#include "FileRW.h"
/*
       FILERW class functions
            Constructor
OPEN, CLOSE, WRITE, ISOPEN, WRITELINE
    READLINE, GETLINE, CHANGEFILE
             ~Destruct
*/
FileRW::FileRW(const std::string& filename="NewTextFile.txt")
{
    myFileName = filename;
};
void FileRW::changeFileType(std::string mode)
{
    if(mode=="out")
        myFile.open(myFileName.c_str(), std::ios::out);
    if(mode=="in")
        myFile.open(myFileName.c_str(), std::ios::in);
    if(mode=="app")
        myFile.open(myFileName.c_str(), std::ios::app);
};
void FileRW::closeFile()
{
    myFile.close();
};
void FileRW::changeFile(const std::string& filename)
{
  closeFile();
  myFileName = filename;
  changeFileType("in");
};
void FileRW::fileReader()
{
    if(getIsOpen()) //file is not open yet
        closeFile();
    changeFileType("in");
    while(getIsOpen() && readLine())
    {
        std::cout<<getLine()<<std::endl;
    }
    closeFile();
};
void FileRW::writeToFile()
{
    if(getIsOpen())
        closeFile();
    changeFileType("out");
    std::string LineToInput;
    std::cout<<"Type to file "<<myFileName.c_str()<<" below: \n"<<std::endl;
    while(getIsOpen())
    {
        std::getline(std::cin,LineToInput);
        if(LineToInput == "escape")
            closeFile();

        writeLine(LineToInput+"\n");
    }
};
void FileRW::writeToFileUsingChar(const char character)
{
    std::string s;
    s.push_back(character);
    if(getIsOpen())
        closeFile();
    changeFileType("out"); //change file to append to it
    writeLine(s);
}
void FileRW::appendFile(const char character)
{
    std::string s;
    s.push_back(character);
    if(getIsOpen())
        closeFile();
    changeFileType("app"); //change file to append to it
    writeLine(s);
};
bool FileRW::getIsOpen() //Returns True if the file is open
{
    return myFile.is_open();
};
bool FileRW::readLine()
{
    if(std::getline(myFile,LineLookedAt).good())
        return true;
    return false;
};
bool FileRW::writeLine(const std::string& line)
{
    if(getIsOpen()==false)
        return false;
    myFile.write(line.c_str(),sizeof(char)*line.size());
    return true;
};
const std::string& FileRW::getLine()
{
    return LineLookedAt;
};
FileRW::~FileRW()
{
    if(getIsOpen());
    {
        std::cout<<"file still open, closing now"<<std::endl;
        closeFile();
    }
    std::cout<<"goodbye!!"<<std::endl;
};
