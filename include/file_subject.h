#pragma once
#include "subject.h"
#include <fstream>


namespace msl
{

class FileSubject : public Subject
{
public:
    FileSubject() = delete;
    FileSubject(std::string name);
    void WriteText(const std::string& text);
    bool RemoveFile();
    void OpenFile();
    void CloseFile();

private:
    std::string  fileName_;
    std::fstream file_;
};
}