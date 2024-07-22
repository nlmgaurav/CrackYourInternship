long long  multiplyTwoLists (Node* l1, Node* l2){
  long long mod = 1000000007;
  Node *temp1 = l1;
  Node *temp2 = l2;
  long long s1 =0;
  while(temp1 != NULL){
      s1 = (s1*10)%mod+temp1->data;
      temp1 = temp1 ->next;
  }
  long long s2 = 0;
   while(temp2 != NULL){
      s2 = (s2*10)%mod+temp2->data;
      temp2 = temp2 ->next;
  }
  return (s1*s2)%mod;
}