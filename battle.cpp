#include "battle.h"

/*
 * The capture method in Generation I differs significantly from those of later generations. To determine whether a Pokémon is caught or not, the steps below are performed. If, at any point, the Pokémon is caught or breaks free, the steps following that point are not performed.

    If a Master Ball is used, the Pokémon is caught.
    Generate a random number, N, depending on the type of ball used.
        For a Poké Ball: 0 to 255.
        For a Great Ball: 0 to 200.
        Otherwise (Ultra Ball or Safari Ball): 0 to 150.
    The Pokémon is caught if...
        It is asleep or frozen and N is less than 25.
        It is paralyzed, burned, or poisoned and N is less than 12.
    Otherwise, if N minus the status threshold (above) is greater than the Pokémon's catch rate, the Pokémon breaks free.
    If not, generate a random value, M, between 0 and 255.
    Calculate f:
        f = (HPmax * 255 * 4) / (HPcurrent * Ball), where all divisions are rounded down to the nearest integer. The minimum value of f is 1 and its maximum value is 255. The value of Ball is 8 if a Great Ball is used or 12 otherwise.
    If f is greater than or equal to M, the Pokémon is caught. Otherwise, the Pokémon breaks free. In practical terms, lowering the target's HP to 1/3 of its maximum will guarantee capture with a Poké Ball, while lowering it to 1/2 will guarantee capture with a Great Ball.

If the Pokémon broke free, the steps below are performed to determine how many times the ball will shake.

    Calculate d:
        d = Catch rate × 100 / Ball, where the value of Ball is 255 for the Poké Ball, 200 for the Great Ball, or 150 for other balls.
    If d is greater than or equal to 256, the ball shakes three times before the Pokémon breaks free.
    If not, calculate x = d × f / 255 + s, where s is 10 if the Pokémon is asleep or frozen or 5 if it is paralyzed, poisoned, or burned.
    If...
        x < 10: the Ball misses the Pokémon completely.
        x < 30: the Ball shakes once before the Pokémon breaks free.
        x < 70: the Ball shakes twice before the Pokémon breaks free.
        Otherwise, the Ball shakes three times before the Pokémon breaks free.
 * */


