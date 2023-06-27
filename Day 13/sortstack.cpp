//https://www.codingninjas.com/studio/problems/sort-a-stack_8230787?challengeSlug=striver-sde-challenge&leftPanelTab=1
#include <bits/stdc++.h>
void sortedInsert(stack<int> &stack, int num) {

    //base case

    if(stack.empty() || (!stack.empty() && stack.top() < num) ) {

        stack.push(num);

        return;

    }

    

    int n = stack.top();

    stack.pop();

    

    //recusrive call

    sortedInsert(stack, num);

    

    stack.push(n);

}

void sortStack(stack<int> &stack)

{

        //base case

        if(stack.empty()) {

            return ;

        }

    

        int num = stack.top();

        stack.pop();

    

        //recursive call

        sortStack(stack);

    

        sortedInsert(stack, num);

}
