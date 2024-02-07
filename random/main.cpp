#include <iostream>
#include "Random.hpp"
using namespace std;

int main(void)
{
    Random r0, r1(1707304574);
    int random1 = r0.randomize(30, 50);
    int random1Seed = r0.getSeed();
    int random2 = r1.randomize(30, 50);
    cout << random1 << "\tseed = " << random1Seed << endl;
    cout << random2 << endl;
}