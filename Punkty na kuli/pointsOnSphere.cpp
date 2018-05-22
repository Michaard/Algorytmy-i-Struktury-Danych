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
    string key;
    double latitude; //szerokosc geograficzna, dla N dodatnia, dla S ujemna; y
    double longitude; //dlugosc geograficzna, dla E dodatnia, dla W ujemna; x
public:
    Point();
    Point(string key){
        this->key=key;
    }
    Point(string key,int nsDeg,int nsMin,char ns,int ewDeg,int ewMin,char ew){
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
    string getKey(){
        return this->key;
    }
    void setLatitude(double nsDegree,char ns){
        if(ns=='S'){
            nsDegree=-nsDegree;
        }
        this->latitude=degToRad(nsDegree);
    }
    double getLatitude(){
        return this->latitude;
    }
    void setLongitude(double ewDegree,char ew){
        if(ew=='W')
            ewDegree=-ewDegree;
        this->longitude=degToRad(ewDegree);
    }
    double getLongitude(){
        return this->longitude;
    }
    bool gt(Point* p){
        if(this->latitude>p->latitude)
            return true;
        else if(this->latitude==p->latitude)
            return this->longitude>p->longitude;
        else
            return false;
    }
    bool lt(Point* p){
        if(this->latitude<p->latitude)
            return true;
        else if(this->latitude==p->latitude)
            return this->longitude<p->longitude;
        else
            return false;
    }
    bool eq(Point* p){
        return (this->latitude==p->latitude && this->longitude==p->longitude);
    }
};

