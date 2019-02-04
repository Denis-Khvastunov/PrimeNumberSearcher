//
// Created by denis on 22.01.19.
//
#include "gtest/gtest.h"
#include "PrimeSearcher.h"

#ifndef LISTATTEST_SEARCHERTEST_H
#define LISTATTEST_SEARCHERTEST_H
#endif //LISTATTEST_SEARCHERTEST_H

using namespace testing;

class SearcherTEST: public Test {
public:
    PrimeSearcher prms;


    static bool isPrime(unsigned long long n){
        for(unsigned long long i=2;i<=sqrt(n);i++)
            if(n%i==0)
                return false;
        return true;
    }


    static bool checkingPrimesVector(std::vector<unsigned long long>_prms){
        for (auto &it : _prms){
            if (!(SearcherTEST::isPrime(it)))
            return 0;
        }
        return 1;
        }
};

TEST_F(SearcherTEST, primesTEST){
    prms.sieveOfEratosthenes(2,15000);
    auto _prms = prms.getPrimes();
    ASSERT_TRUE(SearcherTEST::checkingPrimesVector(_prms));
}








