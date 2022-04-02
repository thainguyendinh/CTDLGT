#include<iostream>
#include<string.h>
using namespace  std;
struct SinhVien{
    int ma;
    char ten[255];
};
struct NodeSinhVien{
    SinhVien *data;
    NodeSinhVien *pLeft;
    NodeSinhVien *pRight;
};
typedef NodeSinhVien * BTree;


struct LopHoc{
    int ma;
    char ten[255];
};
struct NodeLopHOc{
    LopHoc *data;
    NodeLopHOc *pNext;
    NodeLopHOc *pPrevious;
    BTree root;
};
struct DLINK{
    NodeLopHOc *pHead;
    NodeLopHOc *pTail;
};


NodeSinhVien* CreateNodeSinhVien(SinhVien *sv){
    NodeSinhVien *pNode=new NodeSinhVien;
    pNode->data=sv;
    pNode->pLeft=NULL;
    pNode->pRight=NULL;
    return pNode;
}
void Initialize(BTree &root){
    root=NULL;
}
void InserNodeSinhVien(BTree &root,SinhVien *sv){
    NodeSinhVien *pNode=CreateNodeSinhVien(sv);
    if(root==NULL)
        root=pNode;
    else{
        NodeSinhVien *pTmp=root;
        NodeSinhVien *parent=NULL;
        while(pTmp!=NULL){
            parent=pTmp;
            if(pTmp->data>pNode->data)
                pTmp=pTmp->pLeft;
            else if(pTmp->data<pNode->data){
                pTmp=pTmp->pRight;
            }
                
        }
        if(parent->data>pNode->data)
            parent->pLeft=pNode;
        else if(parent->data<pNode->data){
            parent->pRight=pNode;
        }
    }
}
void Inorder(BTree root){
    if(root!=NULL){
        Inorder(root->pLeft);
        cout<<root->data->ma<<"\t"<<root->data->ten<<"\n";
        Inorder(root->pRight);
    }
}

NodeLopHOc *CreateNodeLopHoc(LopHoc *lp,BTree x){
    NodeLopHOc *pNode=new NodeLopHOc;
    pNode->data=lp;
    pNode->pNext=NULL;
    pNode->pPrevious=NULL;
    //pNode->root=NULL;
    pNode->root=x;

    return pNode;
}
void InitializeDLINK(DLINK &link){
    link.pHead=link.pTail=NULL;
}
void InserNodeLopHoc(DLINK &link,LopHoc *lp,BTree root){
    NodeLopHOc *node=CreateNodeLopHoc(lp,root);
    if(link.pTail==NULL){
        link.pHead=link.pTail=node;
    }
    else{
        link.pTail->pNext=node;
        node->pPrevious=link.pTail;
        link.pTail=node;
    }
}
void PrintLopHoc(DLINK link){
    NodeLopHOc *pTmp=link.pHead;
    while(pTmp!=NULL){
        cout<<pTmp->data->ma<<"\t"<<pTmp->data->ten<<"\n";
        pTmp=pTmp->pNext;
    }
}
NodeLopHOc *SearchNodeLopHoc(DLINK link,int ml){
    NodeLopHOc *node=link.pHead;
    while(node!=NULL){
        if(node->data->ma==ml)
            break;
        node=node->pNext;
    }
    return node;
}
int main(){

  
    // DLINK link;
    // InitializeDLINK(link);

    // LopHoc *lop1=new LopHoc;
    // lop1->ma=1;
    // strcpy(lop1->ten,"CN20CLCA");
    // NodeLopHOc *node1=CreateNodeLopHoc(lop1);
    // InserNodeLopHoc(link,node1);

    // LopHoc *lop2=new LopHoc;
    // lop2->ma=2;
    // strcpy(lop2->ten,"CN20CLCB");
    // NodeLopHOc *node2=CreateNodeLopHoc(lop2);
    // InserNodeLopHoc(link,node2);

    // LopHoc *lop3=new LopHoc;
    // lop3->ma=3;
    // strcpy(lop3->ten,"CN20CLCC");
    // NodeLopHOc *node3=CreateNodeLopHoc(lop3);
    // InserNodeLopHoc(link,node3);
    //  cout<<"DANH SACH LOP HOC :\n";
    // PrintLopHoc(link);

    // BTree DSSV1;
    // Initialize(DSSV1);

    // SinhVien *sv1=new SinhVien;
    // sv1->ma=1;
    // strcpy(sv1->ten,"XXX");
    // InserNodeSinhVien(DSSV1,sv1);

    // SinhVien *sv2=new SinhVien;
    // sv2->ma=2;
    // strcpy(sv2->ten,"YYY");
    // InserNodeSinhVien(DSSV1,sv2);

    //  SinhVien *sv3=new SinhVien;
    // sv3->ma=3;
    // strcpy(sv3->ten,"ZZZ");
    // InserNodeSinhVien(DSSV1,sv3);

    // //node1->root=DSSV1;

    // BTree DSSV2;
    // Initialize(DSSV2);

    //  SinhVien *sv5=new SinhVien;
    // sv5->ma=3;
    // strcpy(sv5->ten,"III");
    // InserNodeSinhVien(DSSV2,sv5);
    // node2->root=DSSV2;

    DLINK link;
    InitializeDLINK(link);
    BTree DSSV1;
    Initialize(DSSV1);
    LopHoc *lop1=new LopHoc;
    lop1->ma=1;
    strcpy(lop1->ten,"CN20CLCA");

    SinhVien *sv1=new SinhVien;
    sv1->ma=1;
    strcpy(sv1->ten,"XXX");
    InserNodeSinhVien(DSSV1,sv1);
    InserNodeLopHoc(link,lop1,DSSV1);
    PrintLopHoc(link);
    cout<<"Nhap MA LOP MUON TIM: ";
    int r;
    cin>>r;
    NodeLopHOc *result=SearchNodeLopHoc(link,r);
    if(result==NULL){
        cout<<"KO THAY MA LOP TIM !";
    }
    else{
        cout<<"TIM THAY LOP\n ";
        Inorder(result->root);  
    }
    return 0;
}



