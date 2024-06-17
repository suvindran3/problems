import java.util.Arrays;

class Solution {
    public int findPeakElement(int[] nums) {
        return search(nums, 0, nums.length);
    }

    private int search(int[] nums, int start, int end) {
        final int[] subNums = Arrays.copyOfRange(nums, start, end);
        if (subNums.length == 1) {
            return start;
        }
        System.out.println(Arrays.toString(subNums));
        System.out.printf("Start: %d End: %d\n", start, end);
        if (subNums.length == 2) {
            return subNums[0] > subNums[1] ? start : end - 1;
        }
        final int mid = Math.floorDiv(end - start, 2);
        System.out.printf("Middle index: %d\n", mid);
        if (subNums[mid - 1] < subNums[mid] && subNums[mid] > subNums[mid + 1]) {
            return start + mid;
        } else if (subNums[mid - 1] > subNums[mid]) {
            return search(nums, start, start + mid);
        } else {
            return search(nums, start + mid + 1, nums.length);
        }
    }
}

class PeakElement {
    public static void main(String args[]) {
        final int[] nums = { 1,2,3,4,5,2,1 };
        final Solution solution = new Solution();
        final int index = solution.findPeakElement(nums);
        System.out.printf("Solution: %d\n", index);
    }
}