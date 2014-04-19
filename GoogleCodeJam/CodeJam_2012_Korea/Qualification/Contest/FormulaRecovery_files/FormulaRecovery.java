import java.util.*;
import java.math.*;
import java.io.*;

public class FormulaRecovery {

	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		
		int T = in.nextInt();
		
		BigInteger[] pow10 = new BigInteger[245];
		pow10[0] = new BigInteger("1");
		for(int i=1; i < 245; i++)
		{
			pow10[i] = pow10[i-1].multiply(new BigInteger("10"));
		}

		for(int idx=1; idx <= T; idx++)
		{
			
			StringBuffer[] opd = new StringBuffer[2];
			String ops, igno, res;
			opd[0] = new StringBuffer(in.next());
			ops = in.next();
			opd[1] = new StringBuffer(in.next());
			igno = in.next();
			res = in.next();
			int[][] quesPos = new int[2][Math.max(opd[0].length(), opd[1].length())];
			int[]  quesLen = new int[2];
			quesLen[0] = 0;
			quesLen[1] = 0;
		
			for(int i=0; i < 2; i++)
			{
				for(int j=0; j < opd[i].length(); j++)
				{
					if(opd[i].charAt(j) == '?')
					{
						quesPos[i][quesLen[i]] = j;
						quesLen[i]++;
					}
				}
			}
			
			int F = quesLen[0];
			int S = quesLen[1];
			BigInteger fiBegin = new BigInteger("0");
			BigInteger seBegin = new BigInteger("0");
			
			if(opd[0].length() > 1 && F > 0)
			{
				if(quesPos[0][0] == 0)
					fiBegin = pow10[F-1];
			}
			
			if(opd[1].length() > 1 && S > 0)
			{
				if(quesPos[1][0] == 0)
					seBegin = pow10[S-1];
			}
			
			boolean found = false;
			BigInteger one = new BigInteger("1");
			BigInteger ten = new BigInteger("10");
			for(BigInteger i = fiBegin; !found && i.compareTo(pow10[F]) == -1; i = i.add(one))
			{
				BigInteger curI = i;
				for(int a = F-1; a >= 0; a--)
				{
					opd[0].setCharAt(quesPos[0][a], (char)( (curI.mod(ten)).intValue() + '0'));
					curI = curI.divide(ten);
				}
				
				for(BigInteger j = seBegin; !found && j.compareTo(pow10[S]) == -1; j = j.add(one))
				{
					BigInteger curJ = j;
					for(int a = S-1; a >=0; a--)
					{
						opd[1].setCharAt(quesPos[1][a], (char)( (curJ.mod(ten)).intValue() + '0'));
						curJ = curJ.divide(ten);
					}

					BigInteger curF = new BigInteger(opd[0].toString());
					BigInteger curS = new BigInteger(opd[1].toString());
					BigInteger curRes = new BigInteger("0");
				
					if(ops.equals("+"))
					{
						curRes = curF.add(curS);
					}
					else
						curRes = curF.subtract(curS);
				
					String resStr = curRes.toString();
				
					if(resStr.length() == res.length() && curRes.compareTo(BigInteger.ZERO) != -1)
					{
						boolean valid = true;
						for(int q=0; q < res.length(); q++)
						{
							if(res.charAt(q) != '?' && res.charAt(q) != resStr.charAt(q))
							{
								valid = false;
								break;
							}
						}
						if(valid)
						{
							res = resStr;
							found = true;
							break;
						}
					}
				}
			}
			
			out.println("Case #"+idx+": "+opd[0]+" "+ops+" "+opd[1]+" = "+res);

		}
		out.close();
	}
}
