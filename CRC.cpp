#include<stdio.h>
#include<math.h>
int divisor[8],data[24],data_size,divisor_size,i,remain[8],current_count=1,count=0;
	int quotient[8],q_count=0;
	
int check_zero_one( int array[] ,int size) //Method used to check if given array consist of any bit which is 1
{
	for(i=0;i<size;i++)
	{
		if(array[i]==1)
		{
			count=i;
			return 1;
		}
	}
	return 0;
}
	
	
void printthis(int array[],int size)//Used to print the given array 
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d",array[i]);
	}
}


void remove_zeroes()
{

}

int main()
{
	printf("Data size maximum-16 bit\nDivisor size maximum-8 bit\n");
	printf("Enter the data size:");
	scanf("%d",&data_size);
	printf("Enter the divisor size:");
	scanf("%d",&divisor_size);
	
	
	printf("Enter the data in bits:");
	for(i=0;i<data_size;i++)
	{
	
	scanf("%d",&data[i]);
}
	printf("Enter the divisor in bits:");
	for(i=0;i<divisor_size;i++)
	{
		scanf("%d",&divisor[i]);
	}

//Data has been accepted till now
divisor_size-=1;
data_size-=1;
printf("After reducing divisor size:%d\nAfter reducing data size:%d\n\n",divisor_size,data_size);
for(i=0;i<divisor_size;i++)
{
++data_size;
data[data_size]=0;	
}
//0's have been appended 
printf("\n\n\n");
printf("Data is:");
printthis(data,data_size+1);
printf("\nData size:%d\n",data_size);
printf("\n\nDivisor is:");
printthis(divisor,divisor_size+1);

for(i=0;i<=divisor_size;i++)//At start load the bits from main data in the remain to perform the division
{
	remain[i]=data[i];
}
	printf("\nRemainder at start:");
printthis(remain,divisor_size+1);
//Actual division
current_count+=divisor_size;
do 
{
	if(remain[0]==0)
	{
		quotient[q_count]=0;
		
	}
	else
	{
		quotient[q_count]=1;
	}
	for(i=1;i<=divisor_size;i++)
	{
		if(remain[i]==(divisor[i]*quotient[q_count]))
		{
			remain[i-1]=0;
		}
		else
		{
			remain[i-1]=1;
		}
	}
	;
printf("\nI value:%d",i);
remain[i-1]=data[current_count];
++current_count;
	q_count++;
	printf("\nRemainder after processing:");
printthis(remain,divisor_size+1);
printf("Current count:%d",current_count);

}while(current_count<=data_size);

printf("Current count:%d",current_count);
printf("\nQuotient is: ");
printthis(quotient,q_count);

data_size-=divisor_size;
if(check_zero_one(remain,divisor_size+1)==1)
{
	for(i=count;i<=divisor_size;i++)
	{
		++data_size;
	data[data_size]=remain[i];
	}
	
}
printf("\n*********************************************************************************************************************");
printf("\nEncoded data:");
printthis(data,data_size+1);
	return 0;
}



/**
Variables used
1.data-Used to store the main data
2.divisor-Used to store the divisor which is to be divided
3.data_size-Used to store the size of the data
4.divisor_size-Used to store the size of the divisor
5.quotient-Used to store the quotient of the division
6.q_count-Used to store the current index of the quotient location
7.remain-Used to store the remainder of the division
8.count-Used to store the index at which bit-1 is present in the remainder
9.current_count-Used to store the undex till which the operation on data has been performed
*/
