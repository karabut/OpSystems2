#ifndef PARSER1_PARSER_H
#define PARSER1_PARSER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <tuple>

using namespace std;

template<typename ... Args>
class Parser {
private:
    ifstream &file;
    char columnSep;
    char rowSeparator;
    int linesTotal;
    int skippedLines;

    string getRow(istream &f, size_t linesBefore);
    int linesCount();
    vector<string> splitLine (string& line);
    tuple<Args...>parseRow(string& line, int lineNumber);

    class Iterator {
    private:
        ifstream &file;
        Parser<Args...>* parent;
        std::string content;
        size_t index;
        bool last;
        bool updatedContent;
        void updateContent();

    public:
        Iterator(ifstream &file, size_t index, Parser<Args...>* parent);
        Iterator& operator++();
        Iterator operator++(int i);
        bool operator==(const Iterator &it) const;
        bool operator!=(const Iterator &it);
        std::tuple<Args...> operator*();
    };

public:
    Parser(ifstream& file, int skippedLines);
    ~Parser();
    Iterator begin();
    Iterator end();
};



#endif //PARSER1_PARSER_H
