#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    int at[10],cpuT[20],n,i,j,temp,p[10],st[10],ft[10],wt[10],ta[10];
    int totwt=0,totta=0;
    float awt,ata;
    char pn[10][10],t[10];

    printf("Enter the number of process:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter Process name, Arrivaltime, CPU time & Priority:\n");

        scanf("%s%d%d%d",pn[i],&at[i],&cpuT[i],&p[i]);
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(p[i]<p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;

                temp=at[i];
                at[i]=at[j];
                at[j]=temp;

                temp=cpuT[i];
                cpuT[i]=cpuT[j];
                cpuT[j]=temp;

                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)

    {

        if(i==0)
        {
            st[i]=at[i];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+cpuT[i];
            ta[i]=ft[i]-at[i];
        }
        else
        {
            st[i]=ft[i-1];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+cpuT[i];
            ta[i]=ft[i]-at[i];
        }
        totwt+=wt[i];
        totta+=ta[i];
    }
    awt=(float)totwt/n;
    ata=(float)totta/n;
    printf("\nPname\tArrivaltime\tCPUtime\tPriority\tWaitingtime\tTatime");
    for(i=0; i<n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],at[i],cpuT[i],p[i],wt[i],ta[i]);
    printf("\nAverage Waiting Time is:%f",awt);
    printf("\nAverage Turnaroundtime is:%f",ata);
    getch();
}