Battle::Battle(Player & testplayer): player(testplayer)
{

}
int Battle::Wild_Encounter(){
    time_t seconds;
    time(&seconds);
    srand((unsigned int)seconds);
    int t = rand() % 150;


    PokemonDatabase het;

    Pokemon* WildPokemon;
    WildPokemon = het.pokeVec[t];
    cout << " A wild " << WildPokemon->getName() << " appeared!" << endl;

    string _input_;
    //wildHp <= 0 || playerPokemonHp <= 0
    while(true)
    {
        int wildHp;
        wildHp = WildPokemon->getHp();
        Pokemon* TempPlayerPokemon;
        TempPlayerPokemon = player.PlayerPokemon[bdg];
        int playerPokemonHp;
        playerPokemonHp = player.PlayerPokemon[bdg]->getHp();
        int opdamage = WildPokemon->getAtk() - player.PlayerPokemon[bdg]->getDef();
        if(opdamage <=0){
            opdamage = 1;
        }
        int udamage = player.PlayerPokemon[bdg]->getAtk() - WildPokemon->getDef();
        if(udamage <=0){
            udamage = 1;
        }
        int opspd = WildPokemon->getSpd();
        int uspd = player.PlayerPokemon[bdg]->getSpd();
        cout << "Would you like to attack, catch, switch, or flee?" << endl;
        cin >> _input_;
        if(_input_ == "attack")
        {
            if(uspd >= opspd)
            {
                cout << "The wild pokemon is slower, you attack first!" << endl;
                wildHp -= udamage;
                cout << "The wild pokemon has " << wildHp << " hp remaining!" << endl;
                if(wildHp <= 0)
                {
                    if(player.PlayerPokemon[bdg]->getLevel() != 100)
                    {
                        cout << "The wild pokemon has been defeated, you obtain " << WildPokemon->getLevel() * 8 << " experience points!" << endl;
                        player.PlayerPokemon[bdg]->exp += WildPokemon->getLevel() * 8;
                        while(true)
                        {
                            if(player.PlayerPokemon[bdg]->exp >= (((player.PlayerPokemon[bdg]->getLevel() * player.PlayerPokemon[bdg]->getLevel() * player.PlayerPokemon[bdg]->getLevel()) * 4) / 5))
                            {
                                player.PlayerPokemon[bdg]->exp -= (((player.PlayerPokemon[bdg]->getLevel() * player.PlayerPokemon[bdg]->getLevel() * player.PlayerPokemon[bdg]->getLevel()) * 4) / 5);
                                cout << "You have leveled up!" << endl;
                                int statIncreasehp = rand() % 6;
                                if(statIncreasehp == 0){
                                    statIncreasehp = 1;
                                }
                                int statIncreaseatk = rand() % 6;
                                if(statIncreaseatk == 0){
                                    statIncreaseatk = 1;
                                }
                                int statIncreasedef = rand() % 6;
                                if(statIncreasedef == 0){
                                    statIncreasedef = 1;
                                }
                                int statIncreasespd = rand() % 6;
                                if(statIncreasespd == 0){
                                    statIncreasespd = 1;
                                }
                                player.PlayerPokemon[bdg]->level += 1;
                                player.PlayerPokemon[bdg]->hp += statIncreasehp;
                                player.PlayerPokemon[bdg]->atk += statIncreaseatk;
                                player.PlayerPokemon[bdg]->def += statIncreasedef;
                                player.PlayerPokemon[bdg]->spd += statIncreasespd;
                                cout << "Your new level: " << player.PlayerPokemon[bdg]->level << endl;
                                cout << "Your new hp: " << player.PlayerPokemon[bdg]->hp << endl;
                                cout << "Your new atk: " << player.PlayerPokemon[bdg]->atk << endl;
                                cout << "Your new defense: " << player.PlayerPokemon[bdg]->def << endl;
                                cout << "Your new spd: " << player.PlayerPokemon[bdg]->spd << endl;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    break;
                }
                playerPokemonHp -= opdamage;
                if(playerPokemonHp <= 0)
                {
                    playerPokemonHp = 0;
                }
                cout << "Your pokemon has " << playerPokemonHp << " hp remaining!" << endl;
                if(playerPokemonHp == 0)
                {
                    cout << "You blacked out!" << endl;
                    break;
                }
            }
            else
            {
                cout << "The wild pokemon is faster, they attack first!" << endl;
                playerPokemonHp -= opdamage;
                cout << "The wild pokemon does " << opdamage << " damage!" << endl;
                cout << "Your pokemon has " << playerPokemonHp << " remaining!" << endl;
                if(playerPokemonHp <= 0){
                    cout << "You blacked out!" << endl;
                    break;
                }
                wildHp -= udamage;
                cout << "You did " << udamage << " damage to the wild pokemon!" << endl;
                if(wildHp <= 0)
                {
                    wildHp = 0;
                }
                cout << "The wild pokemon has " << wildHp << " hp remaining!" << endl;

                if(wildHp <= 0)
                {
                    if(player.PlayerPokemon[bdg]->getLevel() != 100)
                    {
                        cout << "The wild pokemon has been defeated, you obtain " << WildPokemon->getLevel() * 8 << " experience points!" << endl;
                        player.PlayerPokemon[bdg]->exp += WildPokemon->getLevel() * 8;
                        while(true)
                        {
                            if(player.PlayerPokemon[bdg]->exp >= (((player.PlayerPokemon[bdg]->getLevel() * player.PlayerPokemon[bdg]->getLevel() * player.PlayerPokemon[bdg]->getLevel()) * 4) / 5))
                            {
                                player.PlayerPokemon[bdg]->exp -= (((player.PlayerPokemon[bdg]->getLevel() * player.PlayerPokemon[bdg]->getLevel() * player.PlayerPokemon[bdg]->getLevel()) * 4) / 5);
                                cout << "You have leveled up!" << endl;
                                int statIncreasehp = rand() % 6;
                                if(statIncreasehp == 0){
                                    statIncreasehp = 1;
                                }
                                int statIncreaseatk = rand() % 6;
                                if(statIncreaseatk == 0){
                                    statIncreaseatk = 1;
                                }
                                int statIncreasedef = rand() % 6;
                                if(statIncreasedef == 0){
                                    statIncreasedef = 1;
                                }
                                int statIncreasespd = rand() % 6;
                                if(statIncreasespd == 0){
                                    statIncreasespd = 1;
                                }
                                player.PlayerPokemon[bdg]->level += 1;
                                player.PlayerPokemon[bdg]->hp += statIncreasehp;
                                player.PlayerPokemon[bdg]->atk += statIncreaseatk;
                                player.PlayerPokemon[bdg]->def += statIncreasedef;
                                player.PlayerPokemon[bdg]->spd += statIncreasespd;
                                cout << "Your new level: " << player.PlayerPokemon[bdg]->level << endl;
                                cout << "Your new hp: " << player.PlayerPokemon[bdg]->hp << endl;
                                cout << "Your new atk: " << player.PlayerPokemon[bdg]->atk << endl;
                                cout << "Your new defense: " << player.PlayerPokemon[bdg]->def << endl;
                                cout << "Your new spd: " << player.PlayerPokemon[bdg]->spd << endl;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }
        if(_input_ == "catch")
        {
            cout << "Pokeball(" << pokeball << "), Greatball(" << greatball << "), Ultraball(" << ultraball << "), and Masterball(" << masterball << ")" << endl;
            cout << "What ball would you like to use? : " << flush;
            string _f_;
            while(true)
            {
                cin >> _f_;
                if(_f_ == "pokeball")
                {
                    if(pokeball == 0)
                    {
                        cout << "oh, you don't have any balls." << endl;
                        break;
                    }
                    if(pokeball != 0)
                    {   pokeball -= 1;
                        int M = rand() % 256;
                        int f = (WildPokemon->getHp() * 255 * 4) / (wildHp * 12);
                        if(f >= M)
                        {
                            if(player.rccc != 120)
                            {

                                cout << "Shake" << flush;
                                Sleep(1000);
                                cout << "." << flush;
                                Sleep(1000);
                                cout << "." << flush;
                                Sleep(1000);
                                cout << "." << endl;
                                Sleep(1000);
                                cout << "Shake" << flush;
                                Sleep(1000);
                                cout << "." << flush;
                                Sleep(1000);
                                cout << "." << flush;
                                Sleep(1000);
                                cout << "." << endl;
                                Sleep(1000);
                                cout << "Shake" << flush;
                                Sleep(1000);
                                cout << "." << flush;
                                Sleep(1000);
                                cout << "." << flush;
                                Sleep(1000);
                                cout << "." << endl;
                                Sleep(1000);
                                cout << "The wild " << WildPokemon->getName() << " was caught!" << endl;
                                cout << "Would you like to nickname it?" << endl;
                                string d;
                                string ll;
                                while(true)
                                {
                                    cin >> d;
                                    if(d == "yes")
                                    {
                                        cout << "What would you like to nickname it?" << endl;
                                        cin >> ll;
                                        cout << "That is a great nickname!!" << endl;
                                        Pokemon* CaughtPokemon;
                                        CaughtPokemon = new Pokemon;
                                        CaughtPokemon->setLevel(WildPokemon->getLevel());
                                        CaughtPokemon->setName(ll);
                                        CaughtPokemon->setHp(WildPokemon->getHp());
                                        CaughtPokemon->setAtk(WildPokemon->getAtk());
                                        CaughtPokemon->setDef(WildPokemon->getDef());
                                        CaughtPokemon->setSpd(WildPokemon->getSpd());
                                        CaughtPokemon->setTeam(p.team);
                                        player.PlayerPokemon[player.rccc] = CaughtPokemon;
                                        player.rccc++;
                                        p.team++;
                                        return 1;

                                    }
                                    if(d == "no")
                                    {
                                        cout << "Ok!" << endl;
                                        Pokemon* CaughtPokemon;
                                        CaughtPokemon = new Pokemon;
                                        CaughtPokemon->setLevel(WildPokemon->getLevel());
                                        CaughtPokemon->setName(WildPokemon->getName());
                                        CaughtPokemon->setHp(WildPokemon->getHp());
                                        CaughtPokemon->setAtk(WildPokemon->getAtk());
                                        CaughtPokemon->setDef(WildPokemon->getDef());
                                        CaughtPokemon->setSpd(WildPokemon->getSpd());
                                        CaughtPokemon->setTeam(p.team);
                                        player.PlayerPokemon[player.rccc] = CaughtPokemon;
                                        player.rccc++;
                                        p.team++;
                                        return 1;

                                    }
                                    else
                                    {
                                        cout << "Try again : " << flush;
                                    }
                                }

                            }
                            //code pc shit

                        }
                        else
                        {
                            cout << "Shake" << flush;
                            Sleep(1000);
                            cout << "." << flush;
                            Sleep(1000);
                            cout << "." << flush;
                            Sleep(1000);
                            cout << "." << endl;
                            Sleep(1000);
                            cout << "Shake" << flush;
                            Sleep(1000);
                            cout << "." << flush;
                            Sleep(1000);
                            cout << "." << flush;
                            Sleep(1000);
                            cout << "." << endl;
                            Sleep(1000);
                            cout << "Shake" << flush;
                            Sleep(1000);
                            cout << "." << flush;
                            Sleep(1000);
                            cout << "." << flush;
                            Sleep(1000);
                            cout << "." << endl;
                            Sleep(1000);
                            cout << "Oh No! The wild pokemon failed to be caught!" << endl;
                            playerPokemonHp -= opdamage;
                            if(playerPokemonHp <= 0)
                            {
                                playerPokemonHp = 0;
                            }
                            cout << "Your pokemon has " << playerPokemonHp << " hp remaining!" << endl;
                            if(playerPokemonHp == 0)
                            {
                                cout << "You blacked out!" << endl;

                                return 1;

                            }

                            break;

                        }

                    }
                }
                if(_f_ == "greatball")
                {
                    if(greatball == 0)
                    {
                        cout << "oh, you don't have any balls." << endl;
                        break;
                    }
                    if(greatball != 0)
                    {
                        int M = rand() % 201;
                        int f = (WildPokemon->getHp() * 255 * 4) / (wildHp * 12);
                        if(f >= M)
                        {
                            if(greatball == 0)
                            {
                                cout << "Oh, you don't have any left." << endl;
                            }
                            if(greatball != 0)
                            {
                                if(player.rccc != 120)
                                {
                                    greatball -= 1;
                                    cout << "Shake" << flush;
                                    Sleep(1000);
                                    cout << "." << flush;
                                    Sleep(1000);
                                    cout << "." << flush;
                                    Sleep(1000);
                                    cout << "." << endl;
                                    Sleep(1000);
                                    cout << "Shake" << flush;
                                    Sleep(1000);
                                    cout << "." << flush;
                                    Sleep(1000);
                                    cout << "." << flush;
                                    Sleep(1000);
                                    cout << "." << endl;
                                    Sleep(1000);
                                    cout << "Shake" << flush;
                                    Sleep(1000);
                                    cout << "." << flush;
                                    Sleep(1000);
                                    cout << "." << flush;
                                    Sleep(1000);
                                    cout << "." << endl;
                                    Sleep(1000);
                                    cout << "The wild " << WildPokemon->getName() << " was caught!" << endl;
                                    cout << "Would you like to nickname it?" << endl;
                                    string d;
                                    string ll;
                                    while(true)
                                    {
                                        cin >> d;
                                        if(d == "yes")
                                        {
                                            cout << "What would you like to nickname it?" << endl;
                                            cin >> ll;
                                            cout << "That is a great nickname!!" << endl;
                                            Pokemon* Charmander;
                                            Charmander = new Pokemon;
                                            Charmander->setLevel(WildPokemon->getLevel());
                                            Charmander->setName(ll);
                                            Charmander->setHp(WildPokemon->getHp());
                                            Charmander->setAtk(WildPokemon->getAtk());
                                            Charmander->setDef(WildPokemon->getDef());
                                            Charmander->setSpd(WildPokemon->getSpd());
                                            player.PlayerPokemon[player.rccc] = Charmander;
                                            player.rccc++;
                                            return 1;
                                            break;
                                        }
                                        if(d == "no")
                                        {
                                            cout << "Ok!" << endl;
                                            Pokemon* Charmander;
                                            Charmander = new Pokemon;
                                            Charmander->setLevel(WildPokemon->getLevel());
                                            Charmander->setName(WildPokemon->getName());
                                            Charmander->setHp(WildPokemon->getHp());
                                            Charmander->setAtk(WildPokemon->getAtk());
                                            Charmander->setDef(WildPokemon->getDef());
                                            Charmander->setSpd(WildPokemon->getSpd());
                                            player.PlayerPokemon[player.rccc] = Charmander;
                                            player.rccc++;
                                            return 1;
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Try again : " << flush;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "Oh No! The wild pokemon failed to be caught!" << endl;
                            playerPokemonHp -= opdamage;
                            if(playerPokemonHp <= 0)
                            {
                                playerPokemonHp = 0;
                            }
                            cout << "Your pokemon has " << playerPokemonHp << " hp remaining!" << endl;
                            if(playerPokemonHp == 0)
                            {
                                cout << "You blacked out!" << endl;
                                return 1;
                                break;
                            }
                            greatball -= 1;
                            break;
                        }

                    }
                }
                if(_f_ == "ultraball")
                {
                    if(ultraball == 0)
                    {
                        cout << "oh, you don't have any balls." << endl;
                        break;
                    }
                    if(ultraball != 0)
                    {
                        int M = rand() % 151;
                        int f = (WildPokemon->getHp() * 255 * 4) / (wildHp * 12);
                        if(f >= M)
                        {
                            if(ultraball == 0)
                            {
                                cout << "Oh, you don't have any left." << endl;
                            }
                            if(ultraball != 0)
                            {
                                if(player.rccc != 120)
                                {
                                    ultraball -= 1;
                                    cout << "Shake" << flush;
                                    Sleep(1000);
                                    cout << "." << flush;
                                    Sleep(1000);
                                    cout << "." << flush;
                                    Sleep(1000);
                                    cout << "." << endl;
                                    Sleep(1000);
                                    cout << "Shake" << flush;
                                    Sleep(1000);
                                    cout << "." << flush;
                                    Sleep(1000);
                                    cout << "." << flush;
                                    Sleep(1000);
                                    cout << "." << endl;
                                    Sleep(1000);
                                    cout << "Shake" << flush;
                                    Sleep(1000);
                                    cout << "." << flush;
                                    Sleep(1000);
                                    cout << "." << flush;
                                    Sleep(1000);
                                    cout << "." << endl;
                                    Sleep(1000);
                                    cout << "The wild " << WildPokemon->getName() << " was caught!" << endl;
                                    cout << "Would you like to nickname it?" << endl;
                                    string d;
                                    string ll;
                                    while(true)
                                    {
                                        cin >> d;
                                        if(d == "yes")
                                        {
                                            cout << "What would you like to nickname it?" << endl;
                                            cin >> ll;
                                            cout << "That is a great nickname!!" << endl;
                                            Pokemon* Charmander;
                                            Charmander = new Pokemon;
                                            Charmander->setLevel(WildPokemon->getLevel());
                                            Charmander->setName(ll);
                                            Charmander->setHp(WildPokemon->getHp());
                                            Charmander->setAtk(WildPokemon->getAtk());
                                            Charmander->setDef(WildPokemon->getDef());
                                            Charmander->setSpd(WildPokemon->getSpd());
                                            player.PlayerPokemon[player.rccc] = Charmander;
                                            player.rccc++;
                                            return 1;
                                            break;
                                        }
                                        if(d == "no")
                                        {
                                            cout << "Ok!" << endl;
                                            Pokemon* Charmander;
                                            Charmander = new Pokemon;
                                            Charmander->setLevel(WildPokemon->getLevel());
                                            Charmander->setName(WildPokemon->getName());
                                            Charmander->setHp(WildPokemon->getHp());
                                            Charmander->setAtk(WildPokemon->getAtk());
                                            Charmander->setDef(WildPokemon->getDef());
                                            Charmander->setSpd(WildPokemon->getSpd());
                                            player.PlayerPokemon[player.rccc] = Charmander;
                                            player.rccc++;
                                            return 1;
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Try again : " << flush;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "Oh No! The wild pokemon failed to be caught!" << endl;
                            playerPokemonHp -= opdamage;
                            if(playerPokemonHp <= 0)
                            {
                                playerPokemonHp = 0;
                            }
                            cout << "Your pokemon has " << playerPokemonHp << " hp remaining!" << endl;
                            if(playerPokemonHp == 0)
                            {
                                cout << "You blacked out!" << endl;
                                return 1;
                                break;
                            }
                            ultraball -= 1;
                            break;
                        }

                    }
                }
                if(_f_ == "masterball")
                {
                    if(masterball != 0)
                    {   masterball -= 1;
                        if(player.rccc != 1200)
                        {

                            cout << "Shake" << flush;
                            Sleep(1);
                            cout << "." << flush;
                            Sleep(1);
                            cout << "." << flush;
                            Sleep(1);
                            cout << "." << endl;
                            Sleep(1);
                            cout << "Shake" << flush;
                            Sleep(1);
                            cout << "." << flush;
                            Sleep(1);
                            cout << "." << flush;
                            Sleep(1);
                            cout << "." << endl;
                            Sleep(1);
                            cout << "Shake" << flush;
                            Sleep(1);
                            cout << "." << flush;
                            Sleep(1);
                            cout << "." << flush;
                            Sleep(1);
                            cout << "." << endl;
                            Sleep(1);
                            cout << "The wild " << WildPokemon->getName() << " was caught!" << endl;
                            cout << "Would you like to nickname it?" << endl;
                            string d;
                            string ll;
                            while(true)
                            {
                                cin >> d;
                                if(d == "yes")
                                {
                                    cout << "What would you like to nickname it?" << endl;
                                    cin >> ll;
                                    cout << "That is a great nickname!!" << endl;
                                    Pokemon* CaughtPokemon;
                                    CaughtPokemon = new Pokemon;
                                    CaughtPokemon->setLevel(WildPokemon->getLevel());
                                    CaughtPokemon->setName(ll);
                                    CaughtPokemon->setHp(WildPokemon->getHp());
                                    CaughtPokemon->setAtk(WildPokemon->getAtk());
                                    CaughtPokemon->setDef(WildPokemon->getDef());
                                    CaughtPokemon->setSpd(WildPokemon->getSpd());
                                    CaughtPokemon->setTeam(p.team);
                                    player.PlayerPokemon[player.rccc] = CaughtPokemon;
                                    player.rccc++;
                                    p.team++;
                                    return 1;

                                }
                                if(d == "no")
                                {
                                    cout << "Ok!" << endl;
                                    Pokemon* CaughtPokemon;
                                    CaughtPokemon = new Pokemon;
                                    CaughtPokemon->setLevel(WildPokemon->getLevel());
                                    CaughtPokemon->setName(WildPokemon->getName());
                                    CaughtPokemon->setHp(WildPokemon->getHp());
                                    CaughtPokemon->setAtk(WildPokemon->getAtk());
                                    CaughtPokemon->setDef(WildPokemon->getDef());
                                    CaughtPokemon->setSpd(WildPokemon->getSpd());
                                    CaughtPokemon->setTeam(p.team);
                                    player.PlayerPokemon[player.rccc] = CaughtPokemon;
                                    player.rccc++;
                                    p.team++;
                                    return 1;

                                }
                                else
                                {
                                    cout << "Try again : " << flush;
                                }
                            }
                        }
                        else
                        {
                            cout << "Try again." << flush;
                        }
                    }
                }
            }
        }
        if(_input_ == "flee")
        {
            int ty = rand() % 5;
            if(ty == 3)
            {
                cout << "You failed to escape." << endl;
                playerPokemonHp -= opdamage;
                cout << "Your pokemon has " << playerPokemonHp << " remaining!" << endl;
                if(playerPokemonHp <= 0)
                {

                    cout << "Which pokemon would you like to switch to?" << endl;
                    int e = 0;
                    while(e <= player.rccc)
                    {

                        if(e == player.rccc)
                        {
                            break;
                        }
                        string rt = player.PlayerPokemon[e]->getName();
                        cout << rt << endl;
                        e = e + 1;
                    }
                    string dick;
                    int e1 = 0;
                    int g = 0;
                    while(true)
                    {
                        cin >> dick;
                        while(true)
                        {
                            if(e1 == player.rccc)
                            {
                                break;
                            }
                            string rt = player.PlayerPokemon[e1]->getName();
                            if(dick == rt)
                            {
                                bdg = e1;
                                g = 9999;
                                break;
                            }
                            e1 = e1 + 1;
                        }
                        if(g == 9999)
                        {
                            break;
                        }
                        cout <<": " << flush;
                }
            }
            else
            {
                cout << "You safely got away!" << endl;
                break;
            }
        }
        if(_input_ == "switch")
        {
            //int transfat = 1;
            cout << "Which pokemon would you like to switch to?" << endl;
            int e = 0;
            while(e <= player.rccc)
            {

                if(e == player.rccc)
                {
                    break;
                }
                string rt = player.PlayerPokemon[e]->getName();
                cout << rt << endl;
                e = e + 1;
            }
            string dick;
            int e1 = 0;
            int g = 0;
            while(true)
            {
                cin >> dick;
                while(true)
                {
                    if(e1 == player.rccc)
                    {
                        break;
                    }
                    string rt = player.PlayerPokemon[e1]->getName();
                    if(dick == rt)
                    {
                        bdg = e1;
                        g = 9999;
                        break;
                    }
                    e1 = e1 + 1;
                }
                if(g == 9999)
                {
                    break;
                }
                cout <<"Enter Again: " << flush;
                //int e1 = 0;
                //while(e1 <= player.rccc)
                //{
                    //if(transfat == 0)
                    //{
                       // break;
                    //}
                    //if(e1 == player.rccc)
                    //{
                       // break;
                    //}
                   // string rt = player.PlayerPokemon[e1]->getName();
                    //(rt == dick)
                    //{
                        //Player* subsitute;
                        //subsitute = new Player(player.PlayerPokemon[e1]->getName(), player.PlayerPokemon[e1]->getHp(), player.PlayerPokemon[e1]->getAtk(), player.PlayerPokemon[e1]->getDef(), player.PlayerPokemon[e1]->getSpd(), player.PlayerPokemon[e1]->getLevel());
                        //pe.addPokemen(subsitute);
                        //player.PlayerPokemon[e1]->getName() = player.PlayerPokemon[0]->getName();
                        //player.PlayerPokemon[0]->getName() = subsitute->getName();
                        //transfat = 0;
                    //}
                   // e1 = e1 + 1;
                //}
                //if(transfat == 0)
                //{
                    //cout << "Switch was succsesful!!!!!!!!!" << endl;
                    //break;
                //}
                //else
                //{
                    //cout << "Suck a dick." << endl;
                //}
            }
        }
        else
        {
            cout << "Try again." << flush;
        }
    }
}
}

