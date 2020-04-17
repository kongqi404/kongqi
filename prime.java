import java.util.ArrayList;
import java.util.Scanner;

public class zuoye {
    public static void main(String[] args) {
        int n= new Scanner(System.in).nextInt();
        long start = System.currentTimeMillis();
        ArrayList<Integer> prime = Eratosthenes(n);
        long end = System.currentTimeMillis();
        System.out.println("埃氏筛耗时："+(end - start)+"ms");
        start = System.currentTimeMillis();
        prime = Euler(n);
        end = System.currentTimeMillis();
        System.out.println("欧拉筛耗时："+(end - start)+"ms");



    }
    public static ArrayList<Integer> Euler(int n){
        ArrayList<Integer> prime = new ArrayList<>();
        int pnum=0;
        boolean [] p = new boolean[n+1];
        for (int i = 2; i <= n; i++) {
            if(p[i]==false) {
                prime.add(i);
                pnum++;
            }
            for(int j=0;j<pnum;j++)
            {
                if(i*prime.get(j)>n)
                    break;
                p[i*prime.get(j)]=true;
                if(i%prime.get(j)==0)
                    break;
            }

        }
        return prime;
    }
    public static ArrayList<Integer> Eratosthenes(int n)
    {
        ArrayList<Integer> prime = new ArrayList<>();
        int [] a = new int[n+1];
        int i = 2;
        while(i*i<n)
        {
            for(int j = 2;i*j<=n;j++)
            {
                if(a[i*j]==0)
                    a[i*j]=1;
            }
            i++;
        }
        for (int i1 = 2; i1 < a.length; i1++) {
            if(a[i1]==0)
                prime.add(i1);
        }
        return prime;
    }
}
