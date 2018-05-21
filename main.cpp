#include <iostream>
#include <tuple>
using namespace std;
template<typename...Args>
struct has_cache
{
	template<typename...Params>
	static auto save_cache(std::tuple<Params...>&& tup)
	{

	}
};
template<typename T,typename...Args>
struct has_cache<T, Args...>
{
	template<typename...Params>
	static auto save_cache(std::tuple<Params...>&& tup)
	{
		using tp_type = std::tuple<Params..., T>;
		return has_cache<Args...>::template save_cache(tp_type{});
	}
};
template<typename...Args>
struct has_cache<bool, Args...>
{
	template<typename...Params>
	static auto save_cache(std::tuple<Params...>&& tup)
	{
		using tp_type = std::tuple<Params...>;
		cout << "need cache" << endl;
		return has_cache<Args...>::template save_cache(tp_type{});
	}
};
template<>
struct has_cache<>
{
	template<typename...Params>
	static auto save_cache(std::tuple<Params...>&& tup)
	{
		using tp_type = std::tuple<Params...>;
		cout << "end" << endl;
		return tp_type{};
	}
};
int main()
{
	
	auto tp = has_cache<int, float, bool, char,int>::save_cache(std::tuple<>{});
	cout << typeid(tp).name() << endl;
	cin.get();
}