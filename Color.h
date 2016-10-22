/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Color.h
 * Author: hassan
 *
 * Created on October 21, 2016, 3:04 PM
 */

#ifndef COLOR_H
#define COLOR_H
#include"Includes.h"
class Color {
public:
    Color();
    Color(int m_r,int m_g,int m_b);
    Color & operator + (int x);
    Color(const Color& orig);
    friend ostream & operator << (ostream &out,const Color & object);
    virtual ~Color();
private:
    int R,G,B;
    bool Increasing,Decreasing;
};

#endif /* COLOR_H */

