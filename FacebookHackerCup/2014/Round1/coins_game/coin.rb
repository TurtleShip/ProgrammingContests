#!/usr/bin/ruby

# Suppress ruby warnings
$VERBOSE = nil

def get_min_move(n,k,c)
  x = (Float(C)/n).ceil
  m = n - [(k/x), n].min
  return m + c
end

T = Integer(gets)

(1..T).each do |cid|
  N = Integer(gets(' ')) # Number of jars
  K = Integer(gets(' ')) # Number of coins available
  C = Integer(gets) # NUmber of coins need to acquire
  min_move = get_min_move(N, K, C)

  puts "Case ##{cid}: #{min_move}"
end