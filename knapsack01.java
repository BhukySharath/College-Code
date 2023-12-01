import java.util.*;
class items{
    int weight;
    double profit;
    public items(int w,double p){
        weight=w;
        profit=p;
    }
}
public class knapsack01{
    
    public static double knapsack(double[][] dp, items[] it,int wt,int pos){
        double profit1=0,profit2=0;
        if(pos>=it.length || wt<=0) {
      
            return 0.0;
        }
        else if(dp[pos][wt-1]!=-1){
          
            return dp[pos][wt-1];
        }
        else{
          
            if(it[pos].weight<=wt){
                profit1=it[pos].profit+knapsack(dp,it,wt-it[pos].weight,pos+1);
            }
            profit2=knapsack(dp,it,wt,pos+1);
            if(profit1>=profit2){
                dp[pos][wt-1]=profit1;
            }
            else{
                dp[pos][wt-1]=profit2;
            }
            return dp[pos][wt-1];
        }
    }
    public static void main(String ar[]){
        int n,w,wt;
        double p;
        Scanner sc=new Scanner (System.in);
        System.out.println("Enter the no of items:");
        n=sc.nextInt();
        items[] it=new items[n];
        for (int i=0;i<n;i++){
            System.out.println("Enter the weight of items:");
            w=sc.nextInt();
            System.out.println("Enter the profit of the items:");
            p=sc.nextDouble();
            it[i]=new items(w,p);
        }
        System.out.println("Enter the total weight of bag:");
        wt=sc.nextInt();
        double[][] dp =new double [n][wt];
        for (int i=0;i<n;i++){
            for (int j=0;j<wt;j++){
                dp[i][j]=-1;
            }
        }
        //logic for fractional knapsack
        System.out.println("The maximum profit you can earn:"+ knapsack(dp,it,wt,0));
    }
}