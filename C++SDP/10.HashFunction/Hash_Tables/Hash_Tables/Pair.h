#ifndef PAIR_H
#define PAIR_H
template <typename T ,typename G>
struct Pair
{
	T key;
	G value;
	Pair(T key, G val) :key(key), value(val)
	{

	}
	bool operator == (const Pair<T, G>&other)
	{
		return other.key == key && other.value == value;
	}
};
#endif
