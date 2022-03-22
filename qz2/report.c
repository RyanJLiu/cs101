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

int main()
{
	int i=0;
	time_t curtime;
	time(&curtime);
	FILE* fp;
	FILE* fr;
	fp=fopen("report.txt","w+");
	fr=fopen("record.bin","rb");
	record rec[1];
	char today[100]
	strftime(today,100,"%Y%m%d", localtime(&curtime));
	char date;
	int num=0;
	int sum=0;
	int receipt=0;
	int t_num=0;
	int t_sum=0;
	int t_reciept=0;
	fprintf(fp, "========= lotto649 Report =========\n- Date ------ Num. ------ Reciept -\n");
	while(fread(rec, sizeof(record), 1, fr))
	{
		if(i==0)
			date=rec[0].lotto_date;
		if(date==rec[0].lotto_date)
			num=num+1;
			sum=sum+(int(rec[0].lotto_receipt/1.1/50));
			reciept=reciept+int(rec[0].lotto_receipt);
			i++;
		else
		{
			fprintf(fp, "%s     %d/%d       %d", date, num, sum, receipt);
			t_num=t_num+num;
			t_sum=t_sum+sum;
			t_receipt=t_receipt+receipt;
		}
		date=rec[0].lotto_date;
		
	}
	fprintf(fp,"-----------------------------------\n       %d    %d/%d           %d\n======== %s Printed =========", i, t_num, t_sum, t_receipt, today);
	fclose(fr);
	fclose(fp);
	return 0;
}
