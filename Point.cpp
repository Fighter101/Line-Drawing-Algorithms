/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Point.cpp
 * Author: hassan
 * 
 * Created on October 21, 2016, 12:23 AM
 */

#include "Point.h"

Point::Point() {
    x=0;
    y=0;
}
Point::Point(int r_x,int r_y)
{
    x=r_x;
    y=r_y;
}
Point::Point(const Point& orig) {
    this->x=orig.x;
    this->y=orig.y;
}
ostream &operator << (ostream & out , const Point & object)
{
    out<< object.x <<" "<< object.y <<endl;
    return out;
}
istream & operator >> (istream & in, Point & object)
{
    in>>object.x>>object.y;
    return in;
}
int Point::getx()
{
    return x;
}
int Point::gety()
{
    return y;
}
Point& CmpX (Point & obj1 , Point & obj2)
{
    if(obj1.x < obj2.x)
    {
        return obj1;
    }
    else return obj2;
}
Point& CmpY (Point & obj1 , Point & obj2)
{
    if(obj1.y < obj2.y)
    {
        return obj1;
    }
    else return obj2;
}
void Point::set(int x,int y) {
    this->x=x;
    this->y=y;
}

Point::~Point() {
}

