#include<iostream>
#include<stdlib.h>//动态分配内存的头文件,使用malloc和free函数需要包含该头文件
#define initsize 10
typedef struct{
    int *data;
    int Maxsize;
    int length;
}sqlist;
void init_list(sqlist &L){
    L.data=(int *)malloc(initsize*sizeof(int));
    L.length=0;
    L.Maxsize=initsize;
}
void increaseSize(sqlist &L, int len){
    int *p=L.data;
    L.data=(int *)malloc((L.Maxsize+len)*sizeof(int));
    for(int i=0;i<L.length;i++){
        L.data[i]=p[i];
    }
    L.Maxsize+=len;
    free(p);
}
// typedef struct{
//     int data[Maxsize];
//     int length;
// }sqlist;
bool listinsert(sqlist &L,int i,int e){//后面元素依次后移
    if(i<1||i>L.length+1) return false;//判断i是否合理
    if(L.length>=L.Maxsize) return false;//判断表是否已满
    for(int j=L.length;j>=i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;//在L的位序i处插入元素e,插入时间复杂度为n
    L.length++;
    return true;
}
bool listDelete(sqlist &L,int i,int &e){//前面元素依次前移,引用符号是为了对应同一份数据也就是把值带回来
    if(i<1||i>L.length) 
        return false;//判断i是否合理
    e=L.data[i-1];//将被删除的元素赋值给e
    for(int j=i;j<L.length;j++){
        L.data[j-1]=L.data[j];
    }//删除位序i的元素，删除时间复杂度为n
    L.length--;
    return true;
}
void initsqlist(sqlist &L){//初始化静态顺序表
    L.length=0;
}
int getelem (sqlist L,int i){
    if(i<1||i>L.length) 
        return -1;//判断i是否合理
    else 
        return L.data[i-1];//获取元素e的值
}
int locatelem(sqlist L,int e){
    if(L.length==0) 
        return -1;//判断表是否为空
    for(int i=0;i<L.length;i++){
        if(L.data[i]==e)
         return i+1;
    }
    return -1;//查找元素e,返回其位序
}
int main(){
    sqlist L;
    init_list(L);
    increaseSize(L,5);
    int n=12;
    int e;
    int a;
    for(int i=1;i<=n;i++){
        listinsert(L,i,i*2);
    }
    std::cout<<L.length<<std::endl;
    std::cout<<"原表为："<<std::endl;
    for(int i=0;i<L.length;i++){
        std::cout<<L.data[i]<<" ";
    }
    if (listDelete(L,10,e)){
        std::cout<<"\n删除的元素为："<<e<<std::endl;
    }
    std::cout<<"删除后的表为："<<std::endl;
    for(int i=0;i<L.length;i++){
        std::cout<<L.data[i]<<" ";
    }
    a=getelem(L,6);
    std::cout<<"\n第6个元素为："<<a<<std::endl;
    a=locatelem(L,20);
    std::cout<<"\n元素20的位序为："<<a<<std::endl;
    return 0;
}