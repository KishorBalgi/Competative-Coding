        int rounds=0,temp;
        map<int,int> counts;
        for(int i:tasks){
            ++counts[i];
        }
        for(const auto &item:counts){
            cout<<item.first<<" : "<<item.second<<endl;
            if(item.second==1) return -1;
            temp=item.second;
            if(temp%3==0)
                rounds+=temp/3;
            else{
                rounds+=temp/3+1;
            }
            
        }
        return rounds;