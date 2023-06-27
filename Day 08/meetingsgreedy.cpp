//https://www.codingninjas.com/codestudio/problems/maximum-meetings_8230795?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
struct meeting{
    int str;
    int en;
    int pos;
};

bool static comparator(struct meeting m1, meeting m2){
    if(m1.en < m2.en) return true;
    else if(m1.en > m2.en) return false;
    else if(m1.pos < m2.pos) return true;

    return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n = start.size();
    struct meeting meet[n];
    for(int i = 0 ; i < n; i++){
        meet[i].str = start[i];
        meet[i].en = end[i];
        meet[i].pos = i+1;
    }

    sort(meet, meet + n, comparator);

    vector<int>answer;

    int limit = meet[0].en;
    answer.push_back(meet[0].pos);
    
    for (int i = 1; i < n; i++) {
        if (meet[i].str > limit) {
            limit = meet[i].en;
            answer.push_back(meet[i].pos);
        }
      }
    return answer;
}

