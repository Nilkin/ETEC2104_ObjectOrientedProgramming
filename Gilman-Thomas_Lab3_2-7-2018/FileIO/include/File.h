#ifndef FILE_H
#define FILE_H

class File
{
    public:
        File();
        void openFile(const std::string& fileName);
        void closeFile();
        virtual ~File();
};

#endif // FILE_H
