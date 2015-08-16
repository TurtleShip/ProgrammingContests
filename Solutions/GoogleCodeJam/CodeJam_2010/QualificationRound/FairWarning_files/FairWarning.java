import java.util.*;
import java.math.*;
import java.math.BigInteger;



public class FairWarning {
	
	static BigInteger GCD(BigInteger a, BigInteger b)
	{

		if(b.compareTo(BigInteger.ZERO) == 0) return a;
		return GCD(b, a.mod(b));
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		int C = sc.nextInt();
		
		for(int idx = 1; idx <= C; idx++)
		{
			int N = sc.nextInt();
			Vector<BigInteger> big = new Vector<BigInteger>(N);
			for(int i=0; i < N; i++)
			{
				String in = sc.next();
				big.add(new BigInteger(in));
			}
			
			Collections.sort(big);
			
			BigInteger gcd = big.get(1).subtract(big.get(0));
			for(int i=2; i < N; i++)
			{
				gcd = GCD(gcd, big.get(i).subtract(big.get(i-1)));
			}
			
			BigInteger ans = (gcd.subtract(big.get(0).mod(gcd)));
			if(big.get(0).mod(gcd).compareTo(BigInteger.ZERO) == 0)
			{
				ans = BigInteger.ZERO;
			}
			
			System.out.println("Case #" + idx + ": " + ans);
		}
		
		
	}

}
