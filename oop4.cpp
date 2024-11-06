#include<iostream>
using namespace std;

class Complex 
{
   int r, img;
   public:
      Complex() 
      {
          r = 0;
          img = 0;
      }
      Complex(int rr, int im) 
      {
          r = rr;
          img = im;
      }
      
      
      void display() 
      {
          if(img >= 0)
          {
              cout << r << "+" << img << "i" << endl;
          }
          else
          {
              cout << r << " " << img << "i" << endl;
          }
      } 

      Complex operator + (Complex);
      friend Complex operator - (Complex, Complex); 
      Complex operator * (Complex);
      Complex operator / (Complex);
};

// Overloading the '+' operator
Complex Complex::operator + (Complex c2)
{
    Complex c3;
    c3.r = r + c2.r;
    c3.img = img + c2.img;
    return c3;
}

// Overloading the '-' operator
Complex operator - (Complex c1, Complex c2)
{
    Complex c3;
    c3.r = c1.r - c2.r;
    c3.img = c1.img - c2.img;
    return c3;
}

// Overloading the '*' operator
Complex Complex::operator * (Complex c2)  
{
    Complex c3;
    c3.r = r * c2.r - img * c2.img;
    c3.img = r * c2.img + img * c2.r;
    return c3;
}     

// Overloading the '/' operator
Complex Complex::operator / (Complex c2)
{
    Complex c3;
    int dr = c2.r * c2.r + c2.img * c2.img;
    c3.r = (r * c2.r + img * c2.img) / dr;
    c3.img = (-r * c2.img + img * c2.r) / dr;
    return c3;
}


int main()
{
    
        int rr, img,c;

        cout << "Enter the Real and Imaginary part of the first number: ";
        cin >> rr >> img;
        Complex c1(rr, img);

        cout << "Enter the Real and Imaginary part of the second number: ";
        cin >> rr >> img;
        Complex c2(rr, img);

        Complex c3;
      
   

    do {
        cout << "Operations:" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;   
        cout << "4. Divide" << endl;
        cout << "5. Exit " << endl;
        cout << "Enter your choice : ";
        cin >> c;

        switch (c)
        {
            case 1:
                c3 = c1 + c2;
                c3.display();
                break;
            case 2:
                c3 = c1 - c2;
                c3.display();
                break;
            case 3:
                c3 = c1 * c2;
                c3.display(); 
                break;
            case 4:
                c3 = c1 / c2;
                c3.display(); 
                break; 
            
            case 5:
                cout << "Program Exited!" << endl;
                break;
            default:
                cout << "Invalid operation. Please try again." << endl;
        }
    } while (c != 5);

    return 0;
}
