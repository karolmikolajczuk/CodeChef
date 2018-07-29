#include <cstdlib>
#include <vector>
#include <algorithm>

int Sume_Of_Array(std::vector<int> array_copy)
{
    int sume = 0;
    for(int i=0; i<array_copy.size(); i++)
    {
        sume += array_copy[i];
    }
  return sume;  
}

void Print_Result(int result)
{
    std::cout << result << std::endl;
}


int main() {
    int size_of_array,
            block,
            possible_add,
            count_of_results=0;
    
    std::cin >> size_of_array >> block >> possible_add; 
    
    
    std::vector<int> array_elements;
    std::vector<int> array_elements_copy;
    std::vector<int> list_of_sume;
    
    for(int i=0; i<size_of_array; i++)
    {
        int temp;
        std::cin >> temp;
        array_elements.push_back(temp);
    
    }
    std::sort(array_elements.begin(), array_elements.end());
    array_elements_copy = array_elements;
   
    for(int i=0; i<array_elements.size(); i++)
    {
        if( i < array_elements.size()-1 && 
            array_elements_copy[i] <= block && 
            array_elements_copy[i+1] <= block)
        {
            while(array_elements_copy[i] <= block ||
                  array_elements_copy[i] <= block)
            {
                array_elements_copy[i]+=possible_add;
                array_elements_copy[i+1]+=possible_add;
            }
        }
    }
    
    list_of_sume.push_back(Sume_Of_Array(array_elements_copy));
    count_of_results++;
    
    Print_Result(count_of_results);
    return 0;
}

