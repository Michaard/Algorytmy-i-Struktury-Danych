#include <iostream>

using namespace std;

template<class C>
class Element{
private:
    C value;
    Element* next;
public:
    Element(C);
    void setNext(Element*);
    Element<C>* getNext();
    C getValue();
};
template<class C>
Element<C>::Element(C value){
    this->value=value;
    this->next=NULL;
}
template<class C>
void Element<C>::setNext(Element* next){
    this->next=next;
}
template<class C>
Element<C>* Element<C>::getNext(){
    return this->next;
}
template<class C>
C Element<C>::getValue(){
    return this->value;
}

template<class C>
class Stack{
private:
    Element<C>* topElement;
public:
    Stack();
    void push(C);
    void pop();
    C top();
    bool isEmpty();
};
template<class C>
Stack<C>::Stack(){
    this->topElement=NULL;
}
template<class C>
void Stack<C>::push(C value){
    Element<C>* elem=new Element<C>(value);
    elem->setNext(this->topElement);
    this->topElement=elem;
}
template<class C>
void Stack<C>::pop(){
    if(!this->isEmpty()){
        Element<C>* tmp=this->topElement;
        this->topElement=this->topElement->getNext();
        delete tmp;
    }
}
template<class C>
C Stack<C>::top(){
    if(!this->isEmpty())
        return this->topElement->getValue();
}
template<class C>
bool Stack<C>::isEmpty(){
    if(this->topElement==NULL)
        return true;
    else
        return false;
}

template<class C>
class Queue{
private:
    Element<C>* firstElement;
    Element<C>* lastElement;
public:
    Queue();
    void push(C);
    void pop();
    C top();
    bool isEmpty();
};
template<class C>
Queue<C>::Queue(){
    this->firstElement=NULL;
    this->lastElement=NULL;
}
template<class C>
void Queue<C>::push(C value){
    Element<C>* elem=new Element<C>(value);
    if(this->isEmpty()){
        this->firstElement=elem;
        this->lastElement=elem;
    }
    else{
        this->lastElement->setNext(elem);
        this->lastElement=elem;
    }
}
template<class C>
void Queue<C>::pop(){
    if(!this->isEmpty()){
        Element<C>* tmp=this->firstElement;
        this->firstElement=this->firstElement->getNext();
        delete tmp;
    }
}
template<class C>
C Queue<C>::top(){
    return this->firstElement->getValue();
}
template<class C>
bool Queue<C>::isEmpty(){
    if(this->firstElement==NULL)
        return true;
    else
        return false;
}

bool isOpenBracket(string br){
    if(br=="(" || br=="[" || br=="{")
        return true;
    else
        return false;
}
bool isCloseBracket(string br){
    if(br==")" || br=="]" || br=="}")
        return true;
    else
        return false;
}
bool isOperator(string op){
    if(op=="+" || op=="~" || op=="*" || op=="d" || op=="m" || op=="^")
        return true;
    else
        return false;
}
bool isDigit(string d){
    if(!isOpenBracket(d) && !isCloseBracket(d) && !isOperator(d))
        return true;
    else
        return false;
}

bool correctBrackets(string* strArray,int size){
    Stack<string> bracketStack;
    for(int i=0;i<size;i++){
        string thisElem=strArray[i];
        if(isOpenBracket(thisElem))
            bracketStack.push(thisElem);
        else if(isCloseBracket(thisElem)){
            if(bracketStack.isEmpty())
                return false;
            string br=bracketStack.top();
            if(thisElem==")" && br!="(")
                return false;
            else if(thisElem=="]" && br!="[")
                return false;
            else if(thisElem=="}" && br!="{")
                return false;
            else
                bracketStack.pop();
        }
    }
    return bracketStack.isEmpty();
}

bool correctSyntax(string* strArray,int size){
    for(int i=0;i<size-1;i++){
        string thisElem=strArray[i];
        string nextElem=strArray[i+1];
        if(isOpenBracket(thisElem) && (isCloseBracket(nextElem) || isOperator(nextElem)))
            return false;
        if(isCloseBracket(thisElem) && (isDigit(nextElem) || isOpenBracket(nextElem)))
            return false;
        else if(isOperator(thisElem) && (isOperator(nextElem) || isCloseBracket(nextElem)))
            return false;
        else if(isDigit(thisElem) && (isDigit(nextElem) || isOpenBracket(nextElem)))
            return false;
    }
    return true;
}

