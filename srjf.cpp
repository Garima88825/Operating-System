#include <iostream>
using namespace std;
class sched
{
	public:
		int n,bt[10],at[10],tat[10],wt[10],rt[10],finish[10],twt,ttat,total;
		void readData();
		void computeSRT();
		void Init();
		void dispTime();
		int getNextProcess(int);
};

void sched::readData()
{
    cout<<"\nEnter no. of processes : ";
    cin>>n;
    cout<<"\nEnter the burst times in order : ";
    for(int i=0; i < n; i++)
    cin>>bt[i];
    cout<<"\nEnter the arrival times in order: ";
    for(int i=0; i < n; i++)
    cin>>at[i];
}

void sched::Init()
{
    total=0;
    twt=0;
    ttat=0;
    for(int i=0; i < n; i++)
	{
        rt[i]=bt[i];
        finish[i]=0;
        wt[i]=0;
        tat[i]=0;
        total+=bt[i];
	}
}

void sched::computeSRT()
{
    readData();
    Init();
    int time,next=0,old,i;
    //cout<<"Gantt Chart\n ";
    for(time=0; time < total; time++)
    {
        old=next;
        next=getNextProcess(time);
        if(old!=next || time==0)
		{
        	//cout<<"("<< time<<")|==P"<< next+1<<"==|";
        }
        rt[next]=rt[next]-1;
        if(rt[next]==0)
		{
			finish[next]=1;
		}

		for(i=0; i < n; i++)
            if(i!=next && finish[i]==0 && at[i]<=time)
                wt[i]++;
    }
    cout<<"("<< total<<")"<< endl;
    for(i=0; i < n; i++)
        if(!finish[i]) {cout<<"Scheduling failed, cannot continue\n"; return;}
    dispTime();
}

int sched::getNextProcess(int time)
{
        int i,low;
        for(i=0; i < n; i++)
            if(finish[i]==0){low=i; break; }
        for(i=0; i < n; i++)
            if(finish[i]!=1)
                if(rt[i] < rt[low] && at[i]<=time)
                        low=i;
        return low;

}

void sched::dispTime()
{
	cout<<"Process \t Burst Time \t Arrival time \t Avg Waiting Time \t Turnaround time \n";
    for(int i=0; i < n; i++)
    {
        twt+=wt[i];
        tat[i]=wt[i]+bt[i];
        ttat+=tat[i];
        cout<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<at[i]<<"\t\t  "<<wt[i]<<"\t\t\t"<<tat[i]<<endl;
        //cout<<"Waiting time for P"<<(i+1)<<" = "<< wt[i]<<", Turnaround time = "<< tat[i]<< endl;
    }
    cout<<endl;
    cout<<"Avg Waiting time = "<<(double)twt/n<<" and Avg Turnaround time = "<<(double)ttat/n<< endl;
    cout<<"Scheduling complete\n";
}

int main()
{
    sched s;
    s.computeSRT();
}
