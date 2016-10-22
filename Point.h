/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Point.h
 * Author: hassan
 *
 * Created on October 21, 2016, 12:23 AM
 */

#ifndef POINT_H
#define POINT_H
#include "Includes.h"
class Point {
public:
    Point();
    Point (int r_x,int r_y_);
    friend ostream & operator << (ostream & out, const Point &object);
    friend istream & operator >> (istream & in , Point &object);
    Point(const Point& orig);
    int getx();
    int gety();
    void set(int x,int y);
    friend Point & CmpX(Point & obj1, Point & obj2);
    friend Point & CmpY(Point & obj1, Point & obj2);
    virtual ~Point();
private:
    int x,y;
    
};

#endif /* POINT_H */

