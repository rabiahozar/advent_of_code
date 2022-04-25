#include <iostream>
#include <memory>

#include <sonar_sweep.h>
#include <dive.h>
#include <life_support.h>
#include <bingo.h>
#include <hypothermal.h>

namespace advent
{
auto select_day(int selected_day) -> std::unique_ptr<AdventOfCode>
{   
    switch (selected_day)
    {
    case 1:
        return std::move(std::make_unique<advent::Day1>());
        break;
    case 2:
        return std::move(std::make_unique<advent::Day2>());
        break;
    case 3:
        return std::move(std::make_unique<advent::Day3>());
        break;
    case 4:
        return std::move(std::make_unique<advent::Day4>());
        break;
    case 5:
        return std::move(std::make_unique<advent::Day5>());
        break;
    default:
        std::cerr << "This day has not been solved." << std::endl;
        return {};
        break;
    }
    return {};
}
} //namespace advent

int main(int argc, char** argv)
{
    if (argc == 2)
    {
        int selected_day = std::atoi(argv[1]);
        std::cout << "Selected Day of Advent Calendar: " << selected_day << std::endl;
        if (const auto& calendar_day = advent::select_day(selected_day))
        {
            calendar_day->Solve();
        }
    }
    else
    {
        std::cerr << "Please select the day of calender between 1 and 50. E.g. 1" << std::endl;
        return -1;
    }
    return 0;
}