#pragma once
#include <string>
#include <list>


namespace msl
{

/// forward declaration
class IObserver;

/// @brief Класс для работы с наблюдателями
class Subject
{
public:
    void Attach(IObserver*);
    void Detach(IObserver*);
    void Notify(const std::string& msg);
    virtual ~Subject() = default;

private:
    /// @brief Список наблюдателей
    std::list<IObserver*> observers;
};

}
