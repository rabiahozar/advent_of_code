#pragma once
#include <string>
#include <vector>
#include <sstream>

namespace advent
{
namespace helper
{
auto comma_sepeated_string_to_vector(const std::string& string, std::vector<int>& numbers) -> void
{
    std::stringstream streamer(string);
    for (int number ; streamer >> number;)
    {
        numbers.push_back(number);
        while (streamer.peek() == ',' || streamer.peek() == ' ')
        {
            streamer.ignore();
        }
    }
}
auto space_sepeated_string_to_vector(const std::string& string, std::vector<int>& numbers) -> void
{
    std::stringstream streamer(string);
    for (int number ; streamer >> number;)
    {
        numbers.push_back(number);
        while (streamer.peek() == ' ')
        {
            streamer.ignore();
        }
    }
}
} // namespace helper
}