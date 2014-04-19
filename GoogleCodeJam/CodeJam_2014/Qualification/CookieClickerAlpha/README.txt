Both B_brute_force.cpp and B.cpp gives the same result.

They both use a similar logic
: Assume that you are going to buy N cookie farms.
  Figure out how much time it will take to get X.

B_brute_force does a brute force search on N.
	: start from N = 0, and keep increasing N until we find an optimal solution.

B.cpp does a binary search on N.

I calculated that B_brute_force was too slow to pass the large input,
so I came up with binary search approach. However, it turned out that
Google's large input was weak enough that B_brute_force was able to 
solve it under 2 minutes. 

I tested B_brute_force agaist one of the worst cases I could think of
( 1.0, 1.0, 100000.0 )

B_brute_force took about 30 seconds while B.cpp took .022 seconds.

If all 100 test cases are about worst cases, then it would take
about 50 minutes to finish the large input.

However, the large input from Google was very weak and 
brute_force was able to solve large input under 2 minutes.
