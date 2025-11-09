

#include <unistd.h>


int main(int argc, char**argv)
{
	if (argc == 3)
	{
		char *fir = argv[1];
		char *sec = argv[2];
		char comp[256] = {0};

		int i = 0;
		while(fir[i])
		{
			if (!comp[fir[i]])
			{
				int j = 0;
				while(sec[j])
				{
					if (fir[i] == sec[j])
					{
						write(1, &fir[i], 1);
						comp[fir[i]] = fir[i];
						break;
					}
					j++;
				}
				
			}
			i++;
		}


	}

	write(1, "\n", 1);
	return 0;
}