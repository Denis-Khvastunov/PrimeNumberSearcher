//
// Created by denis on 19.01.19.
//

#include "XMLparser.h"



void  XMLparser::getFile( std::string filename )
{
    std::string buffer;
    char c;

    auto in = std::ifstream(filename);
        if (!in) { throw std::logic_error("Trying to open nonexistent file!"); }

    while ( in.get( c ) ) buffer += c;
    in.close();

    text = std::move(buffer);
}


 std::vector<std::string> XMLparser::getData( const std::string &text, std::string tag )
{
    std::vector<std::string> collection;
    size_t pos = 0, start;

    while ( true )
    {
        start = text.find( "<" + tag, pos );   if ( start == std::string::npos ) return collection;
        start = text.find( '>' , start );
        start++;

        pos = text.find( "</" + tag, start );   if ( pos == std::string::npos ) return collection;
        collection.push_back( text.substr( start, pos - start ) );
    }
}

std::vector<std::pair<unsigned long long int, unsigned long long int>> XMLparser::getIntervals(){

    std::vector<std::pair<unsigned long long,unsigned long long>> int_intervals;
    std::vector<std::string> string_intervas = XMLparser::getData(text,"interval");

    for (auto &it : string_intervas){
        unsigned long long low,high;
        try {
            if (stoi(XMLparser::getData(it, "low").at(0)) < 0 || stoi(XMLparser::getData(it, "high").at(0)) < 0)
                throw std::logic_error("invalid input");
           low  = stoi(XMLparser::getData(it, "low").at(0));
           high = stoi(XMLparser::getData(it, "high").at(0));
           if (low >= high)
               throw std::logic_error("invalid input");
        }
        catch(...){
            std::cout << "input file has invalid arguments"<<std::endl;
            low = 0;
            high = 0;
        }
        int_intervals.emplace_back(std::make_pair(low,high));
    }

    return  int_intervals;
}


void XMLparser::outputNumbers(std::vector<unsigned long long> primes) {

    std::ofstream OutFile;
    OutFile.open("../xmldir/output.xml");
    OutFile << "<root> \n \t";
    OutFile << "<primes>";
    for (auto it : primes){
        OutFile << it << " ";
    }
    OutFile << "</primes> \n";
    OutFile << "</root>";

}

XMLparser::XMLparser(std::string filename) {
    getFile(filename);
}


