//https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    priority_queue<double>maxh;
    priority_queue<double,vector<double>,greater<double>>minh;
 
    void addNum(int num) {
        if(maxh.empty() || maxh.top()>=num) maxh.push(num);
        else minh.push(num);

        if(maxh.size()>minh.size()+1){
            minh.push(maxh.top());
            maxh.pop();
        }
        else if(maxh.size()<minh.size()){
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if(minh.size()<maxh.size()) return maxh.top();
        else return ((minh.top()+maxh.top())/2);
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
