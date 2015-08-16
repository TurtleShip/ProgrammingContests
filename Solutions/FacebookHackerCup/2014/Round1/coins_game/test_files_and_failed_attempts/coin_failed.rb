#!/usr/bin/ruby

# Suppress ruby warnings
$VERBOSE = nil

def get_min_move(total_jars, total_coins, need_coins)

  if need_coins % total_jars == 0
    min_move = need_coins
  else
    need_mult = need_coins / total_jars
    total_mult = total_coins / total_jars
    if need_mult == total_mult
      min_move =  need_coins + (total_jars - (total_coins % total_jars))
    else ## c_mult < k_mult
      min_move = need_coins
    end
  end
  return min_move

end
T = Integer(gets)

(1..T).each do |cid|
  N = Integer(gets(' ')) # Number of jars
  K = Integer(gets(' ')) # Number of coins available
  C = Integer(gets) # NUmber of coins need to acquire
  min_move = get_min_move(N, K, C)

  (1..(N-1)).each do |empty_jars|
    if min_move == C
      break
    end
    avail_jars = N - empty_jars
    min_move = [min_move, empty_jars + get_min_move(avail_jars, K, C)].min
  end

  puts "Case ##{cid}: #{min_move}"
end