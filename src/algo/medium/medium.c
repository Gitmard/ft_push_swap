
void	bubble_sort(int *tab, int size)
{
	int	i;
	int	tmp;

	while (size > 1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		size--;
	}
}

int	ft_sqrt(int x)
{
	int	min;
	int	max;
	int	mid;

	mid = 0;
	max = x + 1 / 2;
	while (max >= min)
	{
		mid = min + (max - min) / 2;
		if (mid * mid > x)
			max = mid - 1;
		else if (mid * mid < x)
			min = mid + 1;
		else
			return (mid);
	}
	if (x - (max * max) > (min * min) - x)
		return (min);
	return max;
}

int	*create_sorted_array(t_stacks *stacks)
{
	t_list	*iter;
	int	*tab;
	int	i;

	iter = stacks->stack_a->head;
	tab = malloc(sizeof(int) * stacks->stack_a->size);
	if (!tab)
		return (NULL);
	i = 0;
	while (iter)
	{
		tab[i] = iter->value;
		i++;
		iter = iter->next;
	}
	bubble_sort(tab, stacks->stack_a->size);
}

void	locate_closest(t_stacks *stacks, int window_start, int window_size, int *sorted)
{
	t_list	*forward;
	t_list	*backward;

	forward = stacks->stack_a->head->next;
	backward = stacks->stack_a->tail;
	while (forward && backward)
	{
		if (forward->value >= sorted[window_start]
				&& forward->value <= sorted[window_start + window_size])
			return (&ra);
		if (backward->value >= sorted[window_start
				&& backward->value <= sorted[window_start + window_size]])
			return (&rra);
		forward = forward->next;
		backward = backward->prev;
	}
	return (&ra);
}

void	update_poped(int window_start, int value, bool *poped, int *sorted)
{
	int	i;

	i = window_start;
	while (sorted[i] != value)
		i++;
	poped[i] = true;
}

void	update_window(int *window_start, int window_size, bool *poped, int size)
{
	while ((*window_start) + window_size + 1 < size && poped[(*window_start)])
		(*window_start++);
}

int	fill_buckets(t_stacks *stacks, int *sorted, int window_size, int *steps)
{
	int	window_start;
	int	size;
	bool	*poped;
	void	*f(t_stacks *);

	poped = ft_calloc(stacks->stack_a->size, sizeof(bool));
	if (!poped)
		return (1);
	while (stacks->stack_a->size > 0)
	{
		f = locate_closest(stacks);
		while (!(stacks->stack_a->head->value >= sorted[window_start]
				&& stacks->stack_a->head->value <= sorted[window_start + window_size]))
		{
			f(stacks);
			(*steps)++;
		}
		update_poped(window_start, stacks->stack_a->head->value, poped, size);
		pb(stacks);
		if (stacks->stack_b->head->value <= sorted[window_start + window_size / 2])
			rb(stacks);
		update_window(*window_start, window_size, poped, size);
		(*steps)++;
	}
}

int	medium(t_stacks *stacks)
{
	int	*sorted;
	int	window_size;
	int	steps;

	sorted = create_sorted_array(stacks);
	if (!sorted)
		return (-1);
	window_size = sqrt(stacks->stack_a->size);
	steps = 0;
	if (fill_buckets(stacks, sorted, window_size, &steps))
	{
		free(sorted);
		return (-1);
	}
	insert_in_a(stacks, sorted, size, &steps);
	return (steps);
}
