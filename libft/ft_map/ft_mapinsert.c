#include "ft_map.h"
#include "../includes/libft.h"

void 		ft_mapinsert(t_map *map, const char *key, const void *value)
{
	int 	hash;
	int 	(*hash_func)(const char *, int);
	t_hlist **tmp;

	hash_func = map->hashfunc;
	hash = hash_func(key, map->size);
	tmp = &(map->head[hash]);
	if (*tmp == NULL)
	{
		*tmp = ht_
	}
}