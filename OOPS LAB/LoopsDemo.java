class Loops {
    int[] nums = { 11, 22, 33, 44, 55, 66, 77, 88, 99 };

    public void forLoop() {
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
    }

    public void whileLoop() {
        int i = 0;
        while (i < nums.length) {
            System.out.print(nums[i] + " ");
            i++;
        }
    }

    public void forEachLoop() {
        for (int i : nums) {
            System.out.print(i + " ");
        }
    }

    public void doWhileLoop() {
        int i = 0;
        do {
            System.out.print(nums[i] + " ");
            i++;
        } while (i < nums.length);
    }

}

public class LoopsDemo {
    public static void main(String[] args) {
        Loops loop = new Loops();
        System.out.println("Useing ForLoop :");
        loop.forLoop();
        System.out.println();
        System.out.println("Useing ForEachLoop :");
        loop.forEachLoop();
        System.out.println();
        System.out.println("Useing WhileLoop :");
        loop.whileLoop();
        System.out.println();
        System.out.println("Useing DOWhileLoop :");
        loop.doWhileLoop();
        System.out.println();
    }
}
