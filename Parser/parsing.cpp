#include <iostream>

using namespace std;

template<class C>
class Element{
private:
    C value;
    Element<C>* nextElement;
    Element<C>* previousElement;
public:
    Element(C);
    Element<C>* getNextElement();
    Element<C>* getPreviousElement();
    void setNextElement(Element<C>*);
    void setPreviousElement(Element<C>*);
    C getValue();
    void setValue(C);
    void nullifyNextElement();
    void nullifyPreviousElement();
};
template<class C>
Element<C>::Element(C value){
    this->value=value;
    this->nextElement=NULL;
    this->previousElement=NULL;
}
template<class C>
Element<C>* Element<C>::getNextElement(){
    return this->nextElement;
}
template<class C>
Element<C>* Element<C>::getPreviousElement(){
    return this->previousElement;
}
template<class C>
void Element<C>::setNextElement(Element<C>* element){
    this->nextElement=element;
}
template<class C>
void Element<C>::setPreviousElement(Element<C>* element){
    this->previousElement=element;
}
template<class C>
C Element<C>::getValue(){
    return this->value;
}
template<class C>
void Element<C>::setValue(C value){
    this->value=value;
}
template<class C>
void Element<C>::nullifyNextElement(){
    this->nextElement=NULL;
}
template<class C>
void Element<C>::nullifyPreviousElement(){
    this->previousElement=NULL;
}

template<class E>
class List{
private:
    Element<E>* firstElement;
    Element<E>* lastElement;
    unsigned int size;
public:
    List();
    bool isEmpty();
    void add(E);
    void rem(E);
    void displayList();
    Element<E>* getFirstElement();
    Element<E>* getLastElement();
    bool isElement(E);
    bool isElement(E,E&);
    unsigned int getSize();
};
template<class E>
List<E>::List(){
    this->firstElement=NULL;
    this->lastElement=NULL;
    this->size=0;
}
template<class E>
bool List<E>::isEmpty(){
    if(this->firstElement==NULL)
        return true;
    else
        return false;
}
template<class E>
void List<E>::add(E value){
    if(this->isEmpty()){
        this->firstElement=new Element<E>(value);
        this->lastElement=this->firstElement;
    }
    else{
        Element<E>* newElement=new Element<E>(value);
        this->lastElement->setNextElement(newElement);
        newElement->setPreviousElement(this->lastElement);
        this->lastElement=newElement;
    }
    this->size++;
}
template<class E>
void List<E>::rem(E value){
    if(this->isEmpty())
        return;
    Element<E>* toBeRemoved;
    Element<E>* tempElement;
    while(this->firstElement->getValue()==value){
        if(this->firstElement==this->lastElement){
            this->firstElement=NULL;
            this->lastElement=NULL;
            return;
        }
        else{
            toBeRemoved=this->firstElement;
            tempElement=this->firstElement->getNextElement();
            tempElement->nullifyPreviousElement();
            delete toBeRemoved;
            this->firstElement=tempElement;
        }
    }
    tempElement=this->firstElement;
    while(tempElement->getNextElement()!=NULL){
        if(tempElement->getValue()==value){
            toBeRemoved=tempElement;
            tempElement->getPreviousElement()->setNextElement(tempElement->getNextElement());
            tempElement->getNextElement()->setPreviousElement(tempElement->getPreviousElement());
            tempElement=tempElement->getPreviousElement();
            delete toBeRemoved;
        }
        if(tempElement->getNextElement()->getValue()==value){
            toBeRemoved=tempElement->getNextElement();
            if(tempElement->getNextElement()->getNextElement()!=NULL){
                tempElement->setNextElement(tempElement->getNextElement()->getNextElement());
                tempElement->getNextElement()->setPreviousElement(tempElement);
                delete toBeRemoved;
            }
            else{
                tempElement->nullifyNextElement();
                this->lastElement=tempElement;
                delete toBeRemoved;
            }
        }
        if(tempElement->getNextElement()!=NULL){
            tempElement=tempElement->getNextElement();
        }
    }
    this->size--;
}
template<class E>
void List<E>::displayList(){
    if(this->isEmpty())
        cout << "[EMPTY LIST]" << endl;
    else{
        Element<E>* tempElement=this->firstElement;
        cout << "[";
        while(tempElement->getNextElement()!=NULL){
            cout << tempElement->getValue() << ", ";
            tempElement=tempElement->getNextElement();
        }
        cout << this->lastElement->getValue() << "]" << endl;
    }
}
template<class E>
Element<E>* List<E>::getFirstElement(){
    return this->firstElement;
}
template<class E>
Element<E>* List<E>::getLastElement(){
    return this->lastElement;
}
template<class E>
bool List<E>::isElement(E element){
    Element<E>* tempElement=this->firstElement;
    while(tempElement!=NULL){
        if(tempElement->getValue()==element)
            return true;
        else
            tempElement=tempElement->getNextElement();
    }
    return false;
}
template<class E>
bool List<E>::isElement(E element,E& retElement){
    if(!this->isEmpty()){
        Element<E>* tempElement=this->firstElement;
        while(tempElement!=NULL){
            if(tempElement->getValue().substr(2)==element){
                retElement=tempElement->getValue();
                return true;
            }
            else{
                tempElement=tempElement->getNextElement();
            }
        }
    }
    return false;
}
template<class E>
unsigned int List<E>::getSize(){
    return this->size;
}

