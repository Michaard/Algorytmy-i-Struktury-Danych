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
        this->lastElement->setNextElement(elem);
        this->lastElement=elem;
    }
}
template<class C>
void Queue<C>::pop(){
    if(!this->isEmpty()){
        Element<C>* tmp=this->firstElement;
        this->firstElement=this->firstElement->getNextElement();
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
    Element<E>* getFirstElement();
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
        while(tempElement->getNextElement()!=NULL){
            cout << tempElement->getValue() << " ";
            tempElement=tempElement->getNextElement();
        }
        cout << this->lastElement->getValue() << endl;
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

template<class K>
class Vertex{
private:
    K key;
    string color;
    Vertex* predecessor;
    int distanceP1;
    int distanceP2;
    List<Vertex<K>*> neighbours;
public:
    Vertex(K);
    K getKey();
    void setKey(K);
    void setColor(string);
    void setPredecessor(Vertex<K>*);
    void setDistanceP1(int);
    void setDistanceP2(int);
    void addNeighbour(Vertex<K>*);
    int getDistanceP1();
    int getDistanceP2();
    string getColor();
    Vertex<K>* getPredecessor();
    List<Vertex<K>*> getNeighbours();
};
template<class K>
Vertex<K>::Vertex(K key){
    this->key=key;
    this->predecessor=NULL;
}
template<class K>
K Vertex<K>::getKey(){
    return this->key;
}
template<class K>
void Vertex<K>::setKey(K key){
    this->key=key;
}
template<class K>
void Vertex<K>::setColor(string color){
    this->color=color;
}
template<class K>
void Vertex<K>::setPredecessor(Vertex<K>* v){
    this->predecessor=v;
}
template<class K>
void Vertex<K>::setDistanceP1(int distance){
    this->distanceP1=distance;
}
template<class K>
void Vertex<K>::setDistanceP2(int distance){
    this->distanceP2=distance;
}
template<class K>
void Vertex<K>::addNeighbour(Vertex<K>* neighbour){
    this->neighbours.add(neighbour);
}
template<class K>
int Vertex<K>::getDistanceP1(){
    return this->distanceP1;
}
template<class K>
int Vertex<K>::getDistanceP2(){
    return this->distanceP2;
}
template<class K>
string Vertex<K>::getColor(){
    return this->color;
}
template<class K>
Vertex<K>* Vertex<K>::getPredecessor(){
    return this->predecessor;
}
template<class K>
List<Vertex<K>*> Vertex<K>::getNeighbours(){
    return this->neighbours;
}

template<class V>
class Graph{
private:
    List<Vertex<V>*> vertexes;
public:
    void addVertex(V);
    void addEdge(V,V);
    void setDistancesP1(V);
    void setDistancesP2(V);
    bool isConnected(V);
    Vertex<V>* getVertex(V);
};
template<class V>
void Graph<V>::addVertex(V vertexKey){
    Vertex<V>* v=new Vertex<V>(vertexKey);
    this->vertexes.add(v);
}
template<class V>
void Graph<V>::addEdge(V vertex1Key,V vertex2Key){
    Vertex<V>* vertex1;
    Vertex<V>* vertex2;
    Element<Vertex<V>*>* tempElement=this->vertexes.getFirstElement();
    Vertex<V>* tempVertex=tempElement->getValue();
    while(tempElement->getNextElement()!=NULL){
        if(tempVertex->getKey()==vertex1Key){
            vertex1=tempVertex;
            if(vertex1Key==vertex2Key)
                vertex2=vertex1;
        }
        else if(tempVertex->getKey()==vertex2Key)
            vertex2=tempVertex;
        tempElement=tempElement->getNextElement();
        tempVertex=tempElement->getValue();
    }
    if(tempVertex->getKey()==vertex1Key){
        vertex1=tempVertex;
        if(vertex1Key==vertex2Key)
            vertex2=vertex1;
    }
    else if(tempVertex->getKey()==vertex2Key)
        vertex2=tempVertex;
    vertex1->addNeighbour(vertex2);
    vertex2->addNeighbour(vertex1);
}
template<class V>
void Graph<V>::setDistancesP1(V startingVertexKey){
    Vertex<V>* startingVertex;
    Element<Vertex<V>*>* tempElement=this->vertexes.getFirstElement();
    Vertex<V>* tempVertex=tempElement->getValue();
    while(tempElement->getNextElement()!=NULL){
        if(tempVertex->getKey()==startingVertexKey){
            tempVertex->setColor("grey");
            tempVertex->setDistanceP1(0);
            startingVertex=tempVertex;
        }
        else{
            tempVertex->setColor("white");
            tempVertex->setDistanceP1(-1);
        }
        tempElement=tempElement->getNextElement();
        tempVertex=tempElement->getValue();
    }
    if(tempVertex->getKey()==startingVertexKey){
        tempVertex->setColor("grey");
        tempVertex->setDistanceP1(0);
        startingVertex=tempVertex;
    }
    else{
        tempVertex->setColor("white");
        tempVertex->setDistanceP1(-1);
    }
    Queue<Vertex<V>*> vertexQueue;
    Vertex<V>* u;
    Vertex<V>* v;
    vertexQueue.push(startingVertex);
    while(!vertexQueue.isEmpty()){
        u=vertexQueue.top();
        List<Vertex<V>*> uNeighbours=u->getNeighbours();
        if(!uNeighbours.isEmpty()){
            tempElement=uNeighbours.getFirstElement();
            Vertex<V>* tempNeighbourOfU=tempElement->getValue();
            while(tempElement->getNextElement()!=NULL){
                v=tempNeighbourOfU;
                if(v->getColor()=="white"){
                    v->setColor("grey");
                    v->setDistanceP1(u->getDistanceP1()+1);
                    v->setPredecessor(u);
                    vertexQueue.push(v);
                }
                tempElement=tempElement->getNextElement();
                tempNeighbourOfU=tempElement->getValue();
            }
            v=tempNeighbourOfU;
            if(v->getColor()=="white"){
                v->setColor("grey");
                v->setDistanceP1(u->getDistanceP1()+1);
                v->setPredecessor(u);
                vertexQueue.push(v);
            }
        }
        vertexQueue.pop();
        u->setColor("black");
    }
}
template<class V>
void Graph<V>::setDistancesP2(V startingVertexKey){
    Vertex<V>* startingVertex;
    Element<Vertex<V>*>* tempElement=this->vertexes.getFirstElement();
    Vertex<V>* tempVertex=tempElement->getValue();
    while(tempElement->getNextElement()!=NULL){
        if(tempVertex->getKey()==startingVertexKey){
            tempVertex->setColor("grey");
            tempVertex->setDistanceP2(0);
            startingVertex=tempVertex;
        }
        else{
            tempVertex->setColor("white");
            tempVertex->setDistanceP2(-1);
        }
        tempElement=tempElement->getNextElement();
        tempVertex=tempElement->getValue();
    }
    if(tempVertex->getKey()==startingVertexKey){
        tempVertex->setColor("grey");
        tempVertex->setDistanceP2(0);
        startingVertex=tempVertex;
    }
    else{
        tempVertex->setColor("white");
        tempVertex->setDistanceP2(-1);
    }
    Queue<Vertex<V>*> vertexQueue;
    Vertex<V>* u;
    Vertex<V>* v;
    vertexQueue.push(startingVertex);
    while(!vertexQueue.isEmpty()){
        u=vertexQueue.top();
        List<Vertex<V>*> uNeighbours=u->getNeighbours();
        if(!uNeighbours.isEmpty()){
            tempElement=uNeighbours.getFirstElement();
            Vertex<V>* tempNeighbourOfU=tempElement->getValue();
            while(tempElement->getNextElement()!=NULL){
                v=tempNeighbourOfU;
                if(v->getColor()=="white"){
                    v->setColor("grey");
                    v->setDistanceP2(u->getDistanceP2()+1);
                    v->setPredecessor(u);
                    vertexQueue.push(v);
                }
                tempElement=tempElement->getNextElement();
                tempNeighbourOfU=tempElement->getValue();
            }
            v=tempNeighbourOfU;
            if(v->getColor()=="white"){
                v->setColor("grey");
                v->setDistanceP2(u->getDistanceP2()+1);
                v->setPredecessor(u);
                vertexQueue.push(v);
            }
        }
        vertexQueue.pop();
        u->setColor("black");
    }
}
template<class V>
bool Graph<V>::isConnected(V vertexKey){
    Vertex<V>* vertex;
    Element<Vertex<V>*>* tempElement=this->vertexes.getFirstElement();
    Vertex<V>* tempVertex=tempElement->getValue();
    while(tempElement->getNextElement()!=NULL){
        if(tempVertex->getKey()==vertexKey)
            vertex=tempVertex;
        tempElement=tempElement->getNextElement();
        tempVertex=tempElement->getValue();
    }
    if(tempVertex->getKey()==vertexKey)
        vertex=tempVertex;
    if(vertex->getDistanceP1()==-1 && vertex->getDistanceP2()==-1)
        return false;
    else
        return true;
}
template<class V>
Vertex<V>* Graph<V>::getVertex(V vertexKey){
    Vertex<V>* vertex;
    Element<Vertex<V>*>* tempElement=this->vertexes.getFirstElement();
    Vertex<V>* tempVertex=tempElement->getValue();
    while(tempElement->getNextElement()!=NULL){
        if(tempVertex->getKey()==vertexKey){
            vertex=tempVertex;
            return vertex;
        }
        tempElement=tempElement->getNextElement();
        tempVertex=tempElement->getValue();
    }
    if(tempVertex->getKey()==vertexKey)
        vertex=tempVertex;
    else
        return NULL;
    return vertex;
}

int main(){
    Graph<int> graph;
    Queue<int> vertexesToVisit;
    List<int> output;
    int noVertexes, noEdges, noVertexesToVisit;
    int u,v,w;
    int p1,p2;
    cin >> noVertexes;
    for(int i=0;i<noVertexes;i++)
        graph.addVertex(i);
    cin >> noEdges;
    for(int i=0;i<noEdges;i++){
        cin >> u;
        cin >> v;
        graph.addEdge(u,v);
    }
    cin >> p1;
    cin >> p2;
    int movePriority=1;
    cin >> noVertexesToVisit;
    for(int i=0;i<noVertexesToVisit;i++){
        cin >> w;
        vertexesToVisit.push(w);
    }
    int vertexKey;
    while(!vertexesToVisit.isEmpty()){
        vertexKey=vertexesToVisit.top();
        graph.setDistancesP1(p1);
        graph.setDistancesP2(p2);
        if(graph.isConnected(vertexKey)){
            Vertex<int>* vertex=graph.getVertex(vertexKey);
            if(vertex->getDistanceP1()<vertex->getDistanceP2()){
                output.add(1);
                p1=vertex->getKey();
                movePriority=2;
            }
            else if(vertex->getDistanceP1()>vertex->getDistanceP2()){
                output.add(2);
                p2=vertex->getKey();
                movePriority=1;
            }
            else{
                if(movePriority==1){
                    output.add(1);
                    p1=vertex->getKey();
                    movePriority=2;
                }
                else{
                    output.add(2);
                    p2=vertex->getKey();
                    movePriority=1;
                }
            }
        }
        else{
            cout << "Brak po³¹czenia z wierzcho³kiem " << vertexKey << endl;
            return 0;
        }
        vertexesToVisit.pop();
    }
    output.displayList();
    return 0;
}
