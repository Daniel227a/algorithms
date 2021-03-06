#ifndef __Round__ROBIN__
#define __Round__ROBIN__


#include "./Process.h"
#include "./SortingFunction.h"
#include "./PrintTable.h"


void rr_calculate_waiting_time(Process *p, int len, Quantum q)
{
	int i;

	int curr_time = 0;



	int *remain_burst_time = (int *)malloc(sizeof(int) * len);

	int *calc_response_time = (int *)malloc(sizeof(int) * len);


	for (i = 0; i < len; i++)
	{
		remain_burst_time[i] = p[i].burst;

		calc_response_time[i] = FALSE;

	}


	while (TRUE)
	{
		int check = TRUE;


		for (i = 0; i < len; i++)
		{

			if (remain_burst_time[i] > 0)
			{
				check = FALSE;

				if (calc_response_time[i] == FALSE)
				{
					p[i].response_time = curr_time - p[i].arrive_time;

					calc_response_time[i] = TRUE;

				}


				if (remain_burst_time[i] > q)
				{
					curr_time += q;

					remain_burst_time[i] -= q;

				}


				else
				{
					curr_time += remain_burst_time[i];

					p[i].waiting_time = curr_time - p[i].burst;

					remain_burst_time[i] = 0;

				}
			}
		}


		if (check == TRUE)
			break;

	}

	free(remain_burst_time);

}


void rr_calculate_turnaround_time(Process *p, int len)
{
	int i;



	for (i = 0; i < len; i++){
	p[i].turnaround_time = p[i].burst +( p[i].waiting_time - p[i].arrive_time);
	
	if(p[i].turnaround_time <0){

		p[i].turnaround_time =p[i].turnaround_time*-1 ;
	}

	}
		



}


