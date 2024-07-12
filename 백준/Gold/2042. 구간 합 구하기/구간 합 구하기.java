import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static long[] A;
    static int smallK;
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        //배열 크기, 시작인덱스 정할 k구하기
        int temp = N;
        smallK = 0;
        while (temp != 0){
            temp /= 2;
            smallK++;
        }

        //배열에 입력값 넣기
        A = new long[(int) Math.pow(2,smallK+1)];

        int start = (int) Math.pow(2,smallK);
        temp = start;
        for (int i=0; i < N; i++){
            A[temp++] = Long.parseLong(br.readLine());
        }

        for (int i = start-1; i >= 1; i--){
            A[i] = A[i*2] + A[i*2+1];
        }


        StringBuilder sb = new StringBuilder();

        for (int i =0; i< M+K; i++){
            st = new StringTokenizer(br.readLine());
            int select = Integer.parseInt(st.nextToken());

            if (select == 1){
                int index = Integer.parseInt(st.nextToken());
                long value = Long.parseLong(st.nextToken());
                TreeUpdate(index,value);
            }
            if (select == 2){
                int StartIndex = Integer.parseInt(st.nextToken());
                int EndIndex = Integer.parseInt(st.nextToken());
                sb.append(TreePlus(StartIndex,EndIndex)+"\n");
            }
        }

        System.out.println(sb);



    }

    static void TreeUpdate(int index,long value){
        index = index + (int) (Math.pow(2,smallK) -1);
        long ChangeValue = value- A[index];
        while (index != 0){
            A[index] += ChangeValue;
            index /= 2;
        }

    }

    static long TreePlus(int StartIndex,int EndIndex){
        long sum = 0;
        StartIndex = StartIndex + (int) (Math.pow(2,smallK) -1);
        EndIndex = EndIndex + (int)(Math.pow(2,smallK) -1);
         while ( StartIndex <= EndIndex){
             if (StartIndex %2 == 1){
                 sum += A[StartIndex];
                 StartIndex+= 1;
             }
             if (EndIndex%2 == 0){
                 sum += A[EndIndex];
                 EndIndex -=1;
             }
             StartIndex /= 2;
             EndIndex /= 2;
         }


        return sum;
    }



}