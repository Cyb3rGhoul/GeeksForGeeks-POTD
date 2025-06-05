class Solution {
  public:
    // You need to complete this function
    

    int towerOfHanoi(int n, int from, int to, int aux) {
        // Your code here
        
        if(n==1 || n==0){
            return n;
        }
        int ctn = 1;
        ctn += towerOfHanoi(n-1,from,aux,to);
        ctn += towerOfHanoi(n-1,aux,to,from);
        
        return ctn;
    }
};