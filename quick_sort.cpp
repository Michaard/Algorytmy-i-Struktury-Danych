#include <iostream>

int setIndex(int *tab,int strt,int fin){
    int bg=strt-1;
    int the_index=fin+1;
    int key=tab[fin];
    int store;
    while(true){
        do the_index--; while(tab[the_index]>key);
        do bg++; while(tab[bg]<key);
        if(bg<=the_index){
            store=tab[bg];
            tab[bg]=tab[the_index];
            tab[the_index]=store;
        }
        else
            return the_index;
    }
}

void mg_qsort(int *tab,int beg,int en){
    if(beg<en){
        int j=setIndex(tab,beg,en);
        mg_qsort(tab,beg,j);
        mg_qsort(tab,j+1,en);
    }
    return;
}

int find_min_dif(int *tab,int size){
	int min_dif,dif;
	if(tab[0]>tab[1])
		min_dif=tab[0]-tab[1];
	else
		min_dif=tab[1]-tab[0];
	for(int i=1;i<size-1;i++){
		if(min_dif==1)
			return min_dif;
		else if(tab[i]>tab[i+1])
			dif=tab[i]-tab[i+1];
		else
			dif=tab[i+1]-tab[i];
		if(dif<min_dif)
				min_dif=dif;
	}
	return min_dif;
}

int main(){
	int siz;
	std::cin >> siz;
	int *lst=new int[siz];
	for(int i=0;i<siz;i++){
		std::cin >> lst[i];
	}
	mg_qsort(lst,0,siz-1);
	int min_dif=find_min_dif(lst,siz);

	for(int i=0;i<siz;i++)
        std::cout << lst[i] << " ";
    std::cout << std::endl;

	std::cout << min_dif << std::endl;
	for(int i=0;i<siz-1;i++){
		if(lst[i+1]-lst[i]==min_dif)
			std::cout << lst[i] << " " << lst[i+1] << std::endl;
	}
	delete[]lst;
	return 0;
}
