// https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> diagonalTrav;
   queue<Node*> nxtDia;
   nxtDia.push(root);

   while(!nxtDia.empty()){
       int queueCnt=nxtDia.size();
        while(queueCnt--){
            Node* cur=nxtDia.front();
            while(cur){
                diagonalTrav.push_back(cur->data);
                if(cur->left) nxtDia.push(cur->left);
                cur=cur->right;
            }
            nxtDia.pop();
        }
   }
   
   return diagonalTrav;
}