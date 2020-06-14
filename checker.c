#include "push_swap.h"
#include "get_next_line.h"

static int ft_swap_operations(int **stacks, int *lengths, char *instruction)
{
	if (!ft_strcmp(instruction, "sa"))
		ft_swap_ps(stacks[0], lengths[0]);
	else if (!ft_strcmp(instruction, "sb"))
		ft_swap_ps(stacks[1], lengths[1]);
	else if (!ft_strcmp(instruction, "ss"))
		ft_ss(stacks[0], stacks[1], lengths[0], lengths[1]);
	else if (!ft_strcmp(instruction, "pb"))
	{
		ft_push(stacks[0], stacks[1], lengths[0], lengths[1]);
		lengths[0]--;
		lengths[1]++;
	}
	else if (!ft_strcmp(instruction, "pa"))
	{
		ft_push(stacks[1], stacks[0], lengths[1], lengths[0]);
		lengths[1]--;
		lengths[0]++;
	}
	else
		return (0);
	return (1);
}

static int ft_rotate_operations(int **stacks, int *lengths, char *instruction)
{
	if (!ft_strcmp(instruction, "ra"))
		ft_rotate(stacks[0], lengths[0]);
	else if (!ft_strcmp(instruction, "rb"))
		ft_rotate(stacks[1], lengths[1]);
	else if (!ft_strcmp(instruction, "rr"))
		ft_rr(stacks[0], stacks[1], lengths[0], lengths[1]);
	else if (!ft_strcmp(instruction, "rra"))
		ft_rrotate(stacks[0], lengths[0]);
	else if (!ft_strcmp(instruction, "rrb"))
		ft_rrotate(stacks[1], lengths[1]);
	else if (!ft_strcmp(instruction, "rrr"))
		ft_rrr(stacks[0], stacks[1], lengths[0], lengths[1]);
	else
		return (0);
	return (1);
}

static int	ft_check_order(int **stacks, int *lengths)
{
	int		i;

	i = 0;
	if (lengths[1])
		return (0);
	if (lengths[0] == 1)
		return (1);
	while (++i < lengths[0])
		if (stacks[0][i - 1] > stacks[0][i])
			return (0);
	return (1);
}

static int	ft_evaluate(int **stacks, int *lengths)
{
	char	*instruction;
	char	*last_instr;
	int		solved;
	int		i;

	solved = 0;
	last_instr = NULL;
	ft_putnbr_arr(&stacks[0], 1, lengths[0]);
	ft_putnbr_arr(&stacks[1], 1, lengths[1]);
	while (!solved)
	{
		i = -1;
		if (!get_next_line(0, &instruction))
			return (ft_check_order(stacks, lengths));	//stop if ctrl+D is pressed (end of input)
		if (!ft_rotate_operations(stacks, lengths, instruction) &&
			!ft_swap_operations(stacks, lengths, instruction))
		{
			ft_putstr("Error\n");
			exit (0);		//stop if input doesnt match any real instruction
		}
		ft_putnbr_arr(&stacks[0], 1, lengths[0]);
		ft_putnbr_arr(&stacks[1], 1, lengths[1]);
		last_instr = instruction;
	}
	return (1);
}

static int	ft_check(char *str)
{
	if (ft_strcmp(str, ft_itoa(ft_atoi(str))))
	{
		ft_putstr("Error\n");
		return (0);
	}
	while (*str)
	{
		if ((*str > '9' || *str < '0') && *str != '-')
		{
			ft_putstr("Error\n");
			return (0);
		}
		str++;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int		**stacks;
	int		lengths[2];
	int		i;

	if (argc == 1 ||
		(!(stacks = (int **)malloc(sizeof(int*) * 2))) ||
		(!(stacks[0] = (int *)malloc(sizeof(int) * argc - 1))) ||
		(!(stacks[1] = (int *)malloc(sizeof(int) * argc - 1))))
		return (1);
	i = 0;
	while (++i < argc)
	{
		if (!ft_check(argv[i]))
			return (0);
		stacks[0][i - 1] = ft_atoi(argv[i]);
	}
	lengths[0] = argc - 1;
	lengths[1] = 0;
	if (ft_evaluate(stacks, lengths))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}
