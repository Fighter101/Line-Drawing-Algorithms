/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Line.cpp
 * Author: hassan
 * 
 * Created on October 21, 2016, 12:22 AM
 */

#include "Line.h"

Line::Line() {
    dx=0;
    dy=0;
    Slope=0;
}
Line::Line(Point r_P1, Point r_P2)
{
    P1=r_P1;
    P2=r_P2;
}
Line::Line(const Line& orig) 
{
    P1=orig.P1;
    this->P2=orig.P2;
}
ostream & operator << (ostream & out , const Line & object)
{
    out<<object.P1<<object.P2;
    return out;
}
istream & operator >> (istream & in ,  Line & object)
{
    in>>object.P1>>object.P2;
    return in;
}
void Line::SetVars()
{
    dx=P1.getx()-P2.getx();
    dy=P1.gety()-P2.gety();
    if(dx==0)
    {

        Horizontal=false;
        Vertical=true;
        Xincrement=false;
    }
    else if (dy==0)
    {
        Slope=0;
        Horizontal=true;
        Vertical=false;
        Xincrement=false;
    }
    else 
    {
        Horizontal=false;
        Vertical=false;
        Slope=(double)dy/dx;
        if(Slope>=-1&&Slope<=1)
        {
            Xincrement=true;
        }
        else Xincrement=false;
    }
}
void Line::DrawHorizontal()
{
    int StartPoint=min(P1.getx(),P2.getx());
    int EndPoint=max(P1.getx(),P2.getx());
    int Y=P1.gety();
    for(int i=StartPoint;i<=EndPoint;++i)
    {
        grid->SetPixel(i,Y);
    }
}
void Line::DrawVertical() 
{
    int StartPoint=min(P1.gety(),P2.gety());
    int EndPoint=max(P1.gety(),P2.gety());
        int X=P1.getx();
        for(int i=StartPoint;i<=EndPoint;++i)
        {
            grid->SetPixel(X,i);
        }
}

