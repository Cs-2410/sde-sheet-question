class Foo {
public:
    int *counter;
    Foo() {
        this->counter=new int(1);
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        *counter=*counter+1;
    }

    void second(function<void()> printSecond) {
        while(*counter<2);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        *counter=*counter+1;
    }

    void third(function<void()> printThird) {
        while(*counter<3);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        *counter=*counter+1;
    }
};