#include <iostream>
#include <fstream>
#include <vector>

namespace advent
{
int read_input(std::vector<int>& numbers)
{
    std::ifstream in_file;
    
    in_file.open("input.txt");

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

int calculate_increased_days(std::vector<int>& numbers)
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

int calculate_increased_window_count(std::vector<int>& numbers)
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
}
int main(int argc, char **argv)
{
    std::vector<int> numbers;
    if (advent::read_input(numbers))
    {
        std::cout << "Part1.Result: " << advent::calculate_increased_days(numbers) << std::endl;
        std::cout << "Part2.Result: " << advent::calculate_increased_window_count(numbers) << std::endl;

    }
    return 0;
}