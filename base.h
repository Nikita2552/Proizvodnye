#ifndef BASE_H
#define BASE_H

#include <iostream>

namespace userbase
{
    using namespace std;

    class base
    {
    public:
        virtual void iam();
        virtual ~base();
    };

    class onebase: public base
    {
    public:
        virtual void iam();
    };

    class twobase: public base
    {
    public:
        virtual void iam();
    };

    void mainbase();
}


#endif // BASE_H
