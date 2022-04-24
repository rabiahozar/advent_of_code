#pragma once

#include <iostream>
#include <vector>
#include <map>

#include <advent.h>

namespace advent {

using Coordinate = std::pair<int, int>;
using Coordinates = std::map<int, Coordinate>;
using CellContent = std::pair<int, bool>;
using Row = std::vector<CellContent>;
using Board = std::vector<Row>;

class Day4 : public AdventOfCode
{
private:
    // methods
    auto ReadInput() -> int;
    auto MarkVisited(Board& board, const Coordinate& coordinate) -> void;
    auto IsVisited(const CellContent& cell) -> bool;
    auto IsBingo(const Board& board) -> bool;
    auto CalculateBoardScore(Board& board, int selected_number) -> int;

    /**
     * @brief Returns winning board number score
     * 
     * @return int 
     */
    auto FindWinnerBoardScore() -> int;
    /**
     * @brief Returns losing board score
     * 
     * @return int 
     */
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