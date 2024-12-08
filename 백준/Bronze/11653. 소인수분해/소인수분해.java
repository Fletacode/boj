import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.file.Paths;
import java.util.Formatter;
import java.util.Scanner;

// 메인 클래스
public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


        int N = Integer.parseInt(br.readLine());

        for (int i = 2; i <= N; i++) {
            while(N % i == 0){
                N /= i;
                System.out.println(i);
            }
        }

    }
}
