#include<iostream>
using namespace std;

class Solution{
    public:
        string intToRoman(int num){
            int val=0,mul=10;
            string roman="";
            while(num!=0){
                val=num%mul;
                roman=calcRoman(val)+roman;
                num=num-val;
                mul*=10;
            }
            return roman;
        }

        string calcRoman(int n){
            if(n==0) return "";
            if(n<=10){
                switch(n){
                    case 1: return "I";
                    case 2: return "II";
                    case 3: return "III";
                    case 4: return "IV";
                    case 5: return "V";
                    case 6: return "VI";
                    case 7: return "VII";
                    case 8: return "VIII";
                    case 9: return "IX";
                    case 10: return "X";
                }
            }else if(n<=100){
                int diff=100-n;
                string xs="";
                if(diff<50){
                   for(int i=1;i<=diff/10;i++){
                    xs+="X";
                   } 
                   return xs+"C";
                }else{
                    for(int i=1;i<=(diff-50)/10;i++){
                        xs+="X";
                    }
                    return xs+"L";
                }
            }else if(n<=1000){
                int diff=1000-n;
                string cs="";
                if(diff<500){
                   for(int i=1;i<=diff/100;i++){
                    cs+="C";
                   } 
                   return cs+"M";
                }else{
                    for(int i=1;i<=(diff-500)/100;i++){
                        cs+="C";
                    }
                    return cs+"DM";
                }
            }else{
                string ms;
                for(int i=1;i<=n/1000;i++){
                    ms+="M";
                }
                return ms;
            }
            return "";
        }
};

int main(){
    int num=1994;
    Solution a;
    cout<<a.intToRoman(num)<<endl;
}