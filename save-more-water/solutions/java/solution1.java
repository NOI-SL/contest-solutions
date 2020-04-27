import java.io.*;
import java.util.*;

public class Solution {
    static Scanner sc=new Scanner(System.in);
    public static void main(String[] args) {
        int NN=10000;
        int[] leftIndexGivenH=new int[NN+1];
        int[] rightIndexGivenH=new int[NN+1];
        boolean[] leftFoundGivenH=new boolean[NN+1];
      
        int N=sc.nextInt();
        for(int i=0;i<N;i++){
            int h=sc.nextInt();
            
            if(!leftFoundGivenH[h]){
                leftIndexGivenH[h]=i;
                leftFoundGivenH[h]=true;
            }
            rightIndexGivenH[h]=i;
        }
        
        long ans=0;
        
        for(int h=0;h<leftIndexGivenH.length;h++){
            for(int hh=0;hh<leftIndexGivenH.length;hh++){
                if(leftFoundGivenH[h] && leftFoundGivenH[hh]){
                    long temp=((long)Math.min(h,hh))*Math.abs(rightIndexGivenH[hh]-leftIndexGivenH[h]);
                    // System.out.println(h+" "+hh+" "+temp);
                    ans=Math.max(ans,temp);
                }
            }
        }
        
        System.out.println(ans);
    }
}
