#include "player.hpp"
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <math.h>

#define possibleWins 76
namespace TICTACTOE3D
{
const int winningPositions[possibleWins][4] = {{0, 4, 8, 12}, {1, 5, 9, 13}, {2, 6, 10, 14}, {3, 7, 11, 15}, {16, 20, 24, 28}, {17, 21, 25, 29}, {18, 22, 26, 30}, {19, 23, 27, 31}, {32, 36, 40, 44}, {33, 37, 41, 45}, {34, 38, 42, 46}, {35, 39, 43, 47}, {48, 52, 56, 60}, {49, 53, 57, 61}, {50, 54, 58, 62}, {51, 55, 59, 63}, {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}, {16, 17, 18, 19}, {20, 21, 22, 23}, {24, 25, 26, 27}, {28, 29, 30, 31}, {32, 33, 34, 35}, {36, 37, 38, 39}, {40, 41, 42, 43}, {44, 45, 46, 47}, {48, 49, 50, 51}, {52, 53, 54, 55}, {56, 57, 58, 59}, {60, 61, 62, 63}, {0, 16, 32, 48}, {4, 20, 36, 52}, {8, 24, 40, 56}, {12, 28, 44, 60}, {1, 17, 33, 49}, {5, 21, 37, 53}, {9, 25, 41, 57}, {13, 29, 45, 61}, {2, 18, 34, 50}, {6, 22, 38, 54}, {10, 26, 42, 58}, {14, 30, 46, 62}, {3, 19, 35, 51}, {7, 23, 39, 55}, {11, 27, 43, 59}, {15, 31, 47, 63}, {0, 5, 10, 15}, {16, 21, 26, 31}, {32, 37, 42, 47}, {48, 53, 58, 63}, {3, 6, 9, 12}, {19, 22, 25, 28}, {35, 38, 41, 44}, {51, 54, 57, 60}, {0, 17, 34, 51}, {4, 21, 38, 55}, {8, 25, 42, 59}, {12, 29, 46, 63}, {3, 18, 33, 48}, {7, 22, 37, 52}, {11, 26, 41, 56}, {15, 30, 45, 60}, {0, 20, 40, 60}, {1, 21, 41, 61}, {2, 22, 42, 62}, {3, 23, 43, 63}, {12, 24, 36, 48}, {13, 25, 37, 49}, {14, 26, 38, 50}, {15, 27, 39, 51}, {0, 21, 42, 63}, {3, 22, 41, 60}, {12, 25, 38, 51}, {15, 26, 37, 48}};

const int heuristics[5][5] = {
  {0,     -10, -100,  -1000, -10000},
  {10,     0,    0,    0,    0},
  {100,    0,    0,    0,    0},
  {1000,   0,    0,    0,    0},
  {10000,  0,    0,    0,    0}
};

int gamma(const GameState &state){
  if(state.isEOG()){
    if( state.isXWin() == true ){
      return 100000;
    }else if( state.isOWin() == true ){
      return -100000;
    }else{
      return 0;
    }
  }

  uint8_t cell_value;
  int t = 0;
  int p, o, i, j;

  for(i=0;i<possibleWins;i++){
    p = o = 0;
    for(j=0;j<4;j++){
      cell_value = state.at(winningPositions[i][j]);
      if(cell_value & CELL_X){
        p++;
      }else if(cell_value & CELL_O){
        o++;
      }
    }
    t += heuristics[p][o];
  }

  return t;
}

int minimax(const GameState &state, int depth, int alpha, int beta, uint8_t player){
  std::vector<GameState> mu;
  state.findPossibleMoves(mu);
  int v = 0;

  if( state.isEOG() || depth == 0){
    v = gamma(state);
  }else{
    uint8_t nextPlayer = (player == CELL_X) ? CELL_O : CELL_X;
    depth--;
    if( player == CELL_X){
      v = std::numeric_limits<int>::min();
      for( auto child : mu ){
        v = std::max(v, minimax(child, depth-1, alpha, beta, nextPlayer));
        alpha = std::max(v, alpha);
        if( beta <= alpha ){
          //beta prune
          break;
        }
      }
    }else{ // player == 'B'
      v = std::numeric_limits<int>::max();
      for( auto child : mu ){
        v = std::min(v, minimax(child, depth-1, alpha, beta, nextPlayer));
        beta = std::min(v, beta);
        if( beta <= alpha ){
          //alpha prune
          break;
        }
      }
    }
  }
  return v;
}

GameState Player::play(const GameState &pState,const Deadline &pDue)
{
    //std::cerr << "Processing " << pState.toMessage() << std::endl;

    std::vector<GameState> lNextStates;
    pState.findPossibleMoves(lNextStates);


    if (lNextStates.size() == 0) return GameState(pState, Move());

    /*
     * Here you should write your clever algorithms to get the best next move, ie the best
     * next state. This skeleton returns a random move instead.
     */
     uint8_t player = (pState.getNextPlayer() == CELL_X) ? CELL_O : CELL_X;

     int depth = 0;
     int alpha = std::numeric_limits<int>::min();
     int beta = std::numeric_limits<int>::max();

     int v = 0;
     int bestValue = std::numeric_limits<int>::min();
     GameState bestState = lNextStates[0];

     for( auto child : lNextStates ){
       if(pDue.now() > pDue-.1){
         break;
       }
       v = minimax(child, depth, alpha, beta, player);
       if( v > bestValue ){
         bestValue = v;
         bestState = child;
       }
     }


     return bestState;
}

/*namespace TICTACTOE3D*/ }