class GrammarVariable{
private:
    string variable;
    List<string> productions;
public:
    GrammarVariable();
    GrammarVariable(string);
    void setVariable(string);
    string getVariable();
    void setProductions(List<string>);
    void setProductions(string);
    List<string> getProductions();
    void addProduction(string);
    List<string>* getProductionsPointer();
};
GrammarVariable::GrammarVariable(string production){
    unsigned int len=production.length();
    string p="";
    for(unsigned int i=0;i<len;i++){
        char c=production[i];
        if(c==':'){
            this->variable=p;
            p="";
        }
        else if(c=='|'){
            this->productions.add(p);
            p="";
        }
        else if(i==len-1){
            p+=c;
            this->productions.add(p);
        }
        else
            p+=c;
    }
}
void GrammarVariable::setVariable(string var){
    this->variable=var;
}
string GrammarVariable::getVariable(){
    return this->variable;
}
void GrammarVariable::setProductions(List<string> prod){
    this->productions=prod;
}
void GrammarVariable::setProductions(string prod){
    unsigned int len=prod.length();
    string p="";
    for(unsigned int i=0;i<len;i++){
        char c=prod[i];
        if(c=='|'){
            this->productions.add(p);
            p="";
        }
        else if(i==len-1){
            p+=c;
            this->productions.add(p);
        }
        else
            p+=c;
    }
}
List<string> GrammarVariable::getProductions(){
    return this->productions;
}
List<string>* GrammarVariable::getProductionsPointer(){
    return &this->productions;
}
void GrammarVariable::addProduction(string prod){
    this->productions.add(prod);
}

void shortenProduction(Element<string>* production,List<string>* newVariables,unsigned int& n){
    char id='Z'+1-n;
    n++;
    string tmpProd=production->getValue();
    production->setValue(tmpProd.substr(0,1)+id);
    string newVar="";
    newVar+=id;
    newVar+=":"+tmpProd.substr(1);
    newVariables->add(newVar);
}

