#include<iostream>
#include<vector>
using namespace std;

int maxiProfit(vector <int>& prices){
    int mini = prices[0];
    int maxProfit = 0;
    int n = prices.size();

    for(int i=1; i<n; i++){
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}

int main(){
    vector <int> prices = {7, 1, 4, 3, 5, 6};
    maxiProfit(prices);

    return 0;
}