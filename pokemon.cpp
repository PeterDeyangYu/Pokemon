#include "pokemon.h"

Pokemon::Pokemon()
{

}
Pokemon::~Pokemon()
{

}
Pokemon::Pokemon(string _name, int _hp, int _atk, int _def, int _spd, int _level): name(_name), hp(_hp), atk(_atk), def(_def), spd(_spd), level(_level)
{

}
Pokemon & Pokemon::operator = (Pokemon other)
{
    this->name= other.name;
    this->hp= other.hp;
    this->atk= other.atk;
    this->def= other.def;
    this->spd= other.spd;
    this->level= other.level;
    this->exp= other.exp;
    return *this;
}
void Pokemon::setName(string _name)
{
     name = _name;
}
void Pokemon::setHp(int _hp){
    hp = _hp;
}
void Pokemon::setTeam(int _team){
    team = _team;
}
void Pokemon::setAtk(int _atk){
    atk = _atk;
}
void Pokemon::setDef(int _def){
   def = _def;
}
void Pokemon::setSpd(int _spd){
    spd = _spd;
}
void Pokemon::setLevel(int _level){
    level = _level;
    exp = 8*_level;
}
string Pokemon::getName()
{
    return this->name;
}
int Pokemon::getHp()
{
    return this->hp;
}
int Pokemon::getTeam()
{
    return this->team;
}
int Pokemon::getAtk()
{
    return this->atk;
}
int Pokemon::getDef()
{
    return this->def;
}
int Pokemon::getSpd()
{
    return this->spd;
}
int Pokemon::getLevel()
{
    return this->level;
}
