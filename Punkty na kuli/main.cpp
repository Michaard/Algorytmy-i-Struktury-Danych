#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double countDegree(int degree,int minute){
    return degree+(minute/60.0);
}

double degToRad(double angle){
    return angle*M_PI/180.0;
}

double radToDeg(double angle){
    return angle*180.0/M_PI;
}

class Point{
private:
    const char* key;
    double latitude; //szerokosc geograficzna, dla N dodatnia, dla S ujemna; x
    double longitude; //dlugosc geograficzna, dla E dodatnia, dla W ujemna; y
public:
    Point();
    Point(const char* key);
    Point(const char* key,int nsDeg,int nsMin,char ns,int ewDeg,int ewMin,char ew);
    const char* getKey();
    void setLatitude(double nsDegree,char ns);
    double getLatitude();
    void setLongitude(double ewDegree,char ew);
    double getLongitude();
    bool gt(Point* p);
    bool lt(Point* p);
    bool eq(Point* p);
};
Point::Point(const char* key){
    this->key=key;
}
Point::Point(const char* key,int nsDeg,int nsMin,char ns,int ewDeg,int ewMin,char ew){
    this->key=key;
    double nsDegree=countDegree(nsDeg,nsMin);
    if(ns=='S'){
        nsDegree=-nsDegree;
    }
    this->latitude=degToRad(nsDegree);
    double ewDegree=countDegree(ewDeg,ewMin);
    if(ew=='W')
        ewDegree=-ewDegree;
    this->longitude=degToRad(ewDegree);
}
const char* Point::getKey(){
    return this->key;
}
void Point::setLatitude(double nsDegree,char ns){
    if(ns=='S'){
        nsDegree=-nsDegree;
    }
    this->latitude=degToRad(nsDegree);
}
double Point::getLatitude(){
    return this->latitude;
}
void Point::setLongitude(double ewDegree,char ew){
    if(ew=='W')
        ewDegree=-ewDegree;
    this->longitude=degToRad(ewDegree);
}
double Point::getLongitude(){
    return this->longitude;
}
bool Point::gt(Point* p){
    if(this->latitude>p->latitude)
        return true;
    else if(this->latitude==p->latitude)
        return this->longitude>p->longitude;
    else
        return false;
}
bool Point::lt(Point* p){
    if(this->latitude<p->latitude)
        return true;
    else if(this->latitude==p->latitude)
        return this->longitude<p->longitude;
    else
        return false;
}
bool Point::eq(Point* p){
    return (this->latitude==p->latitude && this->longitude==p->longitude);
}

void mergeElem(Point** pointsArray,unsigned int leftBound,unsigned int rightBound){
	int size=rightBound-leftBound+1;
	int halfsize=(size/2)+(size%2);
	Point** tmpPoints=new Point*[halfsize];
	int lb,sb;
	for(lb=leftBound,sb=0;sb<halfsize;lb++,sb++){
		tmpPoints[sb]=pointsArray[lb];
	}
	int rb=((leftBound+rightBound)/2)+1;
	for(lb=leftBound,sb=0;lb<=rightBound;lb++){
		if(sb<halfsize){
			if(rb<=rightBound){
				if(tmpPoints[sb]->lt(pointsArray[rb]) || tmpPoints[sb]->eq(pointsArray[rb])){
					pointsArray[lb]=tmpPoints[sb];
					sb++;
				}
				else{
					pointsArray[lb]=pointsArray[rb];
					rb++;
				}
			}
			else{
				pointsArray[lb]=tmpPoints[sb];
				sb++;
			}
		}
		else{
			pointsArray[lb]=pointsArray[rb];
			rb++;
		}
	}
	delete[]tmpPoints;
	return;
}

void mergeSort(Point** pointsArray,int beg,int end){
	if(beg==end)
		return;
	else{
		int mid=(beg+end)/2;
		mergeSort(pointsArray,beg,mid);
		mergeSort(pointsArray,mid+1,end);
		mergeElem(pointsArray,beg,end);
	}
	return;
}

double ortodroma(Point* p1,Point* p2,double& sphereSize){
    double x1=radToDeg(p1->getLatitude());
    double x2=radToDeg(p2->getLatitude());
    double y1=radToDeg(p1->getLongitude());
    double y2=radToDeg(p2->getLongitude());
    double difXpow2=pow(x2-x1,2);
    double difY=y2-y1;
    double cosX1=cos(degToRad(x1));
    double sqrtVal=sqrt(difXpow2+pow((cosX1*difY),2));
    return sqrtVal*sphereSize/360.0;
}

