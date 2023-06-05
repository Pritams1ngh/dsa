#include<iostream>
#include<string>
using namespace std;

class graph
{
	int arr[50][50];
	string arrc[50];
	int cityno;
	public:
	void acceptcity()
	{
		cout<<"\nEnter the number of cities: ";
		cin>>cityno;
		
		//accept city names
		cout<<"\nEnter the names of cities:- ";
		for(int i=0;i<cityno;i++)
			cin>>arrc[i];
	}
	
	void acceptflight()
	{
		cout<<"\n\nEnter the time taken by the flights for the following routes(Enter 0 if no flight present):- \n";
		for(int i=0;i<cityno;i++)
		{
			for(int j=0;j<cityno;j++)
			{
				cout<<arrc[i]<<" -> "<<arrc[j]<<": ";
				cin>>arr[i][j];
			}
		}
	}
	void disp_matrix()
	{
		cout<<"\n\nThe adjacency matrix is: \n";
		for(int i=0;i<cityno;i++)
		{
			for(int j=0;j<cityno;j++)
				cout<<arr[i][j]<<" ";
			cout<<endl;
		}
	}
	bool checkconnected()
	{
		for(int i=0;i<cityno;i++)
		{
			for(int j=0;j<cityno;j++)
			{
				if(i==j)
					continue;
				else if(arr[i][j]!=0)
					continue;
				else
					return false;
			}
		}
		return true;
	}
};

int main()
{
	graph G1;
	int ch;
	while(true)
	{
		cout<<"\n\n1. Enter flight time durations";
		cout<<"\n2. Display Adjacency Matrix";
		cout<<"\n3. Check whether cities are connected";
		cout<<"\n4. Exit";
		cout<<"\n\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			G1.acceptcity();
			G1.acceptflight();
			break;
			
			case 2:
			G1.disp_matrix();
			break;
			
			case 3:
			if(G1.checkconnected()==true)
				cout<<"\n\nCities are connected !\n";
			else
				cout<<"\n\nCities are not connected\n";
			break;
			
			case 4:
			cout<<"\n\nExiting Program !";
			exit(0);
			
			default:
			cout<<"\nInvalid choice !";
		}
	}
}
