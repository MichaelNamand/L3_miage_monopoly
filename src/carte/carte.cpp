//
//
//

#include "carte.h"


carte::carte(const string &texte): d_texte{texte} {

}

string carte::afficheCarte() const {
    return d_texte;
}
