//
//  sense.hpp
//  hyungoo_optimize_code
//
//  Created by hyungoo shim on 2018. 10. 3..
//  Copyright © 2018년 hyungoo shim. All rights reserved.
//

#ifndef sense_hpp
#define sense_hpp

#include <vector>
#include <iostream>

std::vector< std::vector <float> > sense(char color, std::vector< std::vector <char> > &grid, std::vector< std::vector <float> > &beliefs,  float p_hit, float p_miss);

#endif /* sense_hpp */
