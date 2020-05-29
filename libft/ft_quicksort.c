void	ft_quicksort(int *nums, int index, int len)
{
	int		i;
	int		j;
	int		pivot;
	int		tmp;

	i = 0;
	j = 0;
	pivot = 0;
	tmp = 0;
	if(index < len)
	{
		pivot = index;
		i = index;
		j = len;
		while(i < j)
		{
			while(nums[i] <= nums[pivot] && i < len)
				i++;
			while(nums[j] > nums[pivot])
				j--;
			if(i<j)
			{
				tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}
		tmp = nums[pivot];
		nums[pivot] = nums[j];
		nums[j] = tmp;
		ft_quicksort(nums, index, j - 1);
		ft_quicksort(nums, j + 1, len);
	}
}