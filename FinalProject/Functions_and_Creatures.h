#ifndef Functions_and_Creatures
#define Functions_and_Creatures

using namespace std;

creature player; //create all players for the game
creature bat1;
creature bat2;
creature wumpus;
creature pit1;
creature pit2;
creature arrow;
creature arrow2;

void display_rules(char know_the_rules){
    if ((know_the_rules == 'Y') || (know_the_rules == 'y')){
        cout<<"------------------------------------------------------------------------------------------"<<endl;
        cout<<"The playing field consists of a 5 x 5 square with 25 different rooms. "<<endl;
        cout<<"The goal is to find the wumpus and shoot it with an arrow(5 chances)."<<endl;
        cout<<endl;
        cout<<" Objects: "<<endl;
        cout<<"          Wumpus: your target; a beast that eats you if you ever end up in the same room."<<endl;
        cout<<"          Super Bats (2): creatures that instantly carry you to a random room."<<endl;
        cout<<"          Pits (2): fatal to you if you enter the room."<<endl;
        cout<<" Actions: "<<endl;
        cout<<"          Move: to one of the four rooms connected to your current one."<<endl;
        cout<<"          Shoot: fire an arrow a distance of 1-4 rooms"<<endl;
        cout<<" Warning messages: "<<endl;
        cout<<"          Give you information about the contents of adjacent rooms."<<endl;
        cout<<"          Wumpus: 'You smell a wumpus'"<<endl;
        cout<<"          Bat: 'You hear flapping'"<<endl;
        cout<<"          Pit: 'You feel a draft'"<< endl;
        cout <<"------------------------------------------------------------------------------------------"<<endl;
    }
}

void show_direction(){
        if (player.get_direction() == 0) {cout << "You are currently facing North" << endl;}
        if (player.get_direction() == 1) {cout << "You are currently facing East" << endl;}
        if (player.get_direction() == 2) {cout << "You are currently facing South" << endl;}
        if (player.get_direction() == 3) {cout << "You are currently facing West" << endl;}
}

void show_location(){
    int x, y;
    player.get_location(x,y);
    cout << "You are currently at " << x << ", " << y << endl;
}

bool options(string choice, int& arrow_count){
    if (choice.compare("turn left") == 0){
        player.turn_left();
    }
    else if (choice.compare("turn right") == 0){
        player.turn_right();
    }
    else if (choice.compare("move forward") == 0){
        bool temp = player.move_forward();
        if (temp){
            cout << "Sadly, you cannot phase through walls. Try again" << endl;
        }
    }
    else if (choice.compare("options") == 0){
        cout << endl << "turn left" << endl;
        cout << "turn right" << endl;
        cout << "move forward" << endl;
        cout << "shoot arrow" << endl;
    }
    else if (choice.compare("shoot arrow") == 0){
        if (arrow_count == 0){
            cout << endl << "You Have No Arrows!" << endl;
        }
        else {
            int distance;
            cout << endl << "How many spaces would you like the arrow to go? (Up to 5): ";
            cin >> distance;
            while ((distance > 5) || (distance == 0)){
                if (distance == 0){
                    cout << "You got to shoot somewhere! Try again" << endl;
                    cout << "How many spaces would you like the arrow to go? (Up to 5): ";
                    cin >> distance;
                }
                else {
                    cout << "You can't shoot that far, try a different distance." << endl;
                    cout << "How many spaces would you like the arrow to go? (Up to 5): ";
                    cin >> distance;
                }
            }
            int x1, y1, x2, y2, x3, y3;
            player.get_location(x1, y1);
            arrow2.set_location(x1, y1);
            wumpus.get_location(x3, y3);
            if (player.get_direction() == 0){
                cout << "You fired an arrow to the north" << endl;
                arrow2.set_direction(0);
            }
            if (player.get_direction() == 1){
                cout << "You fired an arrow to the east" << endl;
                arrow2.set_direction(1);
            }
            if (player.get_direction() == 2){
                cout << "You fired an arrow to the south" << endl;
                arrow2.set_direction(2);
            }
            if (player.get_direction() == 3){
                cout << "You fired an arrow to the west" << endl;
                arrow2.set_direction(3);
            }
            
            for (int i = 0; i < distance; ++i){
                arrow2.move_forward();
            }
            arrow2.get_location(x2, y2);
            if ((x3 == x2) & (y3 == y2)){
                cout << "You Win!" << endl;
                return true;
            }
            else {
                cout << "You Missed..." << endl;
            }
            cin.ignore();
        }
    }
    else{
        cout << "That is not an option, Try Again." << endl << "See options anytime by saying 'options'." << endl;
    }
    return false;
}

void is_creature_nearby(){
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    player.get_location(x1,y1);
    bat1.get_location(x2,y2);
    bat2.get_location(x3,y3);
    wumpus.get_location(x4,y4);
    pit1.get_location(x5,y5);
    pit2.get_location(x6,y6);
    
    if ((x1 == x2) || (x1 == x2+1) || (x1 == x2-1)){
        if ((y1 == y2) || (y1 == y2+1) || (y1 == y2-1)){
            cout << "You hear flapping" << endl;
        }
    }
    else if ((x1 == x3) || (x1 == x3+1) || (x1 == x3-1)){
        if ((y1 == y3) || (y1 == y3+1) || (y1 == y3-1)){
            cout << "You hear flapping" << endl;
        }
    }
    
    if ((x1 == x4) || (x1 == x4+1) || (x1 == x4-1)){
        if ((y1 == y4) || (y1 == y4+1) || (y1 == y4-1)){
            cout << "You smell a wumpus" << endl;
        }
    }
    
    if ((x1 == x5) || (x1 == x5+1) || (x1 == x5-1)){
        if ((y1 == y5) || (y1 == y5+1) || (y1 == y5-1)){
            cout << "You feel a draft" << endl;
        }
    }
    else if ((x1 == x6) || (x1 == x6+1) || (x1 == x6-1)){
        if ((y1 == y6) || (y1 == y6+1) || (y1 == y6-1)){
            cout << "You feel a draft" << endl;
        }
    }
}

void did_i_touch_a_bat(){
    int x1, y1, x2, y2, x3, y3;
    player.get_location(x1,y1);
    bat1.get_location(x2,y2);
    bat2.get_location(x3,y3);
    
    if (((x1 == x2) & (y1 == y2)) || ((x1 == x3) & (y1 == y3))) { cout << "A Bat Picked You Up and Moved You!" << endl << endl; player.set_random_location(); }
}

bool did_wumpus_get_me(){
    int x1, y1, x2, y2;
    player.get_location(x1,y1);
    wumpus.get_location(x2,y2);
    
    if ((x1 == x2) & (y1 == y2)) { cout << "You Lost: The Wumpus Ate You!" << endl; return false; }
    else { return true; }
}

bool did_i_fall(){
    int x1, y1, x2, y2, x3, y3;
    player.get_location(x1,y1);
    pit1.get_location(x2,y2);
    pit2.get_location(x3,y3);
    
    if (((x1 == x2) & (y1 == y2)) || ((x1 == x3) & (y1 == y3))) { cout << "You Lost: You Fell In A Pit!" << endl; return false; }
    else { return true; }
}

void did_i_pick_up_arrow(int arrow_count){
    int x1, y1, x2, y2;
    player.get_location(x1,y1);
    arrow.get_location(x2,y2);
    
    if ((x1 == x2) & (y1 == y2)) { cout << "You Found An Arrow!" << endl << endl; arrow_count = arrow_count + 1; arrow.set_location(-1, -1); }
}

#endif