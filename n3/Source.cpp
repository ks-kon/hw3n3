#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <chrono>
#include <random>

#include <boost\functional\hash.hpp>


std::set < std::string > make_random_words(std::size_t N, std::size_t length) // length = 10 - good enough
{
    std::uniform_int_distribution <> letter(97, 122);
    std::default_random_engine e(static_cast <std::size_t> (
        std::chrono::system_clock::now().time_since_epoch().count()));

    std::set < std::string > words;

    for (std::string s(length, '_'); std::size(words) < N; words.insert(s))
        for (auto& c : s)
            c = letter(e);

    return words;
}

int main()
{
	int n = 9941;
	int N = 1000;

	//RANDOM NUMBERS

	std::set <int> s;

	std::vector <int> v;

	int k = 0;

	for (auto i = 0; i < N; ++i)
	{
		if ((s.insert(boost::hash_value <int> (std::rand() % n)).second) == false)
		{
			k += 1;
		}
		v.push_back(k);
	}
	for (auto i : v)
	{
		std::cout << i << ", ";
	}


	//RANDOM WORDS

	std::set <int> hash;

	std::vector <int> c;
	
	int m = 0;
	
	for (auto i = 0; i < N; ++i)
	{
		if ((hash.insert(boost::hash_value <std::string> (make_random_words(1, 3))).second) == false)
		{
			m += 1;
		}
		c.push_back(m);
	}
	for (auto i : c)
	{
		std::cout << i << ", ";
	}

	return EXIT_SUCCESS;
}