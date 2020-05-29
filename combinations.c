#include <libft.h>

// static void		ft_save(int **arr, int nums)
// {
// }

int				**ft_combinations(int len, int *nums)
{
	int *ptr;
	int tmp;
	int i;
	int	j;


	j = 0;
	while (j <= len)
	{
		i = 0;
		while (i < len - 1)
		{
			ft_swap(&nums[i], &nums[i + 1]);
			ft_putnbr_arr(&nums, 1, len);
			i++;
		}
		j++;
	}
	return NULL;
}

int main()
{
	int		arr[4] = {1, 2, 3, 4};

	ft_combinations(4, arr);
	return (0);
}
