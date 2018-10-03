//
//  move.cpp
//  hyungoo_optimize_code
//
//  Created by hyungoo shim on 2018. 10. 3..
//  Copyright © 2018년 hyungoo shim. All rights reserved.
//

#include "headers/move.hpp"
#include "headers/zeros.hpp"

using namespace std;

// OPTIMIZATION: Pass large variable by reference
// and eliminate any variables that aren't needed
vector< vector <float> > move(int dy, int dx, vector < vector <float> > &beliefs)
{
    int height = beliefs.size();
    int width = beliefs[0].size();
    
    // Use improved zeros function
    vector < vector <float> > newGrid = zeros(height, width);
    
    int i, j, new_i, new_j;
    
    for (i=0; i < height; i++) {
        for (j=0; j < width; j++) {
            new_i = (i + dy + height) % height;
            new_j = (j + dx + width)  % width;
            
            newGrid[new_i][new_j] = beliefs[i][j];
        }
    }
    return newGrid;
}


