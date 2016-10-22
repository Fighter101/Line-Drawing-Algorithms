/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Line.h
 * Author: hassan
 *
 * Created on October 21, 2016, 12:22 AM
 */

#ifndef LINE_H
#define LINE_H
#include "Point.h"
#include"Grid.h"
class Line {
public:
    Line();
    Line(Point r_P1,Point r_P2);
    friend istream & operator >> (istream & in , Line & object);
    friend ostream & operator << (ostream & out , const Line & object);
    void Draw(int Mode);
    void SetGrid(Grid *g);
    Line(const Line& orig);
    virtual ~Line();
private:
    Point P1,P2;
    int dx,dy;
    double Slope;
    bool Vertical,Horizontal,Xincrement;
    Grid* grid;
    void Draw0();
    void Draw1();
    void Draw2();
    void Draw3();
    void DrawVertical();
    void DrawHorizontal();
     void SetVars();
};

#endif /* LINE_H */

