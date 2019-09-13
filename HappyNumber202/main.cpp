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
#include <math.h>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> sumHolder;
        set<int>::iterator it;
        int num = n;
        while(num != 1){
            int sum;
            string numberString = to_string(num);
            int length = numberString.length();
            //Go through string and get the sum of the square of the digits
            for(int i=0; i<length; i++) {
                sum += (int(numberString[i] - '0') * int(numberString[i]- '0'));
            }
            //If sum found in the set = cycle
            it = sumHolder.find(sum);
            if(*it == sum){
                return false;
            }
            else{
                sumHolder.insert(sum);
            }
            num = sum;
            sum = 0;
        }
        return true;
    }
};

int main() {
    // insert code here...
    Solution test;
    int number = 30;
    bool answer = test.isHappy(number);
    cout << (answer?"It is a happy number \n":"It is not a happy number \n");
}
