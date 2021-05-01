#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int cols = 16, rows = 15;

char words[rows][cols] = {"tgbwwinterwsesn",
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
                            "ohnkzwaterjgtra"};

char *getWordVertical(int n);
char *reverse(char *a);
bool searchVertical(char *str);
bool searchHorizontal(char *str);


int main()
{
    char word[16];
    int n;
    cin>>n;
    cin.ignore(n,'\n');
    for (int i=0;i<n;i++){
        cin.getline(word,16,'\n');
        if (searchVertical(word) || searchHorizontal(word))
            cout << "Ada\n";
        else 
            cout << "Tidak Ada\n";
    }
    return 0;
}

char *getWordVertical(int n){
    //Buat fungsi untuk mengambil string pada kolom ke-n
    char strambil[15];
    for(int i = 0;i<15;i++){
        strambil[i] = words[i][n];
    }
    
    char *str = strambil;
    return str;
}

char *reverse(char *a){
    //Buat fungsi untuk membalik string yang dimasukkan oleh user
    char *s = a;
	reverse(s,s+15);
	return s;
}

bool searchVertical(char *str){
    //Buat fungsi untuk melakukan pengecekan terhadap keberadaan string str
    //Lakukan pengecekan untuk setiap kolom (dapatkan string dengan memanggil fungsi getWordVertical(kolom))
    //Untuk setiap kolom, lakukan pengecekan pada 2 kondisi, normal dan reverse
    //Gunakan strstr
    char *strcheck;
    for(int kolom=0 ; kolom<15 ; kolom++){
    	strcheck = getWordVertical(kolom);
	
        char *check = strstr(strcheck,str);
        char *checkreverse = strstr(reverse(strcheck),str);
        if (check-strcheck >=0 || checkreverse-strcheck >=0){
            return true;
            break;
        }
        else{
            continue;	
        }
	}
    return false;
}

bool searchHorizontal(char *str){
    //Buat fungsi untuk melakukan pengecekan terhadap keberadaan string str
    //Lakukan pengecekan untuk setiap baris
    //Untuk setiap baris, lakukan pengecekan pada 2 kondisi, normal dan reverse
    //Gunakan strstr
    char *stringcheck, *check, *checkreverse;
    
    for (int i = 0; i < 16; i++){
	stringcheck = *(words+i);
		
	check = strstr(stringcheck, str);
	checkreverse = strstr(reverse(stringcheck), str);
	
		//strstr(stringcheck,str)
		if (check > 0 || checkreverse > 0){
			return true;
			break;
		}else{
			continue;
		}
	}
	return false;
}
