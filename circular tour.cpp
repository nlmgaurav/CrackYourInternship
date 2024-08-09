   int tour(petrolPump p[],int n)
    {
     int curr_petrol=0,start=0,prev =0;
       
       for(int i = 0;i<n;i++){
           curr_petrol+= (p[i].petrol - p[i].distance);
           if(curr_petrol<0) {
               start = i+1;
               prev += curr_petrol;
               curr_petrol = 0;
           }
       }
       return ((prev+curr_petrol)>0) ? (start):-1;
       
       
    }