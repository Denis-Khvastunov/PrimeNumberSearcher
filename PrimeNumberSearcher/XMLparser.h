//
// Created by denis on 19.01.19.
//
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#ifndef LISTATTEST_XMLPARSER_H
#define LISTATTEST_XMLPARSER_H


class XMLparser {
private:
    std::string text;
public:
    XMLparser() = default;
    XMLparser(std::string text);

    void getFile(std::string filename);
    static std::vector<std::string> getData( const std::string &text, std::string tag );
    std::vector<std::pair<unsigned long long int, unsigned long long int>> getIntervals();
    void outputNumbers(std::vector<unsigned long long>);



};


#endif //LISTATTEST_XMLPARSER_H
