import java.util.*;

public class Main{


    public static void sort(int arr[]){
        int n = arr.length;
        
        // create min heap
        for(int i = n-1 / 2; i>=0 ; i--){
            heapify(arr, i, n);
        }

        // perform heap sort
        for(int i = n-1 ; i>0 ; i--){
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;

            heapify(arr, 0, i);
        }
    } 

    public static void heapify(int arr[], int i, int n){
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left<n && arr[left]>arr[largest]){
            largest = left;
        }

        if(right<n && arr[right]>arr[largest]){
            largest = right;
        }

        if(largest != i){
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            
            heapify(arr, largest, n);
        }
    }
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of terms in array : ");
        int n = scanner.nextInt();

        System.out.println("Enter values of the array : ");

        int[] arr = new int[n];
        for(int i=0 ; i<n ; i++){
            arr[i] = scanner.nextInt();
        }

        sort(arr);
        System.out.println("Sorted array is : ");
        printArray(arr);

        scanner.close();
    }

    public static void printArray(int arr[]){
        int n = arr.length;
        for(int i=0;i<n;i++){
            System.out.print(arr[i] + " ");
        }

        System.out.println();

    }
}