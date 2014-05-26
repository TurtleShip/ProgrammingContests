  /*
  2  Problem link
  3  Type: Data structure - segment tree
  4  Algorithm:
  5      Segment tree:
  6          For problems having range queries, segment tree is
  7          one good data structures to kill them!
  8  
  9          For a segment tree, a node of the tree controls
 10          a specific range from our array. For example:
 11          We have 6 elements in our array, node[1] will
 12          control range [0..5], its children node[1*2] and
 13          node[1*2+1] will control range [0..2] and [3..5]
 14          and so on.
 15  
 16      In this problem, at first we build the tree (st_build)
 17      by traversing down to each leaf nodes to calculate their
 18      value, the value of a non-leaf node will be the sum of
 19      its children. I will explain later why we need to save
 20      the cast type of the magician for each node (start with -1
 21      means no cast type) this take O(n)
 22  
 23      Usually for this type of problem, on the update queries
 24      (change 0..3 to 1 for example), we think of traversing down
 25      to 0 1 2 3 to change the value and go up again. This will take
 26      O(n) for each queries in the worst case and is not effective.
 27  
 28      The solution for this called "lazy - update", that is, we will
 29      update once the range of the current node is in the range of the
 30      update query, not to the leaf nodes.
 31  
 32      The function <change> will change the value of the node that fits
 33      inside the range of the query AND UPDATE THE CAST TYPE OF ITS
 34      CHILDREN. This step is important because if later there is a
 35      question query that ask for a range lower than the current range
 36      we've just updated, we need to traverse down and base on
 37      the cast type information, update the nodes as well.
 38      For example: array has 6 elements: [0..5] = 0
 39          Change [0..2] to 1: we stop at node 2:
 40              node[2].value = 3, node[2].utype = F
 41              Update its children utype:
 42              node[2*2].value = 0 // not updated,
 43              node[2*2].utype = F // Like father like son
 44              node[2*2+1].value = 0 // not updated,
 45              node[2*2+1].utype = F // Like father like son
 46              node[2].utype = NULL // We are not gonna update it again
 47          Answer [0]:
 48              Traverse to node[4]: [0..1]:
 49                  Its utype is F -> change its value to 2
 50                  Change its children utype
 51              Go down to node[8]: [0]:
 52                  Its utype is F -> Change its value to 1
 53                  --> This is the answer
 54      A little different on the I type, you should see the code below
 55  */
 56  #include <iostream>
 57  #include <cstdio>
 58  #include <cmath>
 59  #include <cstring>
 60  #include <cstdlib>
 61  #include <vector>
 62  using namespace std;
 63  typedef vector<int> vi;
 64  const int maxn = 1024010;
 65  //-----------------------------------
 66  class node {
 67  public:
 68      int value, len;
 69      char utype;
 70  };
 71  //-----------------------------------
 72  node tree[5*maxn];
 73  vi a;
 74  //-----------------------------------
 75  void st_build(node tree[], int vertex, int l, int r);
 76  void change(int i);
 77  void set_utype(int vertex, char type);
 78  void update(int vertex, int l, int r, int i, int j, char type);
 79  int answer(int vertex, int l, int r, int i, int j);
 80  //-----------------------------------
 81  int main()
 82  {
 83      char ch;
 84      int n,t,ntest,q,u,v;
 85      string str;
 86      cin >> ntest;
 87      for (int test=1; test<=ntest; test++)
 88      {
 89          a.clear();
 90          printf("Case %d:\n",test);
 91          cin >> n;
 92          for (int i=1; i<=n; i++)
 93          {
 94              cin >> t;
 95              getline(cin,str);
 96              getline(cin,str);
 97              for (int j=1; j<=t; j++)
 98                  for (unsigned int k=0; k<str.length(); k++) a.push_back(int(str[k])-48);
 99          }
100          st_build(tree,1,0,a.size()-1);
101          int cnt = 0;
102          cin >> q;
103          for (int i=1; i<=q; i++)
104          {
105              cin >> ch >> u >> v;
106              if (ch!='S') update(1,0,a.size()-1,u,v,ch);
107              else
108              {
109                  cnt++;
110                  cout << "Q" << cnt << ": " << answer(1,0,a.size()-1,u,v) << endl;
111              }
112          }
113      }
114  }
115  //-----------------------------------
116  void st_build(node tree[], int vertex, int l, int r) {
117      if (l==r)                       //If it's a leaf node, set its value to a[l] or a[r]
118      {
119          tree[vertex].value = a[l];
120          tree[vertex].utype = -1;
121          tree[vertex].len = 1;
122      }
123      else
124      {
125          int mid = (l+r)/2;
126          st_build(tree, vertex*2, l, mid);       //Calculate its children
127          st_build(tree, vertex*2+1, mid+1, r);
128          tree[vertex].value = tree[vertex*2].value + tree[vertex*2+1].value; //Calculate its value
129          tree[vertex].utype = -1;
130          tree[vertex].len = r-l+1;
131      }
132  }
133  //-----------------------------------
134  void change(int i) {            //Apply the appropriate cast
135      switch(tree[i].utype)
136      {
137          case 'F': tree[i].value = tree[i].len; break;
138          case 'E': tree[i].value = 0; break;
139          case 'I': tree[i].value = tree[i].len-tree[i].value; break;
140          default: return;
141      }
142      set_utype(i*2,tree[i].utype);   //After applying, push down the cast type to its childrend
143      set_utype(i*2+1,tree[i].utype);
144      tree[i].utype = -1;             //Its cast type is now NULL
145  }
146  //-----------------------------------
147  void set_utype(int vertex, char type) {
148      if (type=='I')                  //Special case
149      {
150          switch(tree[vertex].utype)
151          {
152              case 'F': tree[vertex].utype = 'E'; break;
153              case 'E': tree[vertex].utype = 'F'; break;
154              case 'I': tree[vertex].utype = -1; break; 
155              case -1: tree[vertex].utype = 'I'; break;
156              default: break;
157          }
158      }
159      else tree[vertex].utype = type;
160  }
161  //-----------------------------------
/*
l = curL
r = curR
i = targetL
j = targetR
*/
162  void update(int vertex, int l, int r, int i, int j, char type) {
163      int mid = (l+r)/2;
164      if (l>=i && r<=j) set_utype(vertex,type);   //If it fits in the interval, set it cast type
165      change(vertex);                             //Do the cast type
166      if (l>=i && r<=j) return;
167      else
168      if (l>j || r<i) return;                     //If it's out then quit
169      else
170      {
171          update(vertex*2,l,mid,i,j,type);
172          update(vertex*2+1,mid+1,r,i,j,type);
173          tree[vertex].value = tree[vertex*2].value+tree[vertex*2+1].value;
174      }
175  }
176  //-----------------------------------
177  int answer(int vertex, int l, int r, int i, int j) {
178      int mid = (l+r)/2;
179      change(vertex);             //As traversing down, update the cast type of current index
180      if (l>=i && r<=j) return(tree[vertex].value);
181  
182      if (l>j || r<i) return(0);
183  
184      int p1 = answer(vertex*2,l,mid,i,j);
185      int p2 = answer(vertex*2+1,mid+1,r,i,j);
186      tree[vertex].value = tree[vertex*2].value+tree[vertex*2+1].value;
187  
188      return(p1+p2);
189  }