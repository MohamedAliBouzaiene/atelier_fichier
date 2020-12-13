#include "fichier.h"

using namespace std;

fichier::fichier()
{
    this->mesFichiers.push_back("bf_1_100-Lines.txt");
    this->mesFichiers.push_back("bf_2_100-Lines.txt");
    this->mesFichiers.push_back("sha1_100-Lines.txt");
    this->mesFichiers.push_back("sha2_100-Lines.txt");
    this->reccomendations.push_back("Votre login et votre mot de passe crypte sont dans la liste. Rien ne permet de verifier si le"
                                    " mot de passe a pu etre dechiffre mais il est fortement recommande de changer son mot de "
                                    "passe. Si vous utilisez le meme mot de passe sur d autres services en ligne, changez aussi ces mots de passe.");
    this->reccomendations.push_back("Votre login et votre mot de passe ne sont pas dans la liste mais il est recommande de "
                                    "changer son mot de passe. Si vous utilisez le meme mot de passe sur d autres services en "
                                    "ligne, changez aussi ces mots de passe.");
}

int changeFile(string adresse,string file){
    ifstream myFile(file);
    string myText;
    if(myFile.is_open()){
        while (getline (myFile, myText)) {
            myText.substr(myText.find(":") + 1);
            myText.erase(myText.find(":"),myText.length());
            if(myText==adresse){
                myFile.close();
                return 0;
            }
        }
        myFile.close();
        return 1;
    }
    else
        cout << "file not open" << endl;
    return 3;
}

void fichier::chercherAdresse(string adresse){
    for(vector<string>::iterator it=mesFichiers.begin();it!=mesFichiers.end();it-=-1){
        if(changeFile(adresse,*it)==1 && it+1==mesFichiers.end())
            cout << reccomendations[1] << endl;
        else if (changeFile(adresse,*it)==0){
            cout << reccomendations[0] << endl;
            break;
        }
    }
}


void fichier::chercherString(std::string ktiba){
    ofstream myFile("results.txt");
    string myText;

    for(vector<string>::iterator it=mesFichiers.begin();it!=mesFichiers.end();it-=-1){
        ifstream myFile1(*it);
        if(myFile1.is_open()){
            while (getline (myFile1, myText)) {
                if(myText.find(ktiba) != std::string::npos){
                    myFile << myText << endl;
                }
            }
            myFile1.close();
        }
        else
            cout << "file not open" << endl;
    }
    myFile.close();


}
