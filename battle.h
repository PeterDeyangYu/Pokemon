#ifndef BATTLE_H
#define BATTLE_H
#include <time.h>
#include <cstdlib>
#include "pokemondatabase.h"
#include "player.h"

class Battle{
public:
    int Wild_Encounter();
    Battle(Player & testplayer);

private:

    Player & player;
    Pokemon p;
    int bdg = 0;
    int pokeball = 50;
    int greatball = 0;
    int ultraball = 0;
    int masterball = 1;


};


#endif // BATTLE_H
