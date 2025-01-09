import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        long[][] D = new long[N+1][10];

        for (int i =1; i <= 9; i++){
            D[1][i] = 1;
        }


        for (int i =2; i <= N; i++){
            for (int j = 0; j <= 9; j++){
                if (j == 9){
                    D[i][9] = D[i-1][8] % 1000000000;
                }
                else if (j == 0){
                    D[i][0] = D[i-1][1] % 1000000000;
                }else{
                    D[i][j] = (D[i-1][j-1] + D[i-1][j+1]) % 1000000000;
                }
            }

        }
        long ans = 0;
        for (int i =0; i < 10; i++){
            ans += D[N][i]; 
        }

        System.out.println(ans % 1000000000);


    }
}