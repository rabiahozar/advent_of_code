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
    
    in_file.open("/mnt/test/adventofcode/2021/3/input.txt");

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
} // end of advent

int main(int argc, char **argv)
{
    advent::Diagnostic report;
    if (advent::read_input(report))
    {
        std::cout << "Part1.Result: " << advent::calculate_power_consumtion(report) << std::endl;

    }
    return 0;
}