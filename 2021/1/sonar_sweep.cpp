#include <sonar_sweep.h>
#include <fstream>

namespace advent
{
auto Day1::read_input(std::vector<int>& numbers) -> int
{
    std::ifstream in_file;
    
    in_file.open("day_1_input.txt");

    if (in_file.is_open())
    {
        int line;
        while(in_file >> line)
        {
            numbers.push_back(line);
        }
        in_file.close();
        return numbers.size();
    }
    return -1;
}

auto Day1::calculate_increased_days(std::vector<int>& numbers) -> int
{
    int count = 0;
    for (int front = 0, back = front+1; back < numbers.size(); front++, back++)
    {
        if (numbers[back] > numbers[front])
        {
            count ++;
        }
    }
    return count;
}

auto Day1::calculate_increased_window_count(std::vector<int>& numbers) -> int
{
    std::vector<int> sums;
    const int windows_size = 3;
    for (int front = 0; front < numbers.size()-2; front++)
    {
        int window_sum = 0;
        for (int i =0; i < windows_size ; i++)
        {
            window_sum += numbers[front+i];
        }
        
        sums.push_back(window_sum);
    }
    return calculate_increased_days(sums);
}
auto Day1::solve() -> void
{
    std::vector<int> numbers;
    if (read_input(numbers))
    {
        std::cout << "Day1.Part1.Result: " << calculate_increased_days(numbers) << std::endl;
        std::cout << "Day1.Part2.Result: " << calculate_increased_window_count(numbers) << std::endl;

    }
}
} //namespace advent
