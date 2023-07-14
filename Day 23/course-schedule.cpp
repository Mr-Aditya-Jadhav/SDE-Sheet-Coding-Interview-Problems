//https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int>adj[numCourses];
        for(auto it: pre){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(numCourses, 0);
        vector<int> ans;
        queue<int> q;

        for(int i = 0 ; i < numCourses; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        for(int i = 0 ; i < numCourses; i++){
            if(!indegree[i]){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            ans.push_back(p);
            for(auto it: adj[p]){
                indegree[it]--;
                if(!indegree[it]){
                    q.push(it);
                }
            }
        }
        
        return ans.size() == numCourses;
    }
};
