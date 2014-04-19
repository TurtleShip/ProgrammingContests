import java.util.*;
import java.io.*;

class Info
{
	public int idx;
	public long sum;
	
	public Info()
	{
		idx = -1;
		sum = -1;
	}
	public Info(int i, int s)
	{
		idx = i;
		sum = s;
	}
}

public class ThemePark {
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		
		int T = in.nextInt();
		
		for(int idx=1; idx <= T; idx++)
		{
			int R = in.nextInt(); //number of rides
			int K = in.nextInt(); //maximum capacity of one ride
			int N = in.nextInt();
			
			
			long[] group = new long[N];
			Info[] info = new Info[N];
			
			for(int i=0; i < N; i++)
			{
				group[i] = in.nextLong();
				info[i] = new Info();
			}
			
			int who = 0;
			long profit = 0;
			long cycle = 0;
			int cycleLength = -1;
			int beforeCycleLen = 0;
			long beforeCycleSum = 0;
			for(int i=0; i < Math.min(R,N+1); i++)
			{
				long cur = 0;
				int start = who;
				
				//found the beginning of a cycle
				if(info[start].idx != -1)
				{
					//calculate the cycle
					int temp = 0;
					
					
					while(temp != start)
					{
						beforeCycleSum += info[temp].sum;
						temp = info[temp].idx;
						beforeCycleLen++;
					}
					
					cycle = profit - beforeCycleSum;
					cycleLength = (i - beforeCycleLen);

					break;
				}
				else
				{
					int count = 0;
					while(count < N && (cur+group[who]) <= K)
					{
						cur += group[who];
						who++;
						who %= N;
						count++;
					}
		
					profit += cur;
					info[start].idx = who;
					info[start].sum = cur;
				}
			}
			if(cycleLength != -1)
			{

				int numCycle = (R - beforeCycleLen) / cycleLength;
				profit = beforeCycleSum + cycle * numCycle;
				for(int i = 0; i < R - numCycle * cycleLength - beforeCycleLen; i++)
				{
					profit += info[who].sum;
					who = info[who].idx;
				}
			}

			
			out.println("Case #" + idx + ": " + profit);
	
			
			
		}
		
		out.flush();
		out.close();

	}
}
