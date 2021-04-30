#include <iostream>
#include <cstring>

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
char *reverse(char *str);
bool searchVertical(char *str);
bool searchHorizontal(char *str);


int main()
{
    char word[16];
    int n;
    cin>>n;
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
    char str[16];
    for(int i = 0;i<15;i++){
        str[i] = words[i][n];
    }
    return str;
}

char *reverse(char *str){
    //Buat fungsi untuk membalik string yang dimasukkan oleh user
    return strrev(str);
}

bool searchVertical(char *str){
    //Buat fungsi untuk melakukan pengecekan terhadap keberadaan string str
    //Lakukan pengecekan untuk setiap kolom (dapatkan string dengan memanggil fungsi getWordVertical(kolom))
    //Untuk setiap kolom, lakukan pengecekan pada 2 kondisi, normal dan reverse
    //Gunakan strstr
    char strcheck[16];
    for(int kolom=0 ; kolom<15 ; kolom++){
    	strcheck = getWordVertical(kolom)
	
	check= strstr(strcheck,str);
	if (check-strcheck >=0){
		return true;
		break
	}
	else{
		continue;	
	}
	}
		
}

bool searchHorizontal(char *str){
    //Buat fungsi untuk melakukan pengecekan terhadap keberadaan string str
    //Lakukan pengecekan untuk setiap baris
    //Untuk setiap baris, lakukan pengecekan pada 2 kondisi, normal dan reverse
    //Gunakan strstr
    char stringcheck[16];
    char *check, *checkreverse;
    
    for (int i = 0; i < 16; i++){
		for (int j = 0; j < 16; j++){
			stringcheck[i] = words[i][j];
		}
	//strstr(stringcheck,str)
	check = strstr(stringcheck, str);
	checkreverse = strstr(reverse(stringcheck), str);
	
		if (check > 0 || checkreverse > 0){
			return check;
			break;
		}else{
			continue;
		}
	}
	return !check;
}
