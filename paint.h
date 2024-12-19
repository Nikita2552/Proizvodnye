#ifndef PAINT_H
#define PAINT_H

#include <iostream>
#include <math.h>

namespace userpaint
{
    using namespace std;

    class userwindow;
    class shape;
    class dot;
    class line;
    class triangle;
    class rectangle;
    class circle;

    typedef struct
    {
        int X  = 0;
        int Y  = 0;
    } Point;

    typedef struct
    {
        int Width  = 0;
        int Height  = 0;
    } Size;

    class userwindow
    {
    private:
        char *window;
        Size sz;
        Point currentpoint;
    public:
        userwindow(const int N = 300, const int M = 300);
        ~userwindow();
        void drawwindow();
        void sendshape(shape *sh);
        bool senddot(const Point *p);
        void resetwindow(const char symbol);
    };

    class shape
    {
    public:
        virtual void draw(userwindow *win);
    };

    class dot: public shape
    {
    private:
        Point *currentp;
    public:
        dot(Point *p);
        ~dot();
        void draw(userwindow *win);
    };

    class line: public shape
    {
    private:
        Point **currentps;
        void xmorezero(userwindow *wind, Point *p, float *xcomp, float *ycomp);
        void xlesszero(userwindow *wind, Point *p, float *xcomp, float *ycomp);
        void ymorezero(userwindow *wind, Point *p, float *xcomp, float *ycomp);
        void ylesszero(userwindow *wind, Point *p, float *xcomp, float *ycomp);
        void xyzero(userwindow *wi, Point *po);
        void xlessormore(userpaint::userwindow *wi, Point *po, float *ycom, int *i);
        void ylessormore(userpaint::userwindow *wi, Point *po, float *xcom, int *i);
        void ymacro(float *xcom, float *ycom);
        void xmacro(float *xcom, float *ycom);
    public:
        line(Point *p[2]);
        ~line();
        void draw(userwindow *win);
    };

    class triangle: public shape
    {
    private:
        Point **currentps;
    public:
        triangle(Point *p[3]);
        ~triangle();
        void draw(userwindow *win);
    };

    class circle: public shape
    {
    private:
        Point *currentps;
        int *radius;
        int getycoordinateabs(Point *temp, bool plus);
        void cmacro(userpaint::userwindow *win, Point *tmp, bool flag);
    public:
        circle(Point *p, int *rad);
        ~circle();
        void draw(userwindow *win);
    };

    class rectangle: public shape
    {
    private:
        Point **currentps;
    public:
        rectangle(Point *p[4]);
        ~rectangle();
        void draw(userwindow *win);
    };

    void senddot(userpaint::userwindow *wind, Point *pt);
    void drawline(userpaint::userwindow *wind, Point *pone, Point *ptwo);

    void mainpaint();
}

#endif // PAINT_H
