#pragma once

#include <iostream>
#include <vector>
#include <map>

#include <advent.h>

namespace advent {

using Coordinate = std::pair<int, int>;
using Interval = std::pair<Coordinate, Coordinate>;
enum Direction
{
    NOT_MOVE,
    RIGHT,
    LEFT,
    UP,
    DOWN,
};

class Day5 : public AdventOfCode
{
private:
    // methods
    auto ReadInput() -> int;
    auto FindHorizantalDirection(const Coordinate& start_coordination, const Coordinate& end_coordination) -> Direction;
    auto FindVerticalDirection(const Coordinate& start_coordination, const Coordinate& end_coordination) -> Direction;
    auto MarkCoveredLines() -> void ;
    auto MarkCoveredDiagonalLines() -> void ;
    auto CountIntersections() -> int;
    auto MarktPoint(int index) -> void;

private:  
    // variables
    std::vector<Interval> _intervals;
    /// matrix index, how many times covered
    std::map<int, int> _cover_map;

public:
    auto Solve() -> void override;
};

}  // namespace advent