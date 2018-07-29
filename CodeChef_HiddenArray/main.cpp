/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: karol
 *
 * Created on 28 lipca 2018, 17:11
 */

#include <cstdlib>
#include <vector> //vector
#include <cstdio> //printf
#include <iostream>  // cin


using namespace std;

bool Check_If_Exists(vector<int> main_vec, int candidate)
{
    for(int i=0; i<main_vec.size(); i++)
    {
        if(main_vec[i] == candidate)
            return true;
    }
    return false;
}
int Get_New_Element(int type, int val)
{
    int a;
    printf("%d %d", type, val);
    cin >> a;
    return a;
}

int Get_K(vector<int> main_vec)
{
    int first_element = main_vec[main_vec.size()-1];
    int a;
    int n = 3;

    do
    {
        a = Get_New_Element(1, n);
        if(a != first_element)
        {
            do
            {
                n--;
                a = Get_New_Element(1, n);
                if(a == first_element)
                    return n;
            }while(1);
        }
        n+=3;
    }while(1);
}

void Answer(int type, int answer)
{
    printf("%d %d", type, answer);
}

int main() {

    // daj liste test caseow
    int number_of_test_cases, a, k, type, val;
    cin >> number_of_test_cases;
    
    // wszystkie test casey...
    while(number_of_test_cases--)
    {
        // lista roznych elementow tablicy
        vector<int> list_of_array_elements;
        
        type = 1;
        val = 3;
        // podaj pierwszy element
        cin >> a;
        
        // dodaj ten element do tablicy
        list_of_array_elements.push_back(a);

        // popros o pierwszy element tablicy
        int first_element = Get_New_Element(1, 1);
        list_of_array_elements.push_back(first_element);
        
        // get k pierwszego elementu
        k = Get_K(list_of_array_elements);
         
        int k_plus_one = k+1;
        int n_minus_one = 1;
        int n = 2;
        int n_times_k = n*k;
        
        for(int i=1; i<=60; i++)
        {
            int get_next_element = 
                Get_New_Element(1, n_minus_one*k_plus_one);
            
            int get_potential_element = 
                Get_New_Element(1, n_times_k*k_plus_one);
            
            if(get_next_element != get_potential_element)
                Answer(2, get_next_element);
            
            n++;
            n_minus_one++;
        }

        //schemat dzialania:
        //wez znajdz k pierwszego elementu
        //sprawdz element k+1 jaki jest i dodaj do listy
        //potem sprawdz element 2k
        //jezeli sa rowne to sprawdz element 2k+1
        //potem sprawdz element 3k
        //rob tak do momentu otrzymania dwoch roznych elementow
        //gdy otrzymasz rozne elementy wykonaj Answer
    }

    return 0;
}

