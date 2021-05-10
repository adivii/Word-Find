/*
Adiwijaya Satria Nusantara (2017051006)
Kayla Atsila Ivanka (2017051008)
Muhammad Mufid Sadzili (2017051011)

https://github.com/adivii/Word-Find.git
*/

#include <iostream>
#include <cstring>
using namespace std;

const int rows = 15, cols = 16;

char words[rows][cols]{
    "tgbwwinterwsesn",
    "aaunttmmhfoodnb",
    "jlwcqldzmpmvdmr",
    "asagmquwvvbsohi",
    "bwplotanadtpgnc",
    "rewngodjcpnatnk",
    "eeotwosbqharrsa",
    "azcgeswewnaknpb",
    "dinnerqodlwdcar",
    "onopkwmparktzcc",
    "qbfrogmamwpweey",
    "lqzqnnmrzjjsclg",
    "mosgzczetdbooto",
    "pdcrzmsngrdnrpz",
    "ohnkzwaterjgtra"
};

char *reverse(char *a);
char *getWordVertical(int n);
bool searchVertical(char *s);
char *getWordHorizontal(int n);
bool searchHorizontal(char *s);

int main(){

    int n;
    char word[16];
    cin >> n;
    cin.ignore(1,'\n');
    for (int i=0;i<n;i++){
        cin.getline(word,16,'\n');
        if (searchVertical(word) || searchHorizontal(word)){
            cout << "Ada\n";
        }else{
            cout << "Tidak Ada\n";
    	}
    }
    return 0;
}

char *reverse(char *a){
    //Buat fungsi untuk membalik string yang dimasukkan oleh user
    static char kayla[16];
	for(int i = 0;i<15;i++){
		kayla[i] = a[14-i];
	}
	return kayla;
}

char *getWordVertical(int n){
	static char strambil[15];
    for(int i = 0;i<15;i++){
        strambil[i] = words[i][n];
    }

    return strambil;
}

bool searchVertical(char *s){
    bool stat;
	for(int i = 0;i < 16;i++){
		char *strcek = getWordVertical(i);
		char *cek = strstr(strcek,s);
		char *cekbalik = strstr(reverse(strcek),s);

		if(cek){
			stat = true;
			break;
		}else if(cekbalik){
            stat = true;
            break;
		}else{
            stat = false;
		}
	}
	return stat;
}

char *getWordHorizontal(int n){
	char *string;
    string = *(words+n);
	char *s = string;
	return s;
}

bool searchHorizontal(char *s){
    bool stat;
	for(int i = 0;i < 16;i++){
		char *strcek = getWordHorizontal(i);

		char *cek = strstr(strcek,s);
		char *cekbalik = strstr(reverse(strcek),s);

		if(cek){
			stat = true;
			break;
		}else if(cekbalik){
            stat = true;
            break;
		}else{
            stat = false;
		}
	}
	return stat;
}
