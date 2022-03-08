#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
using namespace std;

int main()
{
	int i, j, k, n;
	time_t curtime;
	time(&curtime);
	cout<<ctime(&curtime);
	FILE* fp;
	
	srand((unsigned) time(NULL));
	cout<<"歡迎光臨長庚樂透彩購買機台\n請問您要買幾組樂透彩: ";
	cin>>n;
	cout<<"已為您購買的"<<n<<"組樂透彩組合輸出至 lotto.txt\n"; 
	int r[n][6]={0};
	for(i=0;i<n;i++)
	{
		for(j=0;j<5;j++)
		{
			r[i][j]=rand()%69+1;
			for(k=0;k<j;k++)
			{
				if(r[i][j]==r[i][k])
				j=j-1;
			}
			cout<<r[i][j]<<" ";	
		}
		r[i][5]=rand()%10+1;	
		cout<<r[i][5]<<"\n";
	}
	
	fp=fopen("lotto.txt","w+");
	fprintf(fp,"========= lotto649 =========\n= ");
	fprintf(fp,ctime(&curtime));
	fprintf(fp,"\n");
	for(i=0;i<5;i++)
	{
		fprintf(fp,"[");
		fprintf(fp,char(i));
		fprintf(fp,"]:");
		for(j=0;j<6;j++)
		{
			fprintf(fp," ");
			if(r[i][j]==0)
				fprintf(fp,"--");
			else
				fprintf(fp,r[i][j]);
		}
		fprintf(fp,"\n");
	}
	
	fprintf(fp,"========= csie@CGU =========\n");
	fclose(fp);
	
	return 0;
}
