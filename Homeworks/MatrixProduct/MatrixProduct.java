import java.util.*;
import java.math.*;
public class MatrixProduct {
    public static int MAX = 10010;
    public static int[][] A = new int[MAX][MAX];
    public static int[][] B = new int[MAX][MAX];
    public static int[][] ans = new int[MAX][MAX];
    
    public static class pdd{
        public double first,second;
        pdd(double first,double second){
            this.first=first;
            this.second=second;
        }    
    }
    
    public static void init(int n){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                A[i][j]=1;
                B[i][j]=2;
                ans[i][j]=0;
            }
        }
    }
    
    public static void showM(int M[][],int n){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                System.out.print(M[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static void product(int n){
        for(int i = 0 ; i<n ; i++)
            for(int j = 0 ; j<n ; j++)
                for(int k = 0 ; k<n ; k++)
                    ans[i][j] = ans[i][j] + (A[i][k] * B[k][j]);
    }
    
    public static pdd prodTime(int n){
    double add=0,product=0;
    for(int i = 0 ; i<n ; i++)
        for(int j = 0 ; j<n ; j++)
            for(int k = 0 ; k<n ; k++){
                long start = System.nanoTime();
                int pd = (A[i][k] * B[k][j]);
                long end = System.nanoTime();
                product += (double)(end-start);
                start = System.nanoTime();
                ans[i][j] = ans[i][j] + pd;
                end = System.nanoTime();
                add += (double)(end-start);
            }
        return new pdd(add/(double)1e9,product/(double)1e9);
    }
    
    public static void main(String[] args) {   
        Scanner sc = new Scanner(System.in);
        System.out.println("Testing function - insert a value 0 <= n < 10010: ");
        int n = sc.nextInt();
        init(n);
        System.out.println("A:");showM(A,n);
        System.out.println("B:");showM(B,n);
        long start = System.nanoTime();
        product(n);
        long end = System.nanoTime();
        System.out.println("ans: ");showM(ans,n);
        System.out.println("time elapsed " + (end-start/((double)1e9) + " seconds."));
        
        System.out.println("----time performance analysis - each 10 steps----");
        System.out.println(" n \t avg(10) \t add_avg(10) \t prod_avg(10) ");       
        for (int i = 0 ; i <= 200;i+=10){
            init(i);//reset values of matrices
            double avg = 0, add_avg=0,prod_avg = 0;
            for(int j = 0;j<10;j++){
                pdd ot;
                start = System.nanoTime();
                ot = prodTime(i);
                end = System.nanoTime();
                avg += (end-start)/(double)1e9;
                   add_avg += ot.first;
                prod_avg += ot.second;
            }
            avg/=10.0;
            add_avg/=10.0;
            prod_avg/=10.0;
            System.out.printf("%d \t %.8f \t %.8f \t %.8f\n",i,avg,add_avg,prod_avg);
        }       
    }

}
