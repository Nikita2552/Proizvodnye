#ifndef TEMPL_H
#define TEMPL_H

#include <iostream>

namespace templo
{
    using namespace std;

    class parentinterface
    {

    };

    class vectorclass: public parentinterface
    {
    private:
        int *coord;
    public:
        vectorclass(int *coords);
        ~vectorclass();
        vectorclass operator+(const vectorclass& cl2) const;
    };

    class matrixclass: public parentinterface
    {
    private:
        int *coord;
    public:
        matrixclass(int *coords);
        ~matrixclass();
        matrixclass operator+(const matrixclass& cl2) const;
    };

    class simpledigitclass: public parentinterface
    {
    private:
        int digit;
    public:
        simpledigitclass(int *dig);
        ~simpledigitclass();
        int get();
        simpledigitclass operator+(simpledigitclass& cl2) const;
    };

    class complexdigitclass: public parentinterface
    {
    private:
        int deg;
        int img;
    public:
        complexdigitclass(int *de, int* im);
        ~complexdigitclass();
        int getd();
        int geti();
        complexdigitclass operator+(complexdigitclass& cl2) const;
    };

    template<typename T> T summclasses(T cl1, T cl2);

    template<class T1, class T2> class someoperations
    {
    private:
        T1 *oclass;
        T2 *tclass;
    public:
        someoperations(const T1& param1, const T2& param2);
        T1 summoclass();
        T2 summtclass();
        //template <class U> U summclass(const U& t1, const U& t2);

    };

    template<class T, T first, int max> class initsome
    {
    private:
        T elem[max];
    public:
        initsome();
    };

//    template<> class voidssome<void*>
//    {
//    private:
//        void **cl;
//    public:
//    };

    void maintempl();
}

template <typename T>  class testclass
{
    public:
        template <typename U> void testfunc (const U& u);
};

#endif // TEMPL_H
