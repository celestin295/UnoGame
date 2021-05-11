#include "card.h"
#include <iostream>
#include <string>
#include <vector>

Color Card::getColor() const{
    return color;
}
    
int Card::getNumber() const{
    return number;
}

string Card::getCardType() const{
    return cardType;
}

void Card::setColor(Color c){
    color = c;
}

void Card::setNumber(int n){
    number = n;
}

void Card::setCardType(string s) {
    cardType = s;
}

NumberCard::NumberCard(Color c, int n) {
    setColor(c);
    setNumber(n);
    setCardType("number");
}
string NumberCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|     " <<  number << "     |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
bool NumberCard::play(Card* discard, GameState &gameState) {
    if(color == discard->getColor() || number == discard->getNumber()){
        return true;
    } else {
        return false;
    }
}


ReverseCard::ReverseCard(Color c) {
    setColor(c);
    setCardType("reverse");
}
string ReverseCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|  REVERSE  |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
bool ReverseCard::play(Card* discard, GameState &gameState) {
    if((color == discard->getColor()) || ("reverse" == discard->getCardType())) {
        if(gameState.turnDirection == LEFT) {
           gameState.turnDirection = RIGHT; 
        } else {
           gameState.turnDirection = LEFT;  
        }
    } else {
        return false;
    }
}


SkipCard::SkipCard(Color c) {
    setColor(c);
    setCardType("skip");
}
string SkipCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|   SKIP    |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
bool SkipCard::play(Card* discard, GameState &gameState) {
    if((color == discard->getColor()) || ("skip" == discard->getCardType())) {
        gameState.skipTurn = true;
    } else {
        return false;
    }
}

DrawTwoCard::DrawTwoCard(Color c) {
    setColor(c);
    setCardType("draw");
}
string DrawTwoCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
            switch(color){
            case RED:
                return "|    RED    |";
                break;
            case BLUE:
                return "|    BLUE   |";
                break;
            case GREEN:
                return "|   GREEN   |";
                break;
            case YELLOW:
                return "|  YELLOW   |";
                break;
            default:
                return "|           |";
                break;
            break;
            }
        case 3:
            ss << "|  DRAW TWO |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
bool DrawTwoCard::play(Card* discard, GameState &gameState) {
    if((color == discard->getColor()) || ("draw" == discard->getCardType())) {
        gameState.skipTurn = true;
        gameState.numCardsToDraw = 2;
    } else {
        return false;
    }
}


WildCard::WildCard() {
    setCardType("wild");
}
string WildCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
                return "|           |";
        case 3:
            ss << "| WILD CARD |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
bool WildCard::play(Card* discard, GameState &gameState) {
    gameState.wildCardPlayed = true;
    int c;
    cout << "What do you want to change the color to? (RED = 1, YELLOW = 2, BLUE = 3, GREEN = 4)" << endl;
    cin >> c;
    
    switch(c) {
        case 1:
        gameState.wildCardColor = 1;
        break;
        
        case 2:
        gameState.wildCardColor = 2;
        break;
        
        case 3:
        gameState.wildCardColor = 3;
        break;
        
        case 4:
        gameState.wildCardColor = 4;
        break;
    }
}

DrawFourCard::DrawFourCard() {
    setCardType("draw");
}
string DrawFourCard::render(int line) const{
    stringstream ss;
    switch(line){
        case 0: return ".___________.";
        case 1: return "|           |";
        case 2: 
                return "|           |";
        case 3:
            ss << "| DRAW FOUR |";
            return ss.str();
            break;
        case 4: return "|           |";
        case 5: return "|           |";
        case 6: return "|           |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
bool DrawFourCard::play(Card* discard, GameState &gameState) {
    gameState.wildCardPlayed = true;
    int c;
    cout << "What do you want to change the color to? (RED = 1, YELLOW = 2, BLUE = 3, GREEN = 4)" << endl;
    cin >> c;
    
    switch(c) {
        case 1:
        gameState.wildCardColor = 1;
        break;
        
        case 2:
        gameState.wildCardColor = 2;
        break;
        
        case 3:
        gameState.wildCardColor = 3;
        break;
        
        case 4:
        gameState.wildCardColor = 4;
        break;
    }
    
    gameState.skipTurn = true;
    gameState.numCardsToDraw = 4;
}