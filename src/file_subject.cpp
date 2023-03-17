#include "file_subject.h"
#include <utility>
#include <filesystem>
#include <strstream>
#include <iostream>

namespace msl
{

FileSubject::FileSubject(std::string name)
: fileName_(std::move(name))
, file_()
{}

void FileSubject::WriteText(const std::string& text)
{
    file_.clear(); // очищаем флаги

    if (!file_.is_open()) // если файл не открыт, то
    {
        file_.open(fileName_, std::ios::out | std::ios::app); // открываем файл для записи с соответсвующим флагом
    }

    file_ << text; // записываем данные в файл
    CloseFile(); // закрываем файл

    Notify("File is exist.\nWas modified: current size = " + std::to_string(std::filesystem::file_size(fileName_))); // оповещаем наблюдателей
}

bool FileSubject::RemoveFile() {
    if (!std::filesystem::exists(fileName_)) // если не существует
    {
        std::cout << "Cant remove: file doest not exists" << std::endl;
        return false;
    }

    bool is_removed = std::filesystem::remove(fileName_); // удаляем файл

    if (is_removed) // если файл удалился, то
    {
        Notify("File does not exists");
    }
    return is_removed;
}

void FileSubject::OpenFile()
{
    file_.open(fileName_, std::ios::out | std::ios::app); // открываем файл с нужным флагом открытия
    if(file_.is_open())
    {
        std::strstream strstream;
        strstream << std::filesystem::file_size(fileName_);
        Notify("File is exist. Size = " +  std::string(strstream.str()));
    }
    else
    {
        Notify("File does not exist.");
    }
    CloseFile();
}

void FileSubject::CloseFile()
{
    file_.close();
}

}