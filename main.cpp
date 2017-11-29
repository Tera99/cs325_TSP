//
//  main.cpp
//  TSP
//
//  Created by Terezie Schaller on 11/29/17.
//  Copyright © 2017 Terezie Schaller. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <sstream>
#include <cmath>

using namespace std;

struct city{
    int id;
    int x;
    int y;
};

int distance(struct city a, struct city b);

void tourLength(vector<int> &myVector, int size, vector<city> &mycityList);

int main() {
    
    //make a vector representing an arbitrary tour
    int size = 5;
    vector <int> route(size);
    for (int i = 0; i < size; i++){
        route[i] = i;
    }
    
    //hardcode some cities
    city cityA;
    city cityB;
    city cityC;
    city cityD;
    city cityE;
    
    cityA.id = 0;
    cityA.x = 2;
    cityA.y = 2;
    
    cityB.id = 1;
    cityB.x = 5;
    cityB.y = 8;
    
    cityC.id = 2;
    cityC.x = 5;
    cityC.y = 3;
    
    cityD.id = 3;
    cityD.x = 8;
    cityD.y = 6;
    
    cityE.id = 4;
    cityE.x = 2;
    cityE.y = 7;
    
    //need a hardcoded city list
    vector<city> cityList;
    cityList.push_back(cityA);
    cityList.push_back(cityB);
    cityList.push_back(cityC);
    cityList.push_back(cityD);
    cityList.push_back(cityE);
    
    tourLength(route, size, cityList);
    
    return 0;
} //end main


//function definitions

int distance(struct city a, struct city b){
    return round(sqrt(pow((b.x - a.x),2) + pow((b.y - a.y),2)));
}

void tourLength(vector<int> &myVector, int size, vector<city> &mycityList){
    //2-OPT code here
    //get tour length
    int length = 0;
    for (int i = 0; i < size-1; i++){
        cout << "city ids: " << myVector[i] << "   " << myVector[i+1] << endl;
        int nextEdge = distance(mycityList[myVector[i]], mycityList[myVector[i+1]]);
        cout << "edge length: " << nextEdge << endl;
        length += nextEdge;
        cout << "total tour length: " << length << endl;
    }
    
    //connect the tail to start
    cout << "Return to start" << endl;
    cout << "city ids: " << myVector.back() << "   " << myVector[0] << endl;
    int lastEdge = distance(mycityList[myVector.back()], mycityList[myVector[0]]);
    length += lastEdge;
    
    cout << "last edge: " << lastEdge << endl;
    cout << "Length: " << length << endl;
    //pick 2 edges, swap, and check tour length
    
    //swap if needed
    
}


