#include <iostream>
#include <gtest/gtest.h>
#include "PrimeSearcher.h"
#include "XMLparser.h"
#include "ParserTEST.h"
#include "SearcherTEST.h"


int main(int argc, char **argv){
    testing::InitGoogleTest( &argc, argv);

    std::clock_t start = std::clock();

   PrimeSearcher pr;
   XMLparser xml("../xmldir/input.xml");
   pr.setIntervals(xml);
   pr.setThreads();
   pr.joinThreads();
   pr.deleteNotUnique();
   xml.outputNumbers(pr.getPrimes());

   std::cout<<"\n Work duration: "<<(std::clock() - start) / (double) CLOCKS_PER_SEC <<"s"<<std::endl;

    return RUN_ALL_TESTS();
    //return 0;


}
