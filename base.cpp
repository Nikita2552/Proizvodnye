
#include "base.h"

void userbase::base::iam()
{
    cout << "base\n";
}

userbase::base::~base()
{

}

void userbase::onebase::iam()
{
    cout << "onebase\n";
}

void userbase::twobase::iam()
{
    cout << "twobase\n";
}

void userbase::mainbase()
{
    base parentbase;
    parentbase.iam();

    onebase childone;
    childone.iam();

    twobase childtwo;
    childtwo.iam();

    base* pointerone;
    pointerone = &childone;
    pointerone->iam();

    base* pointertwo;
    pointertwo = &childtwo;
    pointertwo->iam();

    base* pointtest = new base();
    delete pointtest;
}
