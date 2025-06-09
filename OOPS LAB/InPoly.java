class Animal {
    void animalSound() {
        System.out.println("animal Sound");
    }

    void animalSound(int x) {
        System.out.println("Animal Sounds " + x + " times");
    }
}

class Dog extends Animal {
    @Override
    void animalSound() {
        super.animalSound();
        System.out.println("Dog Barks !!");
    }
}

public class InPoly {
    public static void main(String[] args) {
        Dog dog = new Dog();
        dog.animalSound(12);
        dog.animalSound();
    }
}