void Line::Draw0()
{
    SetVars();
    int Threshold,ThresholdIncrement,Offset,StartPoint,EndPoint,Increment,adjust;
    if(Slope>=0)
    {
        adjust=1;
    }
    else
    {
        adjust=-1;
    }
    if(Horizontal)
    {
        DrawHorizontal();
    }
    else if (Vertical)
    {
        DrawVertical();
    }
    else if (Xincrement)
    {
        StartPoint=min(P1.getx(),P2.getx());
        EndPoint=max(P1.getx(),P2.getx());
        Point & Mini=CmpX(P1,P2);
        int y=Mini.gety();
        Offset=0;
        Threshold=abs(dx);
        ThresholdIncrement=2*abs(dx);
        Increment=2*abs(dy);

        for(int i= StartPoint;i<=EndPoint;++i)
        {
            grid->SetPixel(i,y);
            Offset+=Increment;
            if(Offset>=Threshold)
            {
                y+=adjust;
                Threshold+=ThresholdIncrement;
            }
        }   
    }
    else 
    {
        StartPoint=min(P1.gety(),P2.gety());
        EndPoint=max(P1.gety(),P2.gety());
        int x=CmpY(P1,P2).getx();
        Offset=0;
        Threshold= abs(dy);
        ThresholdIncrement=2*abs(dy);
        Increment=2*abs(dx);
        for(int i=StartPoint;i<=EndPoint;++i)
        {
            grid->SetPixel(x,i);
            Offset+=Increment;
            if(Offset>=Threshold)
            {
                x+=adjust;
                Threshold+=ThresholdIncrement;
            }
        }
    }
    return ;
}
void Line::Draw1()
{
    SetVars();
    double Threshold,ThresholdIncrement,Offset,Increment;
    int StartPoint,EndPoint,adjust;
    if(Slope>=0)
    {
        adjust=1;
    }
    else
    {
        adjust=-1;
    }
    if(Horizontal)
    {
        DrawHorizontal();
    }
    else if (Vertical)
    {
        DrawVertical();
    }
    else if(Xincrement)
    {
        StartPoint=min(P1.getx(),P2.getx());
        EndPoint=max(P1.getx(),P2.getx());
        Point & Mini=CmpX(P1,P2);
        int y=Mini.gety();
        Offset=0;
        Threshold=0.5;
        ThresholdIncrement=1;
        Increment=fabs((double)dy/dx);
        
        for(int i= StartPoint;i<=EndPoint;++i)
        {
            grid->SetPixel(i,y);
            Offset+=Increment;
            if(Offset>=Threshold)
            {
                y+=adjust;
                Threshold+=ThresholdIncrement;
            }
        }   
    }
    else 
    {
        StartPoint=min(P1.gety(),P2.gety());
        EndPoint=max(P1.gety(),P2.gety());
        int x=CmpY(P1,P2).getx();
        Offset=0;
        Threshold= 0.5;
        ThresholdIncrement=1;
        Increment=fabs((double) dx/dy);
        for(int i=StartPoint;i<=EndPoint;++i)
        {
            grid->SetPixel(x,i);
            Offset+=Increment;
            if(Offset>=Threshold)
            {
                x+=adjust;
                Threshold+=ThresholdIncrement;
            }
        }
        
    }
    return ;
}
void Line::Draw2()
{
    SetVars();
    double Increment;
    int StartPoint,EndPoint;
    if(Horizontal)
    {
        DrawHorizontal();
    }
    else if (Vertical)
    {
        DrawVertical();
    }
    else if(Xincrement)
    {
        StartPoint=min(P1.getx(),P2.getx());
        EndPoint=max(P1.getx(),P2.getx());
        Point & Mini=CmpX(P1,P2);
        double y=Mini.gety();
        Increment=(double)(dy)/dx;
        for(int i= StartPoint;i<=EndPoint;++i)
        {
            grid->SetPixel(i,round(y));
            y+=Increment;
        }   
    }
    else 
    {
        StartPoint=min(P1.gety(),P2.gety());
        EndPoint=max(P1.gety(),P2.gety());
        double x=CmpY(P1,P2).getx();
        Increment=(double)(dx)/dy;
        for(int i= StartPoint;i<=EndPoint;++i)
        {
            grid->SetPixel(round(x),i);
            x+=Increment;
        }   
        
    }
    return ;
}
void Line::Draw3() 
{
    SetVars();
    if(Horizontal)
    {
        DrawHorizontal();
    }
    else if (Vertical)
    {
        DrawVertical();
    }
    else if (Xincrement)
    {
        int StartPoint=min(P1.getx(),P2.getx());
        int EndPoint=max(P1.getx(),P2.getx());
        Point & Mini=CmpX(P1,P2);
        double y=Mini.gety();
        double b=y-(Slope*StartPoint);
        for(int i= StartPoint;i<=EndPoint;++i)
        {
            y=(Slope*i)+b;
            grid->SetPixel(i,round(y));
        }   
    }
    else
    {
        int StartPoint=min(P1.gety(),P2.gety());
        int EndPoint=max(P1.gety(),P2.gety());
        double x=CmpY(P1,P2).getx();
        double Increment=(double)(dx)/dy;
        double b=StartPoint-(Slope*x);
        for(int i= StartPoint;i<=EndPoint;++i)
        {
            x=(i-b)*Increment;
            grid->SetPixel(round(x),i);
        }   
    }
}
void Line::Draw(int Mode) 
{
    switch(Mode)
    {
        case (0):
            Draw0();
            break;
        case(1):
            Draw1();
            break;
        case(2):
            Draw2();
            break;
        case(3):
            Draw3();
            break;
        default:
            return;          
    }
    return ;
}

void Line::SetGrid(Grid* g)
{
    grid=g;
}
Line::~Line() {
}

