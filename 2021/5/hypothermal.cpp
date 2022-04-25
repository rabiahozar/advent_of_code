#include <fstream>
#include <sstream>
#include <algorithm>

#include <hypothermal.h>
// TODO make dynamic
#define COLUMN_SIZE 10
#define ROW_SIZE 10

namespace advent
{
auto Visualize(std::map<int, int>& cover_map)
{
    // Visualization
    for (int count = 0; count < 100 ; count++)
    {
        if ((count%COLUMN_SIZE) == 0)
        {
            std::cout << std::endl;
        }
        if (cover_map.count(count)==0)
        {
            std::cout << '.' ;
        }
        else
        {
            std::cout << cover_map[count];
        }
    }
}
auto Day5::ReadInput() -> int
{
    std::ifstream in_file;

    in_file.open("day_5_input.txt");
    if (in_file.is_open())
    {
        std::string line;
        while(std::getline(in_file, line))
        {
            std::stringstream streamer(line);
            std::vector<int> numbers;
            for (int number ; streamer >> number;)
            {
                numbers.push_back(number);
                while (streamer.peek() == ',' || streamer.peek() == ' ' || streamer.peek() == '-'|| streamer.peek() == '>')
                {
                    streamer.ignore();
                }
            }
            if (numbers.size() == 4)
            {
                _intervals.emplace_back(std::make_pair(numbers[0], numbers[1]), std::make_pair(numbers[2], numbers[3]));
            }
        }
 
        in_file.close();
        return 0;
    }
    return -1;
}
auto Day5::MarkCoveredLines2() -> void 
{
    for (const auto& internal : _intervals)
    {
        // x1,y1 < x2, y2 right
        if (internal.first.first < internal.second.first)
        {
            int start_x = internal.first.first;
            int end_x = internal.second.first;
            int start_y, end_y;
            
            // right and down
            if (internal.first.second < internal.second.second)
            {
                start_y = internal.first.second;
                end_y = internal.second.second;
                for (; start_x <= end_x , start_y <= end_y ; start_x++, start_y++)
                {
                    std::cout << "Cover RD: " << start_x << "," << start_y << std::endl;
                    int index = start_y*COLUMN_SIZE + start_x;
                    if (_cover_map.find(index) != _cover_map.end())
                    {
                        _cover_map[index] = 1;
                    }
                    else
                    {
                        _cover_map[index]++;
                    }
                }

            }
            else if ((internal.first.second > internal.second.second)) // right up
            {
                start_y = internal.first.second;
                end_y = internal.second.second;

                for (; start_x <= end_x , start_y >= end_y ; start_x++, start_y--)
                {
                    std::cout << "Cover RU: " << start_x << "," << start_y << std::endl;
                    int index = start_y*COLUMN_SIZE + start_x;
                    if (_cover_map.find(index) != _cover_map.end())
                    {
                        _cover_map[index] = 1;
                    }
                    else
                    {
                        _cover_map[index]++;
                    }
                }
            }
        }
        else if (internal.first.first > internal.second.first)
        {
            int start_x = internal.first.first;
            int end_x = internal.second.first;
            int start_y, end_y;
            // y1 > y2
            
            // left and down
            if (internal.first.second < internal.second.second)
            {
                start_y = internal.first.second;
                end_y = internal.second.second;
                for (; start_x >= end_x , start_y <= end_y ; start_x--, start_y++)
                {
                    std::cout << "Cover LD: " << start_x << "," << start_y << std::endl;
                    int index = start_y*COLUMN_SIZE + start_x;
                    if (_cover_map.find(index) != _cover_map.end())
                    {
                        _cover_map[index] = 1;
                    }
                    else
                    {
                        _cover_map[index]++;
                    }
                }

            }
            else if (internal.first.second > internal.second.second)// left and up
            {
                start_y = internal.first.second;
                end_y = internal.second.second;

                for (; start_x >= end_x , start_y >= end_y ; start_x--, start_y--)
                {
                    std::cout << "Cover LU: " << start_x << "," << start_y << std::endl;
                    int index = start_y*COLUMN_SIZE + start_x;
                    if (_cover_map.find(index) != _cover_map.end())
                    {
                        _cover_map[index] = 1;
                    }
                    else
                    {
                        _cover_map[index]++;
                    }
                }
            }
        }
    }
    Visualize(_cover_map);
}

auto Day5::MarkCoveredLines() -> void 
{
    for (const auto& internal : _intervals)
    {
        // x1 = x2
        if (internal.first.first == internal.second.first)
        {
            int start, end;
            // y1 > y2
            if (internal.first.second > internal.second.second)
            {
                end = internal.first.second;
                start = internal.second.second;
            }
            else // y2>=y1
            {
                start = internal.first.second;
                end = internal.second.second;
            }
            for (; start <= end;start++)
            {
                int index =start*ROW_SIZE + internal.first.first;
                if (_cover_map.count(index) == 0)
                {
                    _cover_map[index] = 1;
                }
                else
                {
                    _cover_map[index]++;
                }
            }
        }
        else if (internal.first.second == internal.second.second) // y1 = y2
        {
            int start, end;
            // x1 > x2
            if (internal.first.first > internal.second.first)
            {
                end = internal.first.first;
                start = internal.second.first;
            }
            else // x2 >= x2
            {
                start = internal.first.first;
                end = internal.second.first;
            }
            for (; start <= end;start++)
            {
                int index = internal.first.second*ROW_SIZE + start;
                if (_cover_map.count(index) == 0)
                {
                    _cover_map[index] = 1;
                }
                else
                {
                    _cover_map[index]++;
                }
            }
        }
    }
    Visualize(_cover_map);
}
auto Day5::CountIntersections() -> int
{
    int count_of_interfactions { 0 };
    for (const auto& iterator:_cover_map)
    {
        if (iterator.second >= 2)
        {
            count_of_interfactions++;
        }
    }
    return count_of_interfactions;
}
auto Day5::Solve() -> void
{
    const auto& res = ReadInput();
    if (res == 0)
    {
        MarkCoveredLines();
        std::cout << "Part1.Result: " << CountIntersections() << std::endl;
        MarkCoveredLines2();
        std::cout << "Part2.Result: " << CountIntersections() << std::endl;
    }
}
} //namespace advent

