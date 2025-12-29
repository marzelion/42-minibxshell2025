
typedef struct s_envmanager
{
	const char	**_envp_bas;
	char		**_envp;
	int			size;
	char **(*init)(s_envmanager *p, char **envp);
	char **(*find)(s_envmanager *p, char *key);
	char **(*remove)(s_envmanager *p, char *key);
	char *(*at)(s_envmanager *p, char *key);
}	t_envmanager;

t_envmanager *t_evm_dtor(t_envmanager *p)
{
	if (!p)
		return (NULL);
	if (p->_envp)
	{
		ft_strsplit_release(&p->_envp);
	}
	p->_envp_base = NULL;
}
t_envmanager *t_evm_init(t_envmanager *p, char **envp)
{
	const char **envpp;
	const char **itenv;;

	envpp = envp;
	p->_envp = malloc((p->size + 1)*sizeof(char **));
	if (!p->_envp)
		return (NULL);
	/*
	 * ft_memcpy(p->_envp, 
	 * */		
	itenv = p->_envp;
	while(envp)
	{
		itenv = ft_strdup(*envp);
		if (!itenv)
		{
			ft_strsplit_release(&p->_envp);
			return (NULL);
		}
		envp++;
		itenv++;
	}
	return (p);
}
t_envmanager *t_evm_ctor(t_envmanager *p, char **envp)
{
	if (!p)
		return (NULL);
	p->init = t_evm_init;
	p->find = t_evmg_find;
	p->at = t_evmg_at;
	p->_envp_base = envp;
	p->size = 0;
	while(p->_envp_base++)
		p->size++;
	return (t_evm_init(p, envp));
}

char **t_evmg_find(t_envmanager *p, char *key)
{
	char **envp;
	if (!p || !key)
		return ((void *)0);
	if (ft_strlen(key) == 0)
		return ((void *)0);
	envp = p->_envp_base;
	while (*envp)
		if (ft_strncmp(*envp, key, ft_strlen(key)) == '=')
			return (envp);
	return (NULL);
}

char **t_evmg_remove(t_envmanager *p, char *key)
{
	char **oldenvp;
	char **remove;
	
	oldenvp = p->find(p, key);
	if (oldenvp)
	{
		remove = oldenvp;
		free(*remove);
		*remove = (void *)0;
		while(++remove)
		{
			oldenvp = remove;
			oldenvp++;
		}
	}
}

char *t_evmg_at(t_envmanager *p, char *key)
{
	char **result;
	
	result = p->find(p, key);
	if (result)
		return (ft_strchr(*result, '=');
	return NULL
}



int main(int argc, char **argv,  char **envp)
{
	t_envmanager t_e;
	
	if(!t_evm_ctor(&t_e, envp))
		return (1);
	t_e = envp;
	char **displayval = t_e.find("DISPLAY");
	char **notfoundval = t_e.find("NOTFOUND");
	//t_e->d("DISPLAY");
	/*
		_envpi["DISPLAY"] = "";
		&_envp[DISPLAY"] = NULL ????????????
	*/
	t_evm_dtor(&t_e);
	return (0);
}
