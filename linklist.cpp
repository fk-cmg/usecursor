//单链表优点在于方便拓展容量和插入改变数据简单，缺点是查找和删除需要遍历链表，时间复杂度为n，不支持随机存取
#include<iostream>
#include<stdlib.h>//动态分配内存的头文件,使用malloc和free函数
struct Lnode{
    int data;
    struct Lnode *next;
};//Lnode,*linklist;//链表结点结构体定义，Lnode为结构体类型，Linklist等价于Lnode*
typedef struct Lnode Lnode,*Linklist;//Linklist等价于Lnode*，linklist强调是链表类型，lnode*强调是结点类型
bool initlist(Linklist &L){ 
 L=NULL;//初始化链表，创建一个空链表,不带头节点
 return true;
}
void test(){
    Linklist L;
    initlist(L);
}
bool initlist_head(Linklist &L){//带头节点的链表初始化
    L=(Lnode *)malloc(sizeof(Lnode));//创建头结点
    if(L==NULL)
         return false;//内存不足，分配失败
    L->next=NULL;//头结点指针域置为空
    return true;
}
bool listinsert_head(Linklist &L,int i, int e){
  if (i<1)
        return false;//i无效
 Lnode *p=L;
 int j=0;
 while(p!=NULL&&j<i-1){//寻找第i-1个结点,在找到之前P一直往后移
     p=p->next;
     j++;
 }
 if(p==NULL)
       return false;//插入位置不合理
 Lnode *s=(Lnode *)malloc(sizeof(Lnode));//创建新结点
 s->data=e;
 s->next=p->next;
 p->next=s;
 return true;
}//单链表后插法插入元素，这是带头结点的


bool listinsert_nohead(Linklist &L,int i,int e){
    if (i<1)
        return false;
    if (i==1){
        Lnode *s=(Lnode *)malloc(sizeof(Lnode));
        s->data=e;
        s->next=L;
        L=s;
        return true;
    }
    Lnode *p=L;
    int j=1;
    if(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(p==NULL)
        return false;
    Lnode *s=(Lnode *)malloc(sizeof(Lnode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}//单链表后插法插入元素，这是不带头结点的
bool insertpriornode(Lnode *p,int e){
    if(p==NULL)
        return false;//p结点不存在
    Lnode *s=(Lnode *)malloc(sizeof(Lnode));
    s->data=p->data;//将p结点的数据域赋值给新结点
    s->next=p->next;//将p结点的指针域赋值给新结点
    p->next=s;//将新结点插入到p结点之后
    p->data=e;//将e的值赋值给p结点的数据域
    return true;
}//节点前插操作，相较于向前遍历，此种方法的时间复杂度为O(1)
bool listdelete_head(Lnode *L,int i,int &e){
 if(L->next==NULL)
     return false;//空表无法删除
 int j=0;
 Lnode *p=L;
 if(p->next!=NULL&&j<i-1){//寻找第i-1个结点
     p=p->next;
     j++;
 }
 if(p==NULL)
     return false;//i的值不合法
 if(p->next==NULL)
     return false;//删除位置不合理,表明p是最后一个结点
     Lnode *q=p->next;
     e=q->data;
     p->next=q->next;
     free(q);  
 return true;
}//最坏时间复杂度为O(n)，最好时间复杂度为O(1)，带头结点的单链表删除第i个结点
Lnode *getelem(Linklist L,int i){
 if(i<0)
  return NULL;
  Lnode *p=L;
  int j=0;
  while(p!=NULL&&j<i){
      p=p->next;
      j++;
  }
  return p;
}//获取单链表第i个结点的地址，带头结点的单链表，第0个结点为头结点，平均时间复杂度为O(n)
Lnode *locate(Linklist L,int e){
    Lnode *P=L->next;
    while(P!=NULL&&P->data!=e)
        P=P->next;
    return P;
}
// 尾插法实现单链表有两种方式，首先是遍历然后建立这种方法时间复杂度为O(n)，第二种是不遍历直接建立这种方法时间复杂度为O(n^2),另一个就是建立一个尾指针
 bool list_Tailnsert(Linklist &L){
    int x;
    L = (Lnode *)malloc(sizeof(Lnode));//创建头结点
    Lnode *s,*tail=L;
    std::cin>>x;
    while(x!=9999){
        s = (Lnode *)malloc(sizeof(Lnode));
        s->data=x;
        tail->next=s;
        tail=s;
        std::cin>>x;
    }
    tail->next=NULL;
    return true;
 }//尾插法建立单链表，带头结点，时间复杂度为O(n)
 bool list_headinsert(Linklist &L){
    Lnode *s;
    int x;
    L=NULL;
    std::cin>>x;
    while(x!=9999){
        s = (Lnode *)malloc(sizeof(Lnode));
         if(s == NULL) return false; 
        s->data=x;
        s->next=L;
        L=s;
        std::cin>>x;
    }
    return true;
 }//头插法建立单链表，不带头结点，时间复杂度为O(n)
 //双链表的初始化
 typedef struct dnode{
    int data;
    struct dnode *prior,*next;
}dnode,*dlinklist;
 bool initdlinklist(dlinklist &L){
    L = (dnode *)malloc(sizeof(dnode));//创建头结点
    if(L==NULL)
        return false;
    L->prior=NULL;
    L->next=NULL;//除了往后指还要往前指
    return true;
}
void testdlinklist(){
    dlinklist L;
    initdlinklist(L);
}
//双链表的后插操作
bool insertdlinklist(dlinklist &p,dnode *s){
    if (p==NULL||s ==NULL)
        return false;
     s->next=p->next;
    if(p->next!=NULL){
        p->next->prior=s;
    }
    s->prior=p; 
    p->next=s;
    return true;
}
//双链表实现按位存取
dnode *getelem_d(dlinklist L,int i){
 if(i<0)
  return NULL;
  dnode *p=L;
  int j=0;
  while(p!=NULL&&j<i){
      p=p->next;
      j++;
  }
  return p;
}
//循环链表就是在创建的时候让L->next=L,这样最后一个结点的next就指向头节点，形成一个闭环
//静态链表分配一整片空间，不同的是它有个游标用于表示下一个空闲位置，这样增加或者删除元素比较简单了
#define MAXSIZE 100
struct node{
    int data;
    int next; //游标，指向下一个空闲位置
}slinklist[MAXSIZE];
