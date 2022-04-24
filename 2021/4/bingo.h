#pragma once

#include <iostream>
#include <vector>
#include <map>

#include <advent.h>

namespace advent {

using Coordinates = std::map<int, std::pair<int, int>>;
using CellContent = std::pair<int, bool>;
using Row = std::vector<CellContent>;
using Board = std::vector<Row>;

class Day4 : public AdventOfCode
{
private:
    // methods
    auto ReadInput() -> int;
    auto MarkVisited(Board& board, int row, int column) -> void;
    auto IsBingo(Board& board) -> bool;
    auto CalculateBoardScore(Board& board, int selected_number) -> int;

    /**
     * @brief Returns board number score
     * 
     * @return int 
     */
    auto FindWinnerBoardScore() -> int;
    auto FindLoserBoardScore() -> int;
private:  
    // variables
    std::vector<Coordinates> _coordinates;
    std::vector<Board> _boards;
    std::vector<int> _selected_numbers;
public:
    auto Solve() -> void override;
};

}  // namespace advent