#include<iostream>
using namespace std;
struct node
{
    node*left;
    node*right;
    int data;
};
class bst
{
    public:
        node*root;
        void insert();
        int search(int);
        int height(node*);
        void inorder(node*);
        void Delete(node*,int);
        void maxkey(node*);
        void minkey(node*);

        bst()
        {
            root=NULL;
        }
};
void bst::insert()
{
    node*curr,*temp;
    curr=new node;
    cout<<"\nEnter the data to be inserted:";
    cin>>curr->data;
    curr->left=curr->right=NULL;
    if(root==NULL)
    {
        root=curr;
        cout<<"\nRoot is created";
    }
    else
    {
        temp=root;
        while(1)
        {
            if(curr->data<temp->data)
            {
                if(temp->left==NULL)
                {
                    temp->left=curr;
                    break;
                }
                else
                {
                    temp=temp->left;
                }
            }
            else
            {
                if(temp->right==NULL)
                {
                    temp->right=curr;
                    break;
                }
                else
                {
                    temp=temp->right;
                }
            }
        }
    }
}

int bst::search(int key)
{
    node*temp,*curr;
    temp=root;
    while(temp!=NULL)
    {
        if(key==temp->data)
        {
            return 1;
        }
        else if(key<temp->data)
        {
            temp=temp->left;
        }
        else
        {

            temp=temp->right;
        }
    }
    return 0;
}

int bst::height(node*root)
{
    int hl,hr;
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        hl=height(root->left)+1;
        hr=height(root->right)+1;
        if(hl>hr)
        {
            return hl;
        }
        else
        {
            return hr;
        }
    }
}
void bst::inorder(node*root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<"\t";
		inorder(root->right);
	}
}

void bst::minkey(node*root)
{
    node *temp;
    int mini=0;
    temp=root;
    if(temp!=NULL)
    {
        while(temp->left!=NULL)
        {
            temp=temp->left;
            mini=temp->data;
        }
    }
    cout<<"\nMINIMUM KEY:"<<mini;
}

void bst::maxkey(node*root)
{
    node *temp;
    int maxm=0;
    temp=root;
    if(temp!=NULL)
    {
        while(temp->right!=NULL)
        {
            temp=temp->right;
            maxm=temp->data;
        }
    }
    cout<<"\nMAXIMUM KEY:"<<maxm;
}

void bst::Delete(node*root,int key)
{
    node*temp,*parent,*curr;
    if(root==NULL)
    {
        cout<<"\nTREE IS NOT CREATED";
    }
    else
    {
        temp=root;
        search(&temp,)
    }
}








int main()
{
    int key,choice,n,k,m;
    bst b;
    char ch;
    do
    {
        cout<<"\nMENU\n1.INSERT IN TREE\n2.SEARCH IN TREE\n3.HEIGHT OF TREE\n4.INORDER TRAVERSAL\n5.MAXIMUM KEY\n6.MINIMUM KEY";
        cout<<"\nEnter your choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the number of nodes to be inserted";
            cin>>m;
            for(int i=0;i<m;i++)
            b.insert();
            break;
        case 2:
            cout<<"\nEnter the key to be searched:";
            cin>>key;
            k=b.search(key);
            if(k==1)
            {
                cout<<"\nKEY IS FOUND";
            }
            else
            {
                cout<<"\nKEY NOT FOUND";
            }
            break;
        case 3:
            n=b.height(b.root);
            cout<<"\nHEIGHT OF TREE:"<<n;
            break;
        case 4:
            cout<<"\nINORDER TRAVERSAL:";
            b.inorder(b.root);
            break;
        case 5:
            b.maxkey(b.root);
            break;

        case 6:
            b.minkey(b.root);
            break;
        }
        cout<<"\nDO YOU WANT TO CONTINUE?";
        cin>>ch;
    }while(ch=='y'|| ch=='Y');
return 0;
}