void removeTerminal(Element<string>* production,List<string>* newVariables,unsigned int& n){
    char id='Z'+1-n;
    n++;
    string tmpProd=production->getValue();
    char c=tmpProd[0];
    string newVar="";
    newVar+=id;
    newVar+=":";
    if(c>='a' && c<='z'){
        newVar+=c;
    }
    else{
        newVar+=tmpProd[1];
    }
    string foundElem="";
    if(newVariables->isElement(newVar.substr(2),foundElem)){
        if(foundElem!=""){
            string newId=foundElem.substr(0,1);
            if(c>='a' && c<='z')
                production->setValue(newId+tmpProd.substr(1,1));
            else
                production->setValue(tmpProd.substr(0,1)+newId);
        }
    }
    else{
        if(c>='a' && c<='z')
            production->setValue(id+tmpProd.substr(1,1));
        else
            production->setValue(tmpProd.substr(0,1)+id);
        newVariables->add(newVar);
    }
    //delete tmpProd;
}

bool hasTerminalValue(string production){
    if(production.length()!=1){
        char c=production[0];
        if(c>='a' && c<='z'){
            return true;
        }
        else{
            c=production[1];
            if(c>='a' && c<='z')
                return true;
        }
    }
    return false;
}

GrammarVariable** cnf(GrammarVariable** inGrammar,unsigned int inNoVariables,unsigned int& newSize){
    List<string>* listOfProductions;
    List<string>* newVariables=new List<string>();
    unsigned int n=inNoVariables;
    for(unsigned int i=0;i<inNoVariables;i++){
        listOfProductions=inGrammar[i]->getProductionsPointer();
        Element<string>* tmpElem=listOfProductions->getFirstElement();
        while(tmpElem->getNextElement()!=NULL){
            if(tmpElem->getValue().length()>2){
                shortenProduction(tmpElem,newVariables,n);
            }
            tmpElem=tmpElem->getNextElement();
        }
        tmpElem=listOfProductions->getLastElement();
        if(tmpElem->getValue().length()>2){
            shortenProduction(tmpElem,newVariables,n);
        }
    }

    unsigned int sizeAddon=newVariables->getSize();
    newSize=inNoVariables+sizeAddon;
    GrammarVariable** resultGrammar1=new GrammarVariable*[newSize];
    for(unsigned int i=0;i<inNoVariables;i++){
        resultGrammar1[i]=inGrammar[i];
    }
    Element<string>* tmpElem=newVariables->getFirstElement();
    for(unsigned int i=inNoVariables;i<newSize;i++){
        resultGrammar1[i]=new GrammarVariable(tmpElem->getValue());
        tmpElem=tmpElem->getNextElement();
    }

    List<string>* newVariables2=new List<string>();
    unsigned int m=newSize;
    for(unsigned int i=0;i<newSize;i++){
        listOfProductions=resultGrammar1[i]->getProductionsPointer();
        Element<string>* tmpElem=listOfProductions->getFirstElement();
        while(tmpElem->getNextElement()!=NULL){
            if(hasTerminalValue(tmpElem->getValue())){
                removeTerminal(tmpElem,newVariables2,m);
            }
            tmpElem=tmpElem->getNextElement();
        }
        tmpElem=listOfProductions->getLastElement();
        if(hasTerminalValue(tmpElem->getValue())){
            removeTerminal(tmpElem,newVariables2,m);
        }
    }

    sizeAddon=newVariables2->getSize();
    unsigned int prevSize=newSize;
    newSize+=sizeAddon;
    GrammarVariable** resultGrammar2=new GrammarVariable*[newSize];
    for(unsigned int i=0;i<prevSize;i++){
        resultGrammar2[i]=resultGrammar1[i];
    }
    tmpElem=newVariables2->getFirstElement();
    for(unsigned int i=prevSize;i<newSize;i++){
        resultGrammar2[i]=new GrammarVariable(tmpElem->getValue());
        tmpElem=tmpElem->getNextElement();
    }
    delete newVariables;
    delete newVariables2;
    delete[]resultGrammar1;
    return resultGrammar2;
}

