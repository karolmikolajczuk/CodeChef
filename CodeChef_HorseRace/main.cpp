#include <iostream> // cin
#include <vector>   // vector
#include <algorithm>// sort

int main() {
    int number_of_tests;
    int number_of_horses;
    
    std::cin >> number_of_tests;
    
    while(number_of_tests--)
    {
        std::vector<int> horses_power;
        std::cin >> number_of_horses;
        for(int i=0; i< number_of_horses; i++)
        {
            int power;
            std::cin >> power;
            horses_power.push_back(power);
        }
        
        std::sort(horses_power.begin(), horses_power.end());
        unsigned int minimum_difference = abs(horses_power[0]-horses_power[1]);
        for(int i=0; i<number_of_horses; i++)
        {
            if(i<number_of_horses-1 && 
                abs(horses_power[i]-horses_power[i+1]) < minimum_difference)
                minimum_difference = abs(horses_power[i]-horses_power[i+1]);
        }
        std::cout << minimum_difference << std::endl;
    }
    
    return 0;
}

