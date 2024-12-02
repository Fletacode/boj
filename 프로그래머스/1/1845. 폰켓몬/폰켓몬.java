import java.util.*;

class Solution {
    
    
    public int solution(int[] nums) {
        int answer = 0;
        
        int choice = nums.length / 2;
        int kinds = 0;
        
        HashSet<Integer> set1 = new HashSet<Integer>();
        
        for (int i = 0; i <  nums.length; i++){
            set1.add(nums[i]);
        }
        
        
        return Math.min(set1.size(), choice);
    }
}