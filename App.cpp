#include "App.h"
#include <deque>

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
    
    a = new Rect(0.0, 0.0, 0.4, 0.4);
    b = new Rect();
}

void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Set Color
    glColor3d(1.0, 0.0, 1.0);
    
    // Draw some points
    glBegin(GL_POLYGON);
    
    glVertex2f(a->getX(), a->getY());
    glVertex2f(a->getX() + a->getW(), a->getY());
    glVertex2f(a->getX() + a->getW(), a->getY() - a->getH());
    glVertex2f(a->getX(), a->getY() - a->getH());
    glEnd();

    glColor3d(0.,1.0,0.0);
    
    glBegin(GL_POLYGON);
    
    glVertex2f(b->getX(), b->getY());
    glVertex2f(b->getX() + b->getW(), b->getY());
    glVertex2f(b->getX() + b->getW(), b->getY() - b->getH());
    glVertex2f(b->getX(), b->getY() - b->getH());
    
    glEnd();
    
    glColor3d(1.0,1.0,1.0);
    
    glBegin(GL_POINTS);
    
    glVertex2f(0.5,0.5);
    glVertex2f(0.5,-0.5);
    glVertex2f(-0.5,-0.5);
    glVertex2f(-0.5,0.5);
    
    glEnd();
    
    glColor3d(1.0,0.0,1.0);
    
    glBegin(GL_LINES);
    glVertex2f(mx - 0.05f, my);
    glVertex2f(mx + 0.05f, my);
    glVertex2f(mx, my - 0.05f);
    glVertex2f(mx, my + 0.05f);
    
    glEnd();

    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    Rect *tmp;
    
    //
    if(b -> contains(mx,my) && a -> contains(mx,my))
    {
        return;
    }
    else if(b->contains(mx,my))
    {
        tmp = b;
        b = a;
        a = tmp;
    }
    
    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
}
