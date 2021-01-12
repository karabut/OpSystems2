//
// Created by Katya on 12.01.2021.
//

#ifndef ROBOTS2_ROBOT_H
#define ROBOTS2_ROBOT_H

#include "map.h"
#include <string>
#include <iostream>
#include <cmath>

enum move_command{
    NO,
    UP,
    DOWN,
    RIGHT,
    LEFT
};



class shared_command{
private:
    cell_value value;
    int X;
    int Y;
public:
    cell_value get_value()const;
    void set_value(const cell_value val);
    int get_X()const;
    void set_X(const int val);
    int get_Y()const;
    void set_Y(const int val);

};

class auto_command{
private:
    move_command value;
    int idx;
public:

    move_command get_value();
    void set_value(const move_command val);
    int get_idx()const;
    void set_idx(const int val);
};




class robot{
private:
    int apple_counter;
    int X;
    int Y;
    bool can_take_apple = false;
    int r_map_rad;
    bool sapp_on = false;
    robot_map map;
public:
    robot();






    void move(const move_command order, just_map& god_map);
    void grab(just_map& god_map);
    void scan(just_map& god_map);
    void draw_robot_map(just_map& god_map);
    void autobot(int N, just_map& god_map);
    void apple_collector(just_map& god_map);

    void set_sapper(just_map &god_map);
    void destroy_sapper(just_map &god_map);

    robot_map give_map_to_sapper();
    void take_fixes(const shared_command c);

    void add_siblings(const int x,const int y,const int to_from, std::vector<r_search>& from, std::vector<r_search>& to);
    void shortest_way(const int x_in_search,const int y_in_search,const int maximum_x,const int maximum_y, cell_value** tmp_map, just_map& god_map);
    bool shortest_coll(const int x_in_search,const int y_in_search,const int maximum_x,const int maximum_y, cell_value** tmp_map, just_map& god_map);


    bool make_collector_move(const int tmp_x,const int tmp_y,const int maximum_x,const int maximum_y, std::vector<map_cell>& apple_positions, cell_value** tmp_map, just_map& god_map, shared_command *c);
    int step_amount(std::string str,const int a)const;
    void ask_command(just_map& god_map);

};



class sapper{
private:
    int X;
    int Y;
    robot_map map;
    bool can_smash_apple = false;
public:

    sapper();
    void move_sapper(const move_command order, just_map &god_map, move_command *collector_command);

    void add_siblings(const int x,const int y,const int to_from, std::vector<r_search>& from, std::vector<r_search>& to);
    bool shortest_sapp(const int x_in_search,const int y_in_search,const int maximum_x,const int maximum_y, cell_value** tmp_map, just_map& god_map,  move_command *collector_command);
    bool make_sapp_move(const int maximum_x,const int maximum_y, std::vector<map_cell>& bomb_positions, cell_value** tmp_map, just_map& god_map, shared_command *c,  move_command *collector_command);

    void get_map_from_collector(robot_map got_one);
    void take_fixes(const shared_command c);
};
 //Todo some basic staff

#endif //ROBOTS2_ROBOT_H
