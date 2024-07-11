#include<iostream>
using namespace std;
double add(double x ,double y){
    return x+y;
}
double subtract(double x , double y){
    return x-y;
}
double multiply(double x , double y){
    return x*y;
}
double divide(double x , double y){
    if (y==0)
    {
        throw runtime_error("Can't divide by zero ");
    }
    else{
        return x/y;
    }
}
int main(){
    cout<<"Welcome the calculator code!"<<endl;
    double num1, num2;
    cout<<"Enter the first number:";
    cin>> num1;
    cout<<"Enter the second number:";
    cin>> num2;
    char operation;
    cout<<"Enter the operation (+, - ,* , /):";
    cin>> operation;

    double result;
    try{
        switch(operation){
            case'+':
            result= add(num1, num2);
            break;
             case '-':
                result = subtract(num1, num2);
                break;
            case '*':
                result = multiply(num1, num2);
                break;
            case '/':
                result = divide(num1, num2);
                break;
            default:
                cout << "Invalid operation. Try again" << endl;
                return 1;
        }
        cout<<"The result is :" <<result<<endl;
        }
        catch(const runtime_error& e) {
        cout<<"Error:" <<e.what() << endl;
        }
        return 0;
    }