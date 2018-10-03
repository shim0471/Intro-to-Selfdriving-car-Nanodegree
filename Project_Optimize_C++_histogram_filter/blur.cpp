//
//  blur.cpp
//  hyungoo_optimize_code
//
//  Created by hyungoo shim on 2018. 10. 3..
//  Copyright © 2018년 hyungoo shim. All rights reserved.
//

#include "headers/blur.hpp"
#include "headers/zeros.hpp"

using namespace std;

// OPTIMIZATION: Pass large variable by reference
vector < vector <float> > blur(vector < vector < float> > &grid, float blurring) {
    
    // OPTIMIZATION: window, DX and  DY variables have the
    // same value each time the function is run.
    // It's very inefficient to recalculate the vectors
    // every time the function runs.
    //
    // The const and/or static operator could be useful.
    // Define and declare window, DX, and DY using the
    // bracket syntax: vector<int> foo = {1, 2, 3, 4}
    // instead of calculating these vectors with for loops
    // and push back
    
    int height = grid.size();
    int width = grid[0].size();
    
    static float center = 1.0 - blurring;
    static float corner = blurring / 12.0;
    static float adjacent = blurring / 6.0;
    
    static vector < vector <float> > window = {
        {corner, adjacent, corner},
        {adjacent, center, adjacent},
        {corner, adjacent, corner}
    };
    
    static vector <int> DX = {-1, 0, 1};
    static vector <int> DY = {-1, 0, 1};
    
    vector < vector <float> > newGrid;
    int dx, dy, ii, jj;
    int new_i;
    int new_j;
    float newVal;
    
    // OPTIMIZATION: Use improved zeros function
    newGrid = zeros(height, width);
    
    for (int i=0; i< height; i++ )
    {
        for (int j=0; j< width; j++ )
        {
            newVal = grid[i][j];
            for (ii=0; ii<3; ii++)
            {
                dy = DY[ii];
                for (jj=0; jj<3; jj++)
                {
                    dx = DX[jj];
                    new_i = (i + dy + height) % height;
                    new_j = (j + dx + width) % width;
                
                    newGrid[new_i][new_j] += newVal * window[ii][jj];
                }
            }
        }
    }
    
    return newGrid;
}



