// https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1

string inorder(Node* root,unordered_map<string,int>& m,vector<Node*>& dupTrees){
        if(!root) return "#";
        
        string str="(";
        str+=inorder(root->left,m,dupTrees);
        str+=to_string(root->data);
        str+=inorder(root->right,m,dupTrees);
        str+=')';
        
        if(m[str]==1) dupTrees.push_back(root);
        m[str]++;
        
        return str;
    }
    vector<Node*> printAllDups(Node* root)
    {
        // Code here
        vector<Node*> dupTrees;
        unordered_map<string,int> hashInorder;
        
        inorder(root,hashInorder,dupTrees);
        
        return dupTrees;
    }