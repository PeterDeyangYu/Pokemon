#ifndef POKEMON_H
#define POKEMON_H
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
#include <time.h>
#include <cstdlib>

using namespace std;

class Pokemon
{
private:
    /*
    string name;
    int hp;
    int atk;
    int def;
    int spd;
    int level;
    int exp;
*/

public:
    string name;
    int hp;
    int atk;
    int def;
    int spd;
    int level;
    int exp;
    int team = 1;
    Pokemon();
    Pokemon(string _name, int _hp, int _atk, int _def, int _spd, int _level);
    Pokemon & operator = (Pokemon other);


    ~Pokemon();
    void introduction();
    void setName(string _name);
    void setHp(int _hp);
    void setAtk(int _atk);
    void setDef(int _def);
    void setSpd(int _spd);
    void setLevel(int _level);
    void setTeam(int _team);


    string getName();
    int getHp();
    int getAtk();
    int getDef();
    int getSpd();
    int getLevel();
    int getTeam();


};

#endif // POKEMON_H
