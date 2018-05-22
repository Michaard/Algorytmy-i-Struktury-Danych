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
public:
    List();
    bool isEmpty();
    void add(E);
    void rem(E);
    void displayList();
    Element<E>* getLastElement();
};
template<class E>
List<E>::List(){
    this->firstElement=NULL;
    this->lastElement=NULL;
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
Element<E>* List<E>::getLastElement(){
    return this->lastElement;
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

class Knot{
private:
    string word;
    List<int> lines;
    Knot* leftDesc;
    Knot* rightDesc;
    Knot* ancestor;
public:
    Knot(string,int);
    Knot* getLeftDesc();
    Knot* getRightDesc();
    Knot* getAncestor();
    List<int> getLines();
    string getWord();
    void setLeftDesc(Knot*);
    void setRightDesc(Knot*);
    void setAncestor(Knot*);
    void addLine(int);
    void setWord(string);
    void displayKnot();
    void nullifyAncestor();
    void nullifyLeftDesc();
    void nullifyRightDesc();
};
Knot::Knot(string word,int line){
    this->word=word;
    this->lines.add(line);
    this->leftDesc=NULL;
    this->rightDesc=NULL;
    this->ancestor=NULL;
}
Knot* Knot::getLeftDesc(){
    return this->leftDesc;
}
Knot* Knot::getRightDesc(){
    return this->rightDesc;
}
Knot* Knot::getAncestor(){
    return this->ancestor;
}
List<int> Knot::getLines(){
    return this->lines;
}
string Knot::getWord(){
    return this->word;
}
void Knot::setLeftDesc(Knot* knot){
    this->leftDesc=knot;
}
void Knot::setRightDesc(Knot* knot){
    this->rightDesc=knot;
}
void Knot::setAncestor(Knot* knot){
    this->ancestor=knot;
}
void Knot::addLine(int line){
    this->lines.add(line);
}
void Knot::setWord(string word){
    this->word=word;
}
void Knot::displayKnot(){
    cout << word << " =>";
    lines.displayList();
}
void Knot::nullifyAncestor(){
    this->ancestor=NULL;
}
void Knot::nullifyLeftDesc(){
    this->leftDesc=NULL;
}
void Knot::nullifyRightDesc(){
    this->rightDesc=NULL;
}

class BSTree{
private:
    Knot* root;
public:
    BSTree();
    bool isEmpty();
    void findOrAddKnot(string,int);
    void displayInOrder(Knot*);
    void displayTree();
    Knot* minimum(Knot*);
    Knot* nextKnot(Knot*);
    void rem(Knot*);
};
BSTree::BSTree(){
    this->root=NULL;
}
bool BSTree::isEmpty(){
    if(this->root==NULL)
        return true;
    else
        return false;
}
void BSTree::findOrAddKnot(string word,int line){
    if(this->isEmpty()){
        Knot* newKnot=new Knot(word,line);
        this->root=newKnot;
    }
    else{
        Knot* currentKnot=this->root;
        Knot* previousKnot;
        while(currentKnot!=NULL){
            if(word.compare(currentKnot->getWord())<0){
                previousKnot=currentKnot;
                currentKnot=currentKnot->getLeftDesc();
            }
            else if(word.compare(currentKnot->getWord())>0){
                previousKnot=currentKnot;
                currentKnot=currentKnot->getRightDesc();
            }
            else{
                if(currentKnot->getLines().getLastElement()->getValue()!=line)
                    currentKnot->addLine(line);
                return;
            }
        }
        Knot* newKnot=new Knot(word,line);
        if(word.compare(previousKnot->getWord())<0){
            previousKnot->setLeftDesc(newKnot);
        }
        else{
            previousKnot->setRightDesc(newKnot);
        }
        newKnot->setAncestor(previousKnot);
    }
}
void BSTree::displayInOrder(Knot* knot){
    Knot* leftSubTree=knot->getLeftDesc();
    if(leftSubTree!=NULL)
        displayInOrder(leftSubTree);
    knot->displayKnot();
    Knot* rightSubTree=knot->getRightDesc();
    if(rightSubTree!=NULL)
        displayInOrder(rightSubTree);
}
void BSTree::displayTree(){
    this->displayInOrder(this->root);
}
Knot* BSTree::minimum(Knot* knot){
    Knot* descendant=knot->getLeftDesc();
    while(descendant!=NULL)
        descendant=descendant->getLeftDesc();
    return descendant;
}
Knot* BSTree::nextKnot(Knot* knot){
    Knot* rightSubTree=knot->getRightDesc();
    if(rightSubTree!=NULL)
        return this->minimum(rightSubTree);
    else{
        Knot* tempKnot=knot;
        Knot* tempAncestor=tempKnot->getAncestor();
        while(tempAncestor->getRightDesc()==tempKnot && tempAncestor!=NULL){
            tempKnot=tempAncestor;
            tempAncestor=tempAncestor->getAncestor();
        }
        return tempAncestor;
    }
}
void BSTree::rem(Knot* knot){
    if(knot->getLeftDesc()==NULL && knot->getRightDesc()==NULL){
        if(knot->getAncestor()==NULL)
            this->root=NULL;
        else{
            if(knot->getAncestor()->getLeftDesc()==knot)
                knot->getAncestor()->nullifyLeftDesc();
            else
                knot->getAncestor()->nullifyRightDesc();
        }
    }
    else if(knot->getLeftDesc()==NULL || knot->getRightDesc()==NULL){
        Knot* descendant;
        if(knot->getLeftDesc()!=NULL)
            descendant=knot->getLeftDesc();
        else
            descendant=knot->getRightDesc();
        descendant->setAncestor(knot->getAncestor());
        if(descendant->getAncestor()==NULL)
            this->root=NULL;
        else{
            if(knot->getAncestor()->getLeftDesc()==knot)
                knot->getAncestor()->setLeftDesc(descendant);
            else
                knot->getAncestor()->setRightDesc(descendant);
        }
    }
    else{
        Knot* next=this->nextKnot(knot);
        knot->setWord(next->getWord());
        knot->getLines()=next->getLines();
        if(next->getLeftDesc()==NULL && next->getRightDesc()==NULL){
            if(next->getAncestor()==NULL)
                this->root=NULL;
            else{
                if(next->getAncestor()->getLeftDesc()==next)
                    next->getAncestor()->nullifyLeftDesc();
                else
                    next->getAncestor()->nullifyRightDesc();
            }
        }
        else if(next->getLeftDesc()==NULL || next->getRightDesc()==NULL){
            Knot* descendant;
            if(next->getLeftDesc()!=NULL)
                descendant=next->getLeftDesc();
            else
                descendant=next->getRightDesc();
            descendant->setAncestor(next->getAncestor());
            if(descendant->getAncestor()==NULL)
                this->root=NULL;
            else{
                if(next->getAncestor()->getLeftDesc()==next)
                    next->getAncestor()->setLeftDesc(descendant);
                else
                    next->getAncestor()->setRightDesc(descendant);
            }
        }
    }
}