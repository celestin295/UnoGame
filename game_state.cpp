#include "game_state.h"
#include "card.h"
#include <vector>

using namespace std;

GameState::GameState(int n){
    numPlayers = n;
    currentPlayerIndex = 0;
    numCardsToPlay = 1;
    numCardsToDraw = 0;
    turnDirection = LEFT;
}

void GameState::nextTurn(){
    previousPlayerIndex = currentPlayerIndex;
    
    if(turnDirection == LEFT){
        currentPlayerIndex++;
        if(currentPlayerIndex >= numPlayers){
            currentPlayerIndex = 0;
        }
    } else {
        currentPlayerIndex--;
        if(currentPlayerIndex < 0)
            currentPlayerIndex = numPlayers - 1;
    }
}
