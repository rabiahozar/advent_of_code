#pragma once

#include <advent.h>

#include <iostream>
#include <vector>

namespace advent {

using Diagnostic = std::vector<std::vector<int>>;

class Day3 : public AdventOfCode
{
private:
    auto read_input(Diagnostic& report) -> int;
    auto calculate_power_consumtion(Diagnostic& report) -> int;
    auto binary_to_decimal(const std::vector<int> binary_nummer) -> int;
    auto calculate_life_support_rating(Diagnostic& report, bool use_most_common,
                                        int& index) -> std::vector<int>;
    auto calculate_oxygen_genarator_rating(Diagnostic& report) -> int;
    auto calculate_co2_scrubber_rating(Diagnostic& report) -> int;
    auto get_life_support_rating_of_submarine(Diagnostic& report) -> int;

public:
    auto solve() -> void override;
};

}  // namespace advent