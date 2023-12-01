import java.util.*;
public class MCM{
    public static int mcmFun(int f,int l,int[][] memo,int[] m){
        if(l-f==0){
            return 0;
        }
        if(memo[f][l]!=-1){
            return memo[f][l];
        }
        else{
            ArrayList<Integer> arr = new ArrayList();
            for(int k=f;k<=l-1;k++){
                int part1 = mcmFun(f,k,memo,m);
                int part2 = mcmFun(k+1,l,memo,m);
                int total = part1+part2+m[f-1]*m[l]*m[k];
                arr.add(total);
                System.out.println("the total is:"+total);
            }
            memo[f][l] = Collections.min(arr);
            return memo[f][l];
        }
    }
    public static void main(String ar[]){
        int n;
        System.out.println("Enter the no of matrix:");
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int[] m = new int[n+1];
        for(int i=0;i<n+1;i++){
            System.out.println("Give dimension:");
            m[i]=sc.nextInt();
        }
        int [][] memo = new int[n+1][n+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                memo[i][j]=-1;
            }
        }
        System.out.println("the minimum no of operation required is:"+mcmFun(1,n,memo,m));



    }
}