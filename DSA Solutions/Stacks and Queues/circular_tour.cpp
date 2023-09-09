// https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int start=0,tot=0,cur=0;
       
       for(int i=0;i<n;i++){
           cur+=p[i].petrol - p[i].distance;
           tot+=p[i].petrol - p[i].distance;
           
           if(cur<0){
               cur=0;
               start=i+1;
           }
       }
       return tot>=0?start:-1;
    }
};