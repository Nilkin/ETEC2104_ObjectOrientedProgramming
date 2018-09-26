#ifndef FILEWRITE_H
#define FILEWRITE_H
#include <fstream>
#include <iostream>
#include <string>
class FileWrite
{
    public:
        FileWrite();
        virtual ~FileWrite();
        void openFile(const std::string& filename);
        void closeFile();
        void writeToFile(const std::string& filename);
        bool getIsOpen();
        bool writeLine(const std::string& line);
    private:
        std::fstream myFile;
};
#endif // FILEWRITE_H
