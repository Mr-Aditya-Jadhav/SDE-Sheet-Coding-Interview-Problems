//https://www.codingninjas.com/codestudio/problems/fractional-knapsack_8230767?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 

struct things{
    float ratio;
    int weight;
    int value;
};

static bool comparator(things a, things b)
{
    double r1 = (double) a.value / (double) a.weight;
    double r2 = (double) b.value / (double) b.weight;
    return r1 > r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    things thing[n];
    int i = 0;
    for(auto it: items){
        
        thing[i].weight = it.first;
        thing[i].value = it.second;
        i++;
    }
    

    sort(thing, thing + n, comparator);

    int curWeight = 0;
    double finalvalue = 0.0;

      for (i = 0; i < n; i++) {

         if (curWeight + thing[i].weight <= w) {
            curWeight += thing[i].weight;
            finalvalue += thing[i].value;
         } else {
            int remain = w - curWeight;
            finalvalue += (thing[i].value / (double) thing[i].weight) * (double) remain;
            break;
         }
      }

      return finalvalue;

}
