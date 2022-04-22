#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include <life_support.h>

namespace advent
{
auto Day3::read_input(Diagnostic& report) -> int
{
    std::ifstream in_file;
    
    in_file.open("day_3_input.txt");

    if (in_file.is_open())
    {
        std::string line;
        while(std::getline(in_file, line))
        {
            report.push_back(std::vector<int>());
            for(char& binary : line) {
                report.back().push_back(static_cast<int>(binary - '0'));
            }
        }
        in_file.close();
        return report.size();
    }
    return -1;
}

auto Day3::calculate_power_consumtion(Diagnostic& report) -> int
{
    int total_report_number = report.size();
    int binary_array_size = 0;
    if (total_report_number > 0)
    {
        binary_array_size = report.front().size();
    }
    std::vector<int> total_count_of_ones(binary_array_size, 0);

    for (const auto& entry : report){
        for (int index = 0; index < entry.size() ; index++)
        {
            if (entry[index] == 1)
            {
                total_count_of_ones[index] +=1;
            }
        }
    }

    int gamma_rate_value = 0;
    int epsilon_rate_value = 0;
    for (int index = 0; index < total_count_of_ones.size() ; index++)
    {
        if (total_count_of_ones[index] >= total_report_number/2)
        {
            gamma_rate_value += std::pow(2, total_count_of_ones.size()-1-index);
        }
        else
        {
            epsilon_rate_value += std::pow(2, total_count_of_ones.size()-1-index);
        }

    } 
    return gamma_rate_value * epsilon_rate_value;
}
auto Day3::binary_to_decimal(const std::vector<int> binary_nummer) -> int
{
    int decimal_value =0;
    for (int index = 0; index < binary_nummer.size() ; index++)
    {
        if (binary_nummer[index] == 1) 
        {
            decimal_value += std::pow(2, binary_nummer.size()-1-index);
        }
    }
    return decimal_value;
}
auto Day3::calculate_life_support_rating(Diagnostic& report, bool use_most_common,
                                    int& index) -> std::vector<int>
{
    if (report.size() == 1)
    {
        return report.front();
    }
    Diagnostic rating_with_ones;
    Diagnostic rating_with_zeros;

    for (auto& entry : report){
        if (entry[index] == 1)
        {
            rating_with_ones.push_back(entry);
        }
        else
        {
            rating_with_zeros.push_back(entry);
        }
    }
    index++;
    if (use_most_common)
    {
        if (rating_with_ones.size() >= rating_with_zeros.size())
        {
            return calculate_life_support_rating(rating_with_ones, use_most_common, index);
        }
        else
        {
            return calculate_life_support_rating(rating_with_zeros, use_most_common, index);
        }
    }
    else
    {
        if (rating_with_zeros.size() <= rating_with_ones.size())
        {
            return calculate_life_support_rating(rating_with_zeros, use_most_common, index);
        }
        else
        {
            return calculate_life_support_rating(rating_with_ones, use_most_common, index);
        }
    }
    
}

auto Day3::calculate_oxygen_genarator_rating(Diagnostic& report) -> int
{
    int index = 0;
    std::vector<int> rating = calculate_life_support_rating(report, true, index);
    return binary_to_decimal(rating);
}
auto Day3::calculate_co2_scrubber_rating(Diagnostic& report) -> int
{
    int index = 0;
    std::vector<int> rating = calculate_life_support_rating(report, false, index);
    return binary_to_decimal(rating);
}

auto Day3::get_life_support_rating_of_submarine(Diagnostic& report) -> int
{
    return calculate_oxygen_genarator_rating(report) * 
            calculate_co2_scrubber_rating(report);
}
auto Day3::solve() -> void
{
    Diagnostic report;
    if (read_input(report))
    {
        std::cout << "Part1.Result: " << calculate_power_consumtion(report) << std::endl;
        std::cout << "Part2.Result: " << get_life_support_rating_of_submarine(report) << std::endl;

    }
}
} //namespace advent

