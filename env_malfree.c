#include "s_shell.h"

void *env_malloc(int sz, void *pfree)
{
	void *newptr;

	if (pfree)
	{
		cladd_denv(pfree, 1);
	}
	newptr = malloc(sz);
	if (!newptr)
	{
		perror("env_malloc error");
		return (NULL);
	}
	if (cladd_denv(newptr, 2) > 0)
		return (newptr);
	free(newptr);
	return (NULL);
}

int cladd_denv(void *penv, int stat)
{
	static void *env_pt[256];
	size_t iter, isize;

	isize = sizeof(env_pt) / sizeof(void *);
	if (!penv)
	{
		if (stat == 3)
		{
			for (iter = 0; iter < isize; iter++)
				if (env_pt[iter])
				{
					free(env_pt[iter]);
					env_pt[iter] = NULL;
				}
			return (1);
		}
		return (-1);
	}

	for (iter = 0; iter < isize; iter++)
	{
		if (env_pt[iter] == penv)
		{
			if (stat < 0 || stat > 1)
				return (-1);
			if (stat == 1)
			{
				free(env_pt[iter]);
				env_pt[iter] = NULL;
			}
			return (1);
		}

		if ((env_pt[iter] == NULL) && (stat == 2))
		{
			env_pt[iter] = penv;
			return (1);
		}
	}
	return (0);
}
