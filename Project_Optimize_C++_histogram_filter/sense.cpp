//
//  sense.cpp
//  hyungoo_optimize_code
//
//  Created by hyungoo shim on 2018. 10. 3..
//  Copyright © 2018년 hyungoo shim. All rights reserved.
//


#include "headers/sense.hpp"

using namespace std;

// OPTIMIZATION: Pass larger variables by reference
vector< vector <float> > sense(char color, vector< vector <char> > &grid, vector< vector <float> > &beliefs,  float p_hit, float p_miss)
{
    int height = grid.size();
    int width = grid[0].size();
    
    for (int i=0; i < height; i++)
    {
        for (int j=0; j < width; j++)
        {
            if ( grid[i][j] == color)
            {
                beliefs[i][j] = beliefs[i][j] * p_hit;
            }
            else
                beliefs[i][j] = beliefs[i][j] * p_miss;
        }
    }
    return beliefs;
}



