#include "file_observer.h"
#include <iostream>
#include <utility>
namespace msl
{

void FileObserver::Update(const std::string &msg)
{
    std::cout << "FileObserver: " << name_ << " " << msg << std::endl;
}

FileObserver::FileObserver(std::string name)
: name_(std::move(name))
{}

}