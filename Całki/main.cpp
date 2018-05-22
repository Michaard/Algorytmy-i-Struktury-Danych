#include <iostream>
#include <cmath>
#include <cstdlib>

#define RECTANGLE_Y1 -100
#define RECTANGLE_Y2 100

double distance(double x1,double y1,double x2,double y2){
    double d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    return d;
}

double round_2(double n){
    int tmp=n*1000;
    if(tmp%10>=5)
        tmp+=10;
    double result=(tmp/10)*0.01;
    return result;
}

double fast_pow(double base,unsigned int power){
    if(power==0)
        return 1;
    else if(power==1)
        return base;
    else{
        if(power%2==1){
            return base*fast_pow(base,power-1);
        }
        else{
            return fast_pow(base*base,power/2);
        }
    }
}

class Integral{
public:
    virtual double compute()=0;
    virtual void display()=0;
    virtual double yValueInX(double)=0;
};

class C:public Integral{
private:
    unsigned int degree;
    double* coefficients;
    double leftLim;
    double rightLim;
    double yValueInX(double);
public:
    C(unsigned int,double*,double,double);
    ~C();
    double compute();
    void display();
};
double C::yValueInX(double x){
    double y=0;
    y+=this->coefficients[0];
    for(unsigned int i=1;i<this->degree;i++){
        y+=this->coefficients[i]*fast_pow(x,i);
    }
    return y;
}
C::C(unsigned int deg,double* coef,double ll,double rl){
    this->degree=deg;
    this->coefficients=coef;
    this->leftLim=ll;
    this->rightLim=rl;
}
C::~C(){
    delete[]this->coefficients;
}
double C::compute(){
    double rectangle_area=distance(this->leftLim,RECTANGLE_Y1,this->rightLim,RECTANGLE_Y1)*distance(this->leftLim,RECTANGLE_Y1,this->leftLim,RECTANGLE_Y2);
    double n=100000000.0;
    int k=0;
    for(unsigned int i=0;i<=n;i++){
        double t1=rand()/(double)RAND_MAX;
        double rand_x=this->leftLim+t1*(this->rightLim-this->leftLim);
        double t2=rand()/(double)RAND_MAX;
        double rand_y=RECTANGLE_Y1+t2*(RECTANGLE_Y2-RECTANGLE_Y1);
        double y=this->yValueInX(rand_x);
        if(y>=0){
            if(rand_y<=y && rand_y>=0)
                k++;
        }
        else{
            if(rand_y>=y && rand_y<=0)
                k--;
        }
    }
    double result=(k/n)*rectangle_area;
    return result;
}
void C::display(){
    if(this->degree>1 && this->coefficients[0]!=0)
        std::cout << this->coefficients[0] << " + ";
    else if(this->degree==1 && this->coefficients[0]!=0){
        std::cout << this->coefficients[0] << std::endl;
        return;
    }
    if(this->degree>2 && this->coefficients[1]!=0){
        if(this->coefficients[1]==1)
            std::cout << "(x) + ";
        else if(this->coefficients[1]==-1)
            std::cout << "(-x) + ";
        else
            std::cout << "(" << this->coefficients[1] << "x) + ";
    }
    else if(this->degree==2 && this->coefficients[1]!=0){
        if(this->coefficients[1]==1)
            std::cout << "(x)" << std::endl;
        else if(this->coefficients[1]==-1)
            std::cout << "(-x)" << std::endl;
        else
            std::cout << "(" << this->coefficients[1] << "x)" << std::endl;
        return;
    }
    if(this->degree>=3){
        for(unsigned int i=2;i<degree-1;i++){
            if(this->coefficients[i]!=0){
                if(this->coefficients[i]==1)
                    std::cout << "(x^" << i << ") + ";
                else if(this->coefficients[i]==-1)
                    std::cout << "(-x^" << i << ") + ";
                else
                    std::cout << "(" << this->coefficients[i] << "x^" << i << ") + ";
            }
        }
        if(this->coefficients[this->degree-1]!=0){
            if(this->coefficients[this->degree-1]==1)
                std::cout << "(x^" << this->degree-1 << ")" << std::endl;
            else if(this->coefficients[this->degree-1]==-1)
                std::cout << "(-x^" << this->degree-1 << ")" << std::endl;
            else
                std::cout << "(" << this->coefficients[this->degree-1] << "x^" << this->degree-1 << ")" << std::endl;
        }
    }
}

class E:public Integral{
private:
    double a;
    double leftLim;
    double rightLim;
    double yValueInX(double x);
public:
    E(double,double,double);
    double compute();
    void display();
};
double E::yValueInX(double x){
    double y=exp(this->a*x);
    return y;
}
E::E(double a,double ll,double rl){
    this->a=-a;
    this->leftLim=ll;
    this->rightLim=rl;
}
double E::compute(){
    double rectangle_area=distance(this->leftLim,0,this->rightLim,0)*distance(this->leftLim,0,this->leftLim,RECTANGLE_Y2);
    double n=1000000.0;
    unsigned int k=0;
    for(unsigned int i=0;i<=n;i++){
        double t1=rand()/(double)RAND_MAX;
        double rand_x=this->leftLim+t1*(this->rightLim-this->leftLim);
        double t2=rand()/(double)RAND_MAX;
        double rand_y=0+t2*(RECTANGLE_Y2-0);
        double y=this->yValueInX(rand_x*rand_x);
        if(rand_y<=y && rand_y>=0)
            k++;
    }
    double result=(k/n)*rectangle_area;
    return result;
}
void E::display(){
    if(a==1)
        std::cout << "e^(x^2)" << std::endl;
    else if(a==-1)
        std::cout << "e^(-x^2)" << std::endl;
    else
        std::cout << "e^(" << this->a << "x^2)" << std::endl;
}

void read_input(Integral** integrals,unsigned int no_integrals){
    char integral_type;
    for(unsigned int i=0;i<no_integrals;i++){
        std::cin >> integral_type;
        if(integral_type=='C'){
            unsigned int input_degree;
            double input_ll;
            double input_rl;
            std::cin >> input_degree;
            double* input_coefs=new double[input_degree];
            for(unsigned int j=0;j<input_degree;j++)
                std::cin >> input_coefs[j];
            std::cin >> input_ll;
            std::cin >> input_rl;
            integrals[i]=new C(input_degree,input_coefs,input_ll,input_rl);
        }
        else if(integral_type=='E'){
            double input_a;
            double input_ll;
            double input_rl;
            std::cin >> input_a;
            std::cin >> input_ll;
            std::cin>> input_rl;
            integrals[i]=new E(input_a,input_ll,input_rl);
        }
    }
}

int main(){
    /*unsigned int deg=3;
    double* c=new double[deg];
    c[0]=0;
    c[1]=0;
    c[2]=-1;
    Integral* i=new C(deg,c,0,1);
    i->display();
    std::cout << round_2(i->compute()) << std::endl;
    double a=1;
    Integral* i2=new E(a,0.5,1);
    i2->display();
    std::cout << round_2(i2->compute()) << std::endl;*/
    unsigned int no_integrals;
    std::cin >> no_integrals;
    Integral** integrals=new Integral*[no_integrals];
    read_input(integrals,no_integrals);
    //std::cout << std::endl << "Computing..." << std::endl << std::endl;
    for(unsigned int i=0;i<no_integrals;i++){
        std::cout << round_2(integrals[i]->compute()) << std::endl;
    }
    //std::cout << fast_pow(3,5) << std::endl;
    return 0;
}
