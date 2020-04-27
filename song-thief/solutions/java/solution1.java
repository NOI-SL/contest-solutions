import java.util.Scanner;
public class Solution{
    static Scanner sc=new Scanner(System.in);
    static int N;
    static int[] ar;
    static int NOT_ENOUGH_LENGTH=-1;
    static int NO_MELODIES_FOUND=0;
    static boolean DEBUG=false;
    
    public static void main(String[] args){
        N=sc.nextInt();
        ar=new int[N];
        for(int i=0;i<N;i++)ar[i]=sc.nextInt();
        int[] ans=new int[N+2];//+2


        for(int x=N-1;x>-1;x--){
            if(DEBUG)System.out.println("DPsol["+x+"]=");
            int temp=minLengthMelody(x);
            if(temp==NOT_ENOUGH_LENGTH)ans[x]=0;
            else if(temp==NO_MELODIES_FOUND)ans[x]=ans[x+1];
            else ans[x]=Math.max(ans[temp+1]+1,ans[x+1]);
        }

        if(DEBUG){
            for(int i=0;i<N;i++)System.out.print(ans[i]+ " ");
            System.out.println("");
        }

        System.out.println(ans[0]);

    }


    public static int minLengthMelody(int x){
        if(DEBUG){
            System.out.print("\tminLengthMeloy("+x+") ");
        }
        if((N-x)<3){
            if(DEBUG)System.out.println("NOT_ENOUGH_LENGTH");
            return NOT_ENOUGH_LENGTH;
        }
        int min=ar[x+1];
        int max=ar[x+1];
        for(int xx=x+2;xx<N;xx++){
            if((Math.min(ar[x],ar[xx])>min) | (Math.max(ar[x],ar[xx])<max)){
                if(DEBUG) System.out.println(xx);
                return xx;
            }
            min=Math.min(min,ar[xx]);
            max=Math.max(min,ar[xx]);
        }
        if(DEBUG)System.out.println("NO_MELODIES_FOUND");
        return NO_MELODIES_FOUND;
    }

}
