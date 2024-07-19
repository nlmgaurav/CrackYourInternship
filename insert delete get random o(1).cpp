class RandomizedCollection {
public:
    map<int,int>m1;
     vector<int>v1;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        v1.push_back(val);
        if(m1.count(val)>0){
            m1[val]++;
            return 0;
        }
        else{
             m1[val]++;
        return 1;
        }
    }
    
    bool remove(int val) {
        vector<int>::iterator itr;
        itr=v1.begin();
        for(int i=0;i<v1.size();i++){
          
            if(v1[i]==val){
            v1.erase(itr);
            break;}
              itr++;
        }
        bool t=false;
        if(m1.count(val)==0){
            t=false;
        }else{
       if(m1[val]>1){
            m1[val]--;
            t=true;
        }
        else if(m1[val]==1){
            m1.erase(val);
            t=true;
        }}
       
        return t;
    }
    
    int getRandom() {
        int n=0;
       
       
      n=v1.size();
      if(n!=0){
      int c=rand()%n;
      return v1[c];
      }
      else
      return 0;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */