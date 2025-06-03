/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */

void insert(stack<int> &s, int val){
    if (s.empty() || val >= s.top()) {
        s.push(val);
        return;
    }
    int n = s.top();
    s.pop();
    insert(s, val);
    s.push(n);
}
void SortedStack ::sort() {
    // Your code here
    if(s.size()==0) return; 
    int val = s.top();
    s.pop();
    sort();
    insert(s,val);
    
}