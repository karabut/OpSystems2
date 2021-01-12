//
// Created by Katya on 12.01.2021.
//

#ifndef ROBOTS2_MAP_H
#define ROBOTS2_MAP_H

#include <string>
#include <vector>
#include <random>
#include <iostream>
#include <time.h>

enum cell_value{
    ROBOT_COLLECTOR,
    ROBOT_SAPPER,
    MYSTERY,
    EMPTY,
    ROCK,
    BOMB,
    APPLE,
    BORDER,
};

cell_value random_state();

char to_map_sign(cell_value a);

class just_map{
private:
    int X;
    int Y;
    cell_value ** map;
    int robot_x;
    int robot_y;
    int apple_x;
    int apple_y;
    int sap_apple_x;
    int sap_apple_y;
    int plug_robot_x;
    int plug_robot_y;
    int sapper_x;
    int sapper_y;
public:

    just_map();
    int get_X()const;
    int get_Y()const;
    void set_robot_x(const int val);
    int get_robot_x()const;
    void set_robot_y(const int val);
    int get_robot_y()const;
    void set_apple_x(const int val);
    int get_apple_x()const;
    void set_apple_y(const int val);
    int get_apple_y()const;
    void set_sap_apple_x(const int val);
    int get_sap_apple_x()const;
    void set_sap_apple_y(const int val);
    int get_sap_apple_y()const;
    int get_plug_robot_x()const;
    int get_plug_robot_y()const;
    void set_sapper_x(const int val);
    int get_sapper_x()const;
    void set_sapper_y(const int val);
    int get_sapper_y()const;

    void set_map(const int x,const int y,const cell_value val);
    cell_value get_map(const int x,const int y)const;
    void set_robot();
};


std::ostream& operator<<(std::ostream& os, const just_map& map_t);





class map_cell{
private:
    int X;
    int Y;
    cell_value value;
public:
    int get_X()const;
    void set_X(const int val);
    int get_Y()const;
    void set_Y(const int val);
    cell_value get_value()const;
    void set_value(const cell_value val);


    map_cell();
};

class r_search: public map_cell{
private:
    int to_from_point = 0;
    int to_go_point = 0;
    int from_to_sum = 0;
    int previous_x = 0;
    int previous_y = 0;
public:
    int get_to_from_point()const;
    void set_to_from_point(const int val);
    int get_to_go_point()const;
    void set_to_go_point(const int val);
    int get_from_to_sum()const;
    void set_from_to_sum(const int val);
    int get_previous_x()const;
    void set_previous_x(const int val);
    int get_previous_y()const;
    void set_previous_y(const int val);

};

bool is_added(const int , const int, std::vector<r_search>);

class robot_map{
public:
    std::vector<map_cell> data;
    robot_map() = default;

    ~robot_map();

    cell_value get_cell(const int ,const int)const;
    bool is_discovered(const int,const int) const;
    void add_cell(const int ,const int,const cell_value);
    bool is_added(const int ,const int);
};



#endif //ROBOTS2_MAP_H
