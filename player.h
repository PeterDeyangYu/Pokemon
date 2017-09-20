#ifndef PLAYER_H
#define PLAYER_H
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <windows.h>
#include "pokemon.h"
#include <thread>
#include <chrono>
//#include "battle.h"

using namespace std;

class Player
{
public:
    Player();
    Pokemon* PlayerPokemon[6];
    string playerName;
    string action;
    int gym_counter = 1;
    int rccc = 1;

    void introduction();
    void playthrough();
};
#endif // PLAYER_H
