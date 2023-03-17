#include <iostream>
#include "file_subject.h"
#include "file_observer.h"


int main() {
    std::string fileName = "file.txt";
    msl::FileSubject fileSubject(fileName);
    msl::FileObserver fileObserver("ObserverOne");
    fileSubject.Attach(&fileObserver);

    std::cout << "1 - open file\n2 - write some text to file\n3 - remove file\n4 - end test\n";
    std::string text;
    bool run = true;


    while (run)
    {
        int i;
        std::cin >> i;
        switch (i)
        {
            case 1:
                fileSubject.OpenFile();
                break;
            case 2:
                std::cout << "Print text: ";
                std::cin >> text;
                fileSubject.WriteText(text);
                break;
            case 3:
                fileSubject.RemoveFile();
                break;
            case 4:
                run = false;
                break;
            default:
                break;
        }
    }

    fileSubject.Detach(&fileObserver);
    return 0;
}
