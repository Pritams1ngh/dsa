#include<iostream>
#include<string>
using namespace std;
class teleline
{
    public:
    int arr[50][50];
    int jio[50][50],airtel[50][50],vi[50][50];
    string arrc[50];
    int citycount=0;
    string comp[3]={"Jio","Airtel","Vodafone-Idea"};
    int cityno;

    void acceptoffices()
    {
        cout<<"\nEnter the number of offices: ";
        cin>>cityno;
        //accept city names
        cout<<"\nEnter the names of cities:- ";
        for(int i=0;i<cityno;i++)
        cin>>arrc[i];
    }

    void acceptcost(int arrr[][50])
    {
        cout<<"\n\nEnter the cost of connection:-(Enter 0 for same office city)\n";
        cout<<"Costing for "<<comp[citycount];
        for(int i=0;i<cityno;i++)
        {
            for(int j=0;j<cityno;j++)
            {
                cout<<arrc[i]<<" -> "<<arrc[j]<<": ";
                cin>>arrr[i][j];
            }
        }
        citycount++;
    }

    void disp_matrix()
    {
        cout<<"\n\nThe resulatant matrix is: \n";
        for(int i=0;i<cityno;i++)
        {
            for(int j=0;j<cityno;j++)
            cout<<arr[i][j]<<" ";
            cout<<endl;
        }
    }

    void comparecost(int oper[][50])
    {
        // for(int z=0;z<cityno-1;z++)
        // {
        for(int i=0;i<cityno;i++)
        for(int j=0;j<cityno;j++)
        if(oper[i][j]<arr[j][j])
        arr[i][j]=oper[i][j];
        // }
    }
};

int main()
{
    teleline G1;
    int ch;
    while(true)
    {
        cout<<"\n\n1. Enter Office data";
        cout<<"\n2. Display Resultant Matrix";
        cout<<"\n3. Compare and find minimum cost";
        cout<<"\n4. Exit";
        cout<<"\n\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            G1.acceptoffices();
            G1.acceptcost(G1.jio);
            G1.acceptcost(G1.airtel);
            G1.acceptcost(G1.vi);
            break;

            case 2:
            G1.disp_matrix();
            break;

            case 3:
            G1.comparecost(G1.jio);
            G1.comparecost(G1.airtel);
            G1.comparecost(G1.vi);
            cout<<"\nComparison complete !\n";
            break;

            case 4:
            cout<<"\n\nExiting Program !";
            exit(0);
        
            default:
            cout<<"\nInvalid choice !";
        }
    }
}