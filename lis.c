int get_max(t_list *stack)
{
	int max;

	max = stack->num;
	while(stack)
	{
		if(stack->num > max)
		{
			
			max = stack->num;
		}
		stack = stack->next;
	}
	return(max);
}