void mergeElem(Point** pointsArray,unsigned int leftBound,unsigned int rightBound){
	int lb,s;
	int size=rightBound-leftBound+1;
	int halfsize=(size/2)+(size%2);
	Point** tmpPoints=new Point*[halfsize];
	for(lb=leftBound,s=0;s<halfsize;lb++,s++){
		tmpPoints[s]=pointsArray[lb];
	}
	int rb=((leftBound+rightBound)/2)+1;
	for(lb=leftBound,s=0;lb<=rightBound;lb++){
		if(s<halfsize){
			if(rb<=rightBound){
				if(tmpPoints[s]->lt(pointsArray[rb]) || tmpPoints[s]->eq(pointsArray[rb])){
					pointsArray[lb]=tmpPoints[s];
					s++;
				}
				else{
					pointsArray[lb]=pointsArray[rb];
					rb++;
				}
			}
			else{
				pointsArray[lb]=tmpPoints[s];
				s++;
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

/*double ortodroma(Point* p1,Point* p2,double& sphereSize){
    double sinp1=sin(p1->getLatitude());
    double cosp1=cos(p1->getLatitude());
    double sinp2=sin(p2->getLatitude());
    double cosp2=cos(p2->getLatitude());
    float longitudeDifference=(radToDeg(p1->getLongitude())-radToDeg(p2->getLongitude()));
    double cosDL=cos(degToRad(longitudeDifference));
    return acos((sinp1*sinp2)+(cosp1*cosp2*cosDL));
}

double ortodroma(Point* p1,double degreeX,double degreeY,double& sphereSize){
    double sinp1=sin(p1->getLatitude());
    double cosp1=cos(p1->getLatitude());
    double sinp2=sin(degreeX);
    double cosp2=cos(degreeX);
    float longitudeDifference=(radToDeg(p1->getLongitude())-radToDeg(degreeY));
    double cosDL=cos(degToRad(longitudeDifference));
    return acos((sinp1*sinp2)+(cosp1*cosp2*cosDL));
}*/

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
        double minDistance;
        Point** closestPair1=new Point*[2];
        Point** closestPair2=new Point*[2];
        int mid=(beg+end)/2;
        double distance1;
        double distance2;
        double distance3;
        closestPair1=setClosestPair(pointsArray,beg,mid,size,sphereSize);
        closestPair2=setClosestPair(pointsArray,mid+1,end,size,sphereSize);
        distance1=ortodroma(closestPair1[0],closestPair1[1],sphereSize);
        distance2=ortodroma(closestPair2[0],closestPair2[1],sphereSize);
        if(distance1<distance2){
            minDistance=distance1;
            closestPairFinal[0]=closestPair1[0];
            closestPairFinal[1]=closestPair1[1];
        }
        /*else if(distance1==distance2){
            if(closestPair1[0]->getKey().compare(closestPair1[1]->getKey())<0){
                if(closestPair2[0]->getKey().compare(closestPair2[1]->getKey())<0){
                    if(closestPair1[0]->getKey().compare(closestPair2[0]->getKey())<0){
                        closestPairFinal[0]=closestPair1[0];
                        closestPairFinal[1]=closestPair1[1];
                    }
                    else{
                        closestPairFinal[0]=closestPair2[0];
                        closestPairFinal[1]=closestPair2[1];
                    }
                }
                else{
                    if(closestPair1[0]->getKey().compare(closestPair2[1]->getKey())<0){
                        closestPairFinal[0]=closestPair1[0];
                        closestPairFinal[1]=closestPair1[1];
                    }
                    else{
                        closestPairFinal[0]=closestPair2[1];
                        closestPairFinal[1]=closestPair2[0];
                    }
                }
            }
            else{
                if(closestPair2[0]->getKey().compare(closestPair2[1]->getKey())<0){
                    if(closestPair1[1]->getKey().compare(closestPair2[0]->getKey())<0){
                        closestPairFinal[0]=closestPair1[1];
                        closestPairFinal[1]=closestPair1[0];
                    }
                    else{
                        closestPairFinal[0]=closestPair2[0];
                        closestPairFinal[1]=closestPair2[1];
                    }
                }
                else{
                    if(closestPair1[1]->getKey().compare(closestPair2[1]->getKey())<0){
                        closestPairFinal[0]=closestPair1[1];
                        closestPairFinal[1]=closestPair1[0];
                    }
                    else{
                        closestPairFinal[0]=closestPair2[1];
                        closestPairFinal[1]=closestPair2[0];
                    }
                }
            }
        }*/
        else{
            minDistance=distance2;
            closestPairFinal[0]=closestPair2[0];
            closestPairFinal[1]=closestPair2[1];
        }
        vector<Point*> tmpPointsS1;
        vector<Point*> tmpPointsS2;
        //cout << "S1: [ " << pointsArray[beg]->getKey() << " ; " << pointsArray[mid]->getKey() << " ] - mid = " << pointsArray[mid]->getKey() << endl;
        //cout << "S2: [ " << pointsArray[mid+1]->getKey() << " ; " << pointsArray[end]->getKey() << " ] - mid = " << pointsArray[mid]->getKey() << endl;
        //cout << "Min Distance1 = " << minDistance << endl;
        for(int i=beg;i<=end;i++){
            if(ortodroma(pointsArray[i],pointsArray[mid]->getLatitude(),pointsArray[i]->getLongitude(),sphereSize) < minDistance){
                //cout << "Umieszczam " << pointsArray[i]->getKey() << endl;
                tmpPointsS1.push_back(pointsArray[i]);
            }
        }
        /*tmpPointsS1.push_back(pointsArray[mid]);
        for(int i=mid+1;i<=end;i++){
            if(ortodroma(pointsArray[i],pointsArray[mid]->getLatitude(),pointsArray[i]->getLongitude(),sphereSize) < minDistance){
                //cout << "Umieszczam " << pointsArray[i]->getKey() << endl;
                tmpPointsS2.push_back(pointsArray[i]);
            }
        }*/
        vector<Point*>::iterator it1;
        vector<Point*>::iterator it2;
        for(it1=tmpPointsS1.begin();it1<tmpPointsS1.end();it1++){
            Point* p1=*it1;
            for(it2=tmpPointsS2.begin();it2<tmpPointsS2.end();it2++){
                Point* p2=*it2;
                distance3=ortodroma(p1,p2,sphereSize);
                if(distance3<minDistance){
                    minDistance=distance3;
                    closestPairFinal[0]=p1;
                    closestPairFinal[1]=p2;
                }
                /*else if(distance3==minDistance){
                    if(p1->getKey().compare(p2->getKey())<0){
                        if(closestPairFinal[0]->getKey().compare(closestPairFinal[1]->getKey())<0){
                            if(p1->getKey().compare(closestPairFinal[0]->getKey())<0){
                                closestPairFinal[0]=p1;
                                closestPairFinal[1]=p2;
                            }
                        }
                        else{
                            if(p1->getKey().compare(closestPairFinal[1]->getKey())<0){
                                closestPairFinal[0]=p1;
                                closestPairFinal[1]=p2;
                            }
                        }
                    }
                    else{
                        if(closestPairFinal[0]->getKey().compare(closestPairFinal[1]->getKey())<0){
                            if(p2->getKey().compare(closestPairFinal[0]->getKey())<0){
                                closestPairFinal[0]=p2;
                                closestPairFinal[1]=p1;
                            }
                        }
                        else{
                            if(p2->getKey().compare(closestPairFinal[1]->getKey())<0){
                                closestPairFinal[0]=p2;
                                closestPairFinal[1]=p1;
                            }
                        }
                    }
                }*/
            }
        }
        //cout << "Closest pair: " << closestPairFinal[0]->getKey() << " - " << closestPairFinal[1]->getKey() << endl;
        //cout << "Min Distance2 = " << minDistance << endl;
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
        string key;
        int nsdeg,nsmin,ewdeg,ewmin;
        char ns,ew;
        cin >> key;
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
    if(closestPair[0]->getKey().compare(closestPair[1]->getKey())<0)
        cout << closestPair[0]->getKey() << " " << closestPair[1]->getKey() << endl;
    else
        cout << closestPair[1]->getKey() << " " << closestPair[0]->getKey() << endl;
//    cout << points[1]->getKey() << " " << points[0]->getKey() << endl;
/*    if(points[0]->getKey().compare(points[1]->getKey())<0)
        cout << points[0]->getKey() << " " << points[1]->getKey() << endl;
    else
        cout << points[1]->getKey() << " " << points[0]->getKey() << endl;*/
    for(int i=0;i<noPoints;i++){
        delete points[i];
    }
    delete[]points;
    delete[]closestPair;
/*    float sizeOfSphere=40075;
    Point* p1=new Point("P01",0,50,'N',8,0,'E');
    Point* p2=new Point("P02",1,10,'N',8,0,'E');
    Point* p3=new Point("P15",1,0,'N',3,0,'W');
    Point* p4=new Point("P16",2,0,'N',2,0,'W');
    cout << ortodroma(p1,p2,sizeOfSphere) << endl;
    cout << ortodroma(p3,p4,sizeOfSphere) << endl;*/
    return 0;
}
