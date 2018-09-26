#include "player.hpp"
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <math.h>

namespace TICTACTOE
{

int sumCols(const GameState &state, uint8_t player, uint8_t opponent){
  int sum = 0;
  for(int i=0;i<4;i++){
    int cnt = 0;
    int tmp = 0;
    bool inSameCol = false;
    for(int j=0;j<4;j++){
      if(state.at(i,j) == opponent){
        tmp = 0;
        break;
      }else if(state.at(i,j) == player){
        tmp = pow(10,cnt);
        cnt++;
      }
    }
    sum += tmp;
  }
  return sum;
}

int sumRows(const GameState &state, uint8_t player, uint8_t opponent){
  int sum = 0;
  for(int i=0;i<4;i++){
    int cnt = 0;
    int tmp = 0;
    for(int j=0;j<4;j++){
      if(state.at(j,i) == opponent){
        tmp = 0;
        break;
      }else if(state.at(j,i) == player){
        tmp = pow(10,cnt);
        cnt++;
      }
    }
    sum += tmp;
  }
  return sum;
}

int sumDiags(const GameState &state, uint8_t player, uint8_t opponent){
  int sum = 0;
  //Diag 1
  int cnt = 0;
  int tmp = 0;
  for(int i=0; i<4; i++){
    if(state.at(i,i) == opponent){
      tmp = 0;
      break;
    }else if(state.at(i,i) == player){
      tmp = pow(10,cnt);
      cnt++;
    }
  }
  sum += tmp;

  //Diag 2
  tmp = 0;
  cnt = 0;
  for(int i=0; i<4; i++){
    if(state.at(i,3-i) == opponent){
      tmp = 0;
      break;
    }else if(state.at(i,3-i) == player){
      tmp = pow(10,cnt);
      cnt++;
    }
  }
  sum += tmp;

  return sum;
}

int gamma(const GameState &state, uint8_t player){
  uint8_t opponent = (player == CELL_X) ? CELL_O : CELL_X;
  if( state.isXWin() == true ){
    return 10000;
  }else if( state.isOWin() == true ){
    return -10000;
  }else if( state.isDraw() == true){
    return 0;
  }else{
    return sumCols(state, player, opponent) + sumRows(state, player, opponent) + sumDiags(state, player, opponent);
  }
}

int minimax(const GameState &state, int depth, int alpha, int beta, uint8_t player){
  std::vector<GameState> mu;
  state.findPossibleMoves(mu);
  int v = 0;

  if( mu.size() == 0 || depth == 0){
    v = gamma(state, player);
    return gamma(state, player);
  }else{
    uint8_t nextPlayer = (player == CELL_X) ? CELL_O : CELL_X;
    depth--;
    if( player == CELL_X){
      v = std::numeric_limits<int>::min();
      for( auto child : mu){
        v = std::max(v, minimax(child, depth-1, alpha, beta, nextPlayer));
        alpha = std::max(v, alpha);
        if( alpha >= beta ){
          //beta prune
          break;
        }
      }
    }else{ // player == 'B'
      v = std::numeric_limits<int>::max();
      for( auto child : mu){
        v = std::min(v, minimax(child, depth-1, alpha, beta, nextPlayer));
        beta = std::min(v, beta);
        if( alpha >= beta ){
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

    int depth = 2;
    int alpha = std::numeric_limits<int>::min();
    int beta = std::numeric_limits<int>::max();

    int v = 0;
    int bestValue = std::numeric_limits<int>::min();
    GameState bestState;

    for( auto child : lNextStates ){
      v = minimax(child, depth, alpha, beta, player);
      if( v > bestValue ){
        bestValue = v;
        bestState = child;
      }
    }


    return bestState;
}

/*namespace TICTACTOE*/ }
