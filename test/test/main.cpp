//
//  main.cpp
//  test
//
//  Created by 於光中 on 2017/9/6.
//  Copyright © 2017年 於光中. All rights reserved.
//
#include <iostream>
#include <string>
#include "vector"
using namespace std;
int maximumSwap(int num) {
    
    vector<int> v;
    while( num != 0 ) {
        v.push_back( num % 10 ); //
        num /= 10;
    }
    for(int j = v.size() - 1; j > 0; j-- ) {
    cout << j<<"    "<<v[j] <<endl;
    }
    int idx = 0, end;
    for( end = v.size() - 1; end > 0; end-- ) {
        idx = 0;
        for( int i = 1; i < end; i++ ) {
            if( v[i] > v[idx] ) idx = i;
        }
        if( v[idx] > v[end] ) break;
    }
    swap( v[idx], v[end] );
    num = 0;
    long long num10 = 1;
    for( int i = 0; i < v.size(); i++ ) {
        num += num10 * v[i];
        num10 *= 10;
    }
    return num;
}


int  main(){
    int sol=maximumSwap(1909);
    cout <<sol<<endl;
    return 0;
    
}
