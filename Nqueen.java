import java.util.*;
public class Nqueen{
    public static boolean place(int[][] board,int row,int col,int n){
        for(int i=0;i<n;i++){

            if(board[row][i]!=0 || board[i][col]!=0){
                return false;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i<row && j<col && i-j==row-col && board[i][j]!=0){
                    return false;
                }
                if(i>row && j<col && i+j==row+col && board[i][j]!=0){
                    return false;
                }
                if(i<row && j>col && i+j==row+col && board[i][j]!=0){
                    return false;
                }
                if(i>row && j>col && i-j==row-col && board[i][j]!=0){
                    return false;
                }
            }
        }
        return true;
    }
    public static void nqueen(int [][] board,int n,int row,int col){
        if(row==n){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    System.out.printf("%d  ",board[i][j]);
                }
                System.out.print("\n");
            }
            System.out.print("\n----------------\n");
            return;
        }

        for(col=0;col<n;col++){
            if(place(board,row,col,n)){
                board[row][col]=1;
            
                nqueen(board,n,row+1,0);
                board[row][col]=0;
            }
        }
    }
    public static void main(String ar[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the no of Queens:");
        int n = sc.nextInt();
        System.out.println("\n----------------");
        int[][] board = new int[n][n];
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i][j] = 0;
                
            }
        }
        
        nqueen(board,n,0,0);

    }
}