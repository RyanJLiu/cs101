#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a-*(int *)b;
}

int main()
{
	int i, j, k, n;
	int num=1;
	int id;
	char name[17]="lotto[00001].txt";
	time_t curtime;
	time(&curtime);
	printf("%s",ctime(&curtime));
	FILE* fp;
	FILE* idf; 
	while((fp = fopen(name,"r"))!=NULL)
	{
		num=num+1;
		snprintf(name, 17, "lotto[%d%d%d%d%d].txt", num/10000, (num%10000)/1000, (num%1000)/100, (num%100)/10, num%10);
		fclose(fp);
	}
	fclose(fp);
	
	srand((unsigned) time(NULL));
	printf("%s","歡迎光臨長庚樂透彩購買機台\n請輸入操作人員ID:(0~5):");
	scanf("%d",&id);
	printf("%s","請問您要買幾組樂透彩: ");
	scanf("%d",&n);
	idf=fopen("operator_id.bin", "wb+");
	fprintf(idf, "%d", id);
	fclose(idf);
	idf=fopen("count.bin", "wb+");
	fprintf(idf, "%d", num);
	fclose(idf);
	int r[5][7]={0};
	for(i=0;i<5;i++)
	{
		if(i<n)
		{
			for(j=0;j<6;j++)
			{
				r[i][j]=rand()%69+1;
				for(k=0;k<j;k++)
				{
					if(r[i][j]==r[i][k])
						j=j-1;
				}
			}
			qsort(r[i],6,sizeof(int),cmp);
			r[i][6]=0;
			while(r[i][6]==0||r[i][6]==r[i][0]||r[i][6]==r[i][1]||r[i][6]==r[i][2]||r[i][6]==r[i][3]||r[i][6]==r[i][4]||r[i][6]==r[i][5])
				r[i][6]=rand()%10+1;	
		}
		else
		{
			for(j=0;j<7;j++)
				r[i][j]=0;
		}
	}
	fp=fopen(name,"w+");
	fprintf(fp,"========= lotto649 =========\n");
	fprintf(fp,"%s%d%d%d%d%d%s","========+ No.",num/10000,(num%10000)/1000,(num%1000)/100,(num%100)/10,num%10," +========\n= ");
	fprintf(fp,"%.*s",24,ctime(&curtime));
	fprintf(fp," =\n");
	for(i=0;i<5;i++)
	{
		fprintf(fp,"[");
		fprintf(fp,"%d",i);
		fprintf(fp,"]:");
		for(j=0;j<7;j++)
		{
			fprintf(fp," ");
			if(r[i][j]==0)
				fprintf(fp,"--");
			else
			{
				if(r[i][j]<10)
					fprintf(fp,"%d%d", 0, r[i][j]);
				else
					fprintf(fp,"%d",r[i][j]);
			}
		}
		fprintf(fp,"\n");
	}
	fprintf(fp,"%s%d%s","========* Op.0000",id," *========\n");
	fprintf(fp,"========= csie@CGU =========\n");
	fclose(fp);
	printf("%s%d%s%s","已為您購買的",n,"組樂透彩組合輸出至 ",name);
	
	return 0;
}
