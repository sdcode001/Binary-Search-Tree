#include<bits/stdc++.h>
using namespace std;
class Node{   //public calss.it can be usable without making friend.
public:
  int val;
  Node* left;
  Node* right;
};

class Binary_Search_Tree{

Node* t=NULL;
Node* m=NULL;
Node* r=NULL;
public:
  Node* Root=NULL;

  Binary_Search_Tree(int arr[],int n){    //creating binary search tree.
    Root=new Node;
    m=Root;
    m->val=arr[0];
    m->left=NULL;
    m->right=NULL;
    for(int i=1;i<n;i++){
      m=Root;
      while(m!=NULL){
        r=m;
        if(arr[i]< m->val){m=m->left;}
        else{m=m->right;}
      }
      t=new Node;
      t->val=arr[i];
      t->left=NULL;
      t->right=NULL;
      if(arr[i]<r->val){r->left=t;}
      else{r->right=t;}
       }
    }

 Node* Bsearch(Node* m,int key){   //binary search function(using recursion) takes root node and key value and if find the key val then return the node address of that node
   if(m==NULL){return NULL;}
   else{
     if(m->val==key){return m;}
     else if(key<m->val){return Bsearch(m->left,key);}
     else{return Bsearch(m->right,key);}
      }
   }

 Node* Iterative_Bsearch(Node* m,int key){
     while(m!=NULL){
       if(key==m->val){return m;}
       else if(key<m->val){m=m->left;}
       else{m=m->right;}
     }
     return NULL;
 }

 void inorder_treversal(Node* ptr){
   if(ptr!=NULL){
   inorder_treversal(ptr->left);
   cout<<ptr->val<<" ";
   inorder_treversal(ptr->right);}
 }

void Binsert(Node* m,int key){
  Node* p=NULL;
  Node* c=NULL;
  while(true){
    if(m==NULL){p=new Node; p->val=key; p->left=NULL; p->right=NULL;
                 if(key< c->val){c->left=p;}
                 else{c->right=p;}
                 break;}

    if(key==m->val){
      m=m->right;
      c=m;
      if(m->left==NULL){p=new Node; p->val=key; p->left=NULL; p->right=NULL; c->left=p; break;}
    }
    else if(key< m->val){c=m; m=m->left;}
    else{c=m; m=m->right;}
    }
  }

void Recursive_Binsert(Node* m, int key, Node* c){    //c will be initially Root and it points to that parent node whose left/right node will be key node.

  if(m==NULL){
    Node* p=new Node;
    p->val=key;
    p->left=NULL;
    p->right=NULL;
    if(key< c->val){c->left=p;}
    else{c->right=p;}
  }
  else{
    if(key==m->val){
    m=m->right;
    c=m;
    if(m->left==NULL){Node* p=new Node; p->val=key; p->left=NULL; p->right=NULL; c->left=p; return;}}
    else if(key<m->val){Recursive_Binsert(m->left,key,m);}
    else{Recursive_Binsert(m->right,key,m);}
  }
}


void Binary_delete(Node* m, int key, Node* p, int i=0){      //p will initially Root but it points to parent node of the node which has to be deleted.
  if(m!=NULL){                                                    //i indicates to left or right node of p (for left=-1,for right=1)
     if(key==m->val){
       if(m->left==NULL && m->right==NULL){if(i==-1){p->left=NULL; delete m;}   //when target node is leaf node.
                                           else if(i==1){p->right=NULL; delete m;}
                                           else{delete m;}}
       else if((m->left==NULL && m->right!=NULL)||(m->left!=NULL && m->right==NULL)){  //when target node is a one degree node.
              if(i==1){
                if(m->left!=NULL){p->right=m->left; delete m;}
                else{p->right=m->right; delete m;}
              }
              else{
                if(m->left!=NULL){p->left=m->left; delete m;}
                else{p->left=m->right; delete m;}
              }
       }
       else{                          //when target node is a two degree node.

         //has to be done.

       }
     }
     else if(key<m->val){Binary_delete(m->left,key,m,-1);}
     else{Binary_delete(m->right,key,m,1);}
  }
}


};


int main(){
 int list[9]={9,15,5,20,16,8,12,3,6};
 Binary_Search_Tree bst(list,9);
 bst.Recursive_Binsert(bst.Root,100,bst.Root);

bst.Binary_delete(bst.Root,100,bst.Root);
bst.Binary_delete(bst.Root,8,bst.Root);
//bst.Binary_delete(bst.Root,15,bst.Root);
bst.inorder_treversal(bst.Root);
  return 0;
}
