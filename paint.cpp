#include "paint.h"

userpaint::userwindow::userwindow(const int N, const int M)
{
    window = new char[M*N];
    sz.Height = M;
    sz.Width = N;

    resetwindow(' ');
}

userpaint::userwindow::~userwindow()
{
//    delete window;
}

void userpaint::userwindow::drawwindow()
{
    for (int j = 0; j < sz.Height; j++)
    {
        for (int i = 0; i < sz.Width; i++)
             cout << *(window + sz.Width*j + i);
         cout << endl;
    }
}

void userpaint::userwindow::sendshape(shape *sh)
{
    sh->draw(this);
}

bool userpaint::userwindow::senddot(const Point *p)
{

    if ((p->X < sz.Width) && (p->Y < sz.Height))
    {
         *(window + sz.Width*p->Y + p->X) = '*';
         return true;
    }

    return false;
}

void userpaint::userwindow::resetwindow(const char symbol = '0')
{
    for (int j = 0; j < sz.Height; j++)
        for (int i = 0; i < sz.Width; i++)
            *(window + sz.Width*j + i) = symbol;
}

userpaint::dot::dot(Point *p)
{
    currentp = p;
}

userpaint::dot::~dot()
{
//    delete currentp;
}

userpaint::line::line(Point *p[2])
{
    currentps = p;
}

userpaint::line::~line()
{
//    delete currentps;
}

userpaint::triangle::triangle(userpaint::Point *p[3])
{
    currentps = p;
}

userpaint::triangle::~triangle()
{
//    delete currentps;
}

userpaint::circle::circle(Point *p, int *rad)
{
    currentps = p;
   radius = rad;
}

userpaint::circle::~circle()
{
//   delete currentps;
//   delete radius;
}

userpaint::rectangle::rectangle(userpaint::Point *p[4])
{
    currentps = p;
}

userpaint::rectangle::~rectangle()
{
//    delete currentps;
}

void userpaint::shape::draw(userwindow *win)
{

}

void userpaint::dot::draw(userwindow *win)
{
    win->senddot(currentp);
}

void userpaint::line::draw(userwindow *win)
{
    Point p;
    float xcompare = currentps[1]->X - currentps[0]->X;
    float ycompare = currentps[1]->Y - currentps[0]->Y;

    if (xcompare > 0)
        xmorezero(win, &p, &xcompare, &ycompare);
    else if (xcompare < 0)
        xlesszero(win, &p, &xcompare, &ycompare);
    else if (ycompare > 0)
        ymorezero(win, &p, &xcompare, &ycompare);
    else if (ycompare < 0)
        ylesszero(win, &p, &xcompare, &ycompare);
    else
        xyzero(win, &p);
}

void userpaint::triangle::draw(userpaint::userwindow *win)
{
    userpaint::drawline(win, currentps[0], currentps[1]);
    userpaint::drawline(win, currentps[1], currentps[2]);
    userpaint::drawline(win, currentps[0], currentps[2]);
}

void userpaint::rectangle::draw(userpaint::userwindow *win)
{
    userpaint::drawline(win, currentps[0], currentps[1]);
    userpaint::drawline(win, currentps[1], currentps[2]);
    userpaint::drawline(win, currentps[2], currentps[3]);
    userpaint::drawline(win, currentps[3], currentps[0]);
}

void userpaint::circle::draw(userpaint::userwindow *win)
{
    Point temp;
    temp.X = currentps->X - *radius;
    cmacro(win, &temp, true);

    while (temp.X < currentps->X + *radius)
    {
        temp.X++;
        cmacro(win, &temp, true);
        cmacro(win, &temp, false);
    }
}

inline void userpaint::circle::cmacro(userpaint::userwindow *win, Point *tmp, bool flag)
{
    tmp->Y = getycoordinateabs(tmp, flag);
    userpaint::senddot(win, tmp);
}

int userpaint::circle::getycoordinateabs(Point *temp, bool plus)
{
    int sq;
    plus ? sq = 1: sq = -1;
    return (int) (sq * abs(sqrt(pow(*radius, 2) - pow(temp->X - currentps->X, 2))) + currentps->Y);
}

void userpaint::senddot(userpaint::userwindow *wind, userpaint::Point *pt)
{
    dot* dt = new dot(pt);
    wind->sendshape(dt);
    delete dt;
}

void userpaint::drawline(userpaint::userwindow *wind, userpaint::Point *pone, userpaint::Point *ptwo)
{
    Point *ps[2];
    Point x0 = {pone->X, pone->Y};
    ps[0] = &x0;
    Point x1 = {ptwo->X, ptwo->Y};
    ps[1] = &x1;
    line* l = new line(ps);
    wind->sendshape(l);
}

