#pragma once
#include <string>


namespace msl
{

/// @brief Forward declaration
class Subject;

/// @brief Интерфейс набоюдателя
class IObserver
{
public:
    virtual void Update(const std::string& msg) = 0;
    virtual ~IObserver() = default;
};

}
