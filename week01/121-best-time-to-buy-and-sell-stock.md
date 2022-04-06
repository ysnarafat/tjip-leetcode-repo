[121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)



```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 10005, currentProfit;
        int profit = 0;
        
        for(int i = 0; i < prices.size(); i++) {            
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            }
            
            currentProfit = prices[i] - minPrice;
            
            if(currentProfit > profit) {
                profit = currentProfit;
            }
        }
        
        return profit;
    }
};
```

> Time Complexity - O(N) </br>
> Space Complexity - O(1)