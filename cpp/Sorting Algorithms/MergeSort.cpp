void merge(long long a[], long long start, long long end)
{
	long long mid=(start+end)/2;
	long long i=start,j=mid+1,k=start;
	long long temp[1000000];

	while(i<=mid&&j<=end)
	{
		if(a[i]<a[j])
		{
			temp[k]=a[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=a[j];
			k++;
			j++;
		}
	}

	while(i<=mid)
	{
		temp[k]=a[i];
		k++;
		i++;
	}

	while(j<=end)
	{
		temp[k]=a[j];
		k++;
		j++;
	}

	for(long long i=start; i<=end; i++)
	{
		a[i]=temp[i];
	}
}

void merge_sort(long long a[],long long start,long long end)
{
	//Base Case: num of elements=0 or 1;
	if(start>=end)
	{
		return;
	}

	long long mid=(start+end)/2;

	merge_sort(a,start,mid);
	merge_sort(a,mid+1,end);

	merge(a,start,end);

}