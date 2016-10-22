/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grid.cpp
 * Author: hassan
 * 
 * Created on October 21, 2016, 2:59 PM
 */

#include "Grid.h"

Grid::Grid(int xres,int yres) 
{
    this->xres=xres;
    this->yres=yres;
    color=Color(0,0,0);
    arr=new Color* [yres];
    for(int i=0;i<yres;i++)
    {
        arr[i]=new Color[xres];
    }
}
void Grid::SetPixel(int x,int y)
{
    int r,g,b;
    srand(time(NULL));
    r=rand()%255+1;
    srand(time(NULL));
    g=(rand()+r)%255+1;
    srand(time(NULL));
    b=(rand()+(r*g))%255+1;
    arr[y][x]=Color(r,g,b);
}
Grid::Grid(const Grid& orig) {
}
ostream & operator << (ostream & out,const Grid & object)
{
    for(int i=0;i<object.yres ;++i)
    {
        for(int j=0;j<object.xres;++j)
            out<<object.arr[i][j]<<endl;
    }
    return out;
}
Grid::~Grid() {
    for(int i;i<yres;++i)
    {
        delete []arr[i];
    }
    delete[] arr;
}

