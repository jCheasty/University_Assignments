/*  Grab a stick. Break it in two.
    Pick the longer piece. Now randomly break that in two.
    Carry out this process a total of n times, always picking the longest piece to break.
    Write a program that takes n as input and outputs the probability
    that a triangle can be formed out of ANY three of the resulting pieces.
*/

import java.util.Scanner;
import java.util.Random;
public class Triangle_Probability{
    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);
        Random rn = new Random();
        System.out.print("Enter number of breaks: ");
        int breaks = sc.nextInt()+1,sims=10000000,tricount=0;
        double[] pieces = new double[breaks];

        for(int i=0;i<sims;++i) {

            double len = 100,bp,s1,s2,s3;

            for(int j=0;j<breaks-1;++j) {

                bp = rn.nextDouble() * len;

                if(len-bp>bp){
                    pieces[j]=bp;
                    len-=bp;
                }else{
                    pieces[j]=len-bp;
                    len=bp;
                }
            }
            pieces[breaks-1]=len;

            out:for(int j=0;j<breaks;++j){
                for(int k=0;k<breaks;++k){
                    for(int l=0;l<breaks;++l){
                        if(j!=k && j!=l && l!=k) {
                            s1 = pieces[j];
                            s2 = pieces[k];
                            s3 = pieces[l];
                            if (s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1){
                                ++tricount;
                                break out;
                            }
                        }
                    }
                }
            }
        }
        System.out.println("\nTrials: "+sims+"\nPieces per trial: "+breaks);
        System.out.println("Number of Triangles: "+tricount);
        System.out.println("~Probability: "+(double) tricount/sims*100+"%");
    }
}

/*---------------------SAMPLE OUTPUTS-------------------------
Enter number of breaks: 2    |  Enter number of breaks: 3	 
                             |								 
Trials: 10000000             |	Trials: 10000000			 
Pieces per trial: 3          |  Pieces per trial: 4			 
Number of Triangles: 3863117 |  Number of Triangles: 7353758 
~Probability: 38.63117%      |  ~Probability: 73.53758%		 */