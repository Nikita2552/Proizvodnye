
#include "templ.h"



templo::vectorclass::vectorclass(int *coords)
{
    coord = coords;
}

templo::vectorclass::~vectorclass()
{

}

templo::vectorclass templo::vectorclass::operator+(const vectorclass &cl2) const
{
    int tcoord[3] = {0, 0, 0};
    vectorclass temp(tcoord);
    return temp;
}

templo::matrixclass::matrixclass(int *coords)
{
    coord = coords;
}

templo::matrixclass::~matrixclass()
{

}

templo::matrixclass templo::matrixclass::operator+(const matrixclass &cl2) const
{
    int tcoord[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    matrixclass temp(tcoord[0]);
    return temp;
}

templo::simpledigitclass::simpledigitclass(int *dig)
{
    digit = *dig;
}

templo::simpledigitclass::~simpledigitclass()
{

}

int templo::simpledigitclass::get()
{
    return digit;
}

templo::simpledigitclass templo::simpledigitclass::operator+(simpledigitclass &cl2) const
{
    int temp  = digit + cl2.get();
    simpledigitclass tempclass(&temp);
    return tempclass;
}

templo::complexdigitclass::complexdigitclass(int *de, int *im)
{
    deg = *de;
    img = *im;
}

templo::complexdigitclass::~complexdigitclass()
{

}

int templo::complexdigitclass::getd()
{
    return deg;
}

int templo::complexdigitclass::geti()
{
    return img;
}

templo::complexdigitclass templo::complexdigitclass::operator+(complexdigitclass &cl2) const
{
    int tdeg  = deg + cl2.getd();
    int timg  = img + cl2.geti();
    complexdigitclass tempclass(&tdeg, &timg);
    return tempclass;
}

template<typename T>
T templo::summclasses(T cl1, T cl2)
{
    return cl1 + cl2;
}

void templo::maintempl()
{
    int a  = 2, b = 5;
    simpledigitclass sa(&a);
    cout << "this is sa  = " << sa.get() << endl;
    simpledigitclass sb(&b);
    cout << "this is sb  = " << sb.get() << endl;
    simpledigitclass sc = summclasses(sa, sb);
    cout << "this is sc  = " << sc.get() << endl;
}

template<class T1, class T2>
templo::someoperations<T1, T2>::someoperations(const T1 &param1, const T2 &param2)
{
    oclass = &param1;
    tclass = &param2;
}

template<class T1, class T2>
T1 templo::someoperations<T1, T2>::summoclass()
{
    return 2* *oclass;
}

template<class T1, class T2>
T2 templo::someoperations<T1, T2>::summtclass()
{
    return 2* *tclass;
}

template<typename T> template<typename U>
void testclass<T>::testfunc(const U &u)
{

}

//Two many template-parameter-lists ???
//template <class T1, class T2> template<class U>
//U templo<T1, T2>::someoperations::summclass(const U &t1, const U &t2)
//{

//}

template<class T, T first, int max>
templo::initsome<T, first, max>::initsome()
{
    elem[0] = first;
}

int test = 0;
