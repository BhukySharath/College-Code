import java.util.*;
class item{
    public double value,weight,ratio;
    public item(double weight,double value){
        this.weight=weight;
        this.value=value;
        this.ratio=value/weight;
    }
}
public class fractionalknapsack{
    public static void merge(item[] items,int a,int b,int c){
        item[] temp=new item[items.length];
        int i=a,j=b+1,k=0,count=0;
        while(i<=b && j<=c){
            if(items[i].ratio<=items[j].ratio){
                temp[k]=items[i];
                i++;
            }
            else{
                temp[k]=items[j];
                j++;
            }
            k++;
        }
        if(i<=b){
            while(i<=b){
                temp[k]=items[i];
                i++;
                k++;
            }
        }
        else{
            while(j<=c){
                temp[k]=items[j];
                k++;
                j++;
            }
        }
        for(int l=0;l<k;l++){
            items[l+a]=temp[l];
        }
        
    
    }
    public static void mergeSort(item[] items,int i,int j ){
            if(i<j){
                
                int mid=(i+j)/2;
                mergeSort(items,i,mid);
                mergeSort(items,mid+1,j);
                merge(items,i,mid,j);
            }


    }
    public static void main(String ar[]){
        int n,i;
        double w,v,profit=0;
        System.out.println("Enter the no of items:");
        Scanner sc=new Scanner (System.in);
        n=sc.nextInt();
        item[] items=new item[n];
        for (i=0;i<n;i++){
            System.out.printf("Enter %d th item details:\n",i);
            System.out.println("Enter the Weight:");
            w=sc.nextDouble();
            System.out.println("Enter the vlaue:");
            v=sc.nextDouble();
            items[i]=new item(w,v);
        }
        for(int s=0;s<n;s++){
            System.out.println("R:"+items[s].ratio);
        }
        mergeSort(items,0,n-1);
        System.out.println("after sorting the items are:");
        for(int s=0;s<n;s++){
            System.out.println("R:"+items[s].ratio);
        }
        //form here logic of kanpsack will begin
        System.out.println("Enter the total capacity of bag:");
        
        double remaing=sc.nextInt();
        i=n-1;
        while(remaing >0 && i>=0){
            if(items[i].weight >remaing){
                profit+=remaing*items[i].ratio;
                break;
            }
            else{
                profit+=items[i].weight *items[i].ratio;
                remaing-=items[i].weight;
            }
            i--;
        }
        System.out.println("You can earn maximum profit upto:"+profit);
    }
}