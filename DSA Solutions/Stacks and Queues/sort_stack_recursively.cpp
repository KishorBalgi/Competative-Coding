// https://practice.geeksforgeeks.org/problems/sort-a-stack/1

void SortedStack :: sort()
{
   //Your code here
   int cur=s.top();
   s.pop();
   if(s.empty()) return s.push(cur); 
   sort();
   
   if(s.top() > cur){
       int temp=s.top();
       s.pop();
       s.push(cur);
       s.push(temp);
       sort();
   }else{
       s.push(cur);
   }
   
}