void rr_print_gantt_chart(Process *p, int len, Quantum q)
{
	int i, j;

	int curr_time = 0, total_burst_time = 0;

	int temp_total_burst_time = 0;


	int *remain_burst_time = (int *)malloc(sizeof(int) * len);


	for (i = 0; i < len; i++)
	{
		remain_burst_time[i] = p[i].burst;

		total_burst_time += p[i].burst;

	}

	printf("\t");


	while (TRUE)
	{
		int check = TRUE;

		for (i = 0; i < len; i++)
		{
			if (remain_burst_time[i] > 0)
			{
				check = FALSE;

				if (remain_burst_time[i] < q)
				{
					printf(" ");
					for (j = 0; j < remain_burst_time[i]; j++)
						printf("--");
				}

				else
				{
					printf(" ");
					for (j = 0; j <= q; j++)
						printf("--");
				}

				if (remain_burst_time[i] > q)
				{
					curr_time += q;
					remain_burst_time[i] -= q;
				}

				else
				{
					curr_time += remain_burst_time[i];
					p[i].waiting_time = curr_time - p[i].burst;
					remain_burst_time[i] = 0;
				}


			}
		}

		if (check == TRUE)
			break;
	}

	printf(" \n\t");

	for (i = 0; i < len; i++)
	{
		remain_burst_time[i] = p[i].burst;
	}


	while (TRUE)
	{
		int check = TRUE;

		for (i = 0; i < len; i++)
		{
			if (remain_burst_time[i] > 0)
			{
				check = FALSE;

				if (remain_burst_time[i] < q)
				{
					printf("|");

					if (remain_burst_time[i] != 1)
					{
						for (j = 0; j <= remain_burst_time[i] / 2; j++)
							printf(" ");

						printf("%2s", p[i].id);

						for (j = 0; j <= remain_burst_time[i] / 2; j++)
							printf(" ");
					}

					else
						printf("%2s", p[i].id);
				}

				else
				{
					printf("|");

					for (j = 0; j < q; j++)
						printf(" ");

					printf("%2s", p[i].id);

					for (j = 0; j < q; j++)
						printf(" ");
				}

				if (remain_burst_time[i] > q)
				{
					curr_time += q;
					remain_burst_time[i] -= q;
				}

				else
				{
					curr_time += remain_burst_time[i];
					p[i].waiting_time = curr_time - p[i].burst;
					remain_burst_time[i] = 0;
				}


			}
		}

		if (check == TRUE)
			break;
	}

	printf("|\n\t");

	for (i = 0; i < len; i++)
	{
		remain_burst_time[i] = p[i].burst;
	}


	while (TRUE)
	{
		int check = TRUE;

		for (i = 0; i < len; i++)
		{
			if (remain_burst_time[i] > 0)
			{
				check = FALSE;

				if (remain_burst_time[i] < q)
				{
					printf(" ");
					for (j = 0; j < remain_burst_time[i]; j++)
						printf("--");
				}

				else
				{
					printf(" ");
					for (j = 0; j <= q; j++)
						printf("--");
				}

				if (remain_burst_time[i] > q)
				{
					curr_time += q;
					remain_burst_time[i] -= q;
				}

				else
				{
					curr_time += remain_burst_time[i];
					p[i].waiting_time = curr_time - p[i].burst;
					remain_burst_time[i] = 0;
				}


			}
		}

		if (check == TRUE)
			break;
	}

	printf("\n\t");

	for (i = 0; i < len; i++)
		remain_burst_time[i] = p[i].burst;

	curr_time = 0;


	while (TRUE)
	{
		int check = TRUE;

		for (i = 0; i < len; i++)
		{
			if (remain_burst_time[i] > 0)
			{
				check = FALSE;

				if (remain_burst_time[i] < q)
				{
					printf("%-2d", curr_time);

					for (j = 0; j < remain_burst_time[i] - 1; j++)
						printf("  ");

					printf(" ");
				}

				else
				{
					printf("%-2d", curr_time);

					for (j = 0; j < q; j++)
						printf("  ");

					printf(" ");
				}

				if (remain_burst_time[i] > q)
				{
					curr_time += q;
					remain_burst_time[i] -= q;
				}

				else
				{
					curr_time += remain_burst_time[i];
					p[i].waiting_time = curr_time - p[i].burst;
					remain_burst_time[i] = 0;
				}
			}
		}

		if (check == TRUE)
			break;
	}

	printf("%-3d\n", total_burst_time);

	printf("\n");

	free(remain_burst_time);

}
void rr_calculate_response_time(Process *process,int process_count,int quantum){
   int temp2=0;
    int inicio=0;
	
	int i;
   // temp2=Cont_process_completed(process_count,process);
    //printf("%d",temp2);
     quantum=6;
	for(i=0;i<process_count;i++){
    process[i].response_time=0;


    }
    inicio=0;    
    while (inicio<process_count)
	{
	
	  
        if(inicio == 0){
      
            process[inicio].response_time=process[inicio].arrive_time;


            
        }else{

            if(process[inicio-1].burst >=quantum){
               
  
                process[inicio].response_time=(process[inicio-1].response_time+quantum);
              
            }else{
                
                 process[inicio].response_time=process[inicio-1].response_time+process[inicio-1].burst;
               
            }

        }
    if(process[inicio].response_time<0){

		process[inicio].response_time=process[inicio].response_time*-1;
	}
inicio++;
    }


	
}

void RR(Process *process, int process_count, Quantum quantum) {
	int i = 0;
	 process_init(process,process_count);
    
     merge_sort_by_arrive_time(process,0,process_count);  
     rr_calculate_waiting_time(process,0,process_count);
     rr_calculate_turnaround_time(process,process_count);
    

    for(i=0;i<process_count;i++){
    process[i].return_time=process[i].return_time+process[i].waiting_time+process[i].burst;


    }
     rr_calculate_response_time(process,process_count,quantum);
    printf("\tRR\n\n");
    //rr_print_gantt_chart(process,process_count,quantum);
    //print_table(process,process_count);


    
}

#endif