void userpaint::line::xmorezero(userpaint::userwindow *wind, Point *p, float *xcomp, float *ycomp)
{
    ymacro(xcomp, ycomp);
    for (int i = 0; i <= *xcomp; i++)
        xlessormore(wind, p,  ycomp, &i);
}

void userpaint::line::xlesszero(userpaint::userwindow *wind, Point *p, float *xcomp, float *ycomp)
{
    ymacro(xcomp, ycomp);
    for (int i = 0; i >= *xcomp; i--)
        xlessormore(wind, p,  ycomp, &i);
}

void userpaint::line::xlessormore(userpaint::userwindow *wi, Point *po, float *ycom, int *i)
{
    po = new Point{currentps[0]->X + *i, currentps[0]->Y + *i * *ycom};
    wi->senddot(po);
}

inline void userpaint::line::ymacro(float *xcom, float *ycom)
{
    *ycom /= *xcom;
}

void userpaint::line::ymorezero(userpaint::userwindow *wind, userpaint::Point *p, float *xcomp, float *ycomp)
{
    xmacro(xcomp, ycomp);
    for (int i = 0; i <= *ycomp; i++)
        ylessormore(wind, p, xcomp, &i);
}

void userpaint::line::ylesszero(userpaint::userwindow *wind, userpaint::Point *p, float *xcomp, float *ycomp)
{
    xmacro(xcomp, ycomp);
    for (int i = 0; i >= *ycomp; i--)
        ylessormore(wind, p, xcomp, &i);
}

void userpaint::line::ylessormore(userwindow *wi, Point *po, float *xcom, int *i)
{
    po = new Point{currentps[0]->X + *i* *xcom, currentps[0]->Y + *i};
    wi->senddot(po);
}

inline void userpaint::line::xmacro(float *xcom, float *ycom)
{
    *xcom /= *ycom;
}

void userpaint::line::xyzero(userpaint::userwindow *wi, Point *po)
{
    po = new Point{currentps[0]->X, currentps[0]->Y};
    wi->senddot(po);
}

void userpaint::mainpaint()
{
    userwindow* win = new  userwindow(50, 50);

    //    Point p  = {3, 3};
    //    dot* dt = new dot(&p);
    //    win->sendshape(dt);

    //    Point *ps[2];
    //    Point x0 = {1, 1};
    //    ps[0] = &x0;
    //    Point x1 = {4, 4};
    //    ps[1] = &x1;
    //    line* l = new line(ps);
    //    win->sendshape(l);

    //    Point *pss[3];
    //    Point x = {1, 1};
    //    pss[0] = &x;
    //    Point x1 = {4, 4};
    //    pss[1] = &x1;
    //    Point x2 = {7, 1};
    //    pss[2] = &x2;
    //    triangle* tr1 = new triangle(pss);
    //    win->sendshape(tr1);

    //    Point x000 = {30, 30};
    //    int radd = 10;
    //    circle* cl = new circle(&x000, &radd);
    //    win->sendshape(cl);

    //    Point *pssss[4];
    //    Point x0000 = {1, 1};
    //    pssss[0] = &x0000;
    //    Point x0001 = {1, 7};
    //    pssss[1] = &x0001;
    //    Point x0002 = {7, 7};
    //    pssss[2] = &x0002;
    //    Point x0003 = {7, 1};
    //    pssss[3] = &x0003;
    //    rectangle* rc = new rectangle(pssss);
    //    win->sendshape(rc);

    /* Рисование домика */

    Point *kv0[4];
    Point x00 = {1, 20};
    kv0[0] = &x00;
    Point x01 = {1, 48};
    kv0[1] = &x01;
    Point x02 = {48, 48};
    kv0[2] = &x02;
    Point x03 = {48, 20};
    kv0[3] = &x03;
    rectangle* rkv0 = new rectangle(kv0);
    win->sendshape(rkv0);

    delete rkv0;

    x00 = {1, 19};
    x01 = {25, 1};
    x02 = {48, 19};
    triangle* tr = new triangle(kv0);
    win->sendshape(tr);

    delete tr;

    x00 = {3, 22};
    x01 = {3, 30};
    x02 = {11, 30};
    x03 = {11, 22};
    rkv0 = new rectangle(kv0);
    win->sendshape(rkv0);

    delete rkv0;

    x00 = {14, 22};
    x01 = {14, 30};
    x02 = {22, 30};
    x03 = {22, 22};
    rkv0 = new rectangle(kv0);
    win->sendshape(rkv0);

    delete rkv0;

    x00 = {25, 22};
    x01 = {25, 45};
    x02 = {45, 45};
    x03 = {45, 22};
    rkv0 = new rectangle(kv0);
    win->sendshape(rkv0);

    delete rkv0;

    x00 = {25, 12};
    int radd = 5;
    circle* cl = new circle(&x00, &radd);
    win->sendshape(cl);

    delete cl;

    win->drawwindow();

    delete win;
}
