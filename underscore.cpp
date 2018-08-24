#include "underscore.hpp"


template <typename Iterator, typename Function>
void each(Iterator begin, Iterator end, Function function)
{
	while(begin != end)
	{
		function(*begin);
		begin++;
	}
}

template <typename Iterator, typename Function>
void transform(Iterator first_begin, Iterator first_end, Iterator second_begin, Function function)
{
	while(first_begin != first_end)
	{
		(*second_begin) = function(*first_begin);
		first_begin++;
		second_begin++;
	}
}


template <typename Collection, typename Function>
Collection filter_accept(Collection &collection, Function function)
{
	Collection result; 
	typename Collection::iterator first_begin, result_begin = result.begin();
	for(first_begin = collection.begin(); first_begin != collection.end(); ++first_begin)
	{
		if(function(*first_begin))
		{
			result.insert(result.end(), *first_begin);
		}
	}

	return result;
}

template <typename Collection, typename Function>
Collection filter_reject(Collection &collection, Function function)
{
	Collection result;
	typename Collection::iterator first_begin, result_begin = result.begin();
	for(first_begin = collection.begin(); first_begin != collection.end(); ++first_begin)
	{
		if(!function(*first_begin))
		{
			result.insert(result.end(), *first_begin);
		}
	}
	return result;
}