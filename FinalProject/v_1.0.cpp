// Code by Todd Herron & Colton Murray
// Game: Hunt The Wumpus

#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>
#include <string>
#include "Creature.h"
#include "Functions_and_Creatures.h"
using namespace std;

int main(){
    srand(time(NULL));
    
    char play_again = 'N'; // variable for asking if the player wants to play again
    char know_the_rules;
    string choice;
    int arrow_count = 5;
    
    cout << "Do You Want To Know How To Play The Game? (Y/N) ";
    cin >> know_the_rules;
    display_rules(know_the_rules);
    
    
    do { // This loop is run while the player wants to play. If the player quits, the game will exit.
        
        player.set_random_location(); // puts characters in random starting positions
        bat1.set_random_location();
        bat2.set_random_location();
        wumpus.set_random_location();
        pit1.set_random_location();
        pit2.set_random_location();
        arrow.set_random_location();
        
        int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
        
        do { //This loop checks to make sure nothing overlaps. If it does, it just tries again until they don't
            player.get_location(x1,y1);
            bat1.get_location(x2,y2);
            bat2.get_location(x3,y3);
            wumpus.get_location(x4,y4);
            pit1.get_location(x5,y5);
            pit2.get_location(x6,y6);
            
            player.set_random_location();
            bat1.set_random_location();
            bat2.set_random_location();
            pit1.set_random_location();
            pit2.set_random_location();
            wumpus.set_random_location();
            
        }
        while (((x1 == x2)&(y1=y2))||((x1 == x3)&(y1=y3))||((x1 == x4)&(y1=y4))||((x1 == x5)&(y1=y5))||((x1 == x6)&(y1==y6)));
        
        player.set_random_direction();
        
        cin.ignore();
        cout << endl;
        
        do {
            show_direction();
            show_location();
            is_creature_nearby();
            did_i_pick_up_arrow(arrow_count);
            cout << "What would you like to do? ";
            getline(cin, choice);
            if (options(choice, arrow_count)){
                break;
            }
            cout << endl;
            did_i_touch_a_bat();
        } while (did_wumpus_get_me() && did_i_fall());
        
        cout << "Do You Want To Play Again? (Y/N) ";
        cin >> play_again;
    } while((play_again == 'Y') || (play_again == 'y'));
    
    return 0;
}