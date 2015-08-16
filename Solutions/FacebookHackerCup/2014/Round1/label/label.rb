#!/usr/bin/ruby

# Suppress ruby warnings
$VERBOSE = nil

T = Integer(gets)

(1..T).each do |cid|

  L = gets(' ').strip!
  N = Integer(gets)

  pow = Array.new(51)
  pow[0] = 1
  (1..50).each do |i|
    pow[i] = pow[i-1] * L.length
  end

  # Find the number of characters
  covered = 0
  len = 1 # Must be at least of length 1
  until covered < N and N <= (covered + pow[len])
    covered += pow[len]
    len += 1
  end

  # Find appropriate letters
  res = ""
  (1..len).each do |pos|
    let = 0
    until let == L.length or (covered + pow[len - pos] >= N)
      covered += pow[len-pos]
      let += 1
    end

    res += L[let]
  end

  puts "Case ##{cid}: #{res}"
end


