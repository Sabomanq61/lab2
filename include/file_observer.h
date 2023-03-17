#pragma once
#include "i_observer.h"
#include <chrono>

namespace msl
{

class FileObserver : public IObserver
{
public:
    FileObserver(std::string  name);
    void Update(const std::string& msg);

private:
    std::string name_;
};

}