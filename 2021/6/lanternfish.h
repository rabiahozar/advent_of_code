#pragma once

#include <iostream>
#include <vector>
#include <map>

#include <advent.h>

namespace advent {

using Coordinate = std::pair<int, int>;
using Interval = std::pair<Coordinate, Coordinate>;

class Day6 : public AdventOfCode
{
private:
    // methods
    
private:  
    // variables


public:
    auto Solve() -> void override;
};

}  // namespace advent