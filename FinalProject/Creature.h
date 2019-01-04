#ifndef Creature
#define Creature

using namespace std;

class creature {
    public:
    
    void set_random_location();
    void set_location(int, int);
    void get_location(int&, int&);
    void set_random_direction();
    int get_direction();
    void set_direction(int);
    void turn_left();
    void turn_right();
    bool move_forward();
    
    private:
    
    int direction_facing;
    int location_x;
    int location_y;
    
};

void creature::set_random_location(){
    location_x=rand()%5;
    location_y=rand()%5;
}

void creature::set_location(int x, int y){
location_x = x;
    location_y = y;
}

void creature::get_location(int& x, int& y){
    x = location_x;
    y = location_y;
}

void creature::set_random_direction(){
    direction_facing = rand()%4;
}

int creature::get_direction(){
    return direction_facing;
}

void creature::set_direction(int a){
    direction_facing = a;
}

void creature::turn_left(){
    if (direction_facing == 0) {direction_facing = 3;}
    else {direction_facing = direction_facing-1;}
}
void creature::turn_right(){
    if (direction_facing == 3) {direction_facing = 0;}
    else {direction_facing = direction_facing+1;}
}

bool creature::move_forward(){
    if (direction_facing == 0){
        if (location_y>0) {location_y = location_y - 1; return 0;}
        else{return 1;}
    }
    if (direction_facing == 1){
        if (location_x<4) {location_x = location_x + 1; return 0;}
        else{return 1;}
    }
    if (direction_facing == 2){
        if (location_y<4) {location_y = location_y + 1; return 0;}
        else{return 1;}
    }
    if (direction_facing == 3){
        if (location_x>0) {location_x = location_x - 1; return 0;}
        else{return 1;}
    }
}

#endif