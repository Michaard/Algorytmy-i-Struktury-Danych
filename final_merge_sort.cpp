#include <iostream>

void merge_elem(int *tab,int left,int right){
	int n,s;
	int siz=right-left+1;
	int halfsiz=(siz/2)+(siz%2);
	int* tmp_tab=new int[halfsiz];
	for(n=left,s=0;s<halfsiz;n++,s++){
		tmp_tab[s]=tab[n];
	}
	int k=((left+right)/2)+1;
	for(n=left,s=0;n<=right;n++){
		if(s<halfsiz){
			if(k<=right){
				if(tmp_tab[s]<tab[k]){
					tab[n]=tmp_tab[s];
					s++;
				}
				else{
					tab[n]=tab[k];
					k++;
				}
			}
			else{
				tab[n]=tmp_tab[s];
				s++;
			}
		}
		else{
			tab[n]=tab[k];
			k++;
		}
	}
	delete[]tmp_tab;
	return;
}

void merge_sort(int *tab,int beg,int en){
	if(beg==en)
		return;
	else{
		int mid=(beg+en)/2;
		merge_sort(tab,beg,mid);
		merge_sort(tab,mid+1,en);
		merge_elem(tab,beg,en);
	}
	return;
}

int find_min_dif(int *tab,int siz){
	int min_dif,dif,i;
	if(tab[0]>tab[1])
		min_dif=tab[0]-tab[1];
	else
		min_dif=tab[1]-tab[0];
	for(i=1;i<siz-1;i++){
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
	int siz,i;
	std::cin >> siz;
	int *lst=new int[siz];
	for(i=0;i<siz;i++){
		std::cin >> lst[i];
	}
	merge_sort(lst,0,siz-1);
	int min_dif=find_min_dif(lst,siz);
	std::cout << min_dif << std::endl;
	for(i=0;i<siz-1;i++){
		if(lst[i+1]-lst[i]==min_dif)
			std::cout << lst[i] << " " << lst[i+1] << std::endl;
	}
	delete[]lst;
	return 0;
}
