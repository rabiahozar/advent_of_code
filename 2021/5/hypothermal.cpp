#include <fstream>
#include <sstream>
#include <algorithm>

#include <hypothermal.h>
// TODO make dynamic
#define COLUMN_SIZE 1000
#define ROW_SIZE 1000

namespace advent
{
auto find_map_index(int row, int column) -> int
{
    return row*COLUMN_SIZE+column;
}
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
auto Day5::MarktPoint(int index) -> void
{
    if (_cover_map.count(index)==0)
    {
        _cover_map[index] = 1;
    }
    else
    {
        _cover_map[index]++;
    }
}
auto Day5::FindHorizantalDirection(const Coordinate& start_coordination, const Coordinate& end_coordination) -> Direction
{
    if (start_coordination.first < end_coordination.first)
    {
        return RIGHT;
    }
    else if (start_coordination.first > end_coordination.first)
    {
        return LEFT;
    }
    else 
    {
        return NOT_MOVE;
    }
}
auto Day5::FindVerticalDirection(const Coordinate& start_coordination, const Coordinate& end_coordination) -> Direction
{
    if (start_coordination.second < end_coordination.second)
    {
        return DOWN;
    }
    else if (start_coordination.second > end_coordination.second)
    {
        return UP;
    }
    else
    {
        return NOT_MOVE;
    }
}
auto Day5::MarkCoveredDiagonalLines() -> void 
{
    for (const auto& interval : _intervals)
    {
        const auto& start_coordination = interval.first;
        const auto& end_coordination = interval.second;
        const auto horizantal_direction = FindHorizantalDirection(start_coordination,end_coordination);
        if (horizantal_direction == RIGHT)
        {
            int start_x = start_coordination.first;
            int end_x = end_coordination.first;
            int start_y = start_coordination.second;
            int end_y = end_coordination.second;

            const auto vertical_direction = FindVerticalDirection(start_coordination,end_coordination);
            if (vertical_direction == DOWN)
            {
                for (; start_x <= end_x , start_y <= end_y ; start_x++, start_y++)
                {
                    MarktPoint(find_map_index(start_y, start_x));
                }
            }
            else if (vertical_direction == UP) 
            {
                for (; start_x <= end_x , start_y >= end_y ; start_x++, start_y--)
                {
                    MarktPoint(find_map_index(start_y, start_x));
                }
            }
        }
        else if (horizantal_direction == LEFT) 
        {
            int start_x = start_coordination.first;
            int end_x = end_coordination.first;
            int start_y = start_coordination.second;
            int end_y = end_coordination.second;

            const auto vertical_direction = FindVerticalDirection(start_coordination,end_coordination);
            if (vertical_direction == DOWN)
            {
                for (; start_x >= end_x , start_y <= end_y ; start_x--, start_y++)
                {
                    MarktPoint(find_map_index(start_y, start_x));
                }
            }
            else if (vertical_direction == UP)
            {
                for (; start_x >= end_x , start_y >= end_y ; start_x--, start_y--)
                {
                    MarktPoint(find_map_index(start_y, start_x));
                }
            }
        }
    }
    // Visualize(_cover_map);
}

auto Day5::MarkCoveredLines() -> void 
{
    for (const auto& interval : _intervals)
    {
        const auto& start_coordination = interval.first;
        const auto& end_coordination = interval.second;

        // x1 = x2
        if (FindHorizantalDirection(start_coordination,end_coordination) == NOT_MOVE)
        {
            int start, end;
            // y1 > y2
            auto direction = FindVerticalDirection(start_coordination,end_coordination);
            if (direction == UP)
            {
                end = start_coordination.second;
                start = end_coordination.second;
            }
            else // y2>=y1
            {
                start = start_coordination.second;
                end = end_coordination.second;
            }
            for (; start <= end;start++)
            {
                MarktPoint(find_map_index(start, start_coordination.first));
            }
        }
        else if (FindVerticalDirection(start_coordination,end_coordination) == NOT_MOVE) // y1 = y2
        {
            int start, end;
            
            auto direction = FindHorizantalDirection(start_coordination,end_coordination);
            if (direction == LEFT)
            {
                end = start_coordination.first;
                start = end_coordination.first;
            }
            else 
            {
                start = start_coordination.first;
                end = end_coordination.first;
            }
            for (; start <= end;start++)
            {
                MarktPoint(find_map_index(start_coordination.second, start));
            }
        }
    }
    // Visualize(_cover_map);
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
        MarkCoveredDiagonalLines();
        std::cout << "Part2.Result: " << CountIntersections() << std::endl;
    }
}
} //namespace advent

