#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
using namespace std;

int main(void)
{
    string message = "Hello World";
    string characters = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    string current_string = "";

    for (int i = 0; i < message.length(); i++)
    {
        for (int j = 0; j < characters.length(); j++)
        {
            char prefix = characters[j];
            system("clear");
            cout << current_string + prefix << endl;

            chrono::milliseconds delay(20);
            this_thread::sleep_for(delay);
            if (message[i] == prefix)
            {
                current_string += prefix;
                break;
            }
        }
    }
    return 0;
}