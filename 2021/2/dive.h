#pragma once

#include <iostream>
#include <vector>

#include <advent.h>

namespace advent 
{

using Command = std::pair<std::string, int>;

class Day2 : public AdventOfCode
{
private:
    auto read_input(std::vector<Command>& commands) -> int;
    auto move(std::vector<Command>& commands) -> int;
    auto move_with_aim(std::vector<Command>& commands) -> double;
public:
    auto solve() -> void override;
};

}