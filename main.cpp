#include <iostream>
#include <string>
#include <stack>

using namespace std;

int cal(char oper, int a, int b)
{
    switch(oper)
    {
    case '+':
       return (a+b);
    break;
    case '-':
       return a-b;
    break;
    case '*':
       return a*b;
    break;
    case '/':
       return a/b;
    break;
    default:
        cout<<"no operator such like that"<<endl;
    }
 }

struct bstnode{
char data;
bstnode *left;
bstnode *right;
int num;
};

bstnode* insert(string expression){
int s = expression.size()-1;
stack<bstnode *> stacknode;
bstnode *root;
while(s>=0){
   if(expression[s] == '*'||expression[s]=='/'||expression[s] == '+'||expression[s]=='-'){
        bstnode *temp = new bstnode;
        temp->data = expression[s];
        temp->left = stacknode.top();
        stacknode.pop();
        temp->right = stacknode.top();
        stacknode.pop();
        root = temp;
        stacknode.push(root);
   }
   else{
    bstnode *temp = new bstnode;
    temp->num = expression[s]-'0';
    temp->left = NULL;
    temp->right= NULL;
    stacknode.push(temp);
   }
   s--;
}
   root = stacknode.top();
   stacknode.pop();
   return root;
}

void topreordertraversal(bstnode *r){
if(r==NULL)
    return;
if(r->data=='+'||r->data=='-'||r->data=='*'||r->data=='/'){
cout<<r->data<<"  ";}
else{
    cout<<r->num<<"   ";
}
topreordertraversal(r->left);
topreordertraversal(r->right);
}

int evaluate(bstnode *root){

   if(root->data=='+'||root->data=='-'||root->data=='*'||root->data=='/'){
//       cout<<cal(root->data,evaluate(root->left)-'0',evaluate(root->right)-'0');
    return cal(root->data,evaluate(root->left),evaluate(root->right));
   }
    else{
     //cout<<root->data<<endl;
     return root->num;

   }
}


int main()
{
    bstnode *root=insert("-+*23*549");
        bstnode *root1=insert("+*23*89");

   //topreordertraversal(root);
//    char a = '5';
//    char c='9';
//    char *d;
//    cout<<a+c;
   // int b = a - 48;
//    cout<<endl<<b<<endl;
//    cout<<evaluate(root);
//    cout<<endl;
//    cout<<cal('+','5'-'0','9'-'0');
    cout<<endl<<evaluate(root)<<endl;
    cout<<endl<<evaluate(root1)<<endl;
//cout<<cal('')
    return 0;
}
