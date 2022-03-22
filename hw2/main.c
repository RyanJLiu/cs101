#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a-*(int *)b;
}

typedef struct lotto_record_t
{
	int lotto_no;
	float lotto_reciept;
	int emp_id;
	char lotto_date[100];
	char lotto_time[100];
}record;

typedef struct emp_record_t
{
	int emp_id;
	char emp_name[100];
	int emp_salary;
}emp_r;

int main()
{
	int i, j, k, n;
	int num=1;
	char name[17]="lotto[00001].txt";
	record rec;
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
	rec.lotto_no=num;
	srand((unsigned) time(NULL));
	printf("%s","�w����{�����ֳz�m�ʶR���x\n�п�J�ާ@�H��ID:(0~5):");
	scanf("%d",&rec.emp_id);
	if(rec.emp_id==0)
	{
		emp_r emp;
		printf("%s","�п�J�n�s�W�ާ@�H�� ID:(1~99):");
		scanf("%d",&emp.emp_id);
		printf("%s","�п�J�n�s�W�ާ@�H�� Name:");
		scanf("%s",&emp.emp_name);
		printf("%s","�п�J�n�s�W�ާ@�H�� Salary:");
		scanf("%d",&emp.emp_salary);
		idf=fopen("operator_id.bin", "ab+");
		fprintf(idf, "%d %s %d\n", emp.emp_id, emp.emp_name, emp.emp_salary);
		fclose(idf);
		printf("��J����");
	}
	else
	{
		printf("%s","�аݱz�n�R�X�ռֳz�m: ");
		scanf("%d",&n);
		strftime(rec.lotto_date,100,"%Y%m%d", localtime(&curtime));
		strftime(rec.lotto_time,100,"%H:%M:%S", localtime(&curtime));
		rec.lotto_reciept=n*50*1.1;
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
		fprintf(fp,"%s%d%s","========* Op.0000",rec.emp_id," *========\n");
		fprintf(fp,"========= csie@CGU =========\n");
		fclose(fp);
		printf("%s%d%s%s","�w���z�ʶR��",n,"�ռֳz�m�զX��X�� ",name);
		idf=fopen("record.bin", "ab+");
		fprintf(idf, "%d %f %d %s %s\n", rec.lotto_no, rec.lotto_reciept, rec.emp_id, rec.lotto_date, rec.lotto_time);
		fclose(idf);
	}
	return 0;
}