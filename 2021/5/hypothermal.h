#pragma once

#include <iostream>
#include <vector>
#include <map>

#include <advent.h>

namespace advent {

using Coordinate = std::pair<int, int>;
using Interval = std::pair<Coordinate, Coordinate>;

class Day5 : public AdventOfCode
{
private:
    // methods
    auto ReadInput() -> int;
    auto MarkCoveredLines() -> void ;
    auto MarkCoveredLines2() -> void ;
    auto CountIntersections() -> int;

private:  
    // variables
    std::vector<Interval> _intervals;
    /// matrix index, how many times covered
    std::map<int, int> _cover_map;

public:
    auto Solve() -> void override;
};

}  // namespace advent