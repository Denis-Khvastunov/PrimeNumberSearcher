//
// Created by denis on 21.01.19.
//

#include "PrimeSearcher.h"


void PrimeSearcher :: sieveOfEratosthenes(unsigned long long int low, unsigned long long int high) {
    bool sieve[high];
    for(auto& it : sieve){
        it = true;
    }

    for (int p=2; p*p<=high; p++)
    {
        if (sieve[p])
        {
            for (int i=p*p; i<=high; i += p)
                sieve[i] = false;
        }
    }
    std::unique_lock<std::mutex> lock(m_vector);


    for (unsigned long long i = low; i < high; i++){
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
    std::cout << "thread operating interval "<<low<<" : "<<high<<" finished work "<<std::endl;

}


void PrimeSearcher :: deleteNotUnique(){
    std::sort(primes.begin(),primes.end());
    primes.resize(unique(primes.begin(),primes.end())-primes.begin());

}


void PrimeSearcher :: joinThreads() {
    for (auto &it : threads){
        it.join();
    }
}

void PrimeSearcher :: setThreads() {
    for (auto it : intervals){
        threads.emplace_back(std::thread(&PrimeSearcher::sieveOfEratosthenes,this,it.first,it.second));
    }
}

void PrimeSearcher ::setIntervals(XMLparser xml) {
    intervals = xml.getIntervals();
}

const std::vector<unsigned long long int> &PrimeSearcher::getPrimes() const {
    return primes;
}
