#include <iostream>

int main() {
    
    int tab[4];
    
    for(int i=0; i<4; i++)
        std::cin >> tab[i];
    
    if(tab[0]*tab[1] == tab[2]*tab[3] || 
       tab[0]*tab[2] == tab[1]*tab[3] || 
       tab[0]*tab[3] == tab[1]*tab[2])
        std::cout << "Possible";
    else
        std::cout << "Impossible";
    
    return 0;
}

