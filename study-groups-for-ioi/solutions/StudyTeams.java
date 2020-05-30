

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

public class Main2 {
    static boolean DEBUG=false;
    static Scanner sc=new Scanner(System.in);
    public static void main(String[] args) {
        String[] temp=sc.nextLine().trim().split(" ");

        int N=Integer.parseInt(temp[0]);
        int D=Integer.parseInt(temp[1]);
        float DD=(float)D;

        float[][] theta12=new float[N][2];
        double[][] xyf=new double[N][2];




        for(int n=0;n<N;n++){
            temp=sc.nextLine().trim().split(" ");
            int id=Integer.parseInt(temp[0].split("/")[2])-1;

            theta12[id][0]=Float.parseFloat(temp[1]);
        }


        for(int n=0;n<N;n++){
            temp=sc.nextLine().trim().split(" ");
            int id=Integer.parseInt(temp[0].split("/")[2])-1;
            theta12[id][1]=Float.parseFloat(temp[1]);
        }


        if(DEBUG){
            for(int n=0;n<N;n++){
                System.out.println(n+"Angles "+theta12[n][0]+" "+theta12[n][1]);
            }
        }



        for(int n=0;n<N;n++){
            double cotTheta1=1.0/Math.tan(theta12[n][0]);
            double t=cotTheta1/Math.tan(Math.PI/2.0 + theta12[n][1]);

            if(DEBUG)System.out.println(n+ " "+cotTheta1+ " "+t);
            xyf[n][0]=DD/(t+1.0);
            xyf[n][1]=cotTheta1*xyf[n][0];
        }

        int[][] xy=new int[N][2];

        for (int n=0;n<N;n++){
            if(DEBUG)System.out.println(xyf[n][0]+" "+xyf[n][1]);
            xy[n][0]=(int)xyf[n][0];
            xy[n][1]=(int)xyf[n][1];

            System.out.println(xy[n][0]+" "+xy[n][1]);

        }

        long ans=0;

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int k=0;k<N;k++){
                    if(i!=j & j!=k & i!=k){
                        int a=(xy[i][0]-xy[j][0])*(xy[i][0]-xy[j][0]) + (xy[i][1]-xy[j][1])*(xy[i][1]-xy[j][1]);
                        int b=(xy[i][0]-xy[k][0])*(xy[i][0]-xy[k][0]) + (xy[i][1]-xy[k][1])*(xy[i][1]-xy[k][1]);






                        if(a==b)ans++;

                    }
                }
            }
        }


        System.out.println(ans/2);



    }

    public static long solve(int[][] xy){
        int N=xy.length;
        if(DEBUG){
            for(int n=0;n<N;n++){
                System.out.println(xy[n][0]+" " +xy[n][1]);
            }
        }

        int[] ar=new int[N-1];
        long ans=0;

        for(int s=0;s<N;s++){
            if(DEBUG)System.out.print("NUMBER = "+s);
            int x=xy[s][0];
            int y=xy[s][1];
            if(DEBUG)System.out.println(" x,y: "+x+" "+y);
            int idx=0;
            for(int ss=0;ss<N;ss++){
                if(ss!=s) {
                    ar[idx] = (xy[ss][0] - x) * (xy[ss][0] - x) + (xy[ss][1] - y) * (xy[ss][1] - y);
                    idx++;
                }
            }

            Arrays.sort(ar);

            if(DEBUG){
                System.out.print("Sorted dist^2: ");
                for(int k=0;k<ar.length;k++){
                    System.out.print(ar[k]+" ");
                }
                System.out.println();
            }



            int curr=ar[0];
            int currCount=1;

            for(int ss=1;ss<ar.length;ss++){
                if(DEBUG){
                    System.out.println(curr+" "+ar[ss]);
                }
                if(ar[ss]==curr){
                    currCount++;
                    if(ss==ar.length-1){
                        ans+=(currCount*(currCount-1))/2;
                        if(DEBUG){
                            System.out.println("FOUND at end!"+ ans);
                        }
                    }
                }
                else{
                    if(currCount>=2){
                        ans+=(currCount*(currCount-1))/2;
                        if(DEBUG){
                            System.out.println("FOUND!"+ ans);
                        }
                    }
                    currCount=1;
                    curr=ar[ss];
                }

                if(DEBUG){
                    System.out.println(curr+" "+ar[ss]+" "+currCount);
                }
            }
        }
        if(DEBUG){
            System.out.println("ANSWER: "+ans);
        }

        return ans;
    }
}
