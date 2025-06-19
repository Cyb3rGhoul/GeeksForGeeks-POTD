class Solution {
  public:
    int BinarySearch(vector<int> &arr, int val,int InitialIndex){
        /*
        
        This Function return index of the first element greater than val
        
        */
        int l = InitialIndex;
        int r = arr.size()-1;
        
        while(l<=r){
            int mid = l+(r-l)/2;
            
            if(arr[mid]<=val){
                l = mid+1;
            }
            else{
                r = mid-1; 
            } 
        }
        return l;
    }
    int minimumCoins(vector<int>& arr, int k) {
        
        sort(arr.begin(),arr.end());
        
        int n = arr.size();
        int result = INT_MAX;
        
        int pre[n+1] = {0};
        for(int i = 1; i<=n; i++)pre[i] = pre[i-1]+arr[i-1];
        
        for(int i = 0;i<n;i++){
            int idx = BinarySearch(arr, arr[i]+k, i);
            
            int SumOfLeftElements = pre[i];
            int SumOfRightElements = (pre[n] - pre[idx]);
            
            // removing left side elements
            int LeftSideCost = SumOfLeftElements;
            
            // making right side elements equal to (arr[i]+k)
            int RightSideCost = SumOfRightElements - (arr[i]+k)*(n-idx); 
            
            int CurrentCost = RightSideCost + LeftSideCost;
            
            result = min(result,CurrentCost);
        }
        
        return result;
    }
};
