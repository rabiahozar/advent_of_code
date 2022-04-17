#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using Command = std::pair<std::string, int>;

int read_input(std::vector<Command>& commands)
{
    std::ifstream in_file;
    
    in_file.open("/mnt/test/adventofcode/2021/2/input.txt");

    if (in_file.is_open())
    {
        std::string line;
        std::string command_direction;
        int command_amount;
        while(std::getline(in_file, line))
        {
            std::istringstream streamer(line);
            streamer >> command_direction;
            streamer >> command_amount;

            commands.push_back(std::make_pair(command_direction, command_amount));
        }
        in_file.close();
        return commands.size();
    }
    return -1;
}

int move(std::vector<Command>& commands)
{
    int position_x = 0;
    int position_y = 0;
    for (auto& command : commands)
    {
        if (command.first == "forward")
        {
            position_x += command.second;
        }
        else if (command.first == "up")
        {
            position_y -= command.second;
        }
        else if (command.first == "down")
        {
            position_y += command.second;
        }
    }
    return position_x * position_y;
}

double move_with_aim(std::vector<Command>& commands)
{
    double position_x = 0;
    double position_y = 0;
    double aim = 0;
    for (auto& command : commands)
    {
        if (command.first == "forward")
        {
            position_x += command.second;
            position_y += aim*command.second;
        }
        else if (command.first == "up")
        {
            aim -= command.second;
        }
        else if (command.first == "down")
        {
            aim += command.second;
        }
    }
    std::cout << position_x << " " << position_y << std::endl;
    return position_x * position_y;
}

int main(int argc, char **argv)
{
    std::vector<Command> commands;
    if (read_input(commands))
    {
        std::cout << "Part1.Result: " << move(commands) << std::endl;
        std::cout <<  std::fixed << "Part2.Result: " << move_with_aim(commands) << std::endl;

    }
    return 0;
}