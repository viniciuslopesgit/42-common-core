  unsigned int    lcm(unsigned int a, unsigned int b)
  {
	int g = 0;

	if (a == 0 || b == 0)
		return 0;

	if (a > b)
		g = a;
	else
		g = b;

	while(1)
	{
		if (g % a == 0 && g % b == 0)
			return (g);
		g++;
	}

  }