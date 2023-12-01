
import java.util.*;
public class TSP{
    public static int  tsp(int[][] dist,int current,ArrayList<Integer> hasToTravel){

        if(hasToTravel.size()==0){
            return dist[current][0];
        }
        ArrayList<Integer> temp=new ArrayList();
        for(int i=0;i<hasToTravel.size();i++){
            ArrayList<Integer> copy=new ArrayList(hasToTravel);
            copy.remove(i);
            temp.add(dist[current][hasToTravel.get(i)]+tsp(dist,hasToTravel.get(i),copy));
        }
        return Collections.min(temp);
    }
    public static void main(String ar[]){
        int n;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the no of cities:");
        n=sc.nextInt();
        int[][] dist=new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    dist[i][j]=0;
                }
                else{
                    System.out.println("Enter the distance from "+i +" "+j+" city");
                    dist[i][j]=sc.nextInt();
                }
            }
        }
        ArrayList<Integer> a=new ArrayList();
        for(int i=1;i<n;i++){
            a.add(i);
        }
        System.out.println("has to trevell:"+a);
        System.out.println("the minimun distance has to  travel is:"+tsp(dist,0,a));
    }
}