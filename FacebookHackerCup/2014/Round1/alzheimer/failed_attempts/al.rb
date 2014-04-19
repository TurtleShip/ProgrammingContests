#!/usr/bin/ruby

# Suppress ruby warnings
$VERBOSE = nil

T = Integer(gets)

(1..T).each do |cid|
  # get user input
  N = Integer(gets(' ')) # Number of children
  K = Integer(gets) # Presents should be divisible by K

  children = []
  (1..N-1).each do
    num = Integer(gets(' '))
    children << num
  end
  num = Integer(gets)
  children << num

  # Done getting user input. Start processing data.
  phase0 = 0
  phase1 = 0

  # Begin phase 0
  children.collect! do |child|
    if child % K != 0
      need = K - child % K
      child += need
      phase0 += need
    end
    child
  end
  children.each do |child|
    print "#{child} "
  end
  puts ""
  # Begin phase 1
  # sort the children and divide them by K
  children.sort!
  children.collect! do |child|
    child /= K
    child
  end

  children.each do |child|
    print "#{child} "
  end
  puts ""


  elist = cop[N]
  is_first = true
  elist.each do |plist|
    is_good = true
    extra = 0
    # puts plist
    (0..N-1).each do |i|
      #puts "plist[#{i}] = #{plist[i]}"
      #puts "children[#{i}] = #{children[i]}"
      if children[i] > plist[i]
        is_good = false
        break
      end
      extra += plist[i] - children[i]
    end
    if is_good
      if is_first
        phase1 = extra
        is_first = false
      else
        phase1 = [phase1, extra].min
      end
    end
  end

  puts "Case ##{cid}: #{phase0 + K*phase1}"
end