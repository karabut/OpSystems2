#include <iostream>
#include <time.h>
#include "map.h"
#include "robot.h"
int main() {
    srand(time(nullptr));
    
    just_map map;

    map.set_robot();
    robot r;
    r.ask_command(map);


    return 0;
}
