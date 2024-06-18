import java.util.ArrayList;
import java.util.List;

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
     List<Integer> largest;
     int[] smallest;
     if (nums1.length > nums2.length) {
        smallest = nums2;
        largest = fromArr(nums1);
     } 
     else {
        smallest = nums1;
        largest = fromArr(nums2);
     }
     for (int i = 0; i < smallest.length; i++) {
        final int index = binarySearch(smallest[i], largest, 0, largest.size());
        largest.add(index, smallest[i]);
     }
     System.out.println(largest.toString());
     return findMedian(largest);
    }

    private int binarySearch(int target, List<Integer> nums, int start, int end) {
        if (end - start == 1) {
            if (nums.get(start) > target) {
                return start;
            }
            return end;
        }
        if (end - start == 2) {
            if (nums.get(start) > target) {
                return start;
            }
            if (nums.get(end - 1) < target) {
                return end;
            }
            return start + 1;
        }
        final List<Integer> subNums = nums.subList(start, end);
        final int mid = Math.floorDiv(end - start, 2);
        System.out.printf("Start: %d, End: %d, Mid: %d Target: %d\n", start, end, mid, target);
        System.out.println(subNums.toString());
        if (subNums.get(mid) > target) {
            return binarySearch(target, nums, start, start + mid);
        } else {
            return binarySearch(target, nums, start + mid + 1, end);
        }
    }

    private List<Integer> fromArr(int[] arr) {
        final List<Integer> l = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            l.add(arr[i]);
        }
        return l;
    }

    private double findMedian(List<Integer> arr) {
        final int middle = Math.floorDiv(arr.size(), 2);
        if (arr.size() % 2 == 0) {
            return (arr.get(middle - 1).doubleValue() + arr.get(middle).doubleValue()) / 2;
        }
        return arr.get(middle);
    }
}

class TwoArrMedian {
    public static void main(String args[]) {
        final int[] nums1 = {1, 2};
        final int[] nums2 = {3, 4};
        final double solution = new Solution().findMedianSortedArrays(nums1, nums2);
        System.out.printf("Solution: %.2f\n", solution);
    }
}