import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    static int[] Uarr;

    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());

        ArrayList<Node> A = new ArrayList<>();

        Uarr = new int[V+1];

        for (int i =1; i <= V; i++) Uarr[i] =i;


        for (int i =1; i <= E; i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int size = Integer.parseInt(st.nextToken());

            A.add(new Node(start,end,size));
        }

        Collections.sort(A);

        long ans = 0;
       
        for (int i  =0; i < A.size(); i++){
            Node item = A.get(i);
            
            int num1 = find(item.start);
            int num2 = find(item.end);
            if ( num1 != num2){
                union(item.start,item.end);
                ans += item.size;

            }

        }


        System.out.println(ans);
    }



    static void union(int a,int b){
        a = find(a);
        b = find(b);
        if (a != b){
            Uarr[b] = a;

        }

    }

    static int find(int num){
        if (Uarr[num] != num){
            return Uarr[num] = find(Uarr[num]);
        }
        else{
            return num;
        }


    }




    static class Node implements Comparable<Node>{
        int start;
        int end;
        int size;

        Node(int start,int end,int size){
            this.start = start;
            this.end = end;
            this.size = size;
        }

        @Override
        public int compareTo(Node o) {
            if (this.size >= o.size) return 1;
            else {
                return -1;
            }

        }
    }
}