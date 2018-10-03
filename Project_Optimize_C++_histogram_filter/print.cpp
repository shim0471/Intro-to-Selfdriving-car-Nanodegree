//
//  print.cpp
//  hyungoo_optimize_code
//
//  Created by hyungoo shim on 2018. 10. 3..
//  Copyright © 2018년 hyungoo shim. All rights reserved.
//

#include "headers/print.hpp"

using namespace std;

void print_vector_float(vector< vector <float> > grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void print_vector_char(vector< vector <char> > grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}



