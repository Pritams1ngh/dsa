#include<iostream>
using namespace std;

class Heap
{
    int n;
    int *minheap,*maxheap;
    public:
    void get();
    void displayMin(){cout<<"Minimum number is:"<<maxheap[0]<<endl;}
    void displayMax(){cout<<"Maximum number is :"<<minheap[0]<<endl;}
    void upAdjust(bool,int);
};

void Heap::get()
{
    cout<<"Enter the number of entries you want :\n"<<endl;
    cin>>n;
    int k;
    minheap=new int[n];
    maxheap=new int[n];
    cout<<"Enter number"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>k;
        minheap[i]=k;
        upAdjust(0,i);
        maxheap[i]=k;
        upAdjust(1,i);
    }
}

void Heap::upAdjust(bool m,int l)
{
    int s;
    if(!m)
    {
        while(minheap[(l-1)/2]<minheap[l])
        {
            s=minheap[l];
            minheap[l]=minheap[(l-1)/2];
            minheap[(l-1)/2]=s;
            l=(l-1)/2;
            if(l==-1)
            break;
        }
    }
    else
    {
        while(maxheap[(l-1)/2]>maxheap[l])
        {
            s=maxheap[l];
            maxheap[l]=maxheap[(l-1)/2];
            maxheap[(l-1)/2]=s;
            l=(l-1)/2;
            if(l==-1)
            break;
        }
    }
}

int main()
{
    int choice;
    cout<<"1.MIN HEAP\n";
    cout<<"2.MAX HEAP\n";
    cout<<"Enter your choice:\n";
    cin>>choice;
    Heap H;
    switch(choice)
    {
        case 1:
        H.get();
        H.displayMin();
        break;
        
        case 2:
        H.get();
        H.displayMax();
        break;
    }
    return(0);
}