//
// Created by Katya on 12.01.2021.
//

#include "map.h"
#include <random>
#include <cmath>



int just_map::get_X()const {
    return X;
}



int just_map::get_Y()const {
    return Y;
}

void just_map::set_robot_x(const int val){
    robot_x = val;
}

int just_map::get_robot_x()const {
    return robot_x;
}

void just_map::set_robot_y(const int val){
    robot_y = val;
}

int just_map::get_robot_y()const {
    return robot_y;
}

void just_map::set_apple_x(const int val){
    apple_x = val;
}

int just_map::get_apple_x()const {
    return apple_x;
}

void just_map::set_apple_y(const int val){
    apple_y = val;
}

int just_map::get_apple_y()const {
    return apple_y;
}

void just_map::set_sap_apple_x(const int val){
    sap_apple_x = val;
}

int just_map::get_sap_apple_x() const{
    return sap_apple_x;
}

void just_map::set_sap_apple_y(const int val){
    sap_apple_y = val;
}

int just_map::get_sap_apple_y()const {
    return sap_apple_y;
}


int just_map::get_plug_robot_x()const {
    return plug_robot_x;
}



int just_map::get_plug_robot_y()const {
    return plug_robot_y;
}

void just_map::set_sapper_x(const int val){
    sapper_x = val;
}

int just_map::get_sapper_x()const {
    return sapper_x;
}

void just_map::set_sapper_y(const int val){
    sapper_y = val;
}

int just_map::get_sapper_y()const {
    return sapper_y;
}


cell_value random_state() {
    int a = rand() % 10;
    if (a == 1){
        return APPLE;
    }else if (a == 2){
        return ROCK;
    }else if (a == 3){
        return BOMB;
    }else{
        return EMPTY;
    }
}

char to_map_sign(cell_value a){
    if(a == APPLE){
        return 'A';
    }
    if(a == ROCK){
        return '0';
    }
    if(a == BOMB){
        return '*';
    }
    if(a == EMPTY){
        return '.';
    }
    if(a == ROBOT_COLLECTOR){
        return 'C';
    }
    if(a == ROBOT_SAPPER){
        return 'S';
    }
    if(a == BORDER){
        return '^';
    }
    return '?';
}

just_map::just_map() {
    int x = 1000;
    int y = 1000;

    X = x;
    Y = y;
    map = new cell_value*[x];

    for(int i = 0; i < x; i++){
        map[i] = new cell_value[y];
    }

    for (int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            map[i][j] = random_state();
        }
    }
}

void just_map::set_robot() {
    int a = rand() % X;
    int b = rand() % Y;
    while(map[a][b] != EMPTY){
        a = rand() % X;
        b = rand() % Y;
    }

    robot_x = a;
    robot_y = b;
    plug_robot_x = a;
    plug_robot_y = b;
    map[a][b] = ROBOT_COLLECTOR;
}


void just_map::set_map(int x, int y, cell_value val) {
    map[x][y] = val;
}

cell_value just_map::get_map(const int x,const int y)const {
    return map[x][y];
}

robot_map::~robot_map(){
    data.clear();
}

bool robot_map::is_discovered(const int x,const int y) const {
    for(auto m : this->data){
        if(m.get_X() == x && m.get_Y() == y){
            return true;
        }
    }
    return false;
}

map_cell::map_cell() {
    X = 0;
    Y = 0;
    value = MYSTERY;
}


int map_cell::get_X()const {
    return X;
}

void map_cell::set_X(const int val) {
    X = val;
}

int map_cell::get_Y()const {
    return Y;
}

void map_cell::set_Y(const int val) {
    Y = val;
}

cell_value map_cell::get_value()const {
    return value;
}

void map_cell::set_value(const cell_value val) {
    value = val;
}

int r_search::get_to_from_point() const{
    return to_from_point;
}

void r_search::set_to_from_point(const int val) {
    to_from_point = val;
}

int r_search::get_to_go_point()const {
    return to_go_point;
}

void r_search::set_to_go_point(const int val) {
    to_go_point = val;
}

int r_search::get_from_to_sum()const {
    return from_to_sum;
}

void r_search::set_from_to_sum(const int val) {
    from_to_sum = val;
}

int r_search::get_previous_x()const {
    return previous_x;
}

void r_search::set_previous_x(const int val) {
    previous_x = val;
}

int r_search::get_previous_y() const{
    return previous_y;
}

void r_search::set_previous_y(const int val) {
    previous_y = val;
}

void robot_map::add_cell(const int x,const int y,const cell_value val) {
    map_cell new_cell;
    new_cell.set_X(x);
    new_cell.set_Y(y);
    new_cell.set_value(val);

    this->data.push_back(new_cell);
}


cell_value robot_map::get_cell(const int x,const int y) const {
    for (auto m : data){
        if(m.get_X() == x && m.get_Y() == y){
            return m.get_value();
        }
    }
}

bool robot_map::is_added(const int a,const int b) {
    for (auto & m : data){
        if(m.get_X() == a && m.get_Y() == b){
            return true;
        }
    }
    return false;
}

bool is_added(const int a,const int b , std::vector<r_search> r_vector) {
    for (auto & m : r_vector){
        if(m.get_X() == a && m.get_Y() == b){
            return true;
        }
    }
    return false;
}
