#include <iostream>
#include <ctime>

class Random
{
private:
    const unsigned int seed;

protected:
    const int getRandomNumber(int &, int &);

public:
    Random(void);
    Random(const int);
    int randomize(int, int);
    int randomize(void);
    const int getSeed(void);
};

Random ::Random() : seed(time(nullptr)) {}

Random ::Random(const int customSeed) : seed(customSeed) {}

int const Random::getSeed()
{
    return seed;
}

const int Random::getRandomNumber(int &low, int &high)
{
    long int key = seed * seed * 345678897565 + 5677886354;
    int randomNumber = low + seed % (high - low + 1);
    return randomNumber;
}

int Random ::randomize()
{
    int low = 0, high = 100;
    return getRandomNumber(low, high);
}
int Random ::randomize(int lowerLimit, int upperLimit)
{
    return getRandomNumber(lowerLimit, upperLimit);
}
