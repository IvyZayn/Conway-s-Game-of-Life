#include "golGameofLife.h"
#include <iostream>

namespace gol
{
  GameofLife::GameofLife(const Status &s) : m_currstatus(s) {}
  GameofLife::~GameofLife() {}

  void GameofLife::TakeStep()
  {

    Status m_nextstatus = m_currstatus;

    for (int i = 0; i < m_currstatus.m_rows; i++)
    {
      for (int j = 0; j < m_currstatus.m_columns; j++)
      {
        if ((m_currstatus.StatusGet(i, j) == "-") && (m_currstatus.NeighAlive(i, j) == 3))
        { //Check for rule 1
          m_nextstatus.m_grid[i][j] = 1;
        }
        else if ((m_currstatus.StatusGet(i, j) == "o") && ((m_currstatus.NeighAlive(i, j) == 3) || (m_currstatus.NeighAlive(i, j) == 2)))
        { //Check for rule 2
          m_nextstatus.m_grid[i][j] = 1;
        }
        else if (m_currstatus.StatusGet(i, j) == "o")
        { //Check for rule 3
          m_nextstatus.m_grid[i][j] = 0;
        }
      }
    }
    m_currstatus = m_nextstatus;
  }

  void GameofLife::PrintGrid()
  {
    m_currstatus.StatusPrint();
    std::cout << "-------------------------" << std::endl;
  }

} // end namespace
