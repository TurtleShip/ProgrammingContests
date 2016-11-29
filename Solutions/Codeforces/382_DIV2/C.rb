#!/usr/bin/ruby

# Get one number at a time
N = STDIN.gets.to_i

# 0 win = 1 person
# 1 win = 2 ppl
# 2 wins = 3 ppl
# 3 wins = 3 + 2 = 5 ppl

# needed[x] = the minimum number of ppl needed to get x wins.
# needed[x] = needed[x-1] + needed[x-2]
needed = [1, 2, 3]

if N == 2
	puts 1
	exit
end

if N == 3
	puts 2
	exit
end

ans = 3
while true
	needed[ans % 3] = needed[(ans - 1) % 3] + needed[(ans - 2) % 3]
	if(needed[ans % 3] > N)
		break
	end
	ans += 1
end

puts (ans - 1)



