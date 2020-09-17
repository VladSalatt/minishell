#ifndef  FT_MAP_H
# define FT_MAP_H

# define DEFAULT_HASHFUNC &ft_hashfunc

typedef struct			s_htablist
{
	char 				*key;
	char				*value;
	struct s_htablist 	*next;
}						t_hlist;

#endif