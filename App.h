#ifndef App_hpp
#define App_hpp
#include "GlutApp.h"
#include <deque>

class Rect
{
public:
    float x;
    float y;
    float w;
    float h;
    
public:
    Rect()
    {
        this->x = -0.1;
        this->y = 0.1;
        this->w = 0.3;
        this->h = 0.3;
    }
    
    Rect(float x, float y, float w, float h)
    {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }
    
    float getX()
    {
        return x;
    }
    float getY()
    {
        return y;
    }
    float getW()
    {
        return w;
    }
    float getH()
    {
        return h;
    }
    
    void setX(float xx)
    {
        x = xx;
    }
    void setY(float yy)
    {
        y = yy;
    }
    void setW(float ww)
    {
        w = ww;
    }
    void setH(float hh)
    {
        h = hh;
    }

    
    bool contains (float x, float y)
    {
        if (x >= (this->x) && y <= (this->x) + w)
        {
            if(y <= (this->y) && y >= (this->y) - h)
            {
                return true;
            }
        }
        return false;
    }
};


class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
    
    Rect *a;
    Rect *b;
    
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
    
    ~App()
    {
        delete a;
        delete b;
    }
};
#endif
