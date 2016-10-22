/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: hassan
 *
 * Created on October 21, 2016, 12:17 AM
 */
#include"Line.h"
int main(int argc, char** argv) 
{
    double Xmin,Xmax,Ymin,Ymax,Xres,Yres;
    int Mode;
    Xmin=atof(argv[1]);
    Xmax=atof(argv[2]);
    Ymin=atof(argv[3]);
    Ymax=atof(argv[4]);
    Xres=atoi(argv[5]);
    Yres=atoi(argv[6]);
    Mode=atoi(argv[8]);
    ifstream in (argv[7]);
    if(!in.is_open())
        return 0;
    string s=argv[7];
    s.erase(s.end()-3,s.end());
    s+="_"+to_string(Mode)+".ppm";
    ofstream out (s.c_str());
    out<<"P3"<<endl;
    out<<Xres<<" "<<Yres<<endl<<255<<endl;
    Grid * grid=new Grid(Xres,Yres);
    long double x1,y1,x2,y2;
    vector<Point>Points;
    Point P;
    Line* line;
    while (true)
    {
        in>>s;
        while(in>>x1>>y1)
        {
            P.set(((x1-Xmin)/(Xmax-Xmin)*(Xres-0.5)),((y1-Ymin)/(Ymax-Ymin)*(Yres-0.5)));
            Points.push_back(P);
        }
        for(size_t i=0;i<Points.size()-1;++i)
        {
            line=new Line(Points[i],Points[i+1]);
            line->SetGrid(grid);
            line->Draw(Mode);
            delete line;
        }
        Points.clear();
        if(!in.eof())
            in.clear();
        else break;
    }
    out<<*grid;
    delete grid;
    return 0;
    
}

