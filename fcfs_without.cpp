#include<iostream>
using namespace std;
int main()
{
	cout<<"\n\t----------FIRST COME FIRST SERVE SCHEDULING-----------\n";
	int n;
	float sum_t=0,sum_w=0;
	cout<<"Enter No. Of Processes :";//n = no. of processes
	cin>>n;
	int Btime[n],Wtime[n],Ttime[n];
	cout<<"\n Enter Burst Time for Each Process:\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\nBURST TIME OF PROCESS P["<<i+1<<"]: ";
		cin>>Btime[i];
		while(Btime[i]<0)
			{
				cout<<"\n Negative time is allowed\n";
				cout<<"\nRE-ENTER BURST TIME OF PROCESS P["<<i+1<<"]:";
				cin>>Btime[i];
			}
	}
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			Wtime[i]=0;
		}
		else
		{
			Wtime[i]=Wtime[i-1]+Btime[i-1];
		}
		Ttime[i]=Wtime[i]+Btime[i];
	}
	cout<<"SOLUTION:\n\n";
	cout<<"--------------------------------------------\n";
	cout<<"PROCESS\tBT\tTAT\tWT\t";
	cout<<"\n--------------------------------------------\n";
	for(int i=0;i<n;i++)
	{
		cout<<"  P"<<i+1<<"\t"<<Btime[i]<<"\t"<<Ttime[i]<<"\t"<<Wtime[i]<<"\t";
		sum_w+=Wtime[i];
		sum_t+=Ttime[i];
		cout<<endl;
	}
	cout<<"\n Average Waiting Time=\t"<<sum_w/n;
	cout<<"\n Average Turnaround Time=\t"<<sum_t/n;
	return 0;
}
