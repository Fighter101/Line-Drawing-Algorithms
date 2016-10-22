/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grid.h
 * Author: hassan
 *
 * Created on October 21, 2016, 2:59 PM
 */

#ifndef GRID_H
#define GRID_H
#include"Includes.h"
#include"Color.h"
class Grid {
public:
    Grid(int Xres,int Yres);
    Grid(const Grid& orig);
    void SetPixel(int x,int y);
    virtual ~Grid();
    friend ostream & operator << (ostream &out,const Grid & object);
private:
    Color **arr;
    int xres,yres;
    Color color;
};

#endif /* GRID_H */

