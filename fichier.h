#ifndef FICHIER_H
#define FICHIER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class fichier
{
    public:
        fichier();
        void chercherAdresse(std::string adresse);
        void chercherString(std::string ktiba);

    protected:
        std::vector<std::string> mesFichiers;
        std::vector<std::string> reccomendations;
};

#endif // FICHIER_H
