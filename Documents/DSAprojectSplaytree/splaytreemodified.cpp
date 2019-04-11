#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
using namespace std;
void line(){
    cout<<"\n--------------------------------------------------------------------------------------------------------------------------------------------------";
}
struct hospital{
    string pname;
    char gender;
    long Inc_id;
    int age;
    long phone;
    string email;
};
struct splay
{
    int key;
    hospital val;
    splay* lchild;
    splay* rchild;
};
 
class SplayTree
{
    public:
        SplayTree()
        {
        }
 
        // RR(Y rotates to the right)
        splay* RR_Rotate(splay* k2)
        {
            splay* k1 = k2->lchild;
            k2->lchild = k1->rchild;
            k1->rchild = k2;
            return k1;
        }
 
        // LL(Y rotates to the left)
        splay* LL_Rotate(splay* k2)
        {
            splay* k1 = k2->rchild;
            k2->rchild = k1->lchild;
            k1->lchild = k2;
            return k1;
        }
 
        splay* Splay(int key, splay* root)
        {  
            // If root is null or it's present return as it is  
            if (root == NULL || root->key == key)  
                return root;  
        
             
            if (root->key > key) //key is present in left subtree 
            {  
                
                if (root->lchild == NULL) return root; //key is not present 
        
                
                if (root->lchild->key > key)  //left - left (Zig-Zig)
                {  
                    
                    root->lchild->lchild = Splay(key , root->lchild->lchild);  
        
                    // Do first rotation for root,  
                    // second rotation is done after else  
                    root = RR_Rotate(root);  
                }  
                else if (root->lchild->key < key) // Zig-Zag (Left Right)  
                {  
                    // First recursively bring  
                    // the key as root of left-right  
                    root->lchild->rchild = Splay(key , root->lchild->rchild);  
        
                    // Do first rotation for root->left  
                    if (root->lchild->rchild != NULL)  
                        root->lchild = LL_Rotate(root->lchild);  
                }  
        
                // Do second rotation for root  
                return (root->lchild == NULL)? root: RR_Rotate(root);  
            }  
            else // Key lies in right subtree  
            {  
                // Key is not in tree, we are done  
                if (root->rchild == NULL) return root;  
        
                // Zig-Zag (Right Left)  
                if (root->rchild->key > key)  
                {  
                    // Bring the key as root of right-left  
                    root->rchild->lchild = Splay(key , root->rchild->lchild);  
        
                    // Do first rotation for root->right  
                    if (root->rchild->lchild != NULL)  
                        root->rchild = RR_Rotate(root->rchild);  
                }  
                else if (root->rchild->key < key)// Zag-Zag (Right Right)  
                {  
                    // Bring the key as root of  
                    // right-right and do first rotation  
                    root->rchild->rchild = Splay(key , root->rchild->rchild);  
                    root = LL_Rotate(root);  
                }  
        
                // Do second rotation for root  
                return (root->rchild == NULL)? root: LL_Rotate(root);  
            }  
        }
 
        splay* New_Node(int key,hospital h)
        {
            splay* p_node = new splay;
            if (!p_node)
            {
                fprintf(stderr, "Out of memory!\n");
                exit(1);
            }
            p_node->key = key;
            p_node->val.pname = h.pname;
            p_node->val.age = h.age;
            p_node->val.phone = h.phone;
            p_node->val.email = h.email;
            p_node->val.gender = h.gender;
            p_node->val.Inc_id = h.Inc_id;
            p_node->lchild = p_node->rchild = NULL;
            return p_node;
        }
 
        splay* Insert(int key,hospital h, splay* root)
        {
            static splay* p_node = NULL;
            if (!p_node)
                p_node = New_Node(key,h);
            else
                p_node->key = key;
            if (!root)
            {
                root = p_node;
                p_node = NULL;
                return root;
            }
            root = Splay(key, root);
            /* This is BST that, all keys <= root->key is in root->lchild, all keys >
            root->key is in root->rchild. */
            if (key < root->key)
            {
                p_node->lchild = root->lchild;
                p_node->rchild = root;
                root->lchild = NULL;
                root = p_node;
            }
            else if (key > root->key)
            {
                p_node->rchild = root->rchild;
                p_node->lchild = root;
                root->rchild = NULL;
                root = p_node;
            }
            else
                return root;
            p_node = NULL;
            return root;
        }
 
        splay* Delete(int key, splay* root)
        {
            splay* temp;
            if (!root)
                return NULL;
            root = Splay(key, root);
            if (key != root->key){
                cout<<"\n"<<key<<" is not present in the tree";
                return root;
            }
            else
            {
                if (!root->lchild)
                {
                    temp = root;
                    root = root->rchild;
                }
                else
                {
                    temp = root;
                    /*Note: Since key == root->key,
                    so after Splay(key, root->lchild),
                    the tree we get will have no right child tree.*/
                    root = Splay(key, root->lchild);
                    root->rchild = temp->rchild;
                }
                free(temp);
                return root;
            }
        }
 
        splay* Search(int key, splay* root)
        {
            return Splay(key, root);
        }

