//
// Created by denis on 21.01.19.
//
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <cmath>
#include <cstring>
#include <algorithm>
#include "XMLparser.h"
#ifndef LISTATTEST_PRIMESEARCHER_H
#define LISTATTEST_PRIMESEARCHER_H



class PrimeSearcher {

private:
    std::mutex m_vector;
    std::vector<unsigned long long> primes;
    std::vector<std::thread> threads;
    std::vector<std::pair<unsigned long long, unsigned long long>> intervals;
public:
    void sieveOfEratosthenes(unsigned long long low, unsigned long long high);
    const std::vector<unsigned long long int> &getPrimes() const;
    void deleteNotUnique();
    void joinThreads();
    void setThreads();
    void setIntervals(XMLparser xml);
};
#endif //LISTATTEST_PRIMESEARCHER_H


