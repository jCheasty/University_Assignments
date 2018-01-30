class myComplex{

public:
    myComplex();
    myComplex(double, double);

    void print();
    double getReal();
    void setReal(double);
    double getImage();
    void setImage(double);

    myComplex Add(const myComplex &z);
    myComplex Subtract(const myComplex &z);
    myComplex Multiply(const myComplex &z);

protected:
    double real, image;
};