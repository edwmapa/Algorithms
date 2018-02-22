import java.util.*;
import java.math.*;
public class Fibo{
	
	public static long fibo(long n){
		long a=0,b=1,temp;
		for(long i = 0 ;i<n;i++){
			temp = b;
			b = a+b;
			a = temp;
		}
		return a;
	}
	
	public static BigInteger fiboB(BigInteger n){
		BigInteger a = BigInteger.ZERO, b = BigInteger.ONE, temp;
		for(BigInteger i = BigInteger.ZERO ; i.compareTo(n)<0; i=i.add(BigInteger.ONE)){
			temp = b;
			b = b.add(a);
			a = temp;
		}
		return a;
	}
	
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Put a number here > ");
		long n = sc.nextLong();
		System.out.println("fibo("+n+") = "+fibo(n));
		
		System.out.println("------Testing Basic Datatypes-------");
		for(short i = 0 ; i<=Short.MAX_VALUE;i++){
			short fib = (short)fibo(i);
			if(fib<0){
				System.out.println("> short overflows at: "+i);
				break;
			}
		}
		for(int i = 0 ; i<=Integer.MAX_VALUE;i++){
			int fib = (int)fibo(i);
			if(fib<0){
				System.out.println("> int overflows at: "+i);
				break;
			}
		}
		for(long i = 0 ; i<=Long.MAX_VALUE;i++){
			long fib = fibo(i);
			if(fib<0){
				System.out.println("> long overflows at: "+i);
				break;
			}
		}
		
		System.out.println("\n------BigIntger Performance-------");
		double time = 0,timeLimit=0.0001;
		BigInteger i = BigInteger.ZERO, fib;
		System.out.println("Calculations for a time<="+timeLimit);
		while(time<timeLimit){
			long tBegin = System.nanoTime();			
			fib = fiboB(i);
			long timeDiff = System.nanoTime()-tBegin;
			time = ((double)timeDiff)/1000000000.0;
			System.out.println("fibo("+i.toString()+") - time(seconds) = "+time);
			i = i.add(BigInteger.ONE);
		}
	}
}
