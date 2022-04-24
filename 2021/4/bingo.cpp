#include <fstream>
#include <sstream>
#include <set>

#include <bingo.h>

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

auto Day4::ReadInput() -> int
{
    std::ifstream in_file;
    
    in_file.open("day_4_input.txt");
    if (in_file.is_open())
    {
        std::string line;
        bool is_first_line = true;
        while(std::getline(in_file, line) && is_first_line)
        {
            is_first_line = false;
            helper::comma_sepeated_string_to_vector(line, _selected_numbers);
        }

        Coordinates coordinate{};
        Board board{};
        int board_row_number= 0;
        std::vector<int> board_numbers;
        while(std::getline(in_file, line))
        {
            if (line.compare("") == 0 ) continue;  
            board_numbers.clear();

            helper::space_sepeated_string_to_vector(line, board_numbers);
            board.push_back(Row());
            for(int column=0; column < board_numbers.size(); column++)
            {
                coordinate[board_numbers[column]] = std::make_pair(board_row_number, column);
                board[board_row_number].push_back(std::move(std::make_pair(board_numbers[column], false)));

            }
            board_row_number++;
            
            if (board_row_number == 5)
            {
                board_row_number = 0;
                _coordinates.push_back(std::move(coordinate));
                _boards.push_back(std::move(board));
                board.clear();
                coordinate.clear();
            }
        } 
        in_file.close();
        return 0;
    }
    return -1;
}

auto Day4::MarkVisited(Board& board, int row, int column) -> void
{
    board[row][column].second = true;
}
auto Day4::IsBingo(Board& board) -> bool
{
    // search bingo horizontal
    for (int x = 0 ; x < board.size() ; x++)
    {
        bool is_bingo = true;
        for (int y = 0 ; y < board[x].size() ; y++)
        {
            is_bingo = is_bingo && board[x][y].second;
        }
        if ( is_bingo) return is_bingo;
    }
    if (board.size() == 0) return false;
    // search bingo vertical
    for (int y = 0 ; y < board[0].size() ; y++)
    {
        bool is_bingo = true;
        for (int x = 0 ; x < board.size() ; x++)
        {
            is_bingo = is_bingo && board[x][y].second;
        }
        if ( is_bingo) return is_bingo;
    }
    return false;
}

auto Day4::CalculateBoardScore(Board& board, int selected_number) -> int
{
    int board_score = 0;
    for (int i = 0 ; i < board.size() ; i++)
    {
        for (int y = 0 ; y < board[i].size() ; y++)
        {
            if (!board[i][y].second)
            {
                board_score += board[i][y].first;
            }
        }
    }
    return board_score*selected_number;
}

auto Day4::FindWinnerBoardScore() -> int 
{
    for (int number : _selected_numbers)
    {
        for (int i = 0 ; i < _boards.size(); i++)
        {
            auto& board = _boards[i];
            if (_coordinates[i].find(number) != _coordinates[i].end())
            {
                MarkVisited(board, _coordinates[i][number].first, _coordinates[i][number].second);
            }
            if (IsBingo(board))
            {
                return CalculateBoardScore(board, number);
            }
        }
    }
    return 0;
}
auto Day4::FindLoserBoardScore() -> int
{
    std::set<int>  already_won_boards;
    for (int number : _selected_numbers)
    {
        for (int i = 0 ; i < _boards.size(); i++)
        {
            if (already_won_boards.size()>0)
            {
                if (already_won_boards.find(i) != already_won_boards.end())
                {
                    continue;
                }
            }
            auto& board = _boards[i];
            if (_coordinates[i].find(number) != _coordinates[i].end())
            {
                MarkVisited(board, _coordinates[i][number].first, _coordinates[i][number].second);
            }
            if (IsBingo(board))
            {
                if (already_won_boards.size() == _boards.size()-1)
                {
                    return CalculateBoardScore(board, number);
                }
                already_won_boards.insert(i);
            }
        }
    }
    return 0;
}

auto Day4::Solve() -> void
{
    const auto& res = ReadInput();
    if (res == 0)
    {
        std::cout << "Part1.Result: " << FindWinnerBoardScore() << std::endl;
        std::cout << "Part2.Result: " << FindLoserBoardScore() << std::endl;
    }
}
} //namespace advent
