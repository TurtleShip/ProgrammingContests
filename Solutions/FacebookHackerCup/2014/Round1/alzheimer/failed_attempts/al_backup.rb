#!/usr/bin/ruby

# Suppress ruby warnings
$VERBOSE = nil

# I imported an array named cop from a file I pre-processed.
# I solved this problem using the array "cop", but had to erase it
# due to file size limit.
# I am attaching the code that I wrote to make the cop.
# The code pre-processing was written in C++

#include <iostream>
#include <vector>
#include <set>
# using namespace std;
# int gcd(int x, int y) { return y ? gcd(y, x % y) : abs(x); }

# const int N = 53; // the maximum number That an element in each coprime list can be
# const int S = 20; // size limit of coprime list
# bool isCoPrime[N+1][N+1];
# typedef vector<int> vi;
# typedef vector< vi > vvi;
# typedef vector< vvi > vvvi;

# typedef set< vi > svi;
# typedef vector< svi > vsvi;

# #define pb(x) push_back(x)

# // coprime list
# vvvi cop;
# vvi emp;

# void preprocess() {

#   for(int i=0; i <= N; i++)
#     for(int j=0; j <= N; j++) {
#       if(i == 0 && j == 0) {
#         isCoPrime[i][j] = false;
#       } else if( i == 1 || j == 1) {
#         isCoPrime[i][j] = true;
#       } else if (i == 0 || j == 0) {
#         isCoPrime[i][j] = false;
#       } else if( i == j) {
#         isCoPrime[i][j] = false;
#       } else {
#         isCoPrime[i][j] = gcd(i,j) == 1;
#       }
#     }
  

#   cop.pb(emp);

#   vvi p_list;
#   for(int i=1; i <= N; i++) {
#     vi cur;
#     cur.pb(i);
#     p_list.pb(cur);
#   }
#   cop.pb(p_list);
#   set< vi >::iterator itr;
#   for(int sz=2; sz <= S; sz++) {
#     vvi entire_p_list;

#     for(int i=0; i < cop[sz-1].size(); i++) {
#         vi prev_p_list = cop[sz-1][i];

#       for(int j=0; j <= N; j++) {
#         bool isGood = true;
#         for(int k=0; isGood && k < prev_p_list.size(); k++) {
#           isGood = isCoPrime[j][prev_p_list[k]];
#         }
#         if(isGood) {
#           vi cur_list = prev_p_list;
#           cur_list.pb(j);
#           sort(cur_list.begin(), cur_list.end() );
#           entire_p_list.pb( cur_list );
#         }
#       }
#     }
#     sort(entire_p_list.begin(), entire_p_list.end());
#     entire_p_list.erase( unique(entire_p_list.begin(), entire_p_list.end()), entire_p_list.end() );
#     cop.pb( entire_p_list );
#   }
# }


# int main() {
#   preprocess();

#   cout<<"cop = [ [[]]";
#   for(int sz=1; sz <= S; sz++) {
#     vvi entire_p_list = cop[sz];
#     cout<<",";
#     cout<<"[";
#     for(int i=0; i < entire_p_list.size(); i++) {
#       vi p_list = entire_p_list[i];
#       if(i > 0) cout<<",";
#       cout<<"[";
#       for(int j=0; j < p_list.size(); j++) {
#         if(j > 0) cout<<",";
#         cout<<p_list[j];
#       }
#       cout<<"]";
#     }
#     cout<<"]";
#   }

#   cout<<"]"<<endl;

#   return 0;
# }
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