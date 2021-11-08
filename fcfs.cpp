#include <iostream>
using namespace std;
class ps
{
public:
int art;
int bt;
int wt;
int ta;

ps()
{
art=bt=wt=ta=0;
}
};

int main()
{
float wta=0,taa=0;int n;
ps tmp;
cout<<"\nEnter the Number of Processes=";
cin>>n;
ps *p=new ps[n];
for(int i=1;i<=n;i++)
{
cout<<"\nEnter the arrival Time for Process "<< i <<"=";
cin>>p[i-1].art;
cout<<"\nEnter the Burst Time for Process "<< i <<"=";
cin>>p[i-1].bt;
}

for(int i=0; i < n; i++)
{
for(int j=i+1; j < n; j++)
if(p[i].art<=p[j].art)
{
p[j].wt=p[i].art+p[i].wt+p[i].bt-p[j].art;
if(p[j].wt < 0)
p[j].wt=0;
}
else
{
tmp=p[i];
p[i]=p[j];
p[j]=tmp;
}
p[i].ta=p[i].bt+p[i].wt;
}
cout<<"PROCESS\t\tAT\tBT\tTAT\tWT\t";
cout<<"\n--------------------------------------------\n";
for(int i=0; i < n; i++)
{
wta+=p[i].wt;
taa+=p[i].ta;
cout<<"  P"<<i+1<<"\t\t"<<p[i].art<<"\t"<<p[i].bt<<"\t"<<taa<<"\t"<<wta<<"\n";
//cout<<"\nThe Waiting Time for Process "<< i+1<<"="<< p[i].wt;
//cout<<"\nThe Turnaround Time for Process "<< i+1<<"="<< p[i].ta;
}
cout<<"\n\nAverage Waiting Time="<< wta/(float)n;
cout<<"\nAverage Turnaround Time="<< taa/(float)n;
return 0;
}

