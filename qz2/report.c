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
	float lotto_receipt;
	int emp_id;
	char lotto_date[100];
	char lotto_time[100];
}record;

int main()
{
	int i, j;
	int c=0;
	time_t curtime;
	time(&curtime);
	FILE* fp;
	FILE* fr;
	fp=fopen("report.txt","w+");
	fr=fopen("records.bin","rb");
	record rec[1];
	char today[100];
	strftime(today,100,"%Y%m%d", localtime(&curtime));
	char date[100];
	int num=0;
	int sum=0;
	int receipt=0;
	int t_num=0;
	int t_sum=0;
	int t_receipt=0;
	fprintf(fp, "========= lotto649 Report =========\n- Date ------ Num. ------ Reciept -\n");
	while(fread(rec, sizeof(record), 1, fr))
	{
		if(i==0)
		{
			for(j=0;j<10;j++)
				date[j]=rec[0].lotto_date[j];
			i++;
		}
		for(j=0;j<10;j++)
		{
			if(date[j]!=rec[0].lotto_date[j])
				c=1;
		}
		if(c==0)
		{
			num=num+1;
			sum=sum+(rec[0].lotto_receipt/1.1/50);
			receipt=receipt+rec[0].lotto_receipt;
			printf("%s, %d, %d, %d\n", date, num, sum, receipt);
		}
		else
		{
			fprintf(fp, "%s%7d/%-9d%8d\n", date, num, sum, receipt);
			t_num=t_num+num;
			t_sum=t_sum+sum;
			t_receipt=t_receipt+receipt;
			i++;
		}
		for(j=0;j<10;j++)
			date[j]=rec[0].lotto_date[j];
		c=0;
	}
	fprintf(fp, "%s%7d/%-9d%8d\n", date, num, sum, receipt);
	t_num=t_num+num;
	t_sum=t_sum+sum;
	t_receipt=t_receipt+receipt;
	fprintf(fp,"-----------------------------------\n%8d%7d/%-9d%8d\n========= %s Printed =========", i, t_num, t_sum, t_receipt, today);
	fclose(fr);
	fclose(fp);
	return 0;
}
