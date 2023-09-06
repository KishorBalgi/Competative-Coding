// https://practice.geeksforgeeks.org/problems/construct-binary-tree-from-string-with-bracket-representation/1

class Solution{
public:
    // function to construct tree from string
    string getChild(string str,int& i,int& j){
        stack<int> braces;
        do{
            if(str[j]=='(') braces.push(j);
            else if(str[j]==')') braces.pop();
            j++;
        }while(!braces.empty());
        i++;
        if(i==j-1) return "";
        return str.substr(i,j-i-1);
    }
    Node *treeFromString(string str){
        // code here
        if(str=="") return NULL;
        if(str[str.length()-1]!=')'){
            Node * newnode=new Node(stoi(str));
            return newnode;
        }
        int i=0,j=0;
        
        while(str[i]!='(') i++;
        
        Node * newnode=new Node(stoi(str.substr(0,i)));
        
        j=i;
        newnode->left=treeFromString(getChild(str,i,j));
        i=j;
        if(j<str.length()) newnode->right=treeFromString(getChild(str,i,j));
        
        return newnode;
    }
};