void cykAlgorithm(string word,GrammarVariable** grammar,unsigned int noVariables){
    unsigned int wordLen=word.length();
    bool cykTable[wordLen][wordLen][noVariables];
    for(unsigned int i=0;i<wordLen;i++)
        for(unsigned int j=0;j<wordLen;j++)
            for(unsigned int k=0;k<noVariables;k++)
                cykTable[i][j][k]=false;

    for(unsigned int i=0;i<wordLen;i++){
        string a=word.substr(i,1);
        for(unsigned int v=0;v<noVariables;v++){
            if(grammar[v]->getProductions().isElement(a)){
                cykTable[0][i][v]=true;
            }
        }
    }

    for(unsigned int i=1;i<wordLen;i++){
        for(unsigned int j=0;j<wordLen-i;j++){
            for(unsigned int a=0;a<noVariables;a++){
                List<string> vProductions=grammar[a]->getProductions();
                for(unsigned int b=0;b<noVariables;b++){
                    for(unsigned int c=0;c<noVariables;c++){
                        if(cykTable[0][j][b] && cykTable[i-1][j+1][c]){
                            string nonTerm="";
                            nonTerm+=grammar[b]->getVariable();
                            nonTerm+=grammar[c]->getVariable();
                            if(vProductions.isElement(nonTerm)){
                                cykTable[i][j][a]=true;
                            }
                        }
                        if(cykTable[i-1][j][b] && cykTable[0][j+i][c]){
                            string nonTerm="";
                            nonTerm+=grammar[b]->getVariable();
                            nonTerm+=grammar[c]->getVariable();
                            if(vProductions.isElement(nonTerm)){
                                cykTable[i][j][a]=true;
                            }
                        }
                        if(i>=3 && (i+1)%2==0 && (j+((i+1)/2))<wordLen-(i/2)){
                            if(cykTable[i/2][j][b] && cykTable[i/2][j+((i+1)/2)][c]){
                                string nonTerm="";
                                nonTerm+=grammar[b]->getVariable();
                                nonTerm+=grammar[c]->getVariable();
                                if(vProductions.isElement(nonTerm)){
                                    cykTable[i][j][a]=true;
                                }
                            }
                        }
                        else if(i>=4 && (i+1)%2!=0 && j+(i/2)<wordLen-(i/2) && j+(i/2)+1<wordLen-(i/2)){
                            if(cykTable[(i/2)-1][j][b] && cykTable[i/2][j+(i/2)][c]){
                                string nonTerm="";
                                nonTerm+=grammar[b]->getVariable();
                                nonTerm+=grammar[c]->getVariable();
                                if(vProductions.isElement(nonTerm)){
                                    cykTable[i][j][a]=true;
                                }
                            }
                            if(cykTable[i/2][j][b] && cykTable[(i/2)-1][j+(i/2)+1][c]){
                                string nonTerm="";
                                nonTerm+=grammar[b]->getVariable();
                                nonTerm+=grammar[c]->getVariable();
                                if(vProductions.isElement(nonTerm)){
                                    cykTable[i][j][a]=true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if(cykTable[wordLen-1][0][0])
        cout << "tak" << endl;
    else
        cout << "nie" << endl;
}

int main(){
    string word;
    unsigned int noVar;

    cin >> word;
    cin >> noVar;

    string inputProduction;
    GrammarVariable** grammar=new GrammarVariable*[noVar];

    for(unsigned int i=0;i<noVar;i++){
        cin >> inputProduction;
        grammar[i]=new GrammarVariable(inputProduction);
    }

    /*for(unsigned int i=0;i<noVar;i++){
        cout << grammar[i]->getVariable() << ":";
        grammar[i]->getProductions().displayList();
    }
    cout << endl;*/

    unsigned int newNoVar;
    GrammarVariable** newGrammar=cnf(grammar,noVar,newNoVar);
    delete[]grammar;
    /*for(unsigned int i=0;i<newNoVar;i++){
        cout << newGrammar[i]->getVariable() << ":";
        newGrammar[i]->getProductions().displayList();
    }*/

    cykAlgorithm(word,newGrammar,newNoVar);

    for(int i=0;i<newNoVar;i++){
        delete newGrammar[i];
    }

    delete[]newGrammar;

    return 0;
}
