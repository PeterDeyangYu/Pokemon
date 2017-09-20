#include "player.h"

#include "battle.h"

Player::Player()
{

}
void Player::introduction()
{

    string s = "What is your name: ";
    for(const auto c : s)
    {
        cout << c << flush;
        this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    cin>> playerName;
    cout << "Welcome " << playerName << "!" << endl;
    //Sleep(1000);
    string PokemonName, Charmander1, Squirtle1, Bulbasaur1;
    Charmander1 = "Charmander";
    Squirtle1 = "Squirtle";
    Bulbasaur1 = "Bulbasaur";
    cout<< "Charmander" << endl;
    //Sleep(1000);
    cout<< "Squirtle" << endl;
    //    Sleep(1000);
    cout<< "Bulbasaur" << endl;
    // Sleep(1000);
    cout<< "Pick your pokemon: " << flush;
    while(true)
    {
        cin >> PokemonName;
        if(PokemonName == Charmander1)
        {
            Pokemon* Charmander;
            Charmander = new Pokemon;
            Charmander->setLevel(5);
            Charmander->setName("Charmander");
            Charmander->setHp(18);
            Charmander->setAtk(10);
            Charmander->setDef(9);
            Charmander->setSpd(11);
            PlayerPokemon[0] = Charmander;
            break;
        }
        if(PokemonName == "100011101010100101110010100000000000111010010001001111101010111110100101000101010101010101011001001010101001101001010001000101110101001")
        {
            Pokemon* Charmander;
            Charmander = new Pokemon;
            Charmander->setLevel(1);
            Charmander->setName("eerereeee");
            Charmander->setHp(1111);
            Charmander->setAtk(100000);
            Charmander->setDef(1222);
            Charmander->setSpd(11);
            PlayerPokemon[0] = Charmander;
            break;
        }
        if(PokemonName == Squirtle1)
        {
            Pokemon* Squirtle;
            Squirtle = new Pokemon;
            Squirtle->setLevel(5);
            Squirtle->setName("Squirtle");
            Squirtle->setHp(19);
            Squirtle->setAtk(9);
            Squirtle->setDef(11);
            Squirtle->setSpd(9);
            PlayerPokemon[0] = Squirtle;
            break;
        }
        if(PokemonName == Bulbasaur1)
        {
            Pokemon* Bulbasaur;
            Bulbasaur = new Pokemon;
            Bulbasaur->setLevel(5);
            Bulbasaur->setName("Bulbasaur");
            Bulbasaur->setHp(19);
            Bulbasaur->setAtk(9);
            Bulbasaur->setDef(9);
            Bulbasaur->setSpd(9);
            PlayerPokemon[0] = Bulbasaur;
            break;
        }
        else
        {
            cout << "Try again: " << flush;
        }
    }
    cout<<"Here's your " << PokemonName << "!" << " Take good care of it please!" << endl;
}
void Player::playthrough(){


    // Sleep(1000);
    cout << "Fight gym " << gym_counter << "->" << flush;
    cout << " (Gym)" << endl;
    //    Sleep(1000);
    cout << "Encounter a wild Pokemon. (Wild)" << endl;
    string gym_battle, wild_encounter, menu;
    gym_battle = "Gym";
    wild_encounter = "Wild";

    while(true){
        cout<<"What would you like to do: " << flush;
        cin>> action;
        if(action == gym_battle)
        {

            break;
        }
        if(action == wild_encounter)
        {
            Battle *r;
            r = new Battle(*this);
            r->Wild_Encounter();

            /*
            if()

            int t = rand() % 150;
            if(t == 0)
            {
                while()
                {

                }
            }
*/
            // break;
        }
        if(action == menu)
        {
            cout<<"Pokemon Party"<< endl;
            cout<<"Save"<< endl;
            cout<<"Quit"<< endl;
            /*
            cout<<"Store"<<e endl;
            cout<<"Release"<< endl;
            */
            break;
        }
    }
}
