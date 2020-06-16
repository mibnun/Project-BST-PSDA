//Muhammad Ibnun Arrosyid 1910512017 Kelas A
//UAS PSDA
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *kiri;
    Node *kanan;
};

Node *pohon = NULL;

void tambah (Node **root, int databaru)
{
       
    if ((*root)==NULL)
       {
        Node *baru;
        baru = new Node;
        baru->data=databaru;
        baru->kiri=NULL;
        baru->kanan=NULL;
        (*root) = baru;
        (*root) -> kiri = NULL;
        (*root) -> kanan = NULL;
        cout << "Data Ditambahkan!";
       }
    else if (databaru<(*root)->data)
              tambah(&(*root)->kiri,databaru);
    else if (databaru>(*root)->data)
        tambah(&(*root)->kanan,databaru);
    else if (databaru==(*root)->data)
        cout << "Data Sudah ada!";
}

//kode/script untuk mencetak tree secara preOrder
void preOrder(Node *root)
{
    if(root!=NULL)
    {
        if(root->data!=NULL)
        {
            printf("%d ",root->data);
        }
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}

//kode/script untuk mencetak tree secara inOrder
void inOrder(Node *root)
{
       if(root!=NULL)
       {
           inOrder(root->kiri);
           if(root->data!=NULL)
           {
               printf("%d ",root->data);
           }
           inOrder(root->kanan);
        }
}

//kode/script untuk mencetak tree secara postOrder
void postOrder(Node *root)
{
       if(root!=NULL)
       {
         postOrder(root->kiri);
         postOrder(root->kanan);
         if(root->data!=NULL)
         {
            printf("%d ",root->data);
         }
       }
}

//kode/script untuk melakukan pencarian data
void search(Node **root, int cari)
{
    if((*root) == NULL)
    {
        cout << "DATA TIDAK DITEMUKAN!";
    }
    else if(cari < (*root)->data)
        search(&(*root)->kiri,cari);
    else if(cari > (*root)->data)
        search(&(*root)->kanan,cari);
    else if(cari == (*root)->data)
        cout << "DATA DITEMUKAN!";
}

//kode/script untuk mengetahui ketinggian/kedalaman
int height(Node *root)
{
       if(root == NULL)
              return -1;
       else{
              int u = height(root->kiri);
        int v = height(root->kanan);
        if(u > v)
          return u + 1;
        else
          return v + 1;
       }
}


//kode/script untuk menghapus suatu node
void hapus(Node **root, int del)
{
       Node *curr;
       Node *parent;
       Node *temp;
       curr = (*root);

       bool flag = false;
  
       while(curr != NULL)
       {
              if(curr->data == del)
              {
                     flag = true;
                     //cout<<"DATA DITEMUKAN!";
                      break;
              }
              else
              {
                  parent = curr;
                  if(del>curr->data)
                     curr = curr->kanan;
                  else
                     curr = curr->kiri;
              }
       }

    if(!flag)
    {
        cout<<"Data tidak ditemukan!. Penghapusan dibatalkan."<<endl;
        return;
    }

       if(height(pohon) == 0)
       {
              if( curr->kiri== NULL && curr->kanan == NULL)
              {
                     (*root) = NULL;
                    
                     return;
              }
       }
       else if(height(pohon) > 0)
       {
              if( curr->kiri== NULL && curr->kanan == NULL)
              {
                     if(parent->kiri == curr)
                     {
                           parent->kiri = NULL;
                           delete curr;
                     }
                     else 
                     {
                           parent->kanan = NULL;
                           delete curr;
                     }

                     return;
              }

              if((curr->kiri == NULL && curr->kanan != NULL)|| (curr->kiri != NULL && curr->kanan == NULL))
              {
                     if(curr->kiri == NULL && curr->kanan != NULL)
                     {
                           if(parent->kiri == curr)
                           {
                              parent->kiri = curr->kanan;
                              delete curr;
                              curr=NULL;
                         }
                         else if(parent->kanan == curr)
                         {
                              parent->kanan = curr->kanan; 
                              delete curr;
                              curr=NULL;
                         }else
						 {
							  temp=*root;						 	
                         	  (*root)=(*root)->kanan;
                         	  delete temp;
                         	  temp=NULL;

						 }
                     }
                  else 
                  {
                           if(parent->kiri == curr)
                           {
                                  parent->kiri = curr->kiri; 
                                  delete curr;
                                  curr=NULL;
                           }
                           else if(parent->kanan == curr) 
                           {
                               parent->kanan = curr->kiri; 
                               delete curr;
                               curr=NULL;
                            }else{
							  temp=*root;						 	
                         	  (*root)=(*root)->kiri;
                         	  delete temp;
                         	  temp=NULL;                         	
							}
                   }
                   return;
              }


              
              if (curr->kiri != NULL && curr->kanan != NULL)
              {
                     Node* bantu;
                     bantu = curr->kanan;

                     if((bantu->kiri == NULL) && (bantu->kanan == NULL))
                     {
                           
                           curr = bantu;
                           delete bantu;
                           curr->kanan = NULL;
                     }
                     else 
                     {
                        
                           if(curr->kanan->kiri != NULL)
                           {
                                  
                                  Node* bantu2;
                                  Node* bantu3; 
                                  bantu3 = curr->kanan;         
                                  bantu2 = curr->kanan->kiri; 
                                  while(bantu2->kiri != NULL)
                                  {
                                         bantu3 = bantu2;
                                         bantu2 = bantu2->kiri;
                                  }
                                  curr->data = bantu2->data;
                                  delete bantu2;
                                  bantu3->kiri = NULL;
                        }
                        else 
                        {
                              Node* tmp;
                              tmp = curr->kanan;
                              curr->data = tmp->data;
                              curr->kanan = tmp->kanan;
                              delete tmp;
                              tmp=NULL;
                        }

                     }
                     return;
              }
       }
}

int findMax(){
	Node* curr = pohon;
	while(curr->kanan!=NULL){
		curr=curr->kanan;
	}
	return curr->data;
}

int findMin(){
	Node* curr = pohon;
	while(curr->kiri!=NULL){
		curr=curr->kiri;
	}
	return curr->data;
}
int main()
{
    char pil;
    int del,cari;
    while (true)
    {
        system("cls"); 
        int data;
        cout << "BINARY SEARCH TREE";
        cout << "\n";
        cout << "\n\tMENU";
        cout << "\n\n";
        cout << "1. Insert Data\n";
        cout << "2. Pre-Order Traversal\n";
        cout << "3. In-Order Traversal\n";
        cout << "4. Post-Order Traversal\n";
        cout << "5. Hapus Data\n";
        cout << "6. Reset BST\n";
        cout << "7. Search Data\n";
        cout << "8. Search Bilangan Terbesar\n";
        cout << "9. Search Bilangan Terkecil\n";
        cout << "E. Keluar/Exit\n";
        cout << "Pilih MENU : ";
        scanf("%c",&pil);
        fflush(stdin); 
        switch(pil)
        {
            //jika memilih '1'
            case '1':
                     cout << "\nINSERT DATA : ";
                     cout << "\n-------";
                     cout << "\nMasukkan data: ";
                     scanf("%d", &data);
                     tambah(&pohon,data);
                     _getch();
                      break;

             //jika memilih '2'
              case '2':
                     cout << "\nOUTPUT PRE-ORDER : ";
                     cout << "\n------------------\n";
                     if(pohon!=NULL)
                           preOrder(pohon);
                     else
                           cout << "BST Kosong!";
                    
                     _getch();
                     break;
                    
              //jika memilih '3'
              case '3':
                     cout << "\nOUTPUT IN-ORDER : ";
                     cout << "\n------------------\n";
                     if(pohon!=NULL)
                           inOrder(pohon);
                     else
                           cout << "BST Kosong!";
                    
                     _getch();
                     break;

             //jika memilih '4'
              case '4':
                     cout << "\nOUTPUT POST-ORDER : ";
                     cout << "\n------------------\n";
                     if(pohon!=NULL)
                           postOrder(pohon);
                     else
                           cout << "BST Kosong!";

                     _getch();
                     break;
                  
              //jika memilih '5'
              case '5':
                     if(pohon!=NULL)
                     {
                           cout << "\nNODE SEBELUM DIHAPUS : ";
                           cout << "\n---------------------- ";
                           cout << "\nPRE-ORDER  : ";
                           preOrder(pohon); //panggil fungsi
                           cout << "\nIN-ORDER   : ";
                           inOrder(pohon); //panggil fungsi
                           printf("\nPOST-ORDER : ");
                           postOrder(pohon); //panggil fungsi
                           cout << "\n\nMENGHAPUS DATA TREE : ";
                           cout << "\n------------------\n";
                           cout << "Insert data yang ingin dihapus: ";
                           scanf("%d", &del);
                        
                           hapus(&pohon, del);
                           cout << "\n\nNODE SETELAH DIHAPUS : ";
                           cout << "\n---------------------- ";
                           cout << "\nPRE-ORDER  : ";
                           preOrder(pohon); //panggil fungsi
                           cout << "\nIN-ORDER   : ";
                           inOrder(pohon); //panggil fungsi
                           cout << "\nPOST-ORDER : ";
                           postOrder(pohon); //panggil fungsi
                     }
                     else
                           cout << "\nBST kosong!";

                     _getch();
                     break;

             //jika memilih '6'
              case '6':
                     pohon=NULL;
                     cout << "\nRESET BST ";
                     cout << "\n------------------";
                     cout << "\nBST sudah direset!";
                      
                     _getch();
                     break;

              //jika memilih '7'
              case '7':
                     cout << "\nOUTPUT ->";
                     cout << "\n------";
                     if(pohon!=NULL)
                     {
                           cout << "\nPRE-ORDER  : ";
                           preOrder(pohon); //panggil fungsi
                           cout << "\nIN-ORDER   : ";
                           inOrder(pohon); //panggil fungsi
                           cout << "\nPOST-ORDER : ";
                           postOrder(pohon); //panggil fungsi
                           cout << "\n\nSEARCH DATA";
                           cout << "\n--------------";
                           cout << "\nInsert data yang ingin dicari : ";
                           scanf("%d", &cari);
                           search(&pohon, cari);
                     }
                     else
                           cout << "\nBST kosong!";

                     _getch();
                     break;
              case '8':
              		cout << "\nBilangan terbesar dalam Tree :"<<findMax();
              		_getch();
              		break;
              case '9':
              		cout << "\nBilangan terkecil dalam Tree :"<<findMin(); 
					_getch(); 
					break;           	
              case 'E'|'e':
                     exit(0);
                     break;
              }
       }
}
