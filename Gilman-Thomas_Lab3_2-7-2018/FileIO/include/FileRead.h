#ifndef FILEREAD_H
#define FILEREAD_H
#include <fstream>
#include <iostream>
#include <string>
class FileRead
{
    public:
        FileRead();
        virtual ~FileRead();
        void Reader(const std::string& filename); //get address of file name
        void openFile(const std::string& fileName);//need to pass in string of file name to open
        void closeFile();
        bool getIsOpen();
        bool readLine();
        const std::string& getLine();
    private:
        std::string LineLookedAt;
        std::istream myFile; //fileLooked at (in File stream)
};

#endif // FILEREAD_H
