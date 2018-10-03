//
//  normalize.cpp
//  hyungoo_optimize_code
//
//  Created by hyungoo shim on 2018. 10. 3..
//  Copyright © 2018년 hyungoo shim. All rights reserved.
//

#include "headers/normalize.hpp"
using namespace std;

// OPTIMIZATION: Pass variable by reference
// and Avoid declaring and defining
// intermediate variables that are not needed.
vector< vector<float> > normalize(vector< vector <float> > &grid)
{
    
    float total = 0.0;
    int i, j;
    
    int rows = grid.size();
    int cols = grid[0].size();
    
    // calculate total probability
    for (i = 0; i < rows; i++)
    {
        for (j=0; j< cols; j++)
        {
            total += grid[i][j];
        }
    }
    
    // normalize vector's elements
    for (i=0; i < rows; i++)
    {
        for (j=0; j< cols; j++)
        {
            grid[i][j] = grid[i][j] / total;
        }
    }
    
    return grid;
}



