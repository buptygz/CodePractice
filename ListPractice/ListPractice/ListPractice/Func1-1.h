//
//  Func1-1.h
//  ListPractice
//
//  Created by 於光中 on 2017/11/3.
//  Copyright © 2017年 於光中. All rights reserved.
//

#ifndef Func1_1_h
#define Func1_1_h
//Func1-1.h 5个常用的函数
bool equal(int c1, int c2)
{
    return c1==c2;
}
bool sq(int c1, int c2)
{
    return c1==c2*c2;
}
bool equal(double c1, double c2)
{
    return abs(c1-c2)<1.0e-6;
}
inline void print(T& c)
{
    cout<<c<<" ";
}
inline void dbl(T& c)
{
    c*=2;
}


#endif /* Func1_1_h */
