import java.util.Arrays;

public class HeapOperations {

    // Function to find the minimum and maximum marks
    public static void findMinMaxMarks(int[] marks) {
        if (marks == null || marks.length == 0) {
            System.out.println("No marks provided.");
            return;
        }

        int min = marks[0];
        int max = marks[0];

        for (int i = 1; i < marks.length; i++) {
            if (marks[i] < min) {
                min = marks[i];
            } else if (marks[i] > max) {
                max = marks[i];
            }
        }

        System.out.println("Minimum marks: " + min);
        System.out.println("Maximum marks: " + max);
    }

    // Function to perform heapify operation in heap sort
    public static void heapify(int[] arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            heapify(arr, n, largest);
        }
    }

    // Function to perform heap sort
    public static void heapSort(int[] arr) {
        int n = arr.length;

        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // One by one extract an element from heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            // call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }

    public static void main(String[] args) {
        int[] marks = {85, 72, 93, 67, 88, 78, 90, 65};

        // Finding minimum and maximum marks
        findMinMaxMarks(marks);

        // Sorting marks in ascending order using heap sort
        heapSort(marks);
        System.out.println("Marks sorted in ascending order:");
        System.out.println(Arrays.toString(marks));
    }
}
