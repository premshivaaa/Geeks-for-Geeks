class Solution {
  public:
  
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int cost = 0;
        
        for(int i : arr){
            minHeap.push(i);
        }
        
        while(minHeap.size() > 1){
            int first = minHeap.top();
            minHeap.pop();
            int second = minHeap.top();
            minHeap.pop();
            
            int length = first + second;
            cost += length;
            
            minHeap.push(length);
        }
        
        return cost;
    }
};