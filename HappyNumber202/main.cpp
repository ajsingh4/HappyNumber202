//
//  main.cpp
//  HappyNumber202
//
//  Created by Aj Gill on 8/18/19.
//  Copyright © 2019 Aj Gill. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

bool happyOrNot(set<int> sumHolder, int n){
    int sum = 0;
    //Convert to string and sum the squares of the digits
    string numberString = to_string(n);
    for(int i=0; i<numberString.length(); i++) {
        sum += (int(numberString[i] - '0') * int(numberString[i]- '0'));
    }
    set<int>::iterator it = sumHolder.find(sum);
    //If sum = 1, happy
    if(sum == 1){
        return true;
    }
    //If sum exists in the set, in a cycle
    else if(*it == sum){
        return false;
    }
    //If neither, add to the set and continue recursing
    else{
        sumHolder.insert(sum);
        return happyOrNot(sumHolder, sum);
    }
    return false;
}

int main() {
    set<int> sumHolder;
    int number = 30;
    bool answer = happyOrNot(sumHolder, number);
    cout << (answer?"It is a happy number \n":"It is not a happy number \n");
}
