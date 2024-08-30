import java.util.Stack;

public class NextGreaterElement {

    public static void findNextGreaterElements(int arr[]) {
        int n = arr.length;
        int nextGreater[] = new int[n];

        Stack<Integer> stack = new Stack<>();

        nextGreater[n - 1] = -1;
        stack.push(arr[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            while (!stack.isEmpty() && stack.peek() <= arr[i]) {
                stack.pop();
            }

            if (stack.isEmpty()) {
                nextGreater[i] = -1;
            } else {
                nextGreater[i] = stack.peek();
            }
            stack.push(arr[i]);
        }

        //print
        for (int i = 0; i < n; i++) {
            System.out.print(nextGreater[i] + " ");
        }
    }

    public static void main(String args[]) {
        int arr[] = { 1, 9, 4, 2, 5, 6, 1, 1, 8 };

        findNextGreaterElements(arr);
    }
}