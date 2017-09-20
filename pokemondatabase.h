#ifndef POKEMONDATABASE_H
#define POKEMONDATABASE_H
#include "pokemon.h"
#include <time.h>
#include <cstdlib>
/*
 * // Declaration
class Singleton {
public:
    static Singleton* Instance();
protected:
    Singleton();
private:
    static Singleton* _instance;
}

// Implementation
Singleton* Singleton::_instance = 0;

Singleton* Singleton::Instance() {
    if (_instance == 0) {
        _instance = new Singleton;
    }
    return _instance;
}
*/

class PokemonDatabase
{
private:



    // static PokemonDatabase  * _instance;

public:
 vector<Pokemon*> pokeVec;
    //static PokemonDatabase * Instance();
/*
    vector<Pokemon>* getPokemons(int o)
    {
        return pokeVec[o];
    }
*/


    void addPokemen(Pokemon * p)
    {
        pokeVec.push_back(p);

    }
    //    Pokemon(string _name, int _hp, int _atk, int _def, int _spd, int _level);


    PokemonDatabase(){

        Pokemon *Mew;
        Mew = new Pokemon("Mew", 403, 298, 298, 298, 75);
        addPokemen(Mew);
        Pokemon *Bulbasaur;
        Bulbasaur = new Pokemon("Bulbasaur", 19, 9, 9, 9, 5);
        addPokemen(Bulbasaur);
        Pokemon *Ivysaur;
        Ivysaur = new Pokemon("Ivysaur", 45, 24, 25, 24, 16);
        addPokemen(Ivysaur);
        Pokemon *Venusaur;
        Venusaur = new Pokemon("Venusaur", 93, 57, 58, 56, 32);
        addPokemen(Venusaur);
        Pokemon *Charmander;
        Charmander = new Pokemon("Charmander", 18, 10, 9, 11, 5);
        addPokemen(Charmander);
        Pokemon *Charmeleon;
        Charmeleon = new Pokemon("Charmeleon", 45, 25, 23, 30, 16);
        addPokemen(Charmeleon);
        Pokemon *Charizard;
        Charizard = new Pokemon("Charizard", 102, 65, 61, 77, 36);
        addPokemen(Charizard);
        Pokemon *Squirtle;
        Squirtle = new Pokemon("Squirtle", 19, 9, 11, 9, 5);
        addPokemen(Squirtle);
        Pokemon *Wartortle;
        Wartortle = new Pokemon("Wartortle", 44, 25, 30, 23, 16);
        addPokemen(Wartortle);
        Pokemon *Blastoise;
        Blastoise = new Pokemon("Blastoise", 102, 64, 77, 61, 36);
        addPokemen(Blastoise);
        Pokemon *Caterpie;
        Caterpie = new Pokemon("Caterpie", 15, 6, 7, 7, 3);
        addPokemen(Caterpie);
        Pokemon *Metapod;
        Metapod = new Pokemon("Metapod", 24, 1, 12, 9, 7);
        addPokemen(Metapod);
        Pokemon *Butterfree;
        Butterfree = new Pokemon("Butterfree", 32, 14, 15, 19, 10);
        addPokemen(Butterfree);
        Pokemon *Weedle;
        Weedle = new Pokemon("Weedle", 15, 7, 6, 8, 3);
        addPokemen(Weedle);
        Pokemon *Kakuna;
        Kakuna = new Pokemon("Kakuna", 20, 1, 12, 9, 7);
        addPokemen(Kakuna);
        Pokemon *Beedrill;
        Beedrill = new Pokemon("Beedrill", 33, 21, 10, 20, 10);
        addPokemen(Beedrill);
        Pokemon *Pidgey;
        Pidgey = new Pokemon("Pidgey", 15, 7, 7, 8, 3);
        addPokemen(Pidgey);
        Pokemon *Pidgeotto;
        Pidgeotto = new Pokemon("Pidgeotto", 50, 26, 24, 30, 18);
        addPokemen(Pidgeotto);
        Pokemon *Pidgeot;
        Pidgeot = new Pokemon("Pidgeot", 105, 62, 59, 70, 36);
        addPokemen(Pidgeot);
        Pokemon *Rattata;
        Rattata = new Pokemon("Rattata", 14, 8, 7, 9, 3);
        addPokemen(Rattata);
        Pokemon *Raticate;
        Raticate = new Pokemon("Raticate", 52, 37, 29, 43, 20);
        addPokemen(Raticate);
        Pokemon *Spearow;
        Spearow = new Pokemon("Spearow", 22, 13, 9, 14, 7);
        addPokemen(Spearow);
        Pokemon *Fearow;
        Fearow = new Pokemon("Fearow", 56, 41, 31, 45, 20);
        addPokemen(Fearow);
        Pokemon *Ekans;
        Ekans = new Pokemon("Ekans", 23, 14, 12, 13, 8);
        addPokemen(Ekans);
        Pokemon *Arbok;
        Arbok = new Pokemon("Arbok", 58, 42, 35, 40, 22);
        addPokemen(Arbok);
        Pokemon *Pikachu;
        Pikachu = new Pokemon("Pikachu", 15, 8, 6, 10, 3);
        addPokemen(Pikachu);
        Pokemon *Raichu;
        Raichu = new Pokemon("Raichu", 43, 32, 21, 35, 15);
        addPokemen(Raichu);
        Pokemon *Sandshrew;
        Sandshrew = new Pokemon("Sandshrew", 26, 17, 18, 11, 8);
        addPokemen(Sandshrew);
        Pokemon *Sandslash;
        Sandslash = new Pokemon("Sandslash", 65, 48, 53, 33, 22);
        addPokemen(Sandslash);
        Pokemon *NidoranF;
        NidoranF = new Pokemon("NidoranF", 24, 11, 12, 10, 7);
        addPokemen(NidoranF);
        Pokemon *Nidorina;
        Nidorina = new Pokemon("Nidorina", 48, 24, 26, 22, 516);
        addPokemen(Nidorina);
        Pokemon *Nidoqueen;
        Nidoqueen = new Pokemon("Nidoqueen", 54, 31, 32, 29, 16);
        addPokemen(Nidoqueen);
        Nidoqueen->setLevel(16);
        Pokemon *NidoranM;
        NidoranM = new Pokemon("NidoranM", 25, 14, 11, 13, 8);
        addPokemen(NidoranM);
        Pokemon *Nidorino;
        Nidorino = new Pokemon("Nidorino", 45, 28, 23, 25, 16);
        addPokemen(Nidorino);
        Pokemon *Nidoking;
        Nidoking = new Pokemon("Nidoking", 51, 34, 29, 32, 16);
        addPokemen(Nidoking);
        Pokemon *Clefairy;
        Clefairy = new Pokemon("Clefairy", 36, 14, 15, 12, 11);
        addPokemen(Clefairy);
        Pokemon *Clefable;
        Clefable = new Pokemon("Clefable", 41, 20, 21, 18, 11);
        addPokemen(Clefable);
        Pokemon *Vulpix;
        Vulpix = new Pokemon("Vulpix", 25, 12, 12, 16, 9);
        addPokemen(Vulpix);
        Pokemon *Ninetales;
        Ninetales = new Pokemon("Ninetales", 32, 18, 18, 23, 9);
        addPokemen(Ninetales);
        Pokemon *Jigglypuff;
        Jigglypuff = new Pokemon("Jigglypuff", 26, 9, 7, 7, 5);
        addPokemen(Jigglypuff);
        Pokemon *Wigglytuff;
        Wigglytuff = new Pokemon("Wigglytuff", 29, 12, 9, 9, 5);
        addPokemen(Wigglytuff);
        Pokemon *Zubat;
        Zubat = new Pokemon("Zubat", 20, 10, 9, 11, 6);
        addPokemen(Zubat);
        Pokemon *Golbat;
        Golbat = new Pokemon("Golbat", 65, 40, 35, 44, 22);
        addPokemen(Golbat);
        Pokemon *Oddish;
        Oddish = new Pokemon("Oddish", 25, 13, 13, 9, 8);
        addPokemen(Oddish);
        Pokemon *Gloom;
        Gloom = new Pokemon("Gloom", 56, 32, 34, 21, 21);
        addPokemen(Gloom);
        Pokemon *Vileplume;
        Vileplume = new Pokemon("Vileplume", 62, 38, 40, 26, 21);
        addPokemen(Vileplume);
        Pokemon *Paras;
        Paras = new Pokemon("Paras", 30, 21, 18, 11, 12);
        addPokemen(Paras);
        Pokemon *Parasect;
        Parasect = new Pokemon("Parasect", 62, 50, 43, 19, 24);
        addPokemen(Parasect);
        Pokemon *Venonat;
        Venonat = new Pokemon("Venonat", 29, 14, 14, 13, 9);
        addPokemen(Venonat);
        Pokemon *Venomoth;
        Venomoth = new Pokemon("Venomoth", 84, 45, 42, 60, 31);
        addPokemen(Venomoth);
        Pokemon *Diglett;
        Diglett = new Pokemon("Diglett", 30, 23, 13, 37, 17);
        addPokemen(Diglett);
        Pokemon *Dugtrio;
        Dugtrio = new Pokemon("Dugtrio", 54, 46, 31, 67, 26);
        addPokemen(Dugtrio);
        Pokemon *Meowth;
        Meowth = new Pokemon("Meowth", 37, 18, 15, 32, 15);
        addPokemen(Meowth);
        Pokemon *Persian;
        Persian = new Pokemon("Persian", 74, 44, 38, 69, 28);
        addPokemen(Persian);
        Pokemon *Psyduck;
        Psyduck = new Pokemon("Psyduck", 44, 22, 21, 23, 26);
        addPokemen(Psyduck);
        Pokemon *Golduck;
        Golduck = new Pokemon("Golduck", 95, 59, 56, 61, 33);
        addPokemen(Golduck);
        Pokemon *Mankey;
        Mankey = new Pokemon("Mankey", 17, 11, 7, 10, 4);
        addPokemen(Mankey);
        Pokemon *Primeape;
        Primeape = new Pokemon("Primeape", 74, 63, 38, 57, 28);
        addPokemen(Primeape);
        Pokemon *Growlithe;
        Growlithe = new Pokemon("Growlithe", 39, 24, 17, 21, 14);
        addPokemen(Growlithe);
        Pokemon *Arcanine;
        Arcanine = new Pokemon("Arcanine", 71, 53, 40, 46, 22);
        addPokemen(Arcanine);
        Pokemon *Poliwag;
        Poliwag = new Pokemon("Poliwag", 20, 11, 9, 15, 6);
        addPokemen(Poliwag);
        Pokemon *Poliwhirl;
        Poliwhirl = new Pokemon("Poliwhirl", 67, 37, 37, 50, 25);
        addPokemen(Poliwhirl);
        Pokemon *Poliwrath;
        Poliwrath = new Pokemon("Poliwrath", 80, 47, 52, 40, 25);
        addPokemen(Poliwrath);
        Pokemon *Abra;
        Abra = new Pokemon("Abra", 26, 9, 8, 24, 11);
        addPokemen(Abra);
        Pokemon *Kadabra;
        Kadabra = new Pokemon("Kadabra", 38, 16, 14, 38, 16);
        addPokemen(Kadabra);
        Pokemon *Alakazam;
        Alakazam = new Pokemon("Alakazam", 43, 21, 19, 43, 16);
        addPokemen(Alakazam);
        Pokemon *Machop;
        Machop = new Pokemon("Machop", 36, 22, 16, 12, 11);
        addPokemen(Machop);
        Pokemon *Machoke;
        Machoke = new Pokemon("Machoke", 82, 61, 44, 30, 28);
        addPokemen(Machoke);
        Pokemon *Machamp;
        Machamp = new Pokemon("Machamp", 88, 77, 49, 35, 28);
        addPokemen(Machamp);
        Pokemon *Bellsprout;
        Bellsprout = new Pokemon("Bellsprout", 20, 12, 8, 9, 5);
        addPokemen(Bellsprout);
        Pokemon *Weepinbell;
        Weepinbell = new Pokemon("Weepinbell", 58, 42, 26, 28, 21);
        addPokemen(Weepinbell);
        Pokemon *Victreebel;
        Victreebel = new Pokemon("Victreebel", 64, 49, 32, 34, 21);
        addPokemen(Victreebel);
        Pokemon *Tentacool;
        Tentacool = new Pokemon("Tentacool", 35, 16, 14, 24, 14);
        addPokemen(Tentacool);
        Pokemon *Tentacruel;
        Tentacruel = new Pokemon("Tentacruel", 88, 47, 44, 65, 30);
        addPokemen(Tentacruel);
        Pokemon *Geodude;
        Geodude = new Pokemon("Geodude", 33, 25, 31, 1, 13);
        addPokemen(Geodude);
        Pokemon *Graveler;
        Graveler = new Pokemon("Graveler", 62, 52, 62, 1, 25);
        addPokemen(Graveler);
        Pokemon *Golem;
        Golem = new Pokemon("Golem", 75, 60, 70, 1, 25);
        addPokemen(Golem);
        Pokemon *Ponyta;
        Ponyta = new Pokemon("Ponyta", 52, 40, 28, 42, 21);
        addPokemen(Ponyta);
        Pokemon *Rapidash;
        Rapidash = new Pokemon("Rapidash", 102, 85, 61, 89, 40);
        addPokemen(Rapidash);
        Pokemon *Slowpoke;
        Slowpoke = new Pokemon("Slowpoke", 57, 27, 27, 10, 17);
        addPokemen(Slowpoke);
        Pokemon *Slowbro;
        Slowbro = new Pokemon("Slowbro", 117, 60, 86, 27, 37);
        addPokemen(Slowbro);
        Pokemon *Magnemite;
        Magnemite = new Pokemon("Magnemite", 46, 21, 38, 26, 24);
        addPokemen(Magnemite);
        Pokemon *Magneton;
        Magneton = new Pokemon("Magneton", 70, 41, 62, 47, 30);
        addPokemen(Magneton);
        Pokemon *Farfetchd;
        Farfetchd = new Pokemon("Farfetchd", 20, 11, 10, 11, 5);
        addPokemen(Farfetchd);
        Pokemon *Doduo;
        Doduo = new Pokemon("Doduo", 42, 37, 22, 33, 19);
        addPokemen(Doduo);
        Pokemon *Dodrio;
        Dodrio = new Pokemon("Dodrio", 78, 73, 48, 67, 31);
        addPokemen(Dodrio);
        Pokemon *Seel;
        Seel = new Pokemon("Seel", 42, 17, 20, 17, 514);
        addPokemen(Seel);
        Pokemon *Dewgong;
        Dewgong = new Pokemon("Dewgong", 105, 52, 59, 52, 34);
        addPokemen(Dewgong);
        Pokemon *Grimer;
        Grimer = new Pokemon("Grimer", 38, 22, 16, 10, 11);
        addPokemen(Grimer);
        Pokemon *Muk;
        Muk = new Pokemon("Muk", 38, 84, 62, 43, 38);
        addPokemen(Muk);
        Pokemon *Shellder;
        Shellder = new Pokemon("Shellder", 29, 20, 29, 14, 12);
        addPokemen(Shellder);
        Pokemon *Cloyster;
        Cloyster = new Pokemon("Cloyster", 34, 27, 48, 21, 12);
        addPokemen(Cloyster);
        Pokemon *Gastly;
        Gastly = new Pokemon("Gastly", 38, 17, 15, 33, 18);
        addPokemen(Gastly);
        Pokemon *Haunter;
        Haunter = new Pokemon("Haunter", 57, 30, 27, 52, 25);
        addPokemen(Haunter);
        Pokemon *Gengar;
        Gengar = new Pokemon("Gengar", 76, 44, 41, 71, 30);
        addPokemen(Gengar);
        Pokemon *Onix;
        Onix = new Pokemon("Onix", 91, 48, 158, 72, 48);
        addPokemen(Onix);
        Pokemon *Drowzee;
        Drowzee = new Pokemon("Drowzee", 45, 20, 19, 18, 16);
        addPokemen(Drowzee);
        Pokemon *Hypno;
        Hypno = new Pokemon("Hypno", 80, 42, 41, 39, 26);
        addPokemen(Hypno);
        Pokemon *Krabby;
        Krabby = new Pokemon("Krabby", 32, 34, 30, 19, 14);
        addPokemen(Krabby);
        Pokemon *Kingler;
        Kingler = new Pokemon("Kingler", 68, 77, 69, 47, 28);
        addPokemen(Kingler);
        Pokemon *Voltorb;
        Voltorb = new Pokemon("Voltorb", 31, 12, 17, 29, 12);
        addPokemen(Voltorb);
        Pokemon *Electrode;
        Electrode = new Pokemon("Electrode", 76, 35, 47, 89, 30);
        addPokemen(Electrode);
        Pokemon *Exeggcute;
        Exeggcute = new Pokemon("Exeggcute", 21, 9, 13, 9, 5);
        addPokemen(Exeggcute);
        Pokemon *Exeggutor;
        Exeggutor = new Pokemon("Exeggutor", 58, 22, 40, 22, 22);
        addPokemen(Exeggutor);
        Pokemon *Cubone;
        Cubone = new Pokemon("Cubone", 43, 21, 19, 43, 16);
        addPokemen(Cubone);
        Pokemon *Marowak;
        Marowak = new Pokemon("Marowak", 71, 49, 66, 30, 28);
        addPokemen(Marowak);
        Pokemon *Hitmonlee;
        Hitmonlee = new Pokemon("Hitmonlee", 70, 77, 36, 57, 26);
        addPokemen(Hitmonlee);
        Pokemon *Hitmonchan;
        Hitmonchan = new Pokemon("Hitmonchan", 70, 68, 52, 50, 26);
        addPokemen(Hitmonchan);
        Pokemon *Lickitung;
        Lickitung = new Pokemon("Lickitung", 113, 45, 60, 27, 37);
        addPokemen(Lickitung);
        Pokemon *Koffing;
        Koffing = new Pokemon("Koffing", 44, 29, 41, 18, 19);
        addPokemen(Koffing);
        Pokemon *Weezing;
        Weezing = new Pokemon("Weezing", 90, 68, 89, 47, 35);
        addPokemen(Weezing);
        Pokemon *Rhyhorn;
        Rhyhorn = new Pokemon("Rhyhorn", 46, 28, 31, 12, 14);
        addPokemen(Rhyhorn);
        Pokemon *Rhydon;
        Rhydon = new Pokemon("Rhydon", 140, 114, 105, 38, 42);
        addPokemen(Rhydon);
        Pokemon *Chansey;
        Chansey = new Pokemon("Chansey", 118, 6, 6, 23, 18);
        addPokemen(Chansey);
        Pokemon *Tangela;
        Tangela = new Pokemon("Tangela", 76, 36, 71, 39, 29);
        addPokemen(Tangela);
        Pokemon *Kangaskhan;
        Kangaskhan = new Pokemon("Kangaskhan", 180, 109, 93, 104, 55);
        addPokemen(Kangaskhan);
        Pokemon *Horsea;
        Horsea = new Pokemon("Horsea", 27, 13, 20, 18, 11);
        addPokemen(Horsea);
        Pokemon *Seadra;
        Seadra = new Pokemon("Seadra", 77, 46, 65, 59, 32);
        addPokemen(Seadra);
        Pokemon *Goldeen;
        Goldeen = new Pokemon("Goldeen", 48, 31, 29, 30, 20);
        addPokemen(Goldeen);
        Pokemon *Seaking;
        Seaking = new Pokemon("Seaking", 95, 65, 47, 49, 33);
        addPokemen(Seaking);
        Pokemon *Staryu;
        Staryu = new Pokemon("Staryu", 27, 14, 17, 23, 11);
        addPokemen(Staryu);
        Pokemon *Starmie;
        Starmie = new Pokemon("Starmie", 54, 35, 39, 51, 20);
        addPokemen(Starmie);
        Pokemon *MrMime;
        MrMime = new Pokemon("MrMime", 49, 24, 33, 44, 22);
        addPokemen(MrMime);
        Pokemon *Scyther;
        Scyther = new Pokemon("Scyther", 55, 46, 35, 44, 19);
        addPokemen(Scyther);
        Pokemon *Jynx;
        Jynx = new Pokemon("Jynx", 113, 50, 36, 90, 45);
        addPokemen(Jynx);
        Pokemon *Electabuzz;
        Electabuzz = new Pokemon("Electabuzz", 79, 54, 39, 68, 30);
        addPokemen(Electabuzz);
        Pokemon *Magmar;
        Magmar = new Pokemon("Magmar", 79, 62, 39, 60, 30);
        addPokemen(Magmar);
        Pokemon *Pinsir;
        Pinsir = new Pokemon("Pinsir", 62, 62, 51, 44, 23);
        addPokemen(Pinsir);
        Pokemon *Tauros;
        Tauros = new Pokemon("Tauros", 67, 51, 48, 55, 23);
        addPokemen(Tauros);
        Pokemon *Magikarp;
        Magikarp = new Pokemon("Magikarp", 11, 5, 6, 6, 1);
        addPokemen(Magikarp);
        Pokemon *Gyarados;
        Gyarados = new Pokemon("Gyarados", 68, 55, 36, 37, 20);
        addPokemen(Gyarados);
        Pokemon *Lapras;
        Lapras = new Pokemon("Lapras", 100, 47, 45, 35, 25);
        addPokemen(Lapras);
        Pokemon *Eevee;
        Eevee = new Pokemon("Eevee", 20, 10, 10, 10, 5);
        addPokemen(Eevee);
        Pokemon *Vaporeon;
        Vaporeon = new Pokemon("Vaporeon", 74, 28, 26, 28, 18);
        addPokemen(Vaporeon);
        Pokemon *Jolteon;
        Jolteon = new Pokemon("Jolteon", 51, 28, 26, 51, 18);
        addPokemen(Jolteon);
        Pokemon *Flareon;
        Flareon = new Pokemon("Flareon", 51, 51, 26, 28, 18);
        addPokemen(Flareon);
        Pokemon *Porygon;
        Porygon = new Pokemon("Porygon", 56, 29, 33, 21, 20);
        addPokemen(Porygon);
        Pokemon *Omanyte;
        Omanyte = new Pokemon("Omanyte", 30, 14, 29, 13, 12);
        addPokemen(Omanyte);
        Pokemon *Omastar;
        Omastar = new Pokemon("Omastar", 106, 53, 105, 49, 40);
        addPokemen(Omastar);
        Pokemon *Kabuto;
        Kabuto = new Pokemon("Kabuto", 30, 25, 28, 19, 13);
        addPokemen(Kabuto);
        Pokemon *Kabutops;
        Kabutops = new Pokemon("Kabutops", 98, 97, 89, 69, 40);
        addPokemen(Kabutops);
        Pokemon *Aerodactyl;
        Aerodactyl = new Pokemon("Aerodactyl", 62, 47, 31, 29, 20);
        addPokemen(Aerodactyl);
        Pokemon *Snorlax;
        Snorlax = new Pokemon("Snorlax", 156, 71, 44, 23, 30);
        addPokemen(Snorlax);
        Pokemon *Articuno;
        Articuno = new Pokemon("Articuno", 383, 268, 298, 268, 75);
        addPokemen(Articuno);
        Pokemon *Zapdos;
        Zapdos = new Pokemon("Zapdos", 383, 278, 268, 298, 75);
        addPokemen(Zapdos);
        Pokemon *Moltres;
        Moltres = new Pokemon("Moltres", 383, 298, 278, 278, 75);
        addPokemen(Moltres);
        Pokemon *Dratini;
        Dratini = new Pokemon("Dratini", 37, 24, 18, 20, 15);
        addPokemen(Dratini);
        Pokemon *Dragonair;
        Dragonair = new Pokemon("Dragonair", 76, 55, 44, 47, 30);
        addPokemen(Dragonair);
        Pokemon *Dragonite;
        Dragonite = new Pokemon("Dragonite", 165, 152, 109, 93, 55);
        addPokemen(Dragonite);
        Pokemon *Mewtwo;
        Mewtwo = new Pokemon("Mewtwo", 415, 318, 278, 358, 80);
        addPokemen(Mewtwo);

    }



};


#endif // POKEMONDATABASE_H
