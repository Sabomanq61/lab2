#include "subject.h"
#include <algorithm>
#include "i_observer.h"

namespace msl
{

void Subject::Notify(const std::string &msg)
{
    for(auto it : observers)
    {
        it->Update(msg);
    }
}

void Subject::Detach(IObserver *iObserver)
{
    observers.erase(std::remove_if(observers.begin(), observers.end(),
                                   [iObserver](IObserver* iObserver_)
                                   {
                                       return iObserver == iObserver_;
                                   }), observers.end());
}

void Subject::Attach(IObserver *iObserver)
{
    observers.push_back(iObserver);
}

}