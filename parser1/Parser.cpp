#include "Parser.h"
#include <iostream>
#include "Tools.h"
using namespace std;


template<typename... Args>
string Parser<Args...>::getRow(istream &f, size_t linesBefore) {
    string str;
    char whatWriten;
    while (f.get(whatWriten)){
        if(whatWriten == rowSeparator){
            break;
        }
        str.push_back(whatWriten);
    }
    return str;
}

template<typename... Args>
int Parser<Args...>::linesCount() {
    file.clear();
    file.seekg(0, ios::beg);
    linesTotal = 0;
    while (getRow(file, linesTotal) != ""){
        linesTotal++;
    }
    file.clear();
    file.seekg(0, ios::beg);
    return 0;
}

template<typename... Args>
vector<string> Parser<Args...>::splitLine(string &line) {
    vector<string> parts;
    string curString;
    for(char whatWriten : line){
        if(whatWriten == columnSep) {
            parts.emplace_back(curString);
            curString.clear();
            continue;
        }
        curString.push_back(whatWriten);
    }
    if (!curString.empty()) parts.emplace_back(curString);
    return parts;
}

template<typename... Args>
tuple<Args...> Parser<Args...>::parseRow(string &line, int lineNumber) {
    int size = sizeof...(Args);

    if(line.empty()){
        throw invalid_argument("Empty line: " + to_string(lineNumber) + "!");
    }

    vector<string> parts = splitLine(line);

    if(parts.size() != size){
        throw invalid_argument("incorrect number of fields in line: " + to_string(lineNumber) + "!");
    }

    tuple<Args...> lineTuple;

    try{
        lineTuple = parseToTuple<Args...>(parts);
    }
    catch (exception& exc) {
        throw invalid_argument("Row - " + to_string(lineNumber) + ", Column -" + exc.what() + "incorrect type !");
    }

    return lineTuple;
}

template<typename... Args>
void Parser<Args...>::Iterator::updateContent() {
    if (last) content = "";
    else {
        file.clear();
        file.seekg(0, std::ios::beg);
        for (int i = 0; i < index; i++) parent->getRow(file, i);
        content = parent->getRow(file, index);
    }
}

template<typename... Args>
Parser<Args...>::Iterator::Iterator(ifstream &file, size_t index, Parser<Args...> *parent) {

}

