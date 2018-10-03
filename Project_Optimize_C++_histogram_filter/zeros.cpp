//
//  zeros.cpp
//  hyungoo_optimize_code
//
//  Created by hyungoo shim on 2018. 10. 3..
//  Copyright © 2018년 hyungoo shim. All rights reserved.
//


#include "headers/zeros.hpp"

using namespace std;

vector < vector <float> > zeros(int &height, int &width) {
    unsigned int i;
    
    // OPTIMIZATION: Reserve space in memory for vectors
    vector < vector <float> > newGrid;
    newGrid.reserve(height);
    vector <float> newRow(width, 0.0);
   
    // OPTIMIZATION: nested for loop not needed
    // because every row in the matrix is exactly the same
    
    for (i=0; i < height; i++)
    {
        newGrid.push_back(newRow);
    }
    
    return newGrid;
}