double ortodroma(Point* p1,double degX,double degY,double& sphereSize){
    double x1=radToDeg(p1->getLatitude());
    double x2=radToDeg(degX);
    double y1=radToDeg(p1->getLongitude());
    double y2=radToDeg(degY);
    double difXpow2=pow(x2-x1,2);
    double difY=y2-y1;
    double cosX1=cos(degToRad(x1));
    double sqrtVal=sqrt(difXpow2+pow((cosX1*difY),2));
    return sqrtVal*sphereSize/360.0;
}

Point** setClosestPair(Point** pointsArray,int beg,int end,int& size,double& sphereSize){
    Point** closestPairFinal=new Point*[2];
    if(beg==end){
        closestPairFinal[0]=pointsArray[beg];
        if(beg<size-1)
            closestPairFinal[1]=pointsArray[beg+1];
        else
            closestPairFinal[1]=pointsArray[0];
    }
    else{
        Point** closestPair1=new Point*[2];
        Point** closestPair2=new Point*[2];
        int mid=(beg+end)/2;
        double minDistance;
        double distanceS1;
        double distanceS2;
        double distanceS12;
        closestPair1=setClosestPair(pointsArray,beg,mid,size,sphereSize);
        closestPair2=setClosestPair(pointsArray,mid+1,end,size,sphereSize);
        distanceS1=ortodroma(closestPair1[0],closestPair1[1],sphereSize);
        distanceS2=ortodroma(closestPair2[0],closestPair2[1],sphereSize);
        if(distanceS1<distanceS2){
            minDistance=distanceS1;
            closestPairFinal[0]=closestPair1[0];
            closestPairFinal[1]=closestPair1[1];
        }
        else{
            minDistance=distanceS2;
            closestPairFinal[0]=closestPair2[0];
            closestPairFinal[1]=closestPair2[1];
        }
        vector<Point*> tmpPointsS1;
        vector<Point*> tmpPointsS2;
        for(int i=beg;i<=mid;i++){
            if(ortodroma(pointsArray[i],pointsArray[mid]->getLatitude(),pointsArray[i]->getLongitude(),sphereSize) < minDistance){
                tmpPointsS1.push_back(pointsArray[i]);
            }
        }
        for(int i=mid+1;i<=end;i++){
            if(ortodroma(pointsArray[i],pointsArray[mid]->getLatitude(),pointsArray[i]->getLongitude(),sphereSize) < minDistance){
                tmpPointsS2.push_back(pointsArray[i]);
            }
        }
        vector<Point*>::iterator it1;
        vector<Point*>::iterator it2;
        for(it1=tmpPointsS1.begin();it1<tmpPointsS1.end();it1++){
            Point* p1=*it1;
            for(it2=tmpPointsS2.begin();it2<tmpPointsS2.end();it2++){
                Point* p2=*it2;
                distanceS12=ortodroma(p1,p2,sphereSize);
                if(distanceS12<minDistance){
                    minDistance=distanceS12;
                    closestPairFinal[0]=p1;
                    closestPairFinal[1]=p2;
                }
            }
        }
    }
    return closestPairFinal;
}

int main(){
    int noPoints;
    double sizeOfSphere;
    cin >> noPoints;
    cin >> sizeOfSphere;
    Point** points=new Point*[noPoints];
    for(int i=0;i<noPoints;i++){
        int nsdeg,nsmin,ewdeg,ewmin;
        char* key=new char[4];
        char keyLetter,ns,ew;
        for(int k=0;k<3;k++){
            cin >> keyLetter;
            key[k]=keyLetter;
        }
        key[3]='\0';
        cin >> nsdeg;
        cin >> nsmin;
        cin >> ns;
        cin >> ewdeg;
        cin >> ewmin;
        cin >> ew;
        points[i]=new Point(key,nsdeg,nsmin,ns,ewdeg,ewmin,ew);
    }
    mergeSort(points,0,noPoints-1);
    Point** closestPair=new Point*[2];
    closestPair=setClosestPair(points,0,noPoints-1,noPoints,sizeOfSphere);
    const char* p1=closestPair[0]->getKey();
    const char* p2=closestPair[1]->getKey();
    if(p1[0]<p2[0])
        cout << p1 << " " << p2 << endl;
    else if(p1[0]>p2[0])
        cout << p2 << " " << p1 << endl;
    else{
        if(p1[1]<p2[1])
            cout << p1 << " " << p2 << endl;
        else if(p1[1]>p2[1])
            cout << p2 << " " << p1 << endl;
        else{
            if(p1[2]<p2[2])
                cout << p1 << " " << p2 << endl;
            else if(p1[2]>p2[2])
                cout << p2 << " " << p1 << endl;
            else
                cout << p1 << " " << p2 << endl;
        }
    }
    for(int i=0;i<noPoints;i++){
        delete points[i];
    }
    delete[]points;
    delete[]closestPair;
    return 0;
}