        void InOrder(splay* root)
        {   
            if (root)
            {
                InOrder(root->lchild);
                cout<< "key: " <<root->key;
                if(root->lchild)
                    cout<< " | left child: "<< root->lchild->key<<"\n";
                if(root->rchild)
                    cout << " | right child: " << root->rchild->key<<"\n";
                cout<< "\n";
                InOrder(root->rchild);
            }
        }
        void PreOrder(splay *root){
            if(root){
                cout<<setw(15)<<root->key<<setw(15)<<root->val.pname<<setw(15)<<root->val.phone<<setw(15)<<root->val.email<<setw(15)<<root->val.gender<<setw(15)<<root->val.Inc_id;
                cout<<"\n";
                PreOrder(root->lchild);
                PreOrder(root->rchild);
            }
        }
};
 
int main()
{   
    cout<<"\n\n\n";
    line();
    line();
    line();
    cout<<"\n\t\t\tData Structures and Algorithm Project";
    cout<<"\t\t By Pranav Narayan 17BCE2213 , Lakshaya Sharma 17BCE0880 , Archak Dey 18BEC0648";
    cout<<"\n\n\n 1)SPLAY TREES IS A VERY COMMONLY USED DATASTRUCTURE IN A LOT OF PLACES INCLUDING SCHOOLS , EMERGENCY ROOMS , FIRE DEPARTMENTS AND POLICE CENTRES";
    cout<<"\n\n 2)SPLAY TREE'S ARE MADE IN SUCH A WAY THAT THE MOST RECENTLY SEARCHED ELEMENT WILL BE PRESENT AT THE ROOT OR NEAR IT, WHICH GIVES US QUICK ACCESS TO FREQUENTLY LOOKED UP ELEMENTS";
    cout<<"\n\n 3) FOR THIS DATA STRUCTURES PROJECT WE ARE GOING TO IMPLEMENT A HOSPITAL MANAGEMENT SYSTEM USING SPLAY TREES";
    line();
    cout<<"\nPress Any key to continue";
    getchar();
    system("clear");
    SplayTree st;
    splay *root;
    root = NULL;
    const int length = 10;
    int i;
    int choice;
    hospital h;
    while(1)
    {   

        cout<<"\n\t\t\tHOSPITAL MANAGEMENT SYSTEM\n\n\t\t\t\t\t\t\t-By VIT University";
        line();
        cout<<endl;

        cout<<"1. Insert Patient"<<endl;
        cout<<"2. Delete Patient"<<endl;
        cout<<"3. Search Patient"<<endl;
        cout<<"4. Display most recently Searched Patient"<<endl;
        cout<<"5. Display All patient details stored in the Database"<<endl;
        cout<<"6. Exit Program"<<endl;
        line();
        cout<<"\nEnter your choice: ";
        cin>>choice;
        cout<<"\n";
    
        int input;
        switch(choice)
        {
        case 1:
            system("clear");
            line();
            cout<<"\n\t\t\t\tPatient Details Input Page";
            line();
            cout<<"\nEnter Patient number to be inserted( Eg 4): ";
            cin>>input;
            cout<<"\nEnter Patient name( Eg John ):";
            cin>>h.pname;
            cout<<"\nEnter Patient Age( Eg 19 ):";
            cin>>h.age;
            cout<<"\nEnter Insurance ID( 6 digits ):";
            cin>>h.Inc_id;
            cout<<"\nEnter Patient Gender( M/F ):";
            cin>>h.gender;
            cout<<"\nEnter Patient Email( abc@xyz.com ):";
            cin>>h.email;
            cout<<"\nEnter Patient Phone No( 10 digits ):";
            cin>>h.phone;
            root = st.Insert(input,h,root);
            cout<<"\nAfter Insert: "<<input<<endl;
            st.InOrder(root);
            getchar();
            break;
        case 2:
            system("clear");
            line();
            cout<<"\n\t\t\t\tPatient Details removal Page";
            line();
            cout<<"\nEnter Patient to be deleted-:";
            cin>>input;
            root = st.Delete(input, root);
            cout<<"\nAfter Delete: "<<input<<endl;
            st.InOrder(root);
            getchar();
            break;
            
        case 3:
            system("clear");
            line();
            cout<<"\n\t\t\t\tPatient Detail search Page";
            line();
            cout<<"\nEnter Patient No to be searched: ";
            cin>>input;
            root = st.Search(input, root);
            if(root->key == input){
                cout<<"\nElement to be searched is found";
                cout<<"\nAfter Search "<<input<<endl;
                st.InOrder(root);
            }
            else{
                cout<<"Element Not found";
            }
            getchar();
            break;
 
        case 4:
            system("clear");
            cout<<"\nMost Recent Searched element: ";
            line();
            cout<<"\nKey:";
            cout<<root->key;
            cout<<"\nName:";
            cout<<root->val.pname;
            line();
            getchar();
            break;
        case 5:
            system("clear");
            cout<<setw(49)<<"PATIENT DETAILS\n";
            line();
            cout<<"\n";
            cout<<setw(15)<<"Patient No"<<setw(15)<<"Name"<<setw(15)<<"Phone"<<setw(15)<<"Email"<<setw(15)<<"Gender"<<setw(15)<<"Inc_id";
            line();
            cout<<"\n";
            st.PreOrder(root);
            getchar();
            break;
        case 6:
            exit(1);
            break;
        default:
            cout<<"\nInvalid type! \n";
        }
    }
    cout<<"\n";
    return 0;
}   