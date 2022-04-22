#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

namespace advent
{
using Diagnostic = std::vector<std::vector<int>>;

int read_input(Diagnostic& report)
{
    std::ifstream in_file;
    
    in_file.open("input.txt");

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

int calculate_power_consumtion(Diagnostic& report)
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
int binary_to_decimal(const std::vector<int> binary_nummer)
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
std::vector<int> calculate_life_support_rating(Diagnostic& report, bool use_most_common, int& index)
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

int calculate_oxygen_genarator_rating(Diagnostic& report)
{
    int index = 0;
    std::vector<int> rating = calculate_life_support_rating(report, true, index);
    return binary_to_decimal(rating);
}
int calculate_co2_scrubber_rating(Diagnostic& report)
{
    int index = 0;
    std::vector<int> rating = calculate_life_support_rating(report, false, index);
    return binary_to_decimal(rating);
}

int get_life_support_rating_of_submarine(Diagnostic& report)
{
    return calculate_oxygen_genarator_rating(report) * 
            calculate_co2_scrubber_rating(report);
}
} // end of advent

int main(int argc, char **argv)
{
    advent::Diagnostic report;
    if (advent::read_input(report))
    {
        std::cout << "Part1.Result: " << advent::calculate_power_consumtion(report) << std::endl;
        std::cout << "Part2.Result: " << advent::get_life_support_rating_of_submarine(report) << std::endl;

    }
    return 0;
}