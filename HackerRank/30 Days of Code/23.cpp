#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;	
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }           
           return root;
           }
        }

    void printLevel(Node *root, int level){
        if(root == NULL) return;
        if(!level) {
            cout << " " << root -> data;
            return;
        }
        printLevel(root -> left, level - 1);
        printLevel(root -> right, level - 1);
    }

    int getHeight(Node *root){
        if(root == NULL) return -1;
        return max(getHeight(root -> left), getHeight(root -> right)) + 1;
    }

	void levelOrder(Node *root){
        if(root == NULL) return;
        int levels = getHeight(root);
        cout << root -> data;
        for(int i = 1 ; i <= levels ; ++i){
            printLevel(root, i);
        }
	}

};//End of Solution
int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);
    return 0;
}