int stringToInt(string str){
    int l=str.length();
    int res=0;
    int d=1;
    if(str[0]=='-'){
        for(int i=l-1;i>=1;i--){
            res+=((int)str[i]-48)*d;
            d*=10;
        }
        res=-res;
    }
    else{
        for(int i=l-1;i>=0;i--){
            res+=((int)str[i]-48)*d;
            d*=10;
        }
    }
    return res;
}
int intLength(int in){
    int length=0;
    if(in==0)
        return 1;
    while(in!=0){
        in/=10;
        length++;
    }
    return length;
}
string intToString(int d){
    int l=intLength(d);
    string tmp,str;
    if(d<0){
        str="-";
        d=-d;
    }
    if(d==0)
        tmp="0";
    for(int i=l-1;i>=0;i--){
        tmp+=d%10+48;
        d/=10;
    }
    int ls=tmp.length();
    for(int i=ls-1;i>=0;i--){
        str+=tmp[i];
    }
    return str;
}
int priority(string op){
    if(op=="+" || op=="~")
        return 1;
    if(op=="*" || op=="d" || op=="m")
        return 2;
    else if(op=="^")
        return 3;
    else
        return 0;
}

Queue<string> translateToONP(string* strArray,int size){
    Stack<string> operatorStack;
    Queue<string> onpQueue;
    for(int i=0;i<size;i++){
        string thisElem=strArray[i];
        if(isDigit(thisElem)){
            onpQueue.push(thisElem);
        }
        else if(isOperator(thisElem)){
            if(!operatorStack.isEmpty()){
                string op=operatorStack.top();
                while(!operatorStack.isEmpty() && isOperator(op) && ((thisElem!="^" && priority(thisElem)<=priority(op))
                || (thisElem=="^" && priority(thisElem)<priority(op)))){
                    onpQueue.push(op);
                    operatorStack.pop();
                    if(!operatorStack.isEmpty())
                        op=operatorStack.top();
                }
                operatorStack.push(thisElem);
            }
            else
                operatorStack.push(thisElem);
        }
        else if(isOpenBracket(thisElem)){
            operatorStack.push(thisElem);
        }
        else if(isCloseBracket(thisElem)){
            string elem=operatorStack.top();
            while(!isOpenBracket(elem)){
                onpQueue.push(elem);
                operatorStack.pop();
                elem=operatorStack.top();
            }
            operatorStack.pop();
        }
    }
    while(!operatorStack.isEmpty()){
        onpQueue.push(operatorStack.top());
        operatorStack.pop();
    }
    return onpQueue;
}

int postfixONPsolve(Queue<string> onpQueue){
    Stack<string> onpStack;
    while(!onpQueue.isEmpty()){
        string symbol=onpQueue.top();
        if(isDigit(symbol)){
            onpStack.push(symbol);
            onpQueue.pop();
        }
        else{
            int res;
            int a=stringToInt(onpStack.top());
            onpStack.pop();
            int b=stringToInt(onpStack.top());
            onpStack.pop();
            if(symbol=="+"){
                res=a+b;
            }
            else if(symbol=="~"){
                res=b-a;
            }
            else if(symbol=="*"){
                res=a*b;
            }
            else if(symbol=="d"){
                if(a<=0)
                    throw "bledne dzialanie";
                else
                    res=b/a;
            }
            else if(symbol=="m"){
                if(a<=0 || b<0)
                    throw "bledne dzialanie";
                else
                    res=b%a;
            }
            else if(symbol=="^"){
                if(a<0 || (a==0 && b==0))
                    throw "bledne dzialanie";
                else{
                    res=1;
                    for(int p=1;p<=a;p++){
                        res*=b;
                    }
                }
            }
            onpStack.push(intToString(res));
            onpQueue.pop();
        }
    }
    return stringToInt(onpStack.top());
}

int main(){
    int inputLength;
    cin >> inputLength;
    string* input=new string[inputLength];
    for(int i=0;i<inputLength;i++)
        cin >> input[i];
    if(!correctBrackets(input,inputLength)){
        cout << "bledne nawiasy" << endl;
        return 0;
    }
    if(!correctSyntax(input,inputLength)){
        cout << "bledna skladnia" << endl;
        return 0;
    }
    int result;
    Queue<string> ONPtranslation=translateToONP(input,inputLength);
    try{
        result=postfixONPsolve(ONPtranslation);
        cout << result << endl;
    }
    catch(const char* err){
        cout << err << endl;
    }
    return 0;
}