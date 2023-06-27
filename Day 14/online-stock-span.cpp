//https://leetcode.com/problems/online-stock-span/

class StockSpanner {
public:
    stack<pair<int, int>> st;
  
    StockSpanner() {
        
    }
    
    int next(int price) {
        pair<int, int> temp;
        int num = 1;
        int toret;
        temp.first = price;
        if(st.empty()){ 
            temp.second = 1; 
            toret = 1;
            }
        else{
            if(st.top().first > price){
                temp.second = 1;
                toret = 1;
            }
            else{
               while(!st.empty() && st.top().first <= price){
                   num += st.top().second;
                   st.pop();
               } 
               toret = num;
               temp.second = num;
            }
        }

        st.push(temp);

        return toret;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */