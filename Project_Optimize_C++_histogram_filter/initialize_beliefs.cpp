//
//  initialize_beliefs.cpp
//  hyungoo_optimize_code
//
//  Created by hyungoo shim on 2018. 10. 3..
//  Copyright © 2018년 hyungoo shim. All rights reserved.
//

#include "headers/initialize_beliefs.hpp"

using namespace std;

vector< vector <float> > initialize_beliefs(int height, int width) {
    
    vector< vector <float> > newGrid;
    newGrid.reserve(height);
    
    vector<float> newRow(width, (1.0 / (float) height * width));
    
    for (int i=0; i < height; i++)
    {
        newGrid.push_back(newRow);
    }
     
    return newGrid;
}




