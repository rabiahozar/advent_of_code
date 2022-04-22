#pragma once
#include <iostream>
#include <vector>

#include <advent.h>

namespace advent 
{

class Day1 : public AdventOfCode
{
private:
    auto read_input(std::vector<int>& numbers) -> int;
    auto calculate_increased_days(std::vector<int>& numbers) -> int;
    auto calculate_increased_window_count(std::vector<int>& numbers) -> int;
public:
    auto solve() -> void override;
};

}