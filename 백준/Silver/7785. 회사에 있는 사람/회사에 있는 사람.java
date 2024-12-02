import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import java.util.StringTokenizer;


class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Integer n = Integer.parseInt(br.readLine());

        Map<String,String> map = new HashMap<>();


        for (int i = 0; i < n; i++) {
            String input = br.readLine();
            StringTokenizer st = new StringTokenizer(input);
            String name = st.nextToken();
            String status = st.nextToken();

            if (map.containsKey(name)){
                map.remove(name);
            } else {
                map.put(name,status);
            }
        }

        List<String> li = new ArrayList<>();

        for (String key : map.keySet()){
            li.add(key);
        }

        Collections.sort(li, Comparator.reverseOrder());

        for (String key : li){
            System.out.println(key);
        }

    }
}