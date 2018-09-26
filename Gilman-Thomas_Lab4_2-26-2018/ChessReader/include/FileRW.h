#ifndef FILERW_H
#define FILERW_H
#include <fstream>
#include <iostream>
#include <string.h>

class FileRW
{
    public:
        FileRW(const std::string& filename);
        void changeFileType(std::string mode="in"); //can be an out file
        void closeFile();
        void changeFile(const std::string& filename); //change file looked at
        void fileReader();
        void writeToFile();
        void writeToFileUsingChar(const char character);
        void appendFile(const char character); //append a line to file looked at
        bool getIsOpen();
        bool readLine();
        bool writeLine(const std::string& line);
        const std::string& getLine();
        virtual ~FileRW();

    private:
        std::string myFileName;
        std::string LineLookedAt;
        std::fstream myFile; //fileLooked at IN/OUT FileStream
};
#endif // FILERW_H
