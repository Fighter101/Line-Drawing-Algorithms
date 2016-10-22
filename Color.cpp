/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Color.cpp
 * Author: hassan
 * 
 * Created on October 21, 2016, 3:04 PM
 */

#include "Color.h"

Color::Color() {
    R=0;
    G=0;
    B=0;
    Increasing=true;
    Decreasing=false;
}
Color::Color(int m_r, int m_g, int m_b)
{
    R=m_r;
    G=m_g;
    B=m_b;
    Increasing=true;
    Decreasing=false;
}
Color & Color::operator +(int x)
{
    if(Increasing)
    {  
        R+=x;
        G+=x;
        B+=x;
    }
    else 
    {
        R-=x;
        G-=x;
        B-=x;
    }
    if (R==255)
    {
        Increasing=false;
        Decreasing=true;
    }
    else if (R==0)
    {
        Decreasing=false;
        Increasing=true;
    }
    return *this;
    
}
Color::Color(const Color& orig) {
}
ostream & operator << (ostream & out,const Color & object)
{
    out<<object.R<<" "<<object.G<<" "<<object.B<<" ";
    return out;
}
Color::~Color() {
}

